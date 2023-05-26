
#include "fsl_debug_console.h"
#include "sss_crypto.h"

#define BITLEN2BYTELEN(x) (((x) + 7u) >> 3)

#define AES_128_KEY_BITS     128u
#define AES_128_KEY_BYTE_LEN BITLEN2BYTELEN(AES_128_KEY_BITS)
#define AES_192_KEY_BITS     192u
#define AES_192_KEY_BYTE_LEN BITLEN2BYTELEN(AES_192_KEY_BITS)
#define AES_256_KEY_BITS     256u
#define AES_256_KEY_BYTE_LEN BITLEN2BYTELEN(AES_256_KEY_BITS)

/******************************************************************************
*******************************************************************************
* Public functions
*******************************************************************************
******************************************************************************/
status_t SSS_aes_cmac_starts(cmac_aes_context_t *ctx, const unsigned char *key, size_t key_bytelen)
{
    status_t ret;
    do
    {
        if ((ret = CRYPTO_InitHardware()) != kStatus_Success)
        {
            break;
        }
        if ((ret = SSS_set_aes_key_cmac(ctx, key, key_bytelen)) != kStatus_Success)
        {
            break;
        }
        /* CMAC OPERATION INIT */
        if ((sss_sscp_mac_context_init(&ctx->sscp_mac, &g_sssSession, &ctx->sssKey, kAlgorithm_SSS_CMAC_AES,
                                        kMode_SSS_Mac)) != kStatus_SSS_Success)
        {
            ret =kStatus_Fail;
            break;
        }

    } while (false);
    return ret;
}

#ifdef SSS_CMAC_UPDATE_SUPPORTED

status_t SSS_aes_cmac_update(cmac_aes_context_t *ctx, const unsigned char *input, size_t ilen)
{
    status_t ret;
    do
    {
        if (ctx == NULL || input == NULL)
        {
            RAISE_ERROR(ret, kStatus_InvalidArgument);
        }

        ret = sss_sscp_mac_update(&ctx->sscp_mac, input, ilen);

    } while (0);

    return (ret);
}

status_t SSS_aes_cmac_finish(cmac_aes_context_t *ctx, unsigned char *output)
{
    status_t ret;
    size_t olen = 0;
    do
    {
        if (ctx == NULL || output == NULL)
        {
            RAISE_ERROR(ret, kStatus_SSS_InvalidArgument);
            break;
        }
        if((sss_sscp_mac_finish(&ctx->sscp_mac, output, &olen)) != kStatus_SSS_Success)
        {
            ret = kStatus_Fail;
            break;
        }

    } while (false);

    return (ret);
}

#endif

void SSS_aes_cmac_free(cmac_aes_context_t *ctx)
{
    if (ctx->sscp_mac_was_set)
    {
        sss_sscp_mac_context_free(&ctx->sscp_mac);
        ctx->sscp_mac_was_set = false;
    }

    SSS_KEY_OBJ_FREE(&ctx->sssKey);
}
status_t SSS_aes_cmac(cmac_aes_context_t *pCtx,
                      const unsigned char *key,
                      size_t keylen,
                      const unsigned char *input,
                      size_t ilen,
                      unsigned char *output)
{
    size_t macSize     = 16u;
    size_t key_bytelen = (keylen + 7u) / 8u;

    status_t ret = kStatus_Fail;
    memset(pCtx, 0, sizeof(cmac_aes_context_t));

    pCtx->sscp_mac_was_set = false;
    do
    {
        if (CRYPTO_InitHardware() != kStatus_Success)
        {
            break;
        }

        if (SSS_aes_cmac_starts(pCtx, key, key_bytelen) != kStatus_Success)
        {
            break;
        }

        pCtx->sscp_mac_was_set = true;
        /* RUN CMAC ONE GO */
        if ((sss_sscp_mac_one_go(&pCtx->sscp_mac, (const uint8_t *)input, ilen, (uint8_t *)output, &macSize)) !=
            kStatus_SSS_Success)
        {
            ret =kStatus_Fail;
        }
        else
        {
            ret = kStatus_Success;
        }
        /* Free MAC context only if its init has been successful */
        (void)sss_sscp_mac_context_free(&pCtx->sscp_mac);
    } while (false);
    /* CLEAN UP */
    /* KEYOBJECT FREE*/
    SSS_aes_cmac_free(pCtx);

    return (ret);
}

/*
 * Implementation of AES-CMAC-PRF-128 defined in RFC 4615
 */
status_t SSS_aes_cmac_prf_128(cmac_aes_context_t *pCtx,
                              const unsigned char *key,
                              size_t key_len,
                              const unsigned char *input,
                              size_t in_len,
                              unsigned char output[16])
{
    status_t ret;
    unsigned char zero_key[AES_128_KEY_BYTE_LEN];
    unsigned char int_key[AES_128_KEY_BYTE_LEN];

    do
    {
        if (key == NULL || input == NULL || output == NULL)
        {
            RAISE_ERROR(ret, kStatus_InvalidArgument);
        }
        if (key_len == AES_128_KEY_BYTE_LEN)
        {
            /* Use key as is */
            memcpy(int_key, key, AES_128_KEY_BYTE_LEN);
        }
        else
        {
            memset(zero_key, 0, AES_128_KEY_BYTE_LEN);

            ret = SSS_aes_cmac(pCtx, zero_key, AES_128_KEY_BITS, key, key_len, int_key);
            if (ret != kStatus_Success)
            {
                break;
            }
        }
        ret = SSS_aes_cmac(pCtx, int_key, AES_128_KEY_BITS, input, in_len, output);
    } while (false);

    memset(int_key, 0, sizeof(int_key));

    return (ret);
}

status_t SSS_set_aes_key_cmac(cmac_aes_context_t *pCtx, const unsigned char *key, size_t key_bytelen)
{
    status_t ret;
    do
    {
        size_t keylen = key_bytelen * 8u;
        uint8_t ramKey[32];
        (void)memcpy(ramKey, key, key_bytelen);

        if ((sss_sscp_key_object_init(&pCtx->sssKey, &g_keyStore)) != kStatus_SSS_Success)
        {
            ret = kStatus_Fail;
            break;
        }
        if ((SSS_KEY_ALLOCATE_HANDLE(&pCtx->sssKey, 1u, kSSS_KeyPart_Default, kSSS_CipherType_AES, key_bytelen,
                                           SSS_KEYPROP_OPERATION_MAC)) != kStatus_SSS_Success)
        {
            ret = kStatus_Fail;
            break;
        }
        if ((SSS_KEY_STORE_SET_KEY(&pCtx->sssKey, ramKey, key_bytelen, keylen, kSSS_KeyPart_Default)) !=
            kStatus_SSS_Success)
        {
            ret = kStatus_Fail;
            break;
        }
        ret = kStatus_Success;

    } while (false);
    return ret;
}

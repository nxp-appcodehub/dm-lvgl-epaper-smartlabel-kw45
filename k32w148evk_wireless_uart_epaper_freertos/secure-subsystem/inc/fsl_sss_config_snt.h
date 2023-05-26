#if (defined(KW45_A0_SUPPORT) && KW45_A0_SUPPORT)
/*
 * Copyright 2018-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_SSS_CONFIG_SNT_H_
#define _FSL_SSS_CONFIG_SNT_H_

#include <stdint.h>

/*SAB Security Enclave Type definitions*/
typedef uint32_t sab_se_type_t;
#define SAB_SE_TYPE_Software       ((sab_se_type_t)0x00)
#define SAB_SE_TYPE_SECO           ((sab_se_type_t)0x01)
#define SAB_SE_TYPE_S200           ((sab_se_type_t)0x02)
#define SAB_SE_TYPE_S300           ((sab_se_type_t)0x03)
#define SAB_SE_TYPE_S400           ((sab_se_type_t)0x04)
#define SAB_SE_TYPE_S500           ((sab_se_type_t)0x05)
#define SAB_SE_TYPE_SECURE_ELEMENT ((sab_se_type_t)0x06)

/*SAB mode definitions. Default is blocking calls*/
typedef uint32_t sab_mode_t;
#define SAB_MODE_ENCRYPT               ((sab_mode_t)0x00)
#define SAB_MODE_DECRYPT               ((sab_mode_t)0x01)
#define SAB_MODE_SIGN                  ((sab_mode_t)0x02)
#define SAB_MODE_VERIFY                ((sab_mode_t)0x03)
#define SAB_MODE_COMPUTE_SHARED_SECRET ((sab_mode_t)0x04)
#define SAB_MODE_DIGEST                ((sab_mode_t)0x05)
#define SAB_MODE_MAC                   ((sab_mode_t)0x06)

/* SAB algorithm definition */
typedef uint32_t sab_algorithm_t;
/* AES */
#define SAB_ALGO_AES_ECB ((sab_algorithm_t)0x00)
#define SAB_ALGO_AES_CBC ((sab_algorithm_t)0x01)
#define SAB_ALGO_AES_CTR ((sab_algorithm_t)0x02)
#define SAB_ALGO_AES_GCM ((sab_algorithm_t)0x03)
#define SAB_ALGO_AES_CCM ((sab_algorithm_t)0x04)
/* CHACHA_POLY */
#define SAB_ALGO_CHACHA_POLY ((sab_algorithm_t)0x05)
/* DES3 */
#define SAB_ALGO_DES3_ECB ((sab_algorithm_t)0x06)
#define SAB_ALGO_DES3_CBC ((sab_algorithm_t)0x07)
/* digest */
#define SAB_ALGO_SHA1   ((sab_algorithm_t)0x08)
#define SAB_ALGO_SHA224 ((sab_algorithm_t)0x09)
#define SAB_ALGO_SHA256 ((sab_algorithm_t)0x0A)
#define SAB_ALGO_SHA384 ((sab_algorithm_t)0x0B)
#define SAB_ALGO_SHA512 ((sab_algorithm_t)0x0C)
/* MAC */
#define SAB_ALGO_CMAC_AES    ((sab_algorithm_t)0x0D)
#define SAB_ALGO_HMAC_SHA256 ((sab_algorithm_t)0x0E)
/* Diffie-Helmann */
#define SAB_ALGO_DH   ((sab_algorithm_t)0x0F)
#define SAB_ALGO_ECDH ((sab_algorithm_t)0x10)
/* DSA */
#define SAB_ALGO_DSA_SHA1   ((sab_algorithm_t)0x11)
#define SAB_ALGO_DSA_SHA224 ((sab_algorithm_t)0x12)
#define SAB_ALGO_DSA_SHA256 ((sab_algorithm_t)0x13)
/* RSA */
#define SAB_ALGO_RSASSA_PKCS1_V1_5_SHA1       ((sab_algorithm_t)0x14)
#define SAB_ALGO_RSASSA_PKCS1_V1_5_SHA224     ((sab_algorithm_t)0x15)
#define SAB_ALGO_RSASSA_PKCS1_V1_5_SHA256     ((sab_algorithm_t)0x16)
#define SAB_ALGO_RSASSA_PKCS1_V1_5_SHA384     ((sab_algorithm_t)0x17)
#define SAB_ALGO_RSASSA_PKCS1_V1_5_SHA512     ((sab_algorithm_t)0x18)
#define SAB_ALGO_RSASSA_PKCS1_PSS_MGF1_SHA1   ((sab_algorithm_t)0x19)
#define SAB_ALGO_RSASSA_PKCS1_PSS_MGF1_SHA224 ((sab_algorithm_t)0x1A)
#define SAB_ALGO_RSASSA_PKCS1_PSS_MGF1_SHA256 ((sab_algorithm_t)0x1B)
#define SAB_ALGO_RSASSA_PKCS1_PSS_MGF1_SHA384 ((sab_algorithm_t)0x1C)
#define SAB_ALGO_RSASSA_PKCS1_PSS_MGF1_SHA512 ((sab_algorithm_t)0x1D)
/* ECDSA */
#define SAB_ALGO_ECDSA_SHA1   ((sab_algorithm_t)0x1E)
#define SAB_ALGO_ECDSA_SHA224 ((sab_algorithm_t)0x1F)
#define SAB_ALGO_ECDSA_SHA256 ((sab_algorithm_t)0x20)
#define SAB_ALGO_ECDSA_SHA384 ((sab_algorithm_t)0x21)
#define SAB_ALGO_ECDSA_SHA512 ((sab_algorithm_t)0x22)

/* SAB Key Type definitions */
#define SAB_KEY_TYPE_SYMMETRIC  (0x00)
#define SAB_KEY_TYPE_ASYMMETRIC (0x01)

/* Key generate function modes */
#define SAB_KEY_GEN_MODE_SYMMETRIC (0U)
#define SAB_KEY_GEN_MODE_ECC       (1U)
#define SAB_KEY_GEN_MODE_MONTDH    (2U)
#define SAB_KEY_GEN_MODE_EDDSA     (3U)

/* clang-format off */
#define SSS_SESSION_MAX_CONTEXT_SIZE        (16)
#define SSS_KEY_STORE_MAX_CONTEXT_SIZE      (16 + 80)
#define SSS_KEY_OBJECT_MAX_CONTEXT_SIZE     (16)
#define SSS_SYMMETRIC_MAX_CONTEXT_SIZE      (16 + 80)
#define SSS_AEAD_MAX_CONTEXT_SIZE           (16)
#define SSS_DIGEST_MAX_CONTEXT_SIZE         (16 + 80)
#define SSS_MAC_MAX_CONTEXT_SIZE            (16 + 16)
#define SSS_ASYMMETRIC_MAX_CONTEXT_SIZE     (16)
#define SSS_TUNNEL_MAX_CONTEXT_SIZE         (16)
#define SSS_DERIVE_KEY_MAX_CONTEXT_SIZE     (16)
#define SSS_RNG_MAX_CONTEXT_SIZE            (16)
#define SSS_PH_CLSHA_CTX_MAX_CONTEXT_SIZE   (216)
/* clang-format on */

#define SSS_TYPE_ENUM_ALT
typedef enum _sss_type
{
    kType_SSS_Software      = SAB_SE_TYPE_Software,
    kType_SSS_SECO          = SAB_SE_TYPE_SECO,
    kType_SSS_Sentinel200   = SAB_SE_TYPE_S200,
    kType_SSS_Sentinel300   = SAB_SE_TYPE_S300,
    kType_SSS_Sentinel400   = SAB_SE_TYPE_S400,
    kType_SSS_Sentinel500   = SAB_SE_TYPE_S500,
    kType_SSS_SecureElement = SAB_SE_TYPE_SECURE_ELEMENT,
} sss_type_t;

#define SSS_MODE_ENUM_ALT
typedef enum _sss_mode
{
    kMode_SSS_Encrypt             = SAB_MODE_ENCRYPT,
    kMode_SSS_Decrypt             = SAB_MODE_DECRYPT,
    kMode_SSS_Sign                = SAB_MODE_SIGN,
    kMode_SSS_Verify              = SAB_MODE_VERIFY,
    kMode_SSS_ComputeSharedSecret = SAB_MODE_COMPUTE_SHARED_SECRET,
    kMode_SSS_Digest              = SAB_MODE_DIGEST,
    kMode_SSS_Mac                 = SAB_MODE_MAC,
} sss_mode_t;

#define SSS_ALGORITHM_ENUM_ALT
typedef enum _sss_algorithm
{
    /* AES */
    kAlgorithm_SSS_AES_ECB = SAB_ALGO_AES_ECB,
    kAlgorithm_SSS_AES_CBC = SAB_ALGO_AES_CBC,
    kAlgorithm_SSS_AES_CTR = SAB_ALGO_AES_CTR,
    kAlgorithm_SSS_AES_GCM = SAB_ALGO_AES_GCM,
    kAlgorithm_SSS_AES_CCM = SAB_ALGO_AES_CCM,
    /* CHACHA_POLY */
    kAlgorithm_SSS_CHACHA_POLY = SAB_ALGO_CHACHA_POLY,
    /* DES3 */
    kAlgorithm_SSS_DES3_ECB = SAB_ALGO_DES3_ECB,
    kAlgorithm_SSS_DES3_CBC = SAB_ALGO_DES3_CBC,
    /* digest */
    kAlgorithm_SSS_SHA1   = SAB_ALGO_SHA1,
    kAlgorithm_SSS_SHA224 = SAB_ALGO_SHA224,
    kAlgorithm_SSS_SHA256 = SAB_ALGO_SHA256,
    kAlgorithm_SSS_SHA384 = SAB_ALGO_SHA384,
    kAlgorithm_SSS_SHA512 = SAB_ALGO_SHA512,
    /* MAC */
    kAlgorithm_SSS_CMAC_AES    = SAB_ALGO_CMAC_AES,
    kAlgorithm_SSS_HMAC_SHA256 = SAB_ALGO_HMAC_SHA256,
    /* Diffie-Helmann */
    kAlgorithm_SSS_DH   = SAB_ALGO_DH,
    kAlgorithm_SSS_ECDH = SAB_ALGO_ECDH,
    /* DSA */
    kAlgorithm_SSS_DSA_SHA1   = SAB_ALGO_DSA_SHA1,
    kAlgorithm_SSS_DSA_SHA224 = SAB_ALGO_DSA_SHA224,
    kAlgorithm_SSS_DSA_SHA256 = SAB_ALGO_DSA_SHA256,
    /* RSA */
    kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA1       = SAB_ALGO_RSASSA_PKCS1_V1_5_SHA1,
    kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA224     = SAB_ALGO_RSASSA_PKCS1_V1_5_SHA224,
    kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA256     = SAB_ALGO_RSASSA_PKCS1_V1_5_SHA256,
    kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA384     = SAB_ALGO_RSASSA_PKCS1_V1_5_SHA384,
    kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA512     = SAB_ALGO_RSASSA_PKCS1_V1_5_SHA512,
    kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA1   = SAB_ALGO_RSASSA_PKCS1_PSS_MGF1_SHA1,
    kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA224 = SAB_ALGO_RSASSA_PKCS1_PSS_MGF1_SHA224,
    kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA256 = SAB_ALGO_RSASSA_PKCS1_PSS_MGF1_SHA256,
    kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA384 = SAB_ALGO_RSASSA_PKCS1_PSS_MGF1_SHA384,
    kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA512 = SAB_ALGO_RSASSA_PKCS1_PSS_MGF1_SHA512,
    /* ECDSA */
    kAlgorithm_SSS_ECDSA_SHA1   = SAB_ALGO_ECDSA_SHA1,
    kAlgorithm_SSS_ECDSA_SHA224 = SAB_ALGO_ECDSA_SHA224,
    kAlgorithm_SSS_ECDSA_SHA256 = SAB_ALGO_ECDSA_SHA256,
    kAlgorithm_SSS_ECDSA_SHA384 = SAB_ALGO_ECDSA_SHA384,
    kAlgorithm_SSS_ECDSA_SHA512 = SAB_ALGO_ECDSA_SHA512,
} sss_algorithm_t;

#define SSS_KEY_CIPHER_TYPE_ENUM_ALT
typedef enum _sss_cipher_type
{
    kSSS_CipherType_NONE = SAB_KEY_TYPE_SYMMETRIC,
    kSSS_CipherType_AES  = SAB_KEY_TYPE_SYMMETRIC,
    kSSS_CipherType_DES  = SAB_KEY_TYPE_SYMMETRIC,

    kSSS_CipherType_CMAC = SAB_KEY_TYPE_SYMMETRIC,
    kSSS_CipherType_HMAC = SAB_KEY_TYPE_SYMMETRIC,

    kSSS_CipherType_MAC     = SAB_KEY_TYPE_SYMMETRIC,
    kSSS_CipherType_RSA     = SAB_KEY_TYPE_ASYMMETRIC, /*! RSA RAW format      */
    kSSS_CipherType_RSA_CRT = SAB_KEY_TYPE_ASYMMETRIC, /*! RSA CRT format      */

    /* The following keys can be identified
     * solely by the *Family* and bit length
     */
    kSSS_CipherType_EC_NIST_P = SAB_KEY_TYPE_ASYMMETRIC, /*! Keys Part of NIST-P Family */
    kSSS_CipherType_EC_NIST_K = SAB_KEY_TYPE_ASYMMETRIC, /*! Keys Part of NIST-K Family */

    /* The following keys need their full curve parameters (p,a,b,x,y,n,h)
     */
    /*! Montgomery Key,   */
    kSSS_CipherType_EC_MONTGOMERY = SAB_KEY_TYPE_ASYMMETRIC,
    /*! twisted Edwards form elliptic curve public key */
    kSSS_CipherType_EC_TWISTED_ED = SAB_KEY_TYPE_ASYMMETRIC,
    /*! Brainpool form elliptic curve public key */
    kSSS_CipherType_EC_BRAINPOOL = SAB_KEY_TYPE_ASYMMETRIC,
    /*! Barreto Naehrig curve */
    kSSS_CipherType_EC_BARRETO_NAEHRIG = SAB_KEY_TYPE_ASYMMETRIC,

    kSSS_CipherType_UserID      = SAB_KEY_TYPE_ASYMMETRIC,
    kSSS_CipherType_Certificate = SAB_KEY_TYPE_ASYMMETRIC,
    kSSS_CipherType_Binary      = SAB_KEY_TYPE_ASYMMETRIC,
    kSSS_CipherType_Count       = SAB_KEY_TYPE_ASYMMETRIC,
    kSSS_CipherType_PCR         = SAB_KEY_TYPE_ASYMMETRIC,
    kSSS_CipherType_ReservedPin = SAB_KEY_TYPE_ASYMMETRIC,
} sss_cipher_type_t;

/* Key generate function modes */
typedef enum
{
    kSSS_KeyGenMode_Symetric = SAB_KEY_GEN_MODE_SYMMETRIC,
    kSSS_KeyGenMode_Ecc      = SAB_KEY_GEN_MODE_ECC,
    kSSS_KeyGenMode_Montdh   = SAB_KEY_GEN_MODE_MONTDH,
    kSSS_KeyGenMode_Ecdsa    = SAB_KEY_GEN_MODE_EDDSA
} sss_key_gen_mode_t;

#endif /* _FSL_SSS_CONFIG_H_ */
#else
/*
 * Copyright 2018-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SSS_CONFIG_SNT_H
#define FSL_SSS_CONFIG_SNT_H

#include <stdint.h>

#define SSS_SESSION_MAX_CONTEXT_SIZE      (16)
#define SSS_KEY_STORE_MAX_CONTEXT_SIZE    (16 + 80)
#define SSS_KEY_OBJECT_MAX_CONTEXT_SIZE   (16)
#define SSS_SYMMETRIC_MAX_CONTEXT_SIZE    (16 + 80)
#define SSS_AEAD_MAX_CONTEXT_SIZE         (16)
#define SSS_DIGEST_MAX_CONTEXT_SIZE       (16 + 80)
#define SSS_MAC_MAX_CONTEXT_SIZE          (16 + 16)
#define SSS_ASYMMETRIC_MAX_CONTEXT_SIZE   (16)
#define SSS_TUNNEL_MAX_CONTEXT_SIZE       (16)
#define SSS_DERIVE_KEY_MAX_CONTEXT_SIZE   (16)
#define SSS_RNG_MAX_CONTEXT_SIZE          (16)
#define SSS_PH_CLSHA_CTX_MAX_CONTEXT_SIZE (216)

#define SSS_TYPE_ENUM_ALT
typedef uint32_t sss_type_t;
#define kType_SSS_Software      ((sss_type_t)0x00u)
#define kType_SSS_SECO          ((sss_type_t)0x01u)
#define kType_SSS_Sentinel200   ((sss_type_t)0x02u)
#define kType_SSS_Sentinel300   ((sss_type_t)0x03u)
#define kType_SSS_Sentinel400   ((sss_type_t)0x04u)
#define kType_SSS_Sentinel500   ((sss_type_t)0x05u)
#define kType_SSS_SecureElement ((sss_type_t)0x06u)

#define SSS_MODE_ENUM_ALT
typedef uint32_t sss_mode_t;
#define kMode_SSS_Encrypt             ((sss_mode_t)0x00u)
#define kMode_SSS_Decrypt             ((sss_mode_t)0x01u)
#define kMode_SSS_Sign                ((sss_mode_t)0x02u)
#define kMode_SSS_Verify              ((sss_mode_t)0x03u)
#define kMode_SSS_ComputeSharedSecret ((sss_mode_t)0x04u)
#define kMode_SSS_Digest              ((sss_mode_t)0x05u)
#define kMode_SSS_Mac                 ((sss_mode_t)0x06u)

#define SSS_ALGORITHM_ENUM_ALT
typedef uint32_t sss_algorithm_t;
/* AES */
#define kAlgorithm_SSS_AES_ECB                      ((sss_algorithm_t)0x00u)
#define kAlgorithm_SSS_AES_CBC                      ((sss_algorithm_t)0x01u)
#define kAlgorithm_SSS_AES_CTR                      ((sss_algorithm_t)0x02u)
#define kAlgorithm_SSS_AES_GCM                      ((sss_algorithm_t)0x03u)
#define kAlgorithm_SSS_AES_CCM                      ((sss_algorithm_t)0x04u)
/* CHACHA_POLY */
#define kAlgorithm_SSS_CHACHA_POLY                  ((sss_algorithm_t)0x05u)
/* DES3 */
#define kAlgorithm_SSS_DES3_ECB                     ((sss_algorithm_t)0x06u)
#define kAlgorithm_SSS_DES3_CBC                     ((sss_algorithm_t)0x07u)
/* digest */
#define kAlgorithm_SSS_SHA1                         ((sss_algorithm_t)0x08u)
#define kAlgorithm_SSS_SHA224                       ((sss_algorithm_t)0x09u)
#define kAlgorithm_SSS_SHA256                       ((sss_algorithm_t)0x0au)
#define kAlgorithm_SSS_SHA384                       ((sss_algorithm_t)0x0bu)
#define kAlgorithm_SSS_SHA512                       ((sss_algorithm_t)0x0cu)
/* MAC */
#define kAlgorithm_SSS_CMAC_AES                     ((sss_algorithm_t)0x0du)
#define kAlgorithm_SSS_HMAC_SHA256                  ((sss_algorithm_t)0x0eu)
/* Diffie-Helmann */
#define kAlgorithm_SSS_DH                           ((sss_algorithm_t)0x0fu)
#define kAlgorithm_SSS_ECDH                         ((sss_algorithm_t)0x10u)
#define kAlgorithm_MONTDH                           ((sss_algorithm_t)0x30u)
/* DSA */
#define kAlgorithm_SSS_DSA_SHA1                     ((sss_algorithm_t)0x11u)
#define kAlgorithm_SSS_DSA_SHA224                   ((sss_algorithm_t)0x12u)
#define kAlgorithm_SSS_DSA_SHA256                   ((sss_algorithm_t)0x13u)
/* RSA */
#define kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA1       ((sss_algorithm_t)0x14u)
#define kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA224     ((sss_algorithm_t)0x15u)
#define kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA256     ((sss_algorithm_t)0x16u)
#define kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA384     ((sss_algorithm_t)0x17u)
#define kAlgorithm_SSS_RSASSA_PKCS1_V1_5_SHA512     ((sss_algorithm_t)0x18u)
#define kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA1   ((sss_algorithm_t)0x19u)
#define kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA224 ((sss_algorithm_t)0x1au)
#define kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA256 ((sss_algorithm_t)0x1bu)
#define kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA384 ((sss_algorithm_t)0x1cu)
#define kAlgorithm_SSS_RSASSA_PKCS1_PSS_MGF1_SHA512 ((sss_algorithm_t)0x1du)
/* ECDSA */
#define kAlgorithm_SSS_ECDSA_SHA1                   ((sss_algorithm_t)0x1eu)
#define kAlgorithm_SSS_ECDSA_SHA224                 ((sss_algorithm_t)0x1fu)
#define kAlgorithm_SSS_ECDSA_SHA256                 ((sss_algorithm_t)0x20u)
#define kAlgorithm_SSS_ECDSA_SHA384                 ((sss_algorithm_t)0x21u)
#define kAlgorithm_SSS_ECDSA_SHA512                 ((sss_algorithm_t)0x22u)
/* KDF */
#define kAlgorithm_SSS_E2E_BLOB                     ((sss_algorithm_t)0x40u)
#define kAlgorithm_SSS_BLE_F5                       ((sss_algorithm_t)0x50u)

#define SAB_KEY_TYPE_SYMMETRIC  (0x00)
#define SAB_KEY_TYPE_ASYMMETRIC (0x01)
#define SSS_KEY_CIPHER_TYPE_ENUM_ALT
typedef uint32_t sss_cipher_type_t;
#define kSSS_CipherType_NONE               ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_AES                ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_DES                ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_CMAC               ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_HMAC               ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_MAC                ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_SYMMETRIC          ((sss_cipher_type_t)0x10u)
#define kSSS_CipherType_RSA                ((sss_cipher_type_t)0x1u)  /*! RSA RAW format      */
#define kSSS_CipherType_RSA_CRT            ((sss_cipher_type_t)0x1u)  /*! RSA CRT format      */
/* The following keys can be identified
 * solely by the *Family* and bit length */
#define kSSS_CipherType_EC_NIST_P          ((sss_cipher_type_t)0x40u) /*! Keys Part of NIST-P Family */
#define kSSS_CipherType_EC_NIST_K          ((sss_cipher_type_t)0x1u)  /*! Keys Part of NIST-K Family */
/* The following keys need their full curve parameters (p,a,b,x,y,n,h) */
/*! Montgomery Key,   */
#define kSSS_CipherType_EC_MONTGOMERY      ((sss_cipher_type_t)0x50u)
/*! twisted Edwards form elliptic curve public key */
#define kSSS_CipherType_EC_TWISTED_ED      ((sss_cipher_type_t)0x51u)
/*! Brainpool form elliptic curve public key */
#define kSSS_CipherType_EC_BRAINPOOL       ((sss_cipher_type_t)0x1u)
/*! Barreto Naehrig curve */
#define kSSS_CipherType_EC_BARRETO_NAEHRIG ((sss_cipher_type_t)0x1u)
#define kSSS_CipherType_UserID             ((sss_cipher_type_t)0x1u)
#define kSSS_CipherType_Certificate        ((sss_cipher_type_t)0x1u)
#define kSSS_CipherType_Binary             ((sss_cipher_type_t)0x1u)
#define kSSS_CipherType_Count              ((sss_cipher_type_t)0x1u)
#define kSSS_CipherType_PCR                ((sss_cipher_type_t)0x1u)
#define kSSS_CipherType_ReservedPin        ((sss_cipher_type_t)0x1u)

#define SSS_STATUS_ENUM_ALT
typedef uint32_t sss_status_t;
/** Operation was successful */
#define kStatus_SSS_Success         ((sss_status_t)0x5a5a5a5au)
/** Operation failed */
#define kStatus_SSS_Fail            ((sss_status_t)0x3c3c0000u)
/** Operation not performed because some of the passed parameters
 * were found inappropriate */
#define kStatus_SSS_InvalidArgument ((sss_status_t)0x3c3c0001u)
/** Where the underlying sub-system *supports* multi-threading,
 * Internal status to handle simultaneous access.
 *
 * This status is not expected to be returned to higher layers.
 * */
#define kStatus_SSS_ResourceBusy    ((sss_status_t)0x3c3c0002u)

#define SSS_KEY_PART_ENUM_ALT
typedef uint32_t sss_key_part_t;
/** Part of a key */
#define kSSS_KeyPart_NONE                            ((sss_key_part_t)0x0u)
/** Applicable where we have UserID, PIN, Binary Files,
 * Certificates, Symmetric Keys, PCR */
#define kSSS_KeyPart_Default                         ((sss_key_part_t)0x1u)
/** Public part of asymmetric key */
#define kSSS_KeyPart_Public                          ((sss_key_part_t)0x2u)
/** Private only part of asymmetric key */
#define kSSS_KeyPart_Private                         ((sss_key_part_t)0x3u)
/** Both, public and private part of asymmetric key */
#define kSSS_KeyPart_Pair                            ((sss_key_part_t)0x4u)

typedef uint32_t sss_mgmt_security_level_t;
#define kSSS_mgmt_security_lvl_NON_SECURE            ((sss_mgmt_security_level_t)0x0u)
#define kSSS_mgmt_security_lvl_NON_SECURE_PRIVILEGED ((sss_mgmt_security_level_t)0x1u)
#define kSSS_mgmt_security_lvl_SECURE                ((sss_mgmt_security_level_t)0x2u)
#define kSSS_mgmt_security_lvl_SECURE_PRIVILEGED     ((sss_mgmt_security_level_t)0x3u)

typedef uint32_t sss_sscp_key_store_property_t;
#define kSSS_key_store_prop_totalAllocatedMemory     ((sss_sscp_key_store_property_t)0x0u)
#define kSSS_key_store_prop_availableMemory          ((sss_sscp_key_store_property_t)0x1u)
#define kSSS_key_store_prop_totalNumberOfKeyObjects  ((sss_sscp_key_store_property_t)0x2u)
#define kSSS_key_store_prop_availableKeyObjects      ((sss_sscp_key_store_property_t)0x3u)

typedef uint32_t sss_sscp_key_property_t;
#define kSSS_KeyProp_Locked                          ((sss_sscp_key_property_t)0x80000000u)
#define kSSS_KeyProp_SecAccess_NS_USER               ((sss_sscp_key_property_t)0x00000000u)
#define kSSS_KeyProp_SecAccess_NS_PRIV               ((sss_sscp_key_property_t)0x20000000u)
#define kSSS_KeyProp_SecAccess_S_USER                ((sss_sscp_key_property_t)0x40000000u)
#define kSSS_KeyProp_SecAccess_S_PRIV                ((sss_sscp_key_property_t)0x60000000u)
#define kSSS_KeyProp_TrustedKey                      ((sss_sscp_key_property_t)0x10000000u)
#define kSSS_KeyProp_NoImportExport                  ((sss_sscp_key_property_t)0x00010000u)
#define kSSS_KeyProp_NoPlainRead                     ((sss_sscp_key_property_t)0x00008000u)
#define kSSS_KeyProp_NoPlainWrite                    ((sss_sscp_key_property_t)0x00004000u)
#define kSSS_KeyProp_NoVerify                        ((sss_sscp_key_property_t)0x00002000u)
#define kSSS_KeyProp_NoSign                          ((sss_sscp_key_property_t)0x00001000u)
#define kSSS_KeyProp_CryptoAlgo_KDF                  ((sss_sscp_key_property_t)0x00000010u)
#define kSSS_KeyProp_CryptoAlgo_AsymSignVerify       ((sss_sscp_key_property_t)0x00000008u)
#define kSSS_KeyProp_CryptoAlgo_AEAD                 ((sss_sscp_key_property_t)0x00000004u)
#define kSSS_KeyProp_CryptoAlgo_MAC                  ((sss_sscp_key_property_t)0x00000002u)
#define kSSS_KeyProp_CryptoAlgo_AES                  ((sss_sscp_key_property_t)0x00000001u)

typedef uint32_t sss_keyObjFree_options_t;
#define kSSS_keyObjFree_KeysStoreNoDefragment        ((sss_sscp_keyObjFree_options_t)0x0u)
#define kSSS_keyObjFree_KeysStoreDefragment          ((sss_sscp_keyObjFree_options_t)0x1u)

typedef uint32_t sss_sscp_blob_type_t;
#define kSSS_blobType_ELKE_blob                       ((sss_sscp_blob_type_t)0x1u)
#define kSSS_blobType_E2E_blob                        ((sss_sscp_blob_type_t)0x2u)
#define kSSS_blobType_NBU_ESK_blob                    ((sss_sscp_blob_type_t)0x3u)
#define kSSS_blobType_NBU_EIRK_blob                   ((sss_sscp_blob_type_t)0x4u)

typedef uint32_t sss_internal_keyID_t;
#define kSSS_internalKey_NPX                          ((sss_sscp_internal_keyID_t)0x80000007u)
#define kSSS_internalKey_NBU_DKEY_SK                  ((sss_sscp_internal_keyID_t)0x80000009u)
#define kSSS_internalKey_NBU_DKEY_IRK                 ((sss_sscp_internal_keyID_t)0x8000000Au)

#endif /* FSL_SSS_CONFIG_H */
#endif /* KW45_A0_SUPPORT */

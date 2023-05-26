#if (defined(KW45_A0_SUPPORT) && KW45_A0_SUPPORT)
/*
 * Copyright 2018-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_SSCP_CONFIG_SNT_H_
#define _FSL_SSCP_CONFIG_SNT_H_

/* SAB command definitions */
typedef uint8_t sab_command_t;
#define SAB_PING_REQ                            ((sab_command_t)0x11)
#define SAB_GET_STATUS_REQ                      ((sab_command_t)0x12)
#define SAB_OPEN_SESSION_REQ                    ((sab_command_t)0x13)
#define SAB_CLOSE_SESSION_REQ                   ((sab_command_t)0x14)
#define SAB_CONTEXT_FREE_REQ                    ((sab_command_t)0x15)
#define SAB_CIPHER_CRYPT_CTR_REQ                ((sab_command_t)0x20)
#define SAB_CIPHER_FINISH_REQ                   ((sab_command_t)0x21)
#define SAB_CIPHER_INIT_REQ                     ((sab_command_t)0x22)
#define SAB_CIPHER_ONE_GO_REQ                   ((sab_command_t)0x23)
#define SAB_CIPHER_UPDATE_REQ                   ((sab_command_t)0x24)
#define SAB_SYMMETRIC_CONTEXT_INIT_REQ          ((sab_command_t)0x25)
#define SAB_AEAD_CONTEXT_INIT_REQ               ((sab_command_t)0x26)
#define SAB_AEAD_FINISH_REQ                     ((sab_command_t)0x27)
#define SAB_AEAD_INIT_REQ                       ((sab_command_t)0x28)
#define SAB_AEAD_ONE_GO_REQ                     ((sab_command_t)0x29)
#define SAB_AEAD_UPDATE_REQ                     ((sab_command_t)0x2a)
#define SAB_AEAD_UPDATE_AAD_REQ                 ((sab_command_t)0x2b)
#define SAB_DIGEST_CONTEXT_INIT_REQ             ((sab_command_t)0x2c)
#define SAB_DIGEST_FINISH_REQ                   ((sab_command_t)0x2d)
#define SAB_DIGEST_INIT_REQ                     ((sab_command_t)0x2e)
#define SAB_DIGEST_ONE_GO_REQ                   ((sab_command_t)0x2f)
#define SAB_DIGEST_UPDATE_REQ                   ((sab_command_t)0x30)
#define SAB_DIGEST_UPDATE_NONBLOCKING_REQ       ((sab_command_t)0x31)
#define SAB_MAC_CONTEXT_INIT_REQ                ((sab_command_t)0x32)
#define SAB_MAC_FINISH_REQ                      ((sab_command_t)0x33)
#define SAB_MAC_INIT_REQ                        ((sab_command_t)0x34)
#define SAB_MAC_ONE_GO_REQ                      ((sab_command_t)0x35)
#define SAB_MAC_UPDATE_REQ                      ((sab_command_t)0x36)
#define SAB_ASYMMETRIC_CONTEXT_INIT_REQ         ((sab_command_t)0x37)
#define SAB_ASYMMETRIC_DECRYPT_REQ              ((sab_command_t)0x38)
#define SAB_ASYMMETRIC_ENCRYPT_REQ              ((sab_command_t)0x39)
#define SAB_ASYMMETRIC_SIGN_DIGEST_REQ          ((sab_command_t)0x3a)
#define SAB_ASYMMETRIC_VERIFY_DIGEST_REQ        ((sab_command_t)0x3b)
#define SAB_ASYMMETRIC_DH_DERIVE_KEY_REQ        ((sab_command_t)0x3c)
#define SAB_TUNNEL_CONTEXT_INIT_REQ             ((sab_command_t)0x3d)
#define SAB_TUNNEL_REQ                          ((sab_command_t)0x3e)
#define SAB_DERIVE_KEY_REQ                      ((sab_command_t)0x3f)
#define SAB_DERIVE_KEY_CONTEXT_INIT_REQ         ((sab_command_t)0x40)
#define SAB_KEY_OBJECT_INIT_REQ                 ((sab_command_t)0x41)
#define SAB_KEY_OBJECT_ALLOCATE_HANDLE_REQ      ((sab_command_t)0x42)
#define SAB_KEY_OBJECT_GET_HANDLE_REQ           ((sab_command_t)0x43)
#define SAB_KEY_OBJECT_SET_ACCESS_REQ           ((sab_command_t)0x44)
#define SAB_KEY_OBJECT_SET_PURPOSE_REQ          ((sab_command_t)0x45)
#define SAB_KEY_OBJECT_SET_USER_REQ             ((sab_command_t)0x46)
#define SAB_KEY_OBJECT_FREE_REQ                 ((sab_command_t)0x47)
#define SAB_KEY_STORE_ALLOCATE_REQ              ((sab_command_t)0x48)
#define SAB_KEY_STORE_CONTEXT_INIT_REQ          ((sab_command_t)0x49)
#define SAB_KEY_STORE_SAVE_REQ                  ((sab_command_t)0x4a)
#define SAB_KEY_STORE_LOAD_REQ                  ((sab_command_t)0x4b)
#define SAB_KEY_STORE_SET_KEY_REQ               ((sab_command_t)0x4c)
#define SAB_KEY_STORE_GENERATE_KEY_REQ          ((sab_command_t)0x4d)
#define SAB_KEY_STORE_GET_KEY_REQ               ((sab_command_t)0x4e)
#define SAB_KEY_STORE_OPEN_KEY_REQ              ((sab_command_t)0x4f)
#define SAB_KEY_STORE_FREEZE_KEY_REQ            ((sab_command_t)0x50)
#define SAB_KEY_STORE_ERASE_KEY_REQ             ((sab_command_t)0x51)
#define SAB_MGMT_ADVANCE_LIFECYCLE_REQ          ((sab_command_t)0x60)
#define SAB_MGMT_ATTEST_REQ                     ((sab_command_t)0x61)
#define SAB_MGMT_BLOB_EXPORT_SECRET_REQ         ((sab_command_t)0x62)
#define SAB_MGMT_BLOB_IMPORT_SECRET_REQ         ((sab_command_t)0x63)
#define SAB_MGMT_BLOB_LOAD_SECRET_REQ           ((sab_command_t)0x64)
#define SAB_MGMT_CONTEXT_INIT_REQ               ((sab_command_t)0x65)
#define SAB_MGMT_EXPORT_SECRET_REQ              ((sab_command_t)0x66)
#define SAB_MGMT_FUSE_PROGRAM_REQ               ((sab_command_t)0x67)
#define SAB_MGMT_FUSE_READ_REQ                  ((sab_command_t)0x68)
#define SAB_MGMT_FUSE_SHADOW_PROGRAM_REQ        ((sab_command_t)0x69)
#define SAB_MGMT_FUSE_SHADOW_READ_REQ           ((sab_command_t)0x6a)
#define SAB_MGMT_GET_LIFECYCLE_REQ              ((sab_command_t)0x6b)
#define SAB_MGMT_GET_PROPERTY_REQ               ((sab_command_t)0x6c)
#define SAB_MGMT_GET_SOFTWARE_VERSION_REQ       ((sab_command_t)0x6d)
#define SAB_MGMT_IMPORT_SECRET_REQ              ((sab_command_t)0x6e)
#define SAB_MGMT_INTEGRITY_CHECK_ENABLE_REQ     ((sab_command_t)0x6f)
#define SAB_MGMT_SET_HOST_ACCESS_PERMISSION_REQ ((sab_command_t)0x70)
#define SAB_MGMT_SET_PROPERTY_REQ               ((sab_command_t)0x71)
#define SAB_MGMT_SET_RETURN_FA_REQ              ((sab_command_t)0x72)
#define SAB_MGMT_GET_RANDOM_REQ                 ((sab_command_t)0x73)
#define SAB_MGMT_CLEAR_ALL_KEYS_REQ             ((sab_command_t)0x74)
#define SAB_MGMT_MBIST_PREPARE_REQ              ((sab_command_t)0x75)

#define SSCP_COMMAND_ENUM_ALT
typedef enum _sscp_command
{
    kSSCP_CMD_SSS_OpenSession                  = SAB_OPEN_SESSION_REQ,
    kSSCP_CMD_SSS_CloseSession                 = SAB_CLOSE_SESSION_REQ,
    kSSCP_CMD_SSS_Ping                         = SAB_PING_REQ,
    kSSCP_CMD_SSS_ContextFree                  = SAB_CONTEXT_FREE_REQ,
    kSSCP_CMD_SSS_SymmetricContextInit         = SAB_SYMMETRIC_CONTEXT_INIT_REQ,
    kSSCP_CMD_SSS_SymmetricCipherOneGo         = SAB_CIPHER_ONE_GO_REQ,
    kSSCP_CMD_SSS_SymmetricCipherInit          = SAB_CIPHER_INIT_REQ,
    kSSCP_CMD_SSS_SymmetricCipherUpdate        = SAB_CIPHER_UPDATE_REQ,
    kSSCP_CMD_SSS_SymmetricCipherFinish        = SAB_CIPHER_FINISH_REQ,
    kSSCP_CMD_SSS_SymmetricCryptCtr            = SAB_CIPHER_CRYPT_CTR_REQ,
    kSSCP_CMD_SSS_AeadContextInit              = SAB_AEAD_CONTEXT_INIT_REQ,
    kSSCP_CMD_SSS_AeadOneGo                    = SAB_AEAD_ONE_GO_REQ,
    kSSCP_CMD_SSS_AeadInit                     = SAB_AEAD_INIT_REQ,
    kSSCP_CMD_SSS_AeadUpdateAead               = SAB_AEAD_UPDATE_AAD_REQ,
    kSSCP_CMD_SSS_AeadUpdate                   = SAB_AEAD_UPDATE_REQ,
    kSSCP_CMD_SSS_AeadFinish                   = SAB_AEAD_FINISH_REQ,
    kSSCP_CMD_SSS_DigestContextInit            = SAB_DIGEST_CONTEXT_INIT_REQ,
    kSSCP_CMD_SSS_DigestOneGo                  = SAB_DIGEST_ONE_GO_REQ,
    kSSCP_CMD_SSS_DigestInit                   = SAB_DIGEST_INIT_REQ,
    kSSCP_CMD_SSS_DigestUpdate                 = SAB_DIGEST_UPDATE_REQ,
    kSSCP_CMD_SSS_DigestFinish                 = SAB_DIGEST_FINISH_REQ,
    kSSCP_CMD_SSS_MacContextInit               = SAB_MAC_CONTEXT_INIT_REQ,
    kSSCP_CMD_SSS_MacOneGo                     = SAB_MAC_ONE_GO_REQ,
    kSSCP_CMD_SSS_MacInit                      = SAB_MAC_INIT_REQ,
    kSSCP_CMD_SSS_MacUpdate                    = SAB_MAC_UPDATE_REQ,
    kSSCP_CMD_SSS_MacFinish                    = SAB_MAC_FINISH_REQ,
    kSSCP_CMD_SSS_AsymetricContextInit         = SAB_ASYMMETRIC_CONTEXT_INIT_REQ,
    kSSCP_CMD_SSS_AsymmetricEncrypt            = SAB_ASYMMETRIC_ENCRYPT_REQ,
    kSSCP_CMD_SSS_AsymmetricDecrypt            = SAB_ASYMMETRIC_DECRYPT_REQ,
    kSSCP_CMD_SSS_AsymmetricSignDigest         = SAB_ASYMMETRIC_SIGN_DIGEST_REQ,
    kSSCP_CMD_SSS_AsymmetricVerifyDigest       = SAB_ASYMMETRIC_VERIFY_DIGEST_REQ,
    kSSCP_CMD_SSS_TunnelContextInit            = SAB_TUNNEL_CONTEXT_INIT_REQ,
    kSSCP_CMD_SSS_Tunnel                       = SAB_TUNNEL_REQ,
    kSSCP_CMD_SSS_DeriveKeyContextInit         = SAB_DERIVE_KEY_CONTEXT_INIT_REQ,
    kSSCP_CMD_SSS_DeriveKey                    = SAB_DERIVE_KEY_REQ,
    kSSCP_CMD_SSS_AsymmetricDeriveKey          = SAB_ASYMMETRIC_DH_DERIVE_KEY_REQ,
    kSSCP_CMD_SSS_KeyObjectContextInit         = SAB_KEY_OBJECT_INIT_REQ,
    kSSCP_CMD_SSS_KeyObjectAllocateHandle      = SAB_KEY_OBJECT_ALLOCATE_HANDLE_REQ,
    kSSCP_CMD_SSS_KeyObjectGetHandle           = SAB_KEY_OBJECT_GET_HANDLE_REQ,
    kSSCP_CMD_SSS_KeyObjectContextFree         = SAB_KEY_OBJECT_FREE_REQ,
    kSSCP_CMD_SSS_KeyStoreContextInit          = SAB_KEY_STORE_CONTEXT_INIT_REQ,
    kSSCP_CMD_SSS_KeyStoreAllocate             = SAB_KEY_STORE_ALLOCATE_REQ,
    kSSCP_CMD_SSS_KeyStoreSave                 = SAB_KEY_STORE_SAVE_REQ,
    kSSCP_CMD_SSS_KeyStoreLoad                 = SAB_KEY_STORE_LOAD_REQ,
    kSSCP_CMD_SSS_KeyStoreSetKey               = SAB_KEY_STORE_SET_KEY_REQ,
    kSSCP_CMD_SSS_KeyStoreGenerateKey          = SAB_KEY_STORE_GENERATE_KEY_REQ,
    kSSCP_CMD_SSS_KeyStoreGetKey               = SAB_KEY_STORE_GET_KEY_REQ,
    kSSCP_CMD_SSS_KeyStoreOpenKey              = SAB_KEY_STORE_OPEN_KEY_REQ,
    kSSCP_CMD_SSS_KeyStoreFreezeKey            = SAB_KEY_STORE_FREEZE_KEY_REQ,
    kSSCP_CMD_SSS_KeyStoreEraseKey             = SAB_KEY_STORE_ERASE_KEY_REQ,
    kSSCP_CMD_SSS_KeyStoreEraseAll             = SAB_MGMT_CLEAR_ALL_KEYS_REQ,
    KSSCP_CMD_SSS_RngGet                       = SAB_MGMT_GET_RANDOM_REQ,
    kSSCP_CMD_SSS_MGMT_ContextInit             = SAB_MGMT_CONTEXT_INIT_REQ,
    kSSCP_CMD_SSS_MGMT_FuseRead                = SAB_MGMT_FUSE_READ_REQ,
    kSSCP_CMD_SSS_MGMT_FuseShadowRegisterRead  = SAB_MGMT_FUSE_SHADOW_READ_REQ,
    kSSCP_CMD_SSS_MGMT_FuseProgram             = SAB_MGMT_FUSE_PROGRAM_REQ,
    kSSCP_CMD_SSS_MGMT_PropertyGet             = SAB_MGMT_GET_PROPERTY_REQ,
    kSSCP_CMD_SSS_MGMT_LifeCycleGet            = SAB_MGMT_GET_LIFECYCLE_REQ,
    kSSCP_CMD_SSS_MGMT_PropertySet             = SAB_MGMT_SET_PROPERTY_REQ,
    kSSCP_CMD_SSS_MGMT_AdvanceLifecycle        = SAB_MGMT_ADVANCE_LIFECYCLE_REQ,
    kSSCP_CMD_SSS_MGMT_SecretImport            = SAB_MGMT_IMPORT_SECRET_REQ,
    kSSCP_CMD_SSS_MGMT_SecretExport            = SAB_MGMT_EXPORT_SECRET_REQ,
    kSSCP_CMD_SSS_MGMT_Attest                  = SAB_MGMT_ATTEST_REQ,
    kSSCP_CMD_SSS_MGMT_SecretBlobLoad          = SAB_MGMT_BLOB_LOAD_SECRET_REQ,
    kSSCP_CMD_SSS_MGMT_SecretBlobExport        = SAB_MGMT_BLOB_EXPORT_SECRET_REQ,
    kSSCP_CMD_SSS_MGMT_SecretBlobImport        = SAB_MGMT_BLOB_IMPORT_SECRET_REQ,
    kSSCP_CMD_SSS_MGMT_SoftwareVersionGet      = SAB_MGMT_GET_SOFTWARE_VERSION_REQ,
    kSSCP_CMD_SSS_MGMT_ReturnFaSet             = SAB_MGMT_SET_RETURN_FA_REQ,
    kSSCP_CMD_SSS_MGMT_HostAccessPermissionSet = SAB_MGMT_SET_HOST_ACCESS_PERMISSION_REQ,
    kSSCP_CMD_SSS_MGMT_IntegrityCheckEnable    = SAB_MGMT_INTEGRITY_CHECK_ENABLE_REQ,
} sscp_command_t;

#endif /* _FSL_SSCP_CONFIG_SNT_H_ */
#else
/*
 * Copyright 2018-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SSCP_CONFIG_SNT_H
#define FSL_SSCP_CONFIG_SNT_H

#define SSCP_COMMAND_ENUM_ALT
typedef uint8_t sscp_command_t;
#define kSSCP_CMD_SSS_OpenSession                  ((sscp_command_t)0x13)
#define kSSCP_CMD_SSS_CloseSession                 ((sscp_command_t)0x14)
#define kSSCP_CMD_SSS_Ping                         ((sscp_command_t)0x11)
#define kSSCP_CMD_SSS_ContextFree                  ((sscp_command_t)0x15)
#define kSSCP_CMD_SSS_SymmetricContextInit         ((sscp_command_t)0x25)
#define kSSCP_CMD_SSS_SymmetricCipherOneGo         ((sscp_command_t)0x23)
#define kSSCP_CMD_SSS_SymmetricCipherInit          ((sscp_command_t)0x22)
#define kSSCP_CMD_SSS_SymmetricCipherUpdate        ((sscp_command_t)0x24)
#define kSSCP_CMD_SSS_SymmetricCipherFinish        ((sscp_command_t)0x21)
#define kSSCP_CMD_SSS_SymmetricCryptCtr            ((sscp_command_t)0x20)
#define kSSCP_CMD_SSS_AeadContextInit              ((sscp_command_t)0x26)
#define kSSCP_CMD_SSS_AeadOneGo                    ((sscp_command_t)0x29)
#define kSSCP_CMD_SSS_AeadInit                     ((sscp_command_t)0x28)
#define kSSCP_CMD_SSS_AeadUpdateAead               ((sscp_command_t)0x2b)
#define kSSCP_CMD_SSS_AeadUpdate                   ((sscp_command_t)0x2a)
#define kSSCP_CMD_SSS_AeadFinish                   ((sscp_command_t)0x27)
#define kSSCP_CMD_SSS_DigestContextInit            ((sscp_command_t)0x2c)
#define kSSCP_CMD_SSS_DigestOneGo                  ((sscp_command_t)0x2f)
#define kSSCP_CMD_SSS_DigestInit                   ((sscp_command_t)0x2e)
#define kSSCP_CMD_SSS_DigestUpdate                 ((sscp_command_t)0x30)
#define kSSCP_CMD_SSS_DigestFinish                 ((sscp_command_t)0x2d)
#define kSSCP_CMD_SSS_MacContextInit               ((sscp_command_t)0x32)
#define kSSCP_CMD_SSS_MacOneGo                     ((sscp_command_t)0x35)
#define kSSCP_CMD_SSS_MacInit                      ((sscp_command_t)0x34)
#define kSSCP_CMD_SSS_MacUpdate                    ((sscp_command_t)0x36)
#define kSSCP_CMD_SSS_MacFinish                    ((sscp_command_t)0x33)
#define kSSCP_CMD_SSS_AsymetricContextInit         ((sscp_command_t)0x37)
#define kSSCP_CMD_SSS_AsymmetricEncrypt            ((sscp_command_t)0x39)
#define kSSCP_CMD_SSS_AsymmetricDecrypt            ((sscp_command_t)0x38)
#define kSSCP_CMD_SSS_AsymmetricSignDigest         ((sscp_command_t)0x3a)
#define kSSCP_CMD_SSS_AsymmetricVerifyDigest       ((sscp_command_t)0x3b)
#define kSSCP_CMD_SSS_TunnelContextInit            ((sscp_command_t)0x3d)
#define kSSCP_CMD_SSS_Tunnel                       ((sscp_command_t)0x3e)
#define kSSCP_CMD_SSS_DeriveKeyContextInit         ((sscp_command_t)0x40)
#define kSSCP_CMD_SSS_DeriveKey                    ((sscp_command_t)0x3f)
#define kSSCP_CMD_SSS_AsymmetricDeriveKey          ((sscp_command_t)0x3c)
#define kSSCP_CMD_SSS_KeyObjectContextInit         ((sscp_command_t)0x41)
#define kSSCP_CMD_SSS_KeyObjectAllocateHandle      ((sscp_command_t)0x42)
#define kSSCP_CMD_SSS_KeyObjectGetHandle           ((sscp_command_t)0x43)
#define kSSCP_CMD_SSS_KeyObjectSetProperties       ((sscp_command_t)0x44)
#define kSSCP_CMD_SSS_KeyObjectGetProperties       ((sscp_command_t)0x45)
#define kSSCP_CMD_SSS_KeyObjectContextFree         ((sscp_command_t)0x47)
#define kSSCP_CMD_SSS_KeyStoreContextInit          ((sscp_command_t)0x49)
#define kSSCP_CMD_SSS_KeyStoreContextFree          ((sscp_command_t)0x76)
#define kSSCP_CMD_SSS_KeyStoreAllocate             ((sscp_command_t)0x48)
#define kSSCP_CMD_SSS_KeyStoreSave                 ((sscp_command_t)0x4a)
#define kSSCP_CMD_SSS_KeyStoreLoad                 ((sscp_command_t)0x4b)
#define kSSCP_CMD_SSS_KeyStoreSetKey               ((sscp_command_t)0x4c)
#define kSSCP_CMD_SSS_KeyStoreGenerateKey          ((sscp_command_t)0x4d)
#define kSSCP_CMD_SSS_KeyStoreGetKey               ((sscp_command_t)0x4e)
#define kSSCP_CMD_SSS_KeyStoreOpenKey              ((sscp_command_t)0x4f)
#define kSSCP_CMD_SSS_KeyStoreFreezeKey            ((sscp_command_t)0x50)
#define kSSCP_CMD_SSS_KeyStoreEraseKey             ((sscp_command_t)0x51)
#define kSSCP_CMD_SSS_KeyStoreGetProperty          ((sscp_command_t)0x77)
#define KSSCP_CMD_SSS_RngGet                       ((sscp_command_t)0x73)
#define kSSCP_CMD_SSS_MGMT_ContextInit             ((sscp_command_t)0x65)
#define kSSCP_CMD_SSS_MGMT_FuseRead                ((sscp_command_t)0x68)
#define kSSCP_CMD_SSS_MGMT_FuseShadowRegisterRead  ((sscp_command_t)0x6a)
#define kSSCP_CMD_SSS_MGMT_FuseProgram             ((sscp_command_t)0x67)
#define kSSCP_CMD_SSS_MGMT_PropertyGet             ((sscp_command_t)0x6c)
#define kSSCP_CMD_SSS_MGMT_LifeCycleGet            ((sscp_command_t)0x6b)
#define kSSCP_CMD_SSS_MGMT_PropertySet             ((sscp_command_t)0x71)
#define kSSCP_CMD_SSS_MGMT_AdvanceLifecycle        ((sscp_command_t)0x60)
#define kSSCP_CMD_SSS_MGMT_SecretImport            ((sscp_command_t)0x6e)
#define kSSCP_CMD_SSS_MGMT_SecretExport            ((sscp_command_t)0x66)
#define kSSCP_CMD_SSS_MGMT_Attest                  ((sscp_command_t)0x61)
#define kSSCP_CMD_SSS_MGMT_SecretBlobLoad          ((sscp_command_t)0x64)
#define kSSCP_CMD_SSS_MGMT_SecretBlobExport        ((sscp_command_t)0x62)
#define kSSCP_CMD_SSS_MGMT_SecretBlobImport        ((sscp_command_t)0x63)
#define kSSCP_CMD_SSS_MGMT_SoftwareVersionGet      ((sscp_command_t)0x6d)
#define kSSCP_CMD_SSS_MGMT_ReturnFaSet             ((sscp_command_t)0x72)
#define kSSCP_CMD_SSS_MGMT_HostAccessPermissionSet ((sscp_command_t)0x70)
#define kSSCP_CMD_SSS_MGMT_IntegrityCheckEnable    ((sscp_command_t)0x6f)
#define kSSCP_CMD_SSS_MGMT_ClearAllKeys            ((sscp_command_t)0x74)
#define kSSCP_CMD_SSS_KeyStoreImportKey            ((sscp_command_t)0x78)
#define kSSCP_CMD_SSS_KeyStoreExportKey            ((sscp_command_t)0x79)
/* kSSCP_CMD_SSS_KeyStoreEraseAll command ID have to be updated once value will be defined in elke specification */
#define kSSCP_CMD_SSS_KeyStoreEraseAll             ((sscp_command_t)0xff)

#define SSCP_PARAMCONTEXTTYPE_ENUM_ALT
/*! @brief SSCP ParamContextType list */
#define kSSCP_ParamContextType_SSS_Session    (0x1u)
#define kSSCP_ParamContextType_SSS_Symmetric  (0x2u)
#define kSSCP_ParamContextType_SSS_Aead       (0x3u)
#define kSSCP_ParamContextType_SSS_Digest     (0x4u)
#define kSSCP_ParamContextType_SSS_Mac        (0x5u)
#define kSSCP_ParamContextType_SSS_Asymmetric (0x6u)
#define kSSCP_ParamContextType_SSS_Tunnel     (0x7u)
#define kSSCP_ParamContextType_SSS_DeriveKey  (0x8u)
#define kSSCP_ParamContextType_SSS_Object     (0x9u)
#define kSSCP_ParamContextType_SSS_KeyStore   (0xau)
/*#define kSSCP_ParamContextType_SSS_KeyStoreCtx (0xbu)*/
#define kSSCP_ParamContextType_SSS_Mgmt       (0xcu)
#define kSSCP_ParamContextType_SSS_Rng        (0xdu)

#endif /* FSL_SSCP_CONFIG_SNT_H */
#endif /* KW45_A0_SUPPORT */

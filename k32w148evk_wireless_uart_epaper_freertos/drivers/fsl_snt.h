/*
 * Copyright 2019-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __SNT_DRIVER_H__
#define __SNT_DRIVER_H__

#include "fsl_common.h"
#include "fsl_device_registers.h"

/* The count of MU_TR */
#define MU_TR_COUNT ELEMU_TR_COUNT
/* The count of MU_RR */
#define MU_RR_COUNT ELEMU_RR_COUNT
/* The count of MU_RR */
#define MU_MSG_HEADER_SIZE (1U)

#define MESSAGING_TAG_COMMAND (0x17u)
#define MESSAGING_TAG_REPLY   (0x0Cu)
#define STATIC_CHECK_BITS     (0xD7u)

#if defined(K32W232H_SERIES) || defined(K32L4A_SERIES)
#define SNT_HAS_LOADABLE_FW (0x1u)
#endif /*defined(K32W232H_SERIES) || defined(K32L4A_SERIES)*/
enum
{
    kStatus_SNT_AgumentOutOfRange = MAKE_STATUS(kStatusGroup_SNT, 0x1u), /*!< SNT status for out of range access. */
    kStatus_SNT_InvalidArgument   = MAKE_STATUS(kStatusGroup_SNT, 0x2u), /*!< SNT status for invalid argument check. */
    kStatus_SNT_RequestTimeout    = MAKE_STATUS(kStatusGroup_SNT, 0x3u), /*!< SNT status for timeout. */
    kStatus_SNT_Busy = MAKE_STATUS(kStatusGroup_SNT, 0x4u), /*!< SNT status for reservation by other core. */
};

typedef enum
{
    kStatus_SNT_Unknown       = 0x0u, /*!< Unexpected SNT ownership. */
    kStatus_SNT_LockedByMe    = 0x1u, /*!< SNT reserved for current core. */
    kStatus_SNT_LockedByOther = 0x2u, /*!< SNT reserved for other core. */
    kStatus_SNT_Free          = 0x3u, /*!< SNT not reserved. */
} snt_ownership_status_t;

typedef struct mu_hdr
{
    uint8_t tag_sts;
    uint8_t check_bits;
    uint8_t size;
    uint8_t command;
} mu_hdr_t;

void SNT_mu_hal_send_data(ELEMU_Type *mu, uint8_t regid, uint32_t *data);
void SNT_mu_hal_receive_data(ELEMU_Type *mu, uint8_t regid, uint32_t *data);
status_t SNT_mu_hal_receive_data_wait(ELEMU_Type *mu, uint8_t regid, uint32_t *data, uint32_t wait);
status_t SNT_mu_read_message(ELEMU_Type *mu, uint32_t *buf, uint8_t *size, uint8_t read_header);
status_t SNT_mu_read_data_wait(ELEMU_Type *mu, uint32_t buf[], uint8_t *size, uint32_t wait);

status_t SNT_mu_send_message(ELEMU_Type *mu, uint32_t buf[], size_t wordCount);
status_t SNT_mu_get_response(ELEMU_Type *mu, uint32_t *buf, size_t wordCount);
status_t SNT_mu_wait_for_data(ELEMU_Type *mu, uint32_t *buf, size_t wordCount, uint32_t wait);

status_t SNT_mu_wait_for_ready(ELEMU_Type *mu, uint32_t wait);

#if (defined(FSL_FEATURE_ELEMU_HAS_SEMA4_STATUS_REGISTER) && FSL_FEATURE_ELEMU_HAS_SEMA4_STATUS_REGISTER)
snt_ownership_status_t SNT_mu_get_ownership_status(ELEMU_Type *mu);
status_t SNT_mu_get_ownership(ELEMU_Type *mu);
status_t SNT_mu_release_ownership(ELEMU_Type *mu);
status_t SNT_mu_release_ownership_force(ELEMU_Type *mu);
#endif /* FSL_FEATURE_ELEMU_HAS_SEMA4_STATUS_REGISTER */

void SNT_mu_init(ELEMU_Type *mu);
status_t SNT_LP_WakeupPathInit(ELEMU_Type *mu);

#if (defined(SNT_HAS_LOADABLE_FW) && SNT_HAS_LOADABLE_FW)
status_t SNT_loadFw(ELEMU_Type *mu, uint32_t image[]);
status_t SNT_loadFwLocal(ELEMU_Type *mu);
#endif /* SNT_HAS_LOADABLE_FW */

#endif /* __SNT_DRIVER_H__ */

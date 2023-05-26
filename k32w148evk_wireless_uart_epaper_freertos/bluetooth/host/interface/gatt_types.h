/*! *********************************************************************************
 * \addtogroup GATT
 * @{
 ********************************************************************************** */
/*! *********************************************************************************
* Copyright (c) 2014, Freescale Semiconductor, Inc.
* Copyright 2016-2017, 2021-2022 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef GATT_TYPES_H
#define GATT_TYPES_H

/************************************************************************************
*************************************************************************************
* Include
*************************************************************************************
************************************************************************************/
#include "att_errors.h"
#include "att_types.h"
#include "att_params.h"
#include "gatt_database.h"


#define gCccdEmpty_c            0x0000U   /*!< Nothing is enabled. */
#define gCccdNotification_c     BIT0      /*!< Enables notifications. */
#define gCccdIndication_c       BIT1      /*!< Enabled indications. */

/************************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
************************************************************************************/
/*! GATT Attribute structure definition */
typedef struct {
    uint16_t        handle;             /*!< Attribute handle. */
    bleUuidType_t   uuidType;           /*!< Type of the UUID. */
    bleUuid_t       uuid;               /*!< The attribute's UUID. */
    uint16_t        valueLength;        /*!< Length of the attribute value array. */
    uint16_t        maxValueLength;     /*!< Maximum length of the attribute value array; if this is set to 0, then the attribute's length is fixed and cannot be changed. */
    uint8_t*        paValue;            /*!< Attribute value array. */
} gattAttribute_t;

/*! GATT Characteristic structure definition */
typedef struct {
    gattCharacteristicPropertiesBitFields_t     properties;         /*!< Characteristic Properties as defined by GATT. */
    gattAttribute_t                             value;              /*!< Characteristic Value attribute. */
    uint8_t                                     cNumDescriptors;    /*!< Size of the Characteristic Descriptors array. */
    gattAttribute_t*                            aDescriptors;       /*!< Characteristic Descriptors array. */
} gattCharacteristic_t;

/*! GATT Service structure definition */
typedef struct gattService_tag {
    uint16_t                startHandle;            /*!< The handle of the Service Declaration attribute. */
    uint16_t                endHandle;              /*!< The last handle belonging to this Service (followed by another Service declaration of the end of the database). */
    bleUuidType_t           uuidType;               /*!< Service UUID type. */
    bleUuid_t               uuid;                   /*!< Service UUID. */
    uint8_t                 cNumCharacteristics;    /*!< Size of the Characteristic array. */
    gattCharacteristic_t*   aCharacteristics;       /*!< Characteristic array. */
    uint8_t                 cNumIncludedServices;   /*!< Size of the Included Services array. */
    struct gattService_tag* aIncludedServices;      /*!< Included Services array. */
} gattService_t;

/*! Flags for the value of the Client Characteristic Configuration Descriptor. */
typedef uint8_t gattCccdFlags_t;

/*! Characteristic Presentation Format Descriptor structure */
typedef struct {
    uint8_t     format;
    int8_t      exponent;
    uint16_t    unitUuid16;
    uint8_t     ns;
    uint16_t    description;
} gattDbCharPresFormat_t;

/*! GATT Handle Range structure definition */
typedef struct {
    uint16_t    startHandle;    /*!< Start Handle. */
    uint16_t    endHandle;      /*!< End Handle - shall be greater than or equal to Start Handle. */
} gattHandleRange_t;

typedef enum
{
    gGattClientChangeUnaware_c          = 0x00U, /*!< Gatt client state */
    gGattClientStateChangePending_c     = 0x01U, /*!< Gatt client state */
    gGattClientChangeAware_c            = 0x02U, /*!< Gatt client state */
} gattCachingClientState_c;

typedef enum {
    gattClientFirstConnection_c         = 0x00U, /* hash update for the first connection with a peer */
    gattClientReconnectBondedPeer_c     = 0x01U, /* hash update after reconnecting with a bonded peer */
    gattClientActiveConnectionUpdate    = 0x02U, /* hash update when a change occurs during an active connection */
    gattClientNoChange                  = 0x03U, /* idle state - no change */
} gattClientHashUpdateType_t;

/*! GATT Client Procedure type */
typedef enum {
    gGattProcExchangeMtu_c                          = 0x00U, /*!< MTU Exchange */
    gGattProcDiscoverAllPrimaryServices_c           = 0x01U, /*!< Primary Service Discovery */
    gGattProcDiscoverPrimaryServicesByUuid_c        = 0x02U, /*!< Discovery of Services by UUID */
    gGattProcFindIncludedServices_c                 = 0x03U, /*!< Discovery of Included Services within a Service range */
    gGattProcDiscoverAllCharacteristics_c           = 0x04U, /*!< Characteristic Discovery within Service range */
    gGattProcDiscoverCharacteristicByUuid_c         = 0x05U, /*!< Characteristic Discovery by UUID */
    gGattProcDiscoverAllCharacteristicDescriptors_c = 0x06U, /*!< Characteristic Descriptor Discovery */
    gGattProcReadCharacteristicValue_c              = 0x07U, /*!< Characteristic Reading using Value handle */
    gGattProcReadUsingCharacteristicUuid_c          = 0x08U, /*!< Characteristic Reading by UUID */
    gGattProcReadMultipleCharacteristicValues_c     = 0x09U, /*!< Reading multiple Characteristics at once */
    gGattProcWriteCharacteristicValue_c             = 0x0AU, /*!< Characteristic Writing */
    gGattProcReadCharacteristicDescriptor_c         = 0x0BU, /*!< Reading Characteristic Descriptors */
    gGattProcWriteCharacteristicDescriptor_c        = 0x0CU, /*!< Writing Characteristic Descriptors */
#if defined(gBLE51_d) && (gBLE51_d == 1U)
#if defined(gGattCaching_d) && (gGattCaching_d == 1U)
    gGattProcUpdateDatabaseCopy_c                   = 0x0DU, /*!< Inform the application to update its database copy */
    gGattProcSignalServiceDiscoveryComplete_c       = 0x0EU, /*!< Inform the application that service discovery has finished */
#endif /* gGattCaching_d */
#endif /* gBLE51_d */
    gGattProcReadMultipleVarLengthCharValues_c      = 0x0FU, /*!< Read Multiple Variable Length Characteristic Values */
} gattProcedureType_t;

typedef enum {
    gattProcPhaseInitiated,
    gattProcPhaseRunning
} gattProcedurePhase_t;

typedef struct {
    bool_t                  isOngoing;
    gattProcedureType_t     ongoingProcedureType;
    gattProcedurePhase_t    ongoingProcedurePhase;
} procStatus_t;

/* Structure members are ordered to minimize the padding size */
typedef struct {
    uint16_t index;
    uint16_t max;
    bleUuid_t charUuid;
    bleUuidType_t charUuidType;
    bool_t reliableLongWrite;
    deviceId_t deviceId;
    bool_t bAllocatedArray;

    union {
        uint8_t* pCount8b;
        uint16_t* pCount16b;
    } pOutActualCount;

    union {
        gattService_t* aServices;
        gattCharacteristic_t* aChars;
        gattAttribute_t* aDescriptors;
        uint8_t* aBytes;
        uint16_t* aHandles;
    } array;

    union {
        attReadByGroupTypeRequestParams_t rbgtParams;
        attFindByTypeValueRequestParams_t fbtvParams;
        attReadByTypeRequestParams_t rbtParams;
        attFindInformationRequestParams_t fiParams;
        attReadRequestParams_t rParams;
        attReadBlobRequestParams_t rbParams;
        attReadMultipleRequestParams_t rmParams;
        attVarWriteRequestAndCommandParams_t wParams;
        attSignedWriteCommandParams_t swParams;
        attPrepareWriteRequestResponseParams_t pwParams;
        attExecuteWriteRequestParams_t ewParams;
    } reqParams;
} procDataStruct_t;

#endif /* GATT_TYPES_H */

/*! *********************************************************************************
* @}
********************************************************************************** */

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    b_g474e_dpow1_usbpd_pwr.c
  * @author  MCD Application Team
  * @brief   This file provides a set of firmware functions to manage
  *          USB-PD Power
  *          available on B-G474E-DPOW1 board(MB1428) from STMicroelectronics.
  @endverbatim
  ******************************************************************************
  *
  * Copyright (c) 2019 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "b_g474e_dpow1_usbpd_pwr.h"

/* USER CODE BEGIN include */
/* USER CODE END include */

/** @addtogroup BSP
  * @{
  */

/** @addtogroup B-G474E-DPOW1
  * @{
  */

/** @addtogroup B-G474E-DPOW1_USBPD_PWR
  * @{
  */

/** @defgroup B-G474E-DPOW1_USBPD_PWR_Private_Typedef Private Typedef
  * @{
  */
/* USER CODE BEGIN POWER_Private_Typedef */
/* USER CODE END POWER_Private_Typedef */
/**
  * @}
  */

/** @defgroup B-G474E-DPOW1_USBPD_PWR_Private_Constants Private Constants
* @{
*/
/* USER CODE BEGIN POWER_Private_Constants */

/* Delay between ADC end of calibration and ADC enable.                     */
/* Delay estimation in CPU cycles: Case of ADC enable done                  */
/* immediately after ADC calibration, ADC clock setting slow                */
/* (LL_ADC_CLOCK_ASYNC_DIV32). Use a higher delay if ratio                  */
/* (CPU clock / ADC clock) is above 32.                                     */

#define ADC_DELAY_CALIB_ENABLE_CPU_CYCLES  (LL_ADC_DELAY_CALIB_ENABLE_ADC_CYCLES * 32u)

#define VDDA_APPLI            3300u
/* USER CODE END POWER_Private_Constants */
/**
  * @}
  */

/** @defgroup B-G474E-DPOW1_USBPD_PWR_Private_Macros Private Macros
  * @{
  */
/* USER CODE BEGIN POWER_Private_Macros */

/* USER CODE END POWER_Private_Macros */
/**
  * @}
  */

/** @defgroup B-G474E-DPOW1_USBPD_PWR_Private_Variables Private Variables
  * @{
  */
/* USER CODE BEGIN POWER_Private_Variables */

/* USER CODE END POWER_Private_Variables */
/**
  * @}
  */

/** @defgroup B-G474E-DPOW1_USBPD_PWR_Private_Functions Private Functions
  * @{
  */
/* USER CODE BEGIN POWER_Private_Prototypes */
static void PWR_Configure_ADC(void);
static void PWR_Activate_ADC(void);
/* USER CODE END POWER_Private_Prototypes */
/**
  * @}
  */

/** @addtogroup B-G474E-DPOW1_USBPD_PWR_Exported_Functions
  * @{
  */

/**
  * @brief  Global initialization of PWR resource used by USB-PD
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_Init(uint32_t Instance)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_Init */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_NONE;

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_Init */
}

/**
  * @brief  Global de-initialization of PWR resource used by USB-PD
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_Deinit(uint32_t Instance)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_Deinit */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_NONE;

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_Deinit */
}

/**
  * @brief  Initialize the hardware resources used by the Type-C power delivery (PD)
  *         controller.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VBUSInit(uint32_t Instance)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSInit */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_NONE;

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  else
  {
    /* For Sink cases */
    PWR_Configure_ADC();
    PWR_Activate_ADC();
    /*  MeasureVrefAnalog(); */
    LL_ADC_REG_StartConversion(VSENSE_ADC_INSTANCE);
  }

  return ret;
  /* USER CODE END BSP_USBPD_PWR_VBUSInit */
}

/**
  * @brief  Release the hardware resources used by the Type-C power delivery (PD)
  *         controller.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VBUSDeInit(uint32_t Instance)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSDeInit */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_VBUSDeInit */
}

/**
  * @brief  Enable power supply over VBUS.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VBUSOn(uint32_t Instance)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSOn */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_VBUSOn */
}

/**
  * @brief  Disable power supply over VBUS.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VBUSOff(uint32_t Instance)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSOff */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_VBUSOff */
}

/**
  * @brief  Set a fixed/variable PDO and manage the power control.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  VbusTargetInmv the vbus Target (in mV)
  * @param  OperatingCurrent the Operating Current (in mA)
  * @param  MaxOperatingCurrent the Max Operating Current (in mA)
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VBUSSetVoltage_Fixed(uint32_t Instance,
                                           uint32_t VbusTargetInmv,
                                           uint32_t OperatingCurrent,
                                           uint32_t MaxOperatingCurrent)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSSetVoltage_Fixed */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_NONE;
  UNUSED(VbusTargetInmv);
  UNUSED(OperatingCurrent);
  UNUSED(MaxOperatingCurrent);
  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_VBUSSetVoltage_Fixed */
}

/**
  * @brief  Set a fixed/variable PDO and manage the power control.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  VbusTargetMinInmv the vbus Target min (in mV)
  * @param  VbusTargetMaxInmv the vbus Target max (in mV)
  * @param  OperatingCurrent the Operating Current (in mA)
  * @param  MaxOperatingCurrent the Max Operating Current (in mA)
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VBUSSetVoltage_Variable(uint32_t Instance,
                                              uint32_t VbusTargetMinInmv,
                                              uint32_t VbusTargetMaxInmv,
                                              uint32_t OperatingCurrent,
                                              uint32_t MaxOperatingCurrent)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSSetVoltage_Variable */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  UNUSED(VbusTargetMinInmv);
  UNUSED(VbusTargetMaxInmv);
  UNUSED(OperatingCurrent);
  UNUSED(MaxOperatingCurrent);

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSSetVoltage_Variable */
}

/**
  * @brief  Set a Battery PDO and manage the power control.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  VbusTargetMin the vbus Target min (in mV)
  * @param  VbusTargetMax the vbus Target max (in mV)
  * @param  OperatingPower the Operating Power (in mW)
  * @param  MaxOperatingPower the Max Operating Power (in mW)
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VBUSSetVoltage_Battery(uint32_t Instance,
                                             uint32_t VbusTargetMin,
                                             uint32_t VbusTargetMax,
                                             uint32_t OperatingPower,
                                             uint32_t MaxOperatingPower)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSSetVoltage_Battery */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  UNUSED(VbusTargetMin);
  UNUSED(VbusTargetMax);
  UNUSED(OperatingPower);
  UNUSED(MaxOperatingPower);

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSSetVoltage_Battery */
}

/**
  * @brief  Set a APDO and manage the power control.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  VbusTargetInmv the vbus Target (in mV)
  * @param  OperatingCurrent the Operating current (in mA)
  * @param  Delta Delta between with previous APDO (in mV), 0 means APDO start
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VBUSSetVoltage_APDO(uint32_t Instance,
                                          uint32_t VbusTargetInmv,
                                          uint32_t OperatingCurrent,
                                          int32_t Delta)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSSetVoltage_APDO */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  UNUSED(VbusTargetInmv);
  UNUSED(OperatingCurrent);
  UNUSED(Delta);

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSSetVoltage_APDO */
}

/**
  * @brief  Get actual voltage level measured on the VBUS line.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  pVoltage Pointer on measured voltage level (in mV)
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VBUSGetVoltage(uint32_t Instance, uint32_t *pVoltage)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSGetVoltage */

  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_NONE;

  if ((Instance >= USBPD_PWR_INSTANCES_NBR) || (NULL == pVoltage))
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  else
  {
    uint32_t voltage;

    voltage = __LL_ADC_CALC_DATA_TO_VOLTAGE(VDDA_APPLI,  ((uint32_t)LL_ADC_REG_ReadConversionData12(VSENSE_ADC_INSTANCE)), LL_ADC_RESOLUTION_12B); /* mV */

    /* B-G474E-DPOW1 board is used */
    /* Value is multiplied by 7.613 (Divider R135/R136 (49.9K/330K) for VSENSE */
    voltage *= 7613u;
    voltage /= 1000u;

    *pVoltage = voltage;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_VBUSGetVoltage */
}

/**
  * @brief  Get actual current level measured on the VBUS line.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  pCurrent Pointer on measured current level (in mA)
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VBUSGetCurrent(uint32_t Instance, int32_t *pCurrent)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSGetCurrent */
  /* Check if instance is valid       */
  int32_t ret;

  if ((Instance >= USBPD_PWR_INSTANCES_NBR) || (NULL == pCurrent))
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  else
  {
    *pCurrent = 0;
    ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_VBUSGetCurrent */
}

/**
  * @brief  Initialize VCONN sourcing.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  CCPinId Type-C CC pin identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_CC1
  *         @arg @ref USBPD_PWR_TYPE_C_CC2
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VCONNInit(uint32_t Instance,
                                uint32_t CCPinId)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VCONNInit */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  UNUSED(CCPinId);

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_VCONNInit */
}

/**
  * @brief  Un-Initialize VCONN sourcing.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  CCPinId Type-C CC pin identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_CC1
  *         @arg @ref USBPD_PWR_TYPE_C_CC2
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VCONNDeInit(uint32_t Instance,
                                  uint32_t CCPinId)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VCONNDeInit */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  UNUSED(CCPinId);

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_VCONNDeInit */
}

/**
  * @brief  Enable VCONN sourcing.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  CCPinId Type-C CC pin identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_CC1
  *         @arg @ref USBPD_PWR_TYPE_C_CC2
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VCONNOn(uint32_t Instance,
                              uint32_t CCPinId)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VCONNOn */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  UNUSED(CCPinId);

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_VCONNOn */
}

/**
  * @brief  Disable VCONN sourcing.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  CCPinId CC pin identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_CC1
  *         @arg @ref USBPD_PWR_TYPE_C_CC2
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VCONNOff(uint32_t Instance,
                               uint32_t CCPinId)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VCONNOff */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  UNUSED(CCPinId);

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_VCONNOff */
}

/**
  * @brief  Get actual VCONN status.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  CCPinId Type-C CC pin identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_CC1
  *         @arg @ref USBPD_PWR_TYPE_C_CC2
  * @param  pState VCONN status (1: On, 0: Off)
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VCONNIsOn(uint32_t Instance,
                                uint32_t CCPinId, uint8_t *pState)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VCONNIsOn */
  /* Check if instance is valid       */
  int32_t ret;
  UNUSED(CCPinId);

  if ((Instance >= USBPD_PWR_INSTANCES_NBR) || (NULL == pState))
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  else
  {
    *pState = 0;
    ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_VCONNIsOn */
}

/**
  * @brief  Set the VBUS disconnection voltage threshold.
  * @note   Callback funtion registered through BSP_USBPD_PWR_RegisterVBUSDetectCallback
  *         function call is invoked when VBUS falls below programmed threshold.
  * @note   By default VBUS disconnection threshold is set to 3.3V
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  VoltageThreshold VBUS disconnection voltage threshold (in mV)
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_SetVBUSDisconnectionThreshold(uint32_t Instance,
                                                    uint32_t VoltageThreshold)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_SetVBUSDisconnectionThreshold */
  /* Check if instance is valid       */
  int32_t ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  UNUSED(VoltageThreshold);

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_SetVBUSDisconnectionThreshold */
}

/**
  * @brief  Register USB Type-C Current callback function.
  * @note   Callback function invoked when VBUS rises above 4V (VBUS present) or
  *         when VBUS falls below programmed threshold (VBUS absent).
  * @note   Callback funtion is un-registered when callback function pointer
  *         argument is NULL.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  pfnVBUSDetectCallback callback function pointer
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_RegisterVBUSDetectCallback(uint32_t  Instance,
                                                 USBPD_PWR_VBUSDetectCallbackFunc *pfnVBUSDetectCallback)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_RegisterVBUSDetectCallback */
  /* Check if instance is valid       */
  int32_t ret;

  if ((Instance >= USBPD_PWR_INSTANCES_NBR) || (NULL == pfnVBUSDetectCallback))
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  else
  {
    pfnVBUSDetectCallback(Instance, VBUS_NOT_CONNECTED);
    ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_RegisterVBUSDetectCallback */
}

/**
  * @brief  Get actual VBUS status.
  * @param  Instance Type-C port identifier
  *         This parameter can be take one of the following values:
  *         @arg @ref USBPD_PWR_TYPE_C_PORT_1
  * @param  pState VBUS status (1: On, 0: Off)
  * @retval BSP status
  */
int32_t BSP_USBPD_PWR_VBUSIsOn(uint32_t Instance, uint8_t *pState)
{
  /* USER CODE BEGIN BSP_USBPD_PWR_VBUSIsOn */
  /* Check if instance is valid       */
  int32_t ret;

  if (Instance >= USBPD_PWR_INSTANCES_NBR)
  {
    ret = BSP_ERROR_WRONG_PARAM;
  }
  else
  {
    *pState = 0u;
    ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
  }
  return ret;
  /* USER CODE END BSP_USBPD_PWR_VBUSIsOn */
}

/**
  * @}
  */

/** @addtogroup B-G474E-DPOW1_USBPD_PWR_Private_Functions
  * @{
  */

/* USER CODE BEGIN POWER_Private_Functions */
static void PWR_Configure_ADC(void)
{
  /*## Configuration of GPIO used by ADC channels ############################*/
  uint32_t wait_loop_index;

  /* Note: On this STM32 device, ADC1 channel 0 is mapped on GPIO pin PA.00 */

  /* Enable GPIO Clock */
  VSENSE_GPIO_ENABLE_CLOCK();

  /* Configure GPIO in analog mode to be used as ADC input */
  LL_GPIO_SetPinMode(VSENSE_GPIO_PORT, VSENSE_GPIO_PIN, LL_GPIO_MODE_ANALOG);

  /*## Configuration of ADC ##################################################*/

  /*## Configuration of ADC hierarchical scope: common to several ADC ########*/

  /* Enable ADC clock (core clock) */
  VSENSE_ADC_ENABLE_CLOCK();

  /* Note: Hardware constraint (refer to description of the functions         */
  /*       below):                                                            */
  /*       On this STM32 serie, setting of these features is conditioned to   */
  /*       ADC state:                                                         */
  /*       All ADC instances of the ADC common group must be disabled.        */
  /* Note: In this example, all these checks are not necessary but are        */
  /*       implemented anyway to show the best practice usages                */
  /*       corresponding to reference manual procedure.                       */
  /*       Software can be optimized by removing some of these checks, if     */
  /*       they are not relevant considering previous settings and actions    */
  /*       in user application.                                               */
  uint32_t IsEnabled = __LL_ADC_IS_ENABLED_ALL_COMMON_INSTANCE(VSENSE_ADC_COMMON);
  if (0u == IsEnabled)
  {
    /* Note: Call of the functions below are commented because they are       */
    /*       useless in this example:                                         */
    /*       setting corresponding to default configuration from reset state. */

    /* Set ADC clock (conversion clock) common to several ADC instances */
    /* Note: On this STM32 serie, ADC common clock asynchonous prescaler      */
    /*       is applied to each ADC instance if ADC instance clock is         */
    /*       set to clock source asynchronous                                 */
    /*       (refer to function "LL_ADC_SetClock()" below).                   */
    LL_ADC_SetCommonClock(__LL_ADC_COMMON_INSTANCE(VSENSE_ADC_INSTANCE), LL_ADC_CLOCK_SYNC_PCLK_DIV4);

    /* Set ADC measurement path to internal channels */
    LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(VSENSE_ADC_INSTANCE), LL_ADC_PATH_INTERNAL_VREFINT);

    /*## Configuration of ADC hierarchical scope: multimode ####################*/

    /* Note: Feature not available on this STM32 serie */
  }

  /*## Configuration of ADC hierarchical scope: ADC instance #################*/

  /* Note: Hardware constraint (refer to description of the functions         */
  /*       below):                                                            */
  /*       On this STM32 serie, setting of these features is conditioned to   */
  /*       ADC state:                                                         */
  /*       ADC must be disabled.                                              */
  if (0u == LL_ADC_IsEnabled(VSENSE_ADC_INSTANCE))
  {
    /* Delay for internal voltage reference stabilization time.               */
    /* Compute number of CPU cycles to wait for, from delay in us.            */
    /* Note: Variable divided by 2 to compensate partially                    */
    /*       CPU processing cycles (depends on compilation optimization).     */
    /* Note: If system core clock frequency is below 200kHz, wait time        */
    /*       is only a few CPU processing cycles.                             */
    wait_loop_index = ((LL_ADC_DELAY_VREFINT_STAB_US * (SystemCoreClock / (100000u * 2u))) / 10u);
    while (0u != wait_loop_index)
    {
      wait_loop_index--;
    }
  }

  /*## Configuration of ADC hierarchical scope: ADC group regular ############*/

  /* Note: Hardware constraint (refer to description of the functions         */
  /*       below):                                                            */
  /*       On this STM32 serie, setting of these features is conditioned to   */
  /*       ADC state:                                                         */
  /*       ADC must be disabled or enabled without conversion on going        */
  /*       on group regular.                                                  */
  uint32_t is_conversion = LL_ADC_REG_IsConversionOngoing(VSENSE_ADC_INSTANCE);
  uint32_t is_enabled = LL_ADC_IsEnabled(VSENSE_ADC_INSTANCE);
  if ((0u == is_conversion) || (0u == is_enabled))
  {
    /* Set ADC group regular trigger source */
    LL_ADC_REG_SetTriggerSource(VSENSE_ADC_INSTANCE, LL_ADC_REG_TRIG_SOFTWARE);

    /* Set ADC group regular continuous mode */
    LL_ADC_REG_SetContinuousMode(VSENSE_ADC_INSTANCE, LL_ADC_REG_CONV_CONTINUOUS);

    /* Set ADC group regular overrun behavior */
    LL_ADC_REG_SetOverrun(VSENSE_ADC_INSTANCE, LL_ADC_REG_OVR_DATA_OVERWRITTEN);

    /* Set ADC group regular sequencer */
    /* Note: On this STM32 serie, ADC group regular sequencer has             */
    /*       two settings:                                                    */
    /*       - Sequencer configured to fully configurable:                    */
    /*         sequencer length and each rank                                 */
    /*         affectation to a channel are configurable.                     */
    /*         Channels selection is limited to channels 0 to 14.             */
    /*       - Sequencer configured to not fully configurable:                */
    /*         sequencer length and each rank affectation to a channel        */
    /*         are fixed by channel HW number.                                */
    /*         Channels selection is not limited (channels 0 to 18).          */
    /*       Refer to description of function                                 */
    /*       "LL_ADC_REG_SetSequencerConfigurable()".                         */

    /* Set ADC group regular sequence: channel on rank corresponding to       */
    /* channel number.                                                        */
    LL_ADC_REG_SetSequencerRanks(VSENSE_ADC_INSTANCE, VSENSE_ADC_RANK, VSENSE_ADC_CHANNEL);

  }

  /*## Configuration of ADC hierarchical scope: ADC group injected ###########*/

  /* Note: Feature available on this STM32 serie but not used */

  /*## Configuration of ADC hierarchical scope: channels #####################*/

  /* Note: Hardware constraint (refer to description of the functions         */
  /*       below):                                                            */
  /*       On this STM32 serie, setting of these features is conditioned to   */
  /*       ADC state:                                                         */
  /*       ADC must be disabled or enabled without conversion on going        */
  /*       on either groups regular or injected.                              */
  uint32_t reg_is_ongoing = LL_ADC_REG_IsConversionOngoing(VSENSE_ADC_INSTANCE);
  uint32_t inj_is_ongoing = LL_ADC_INJ_IsConversionOngoing(VSENSE_ADC_INSTANCE);
  uint32_t adc_is_enabled = LL_ADC_IsEnabled(VSENSE_ADC_INSTANCE);
  if ((0u == adc_is_enabled) || ((0u == reg_is_ongoing) && (0u == inj_is_ongoing)))
  {
    /* Set ADC channels sampling time */
    LL_ADC_SetChannelSamplingTime(VSENSE_ADC_INSTANCE, VSENSE_ADC_CHANNEL, LL_ADC_SAMPLINGTIME_247CYCLES_5);
  }

  /*## Configuration of ADC transversal scope: analog watchdog ###############*/

  /* Note: On this STM32 serie, there is only 1 analog watchdog available.    */

  /* Set ADC analog watchdog: channels to be monitored */
  LL_ADC_SetAnalogWDMonitChannels(VSENSE_ADC_INSTANCE, LL_ADC_AWD1, LL_ADC_AWD_ALL_CHANNELS_REG);

  /* Set ADC analog watchdog: thresholds */
  LL_ADC_ConfigAnalogWDThresholds(VSENSE_ADC_INSTANCE, LL_ADC_AWD1, 700, 600);

  /*## Configuration of ADC transversal scope: oversampling ##################*/

  /* Set ADC oversampling scope */
  LL_ADC_SetOverSamplingScope(VSENSE_ADC_INSTANCE, LL_ADC_OVS_GRP_REGULAR_CONTINUED);

  /* Set ADC oversampling parameters */
  LL_ADC_ConfigOverSamplingRatioShift(VSENSE_ADC_INSTANCE, LL_ADC_OVS_RATIO_16, LL_ADC_OVS_SHIFT_RIGHT_4);

  /*## Configuration of ADC interruptions ####################################*/
  /* Enable ADC analog watchdog 1 interruption */
  LL_ADC_EnableIT_AWD1(VSENSE_ADC_INSTANCE);
}

/**
  * @brief  Perform ADC activation procedure to make it ready to convert
  *         (ADC instance: ADC1).
  * @note   Operations:
  *         - ADC instance
  *           - Run ADC self calibration
  *           - Enable ADC
  *         - ADC group regular
  *           none: ADC conversion start-stop to be performed
  *                 after this function
  *         - ADC group injected
  *           Feature not available                                  (feature not available on this STM32 serie)
  * @retval None
  */
static void PWR_Activate_ADC(void)
{
  __IO uint32_t wait_loop_index = 0;
  __IO uint32_t backup_setting_adc_dma_transfer;
#if (USE_TIMEOUT == 1)
  uint32_t Timeout = 0; /* Variable used for timeout management */
#endif /* USE_TIMEOUT */

  /*## Operation on ADC hierarchical scope: ADC instance #####################*/

  /* Note: Hardware constraint (refer to description of the functions         */
  /*       below):                                                            */
  /*       On this STM32 serie, setting of these features is conditioned to   */
  /*       ADC state:                                                         */
  /*       ADC must be disabled.                                              */
  /* Note: In this example, all these checks are not necessary but are        */
  /*       implemented anyway to show the best practice usages                */
  /*       corresponding to reference manual procedure.                       */
  /*       Software can be optimized by removing some of these checks, if     */
  /*       they are not relevant considering previous settings and actions    */
  /*       in user application.                                               */
  if (0u == LL_ADC_IsEnabled(VSENSE_ADC_INSTANCE))
  {
    /* Disable ADC deep power down mode */
    LL_ADC_DisableDeepPowerDown(VSENSE_ADC_INSTANCE);

    /* Enable ADC internal voltage regulator */
    LL_ADC_EnableInternalRegulator(VSENSE_ADC_INSTANCE);

    /* Delay for ADC internal voltage regulator stabilization.                */
    /* Compute number of CPU cycles to wait for, from delay in us.            */
    /* Note: Variable divided by 2 to compensate partially                    */
    /*       CPU processing cycles (depends on compilation optimization).     */
    /* Note: If system core clock frequency is below 200kHz, wait time        */
    /*       is only a few CPU processing cycles.                             */
    wait_loop_index = ((LL_ADC_DELAY_INTERNAL_REGUL_STAB_US * (SystemCoreClock / (100000u * 2u))) / 10u);
    while (0u != wait_loop_index)
    {
      wait_loop_index--;
    }

    /* Disable ADC DMA transfer request during calibration */
    /* Note: Specificity of this STM32 serie: Calibration factor is           */
    /*       available in data register and also transfered by DMA.           */
    /*       To not insert ADC calibration factor among ADC conversion data   */
    /*       in DMA destination address, DMA transfer must be disabled during */
    /*       calibration.                                                     */
    backup_setting_adc_dma_transfer = LL_ADC_REG_GetDMATransfer(VSENSE_ADC_INSTANCE);
    LL_ADC_REG_SetDMATransfer(VSENSE_ADC_INSTANCE, LL_ADC_REG_DMA_TRANSFER_NONE);

    /* Run ADC self calibration */
    LL_ADC_StartCalibration(VSENSE_ADC_INSTANCE, LL_ADC_SINGLE_ENDED);

    /* Poll for ADC effectively calibrated */
#if (USE_TIMEOUT == 1)
    Timeout = ADC_CALIBRATION_TIMEOUT_MS;
#endif /* USE_TIMEOUT */

    while (0u != LL_ADC_IsCalibrationOnGoing(VSENSE_ADC_INSTANCE))
    {
#if (USE_TIMEOUT == 1)
      /* Check Systick counter flag to decrement the time-out value */
      if (LL_SYSTICK_IsActiveCounterFlag())
      {
        if (0u == Timeout--)
        {
          /* Time-out occurred. Set LED to blinking mode */
          LED_Blinking(LED_BLINK_ERROR);
        }
      }
#endif /* USE_TIMEOUT */
    }

    /* Restore ADC DMA transfer request after calibration */
    LL_ADC_REG_SetDMATransfer(VSENSE_ADC_INSTANCE, backup_setting_adc_dma_transfer);

    /* Delay between ADC end of calibration and ADC enable.                   */
    /* Note: Variable divided by 2 to compensate partially                    */
    /*       CPU processing cycles (depends on compilation optimization).     */
    wait_loop_index = (ADC_DELAY_CALIB_ENABLE_CPU_CYCLES >> 1u);
    while (0u != wait_loop_index)
    {
      wait_loop_index--;
    }

    /* Enable ADC */
    LL_ADC_Enable(VSENSE_ADC_INSTANCE);

    /* Poll for ADC ready to convert */
#if (USE_TIMEOUT == 1)
    Timeout = ADC_ENABLE_TIMEOUT_MS;
#endif /* USE_TIMEOUT */

    while (0u == LL_ADC_IsActiveFlag_ADRDY(VSENSE_ADC_INSTANCE))
    {
#if (USE_TIMEOUT == 1)
      /* Check Systick counter flag to decrement the time-out value */
      if (LL_SYSTICK_IsActiveCounterFlag())
      {
        if (0u == Timeout--)
        {
          /* Time-out occurred. Set LED to blinking mode */
          LED_Blinking(LED_BLINK_ERROR);
        }
      }
#endif /* USE_TIMEOUT */
    }

    /* Note: ADC flag ADRDY is not cleared here to be able to check ADC       */
    /*       status afterwards.                                               */
    /*       This flag should be cleared at ADC Deactivation, before a new    */
    /*       ADC activation, using function "LL_ADC_ClearFlag_ADRDY()".       */
  }

  /*## Operation on ADC hierarchical scope: ADC group regular ################*/
  /* Note: No operation on ADC group regular performed here.                  */
  /*       ADC group regular conversions to be performed after this function  */
  /*       using function:                                                    */
  /*       "LL_ADC_REG_StartConversion();"                                    */

  /*## Operation on ADC hierarchical scope: ADC group injected ###############*/
  /* Note: Feature not available on this STM32 serie */
}

/* USER CODE END POWER_Private_Functions */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


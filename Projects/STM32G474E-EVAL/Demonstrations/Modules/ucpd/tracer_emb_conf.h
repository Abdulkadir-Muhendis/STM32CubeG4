/**
  ******************************************************************************
  * @file    tracer_emb_conf.h
  * @author  MCD Application Team
  * @brief   This file contains the Trace HW related defines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics International N.V.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#ifndef TRACER_EMB_CONF_H
#define TRACER_EMB_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_ll_gpio.h"
#include "stm32g4xx_ll_rcc.h"
#include "stm32g4xx_ll_usart.h"
#include "stm32g4xx_ll_bus.h"
#include "stm32g4xx_ll_dma.h"
#if defined(LPUART1)
#include "stm32g4xx_ll_lpuart.h"
#endif /* LPUART1 */
/* Private typedef -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
      Definitions for TRACE feature
-------------------------------------------------------------------------------*/
#define TRACER_EMB_BAUDRATE                          921600UL

#define TRACER_EMB_DMA_MODE                          1UL
#define TRACER_EMB_IT_MODE                           0UL

#define TRACER_EMB_BUFFER_SIZE                       1024UL

/* -----------------------------------------------------------------------------
      Definitions for TRACE Hw information
-------------------------------------------------------------------------------*/

#define TRACER_EMB_USART_INSTANCE                    USART1

#define TRACER_EMB_TX_GPIO                           GPIOA
#define TRACER_EMB_TX_PIN                            LL_GPIO_PIN_9
#define TRACER_EMB_TX_AF                             LL_GPIO_AF_7
#define TRACER_EMB_TX_GPIO_ENABLE_CLOCK()            LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)
#define TRACER_EMB_TX_GPIO_DISABLE_CLOCK()           LL_AHB2_GRP1_DisableClock(LL_AHB2_GRP1_PERIPH_GPIOA)
#define TRACER_EMB_RX_GPIO                           GPIOA
#define TRACER_EMB_RX_PIN                            LL_GPIO_PIN_10
#define TRACER_EMB_RX_AF                             LL_GPIO_AF_7
#define TRACER_EMB_RX_GPIO_ENABLE_CLOCK()            LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)
#define TRACER_EMB_RX_GPIO_DISABLE_CLOCK()           LL_AHB2_GRP1_DisableClock(LL_AHB2_GRP1_PERIPH_GPIOA)
#define TRACER_EMB_ENABLE_CLK_USART()                LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1)
#define TRACER_EMB_DISABLE_CLK_USART()               LL_APB2_GRP1_DisableClock(LL_APB2_GRP1_PERIPH_USART1)
#define TRACER_EMB_SET_CLK_SOURCE_USART()            /* No need for clock source selection in case of USART1 // LL_RCC_SetUSARTClockSource(LL_RCC_USART1_CLKSOURCE_PCLK2) */
#define TRACER_EMB_USART_IRQ                         USART1_IRQn
#define TRACER_EMB_USART_IRQHANDLER                  USART1_IRQHandler
#define TRACER_EMB_TX_AF_FUNCTION                    LL_GPIO_SetAFPin_8_15
#define TRACER_EMB_RX_AF_FUNCTION                    LL_GPIO_SetAFPin_8_15
#define TRACER_EMB_DMA_INSTANCE                      DMA1
#define TRACER_EMB_ENABLE_CLK_DMA()                  do{                                                                    \
                                                       LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);                 \
                                                       LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMAMUX1);              \
                                                       }while(0)
#define TRACER_EMB_TX_DMA_REQUEST                    LL_DMAMUX_REQ_USART1_TX
#define TRACER_EMB_TX_DMA_CHANNEL                    LL_DMA_CHANNEL_6
#define TRACER_EMB_TX_DMA_IRQ                        DMA1_Channel6_IRQn
#define TRACER_EMB_TX_DMA_IRQHANDLER                 DMA1_Channel6_IRQHandler
#define TRACER_EMB_TX_DMA_ACTIVE_FLAG                LL_DMA_IsActiveFlag_TC6
#define TRACER_EMB_TX_DMA_CLEAR_FLAG                 LL_DMA_ClearFlag_GI6


#ifdef __cplusplus
}
#endif

#endif /* TRACER_EMB_CONF_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


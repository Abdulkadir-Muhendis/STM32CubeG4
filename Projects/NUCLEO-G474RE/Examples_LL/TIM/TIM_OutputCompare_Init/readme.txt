/**
  @page TIM_OutputCompare_Init TIM example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/TIM/TIM_OutputCompare_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM_OutputCompare_Init example.
  ******************************************************************************
  *
  * Copyright (c) 2019 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  @endverbatim

@par Example Description

Configuration of the TIM peripheral to generate an output 
waveform in different output compare modes. This example is based on the 
STM32G4xx TIM LL API. The peripheral initialization uses 
LL unitary service functions for optimization purposes (performance and size).

In this example TIM2 input clock (TIM2CLK) frequency is set to APB1 clock (PCLK1),
since APB1 pre-scaler is equal to 1.
    TIM2CLK = PCLK1
    PCLK1 = HCLK
    => TIM2CLK = HCLK = SystemCoreClock (170 Mhz)

To set the TIM2 counter clock frequency to 10 KHz, the pre-scaler (PSC) is
calculated as follows:
PSC = (TIM2CLK / TIM2 counter clock) - 1
PSC = (SystemCoreClock /10 KHz) - 1

SystemCoreClock is set to 170 MHz for STM32G4xx Devices.

Auto-reload (ARR) is calculated to get a time base period of 100 ms,
meaning a time base frequency of 10 Hz.
ARR = (TIM2 counter clock / time base frequency) - 1
ARR = (TIM2 counter clock / 10) - 1

The capture/compare register (CCR1) of the output channel is set to half the
auto-reload value. Therefore the timer output compare delay is 50 ms.
Generally speaking this delay is calculated as follows:
CC1_delay = TIM2 counter clock / CCR1

The timer output channel is mapped on the pin PA5 (connected to LED2 on board
NUCLEO-G474RE RevC).
Thus LED2 status (on/off) mirrors the timer output level (active v.s. inactive).

User push-button can be used to change the output compare mode:
  - When the output channel is configured in output compare toggle:  LED2 
    TOGGLES when the counter (CNT) matches the capture/compare register (CCR1).
  - When the output channel is configured in output compare active:  LED2 
    switched ON when the counter (CNT) matches the capture/compare register
    (CCR1).
  - When the output channel is configured in output compare inactive:  LED2 
    switched OFF when the counter (CNT) matches the capture/compare register
    (CCR1).
    
Initially the output channel is configured in output compare toggle mode.

@par Directory contents 

  - TIM/TIM_OutputCompare_Init/Inc/stm32g4xx_it.h          Interrupt handlers header file
  - TIM/TIM_OutputCompare_Init/Inc/main.h                  Header for main.c module
  - TIM/TIM_OutputCompare_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - TIM/TIM_OutputCompare_Init/Src/stm32g4xx_it.c          Interrupt handlers
  - TIM/TIM_OutputCompare_Init/Src/main.c                  Main program
  - TIM/TIM_OutputCompare_Init/Src/system_stm32g4xx.c      STM32G4xx system source file


@par Hardware and Software environment

  - This example runs on STM32G474RETx devices.
    
  - This example has been tested with NUCLEO-G474RE board and can be
    easily tailored to any other supported device and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

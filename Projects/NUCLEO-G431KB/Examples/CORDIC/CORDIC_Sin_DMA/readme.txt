/**
  @page CORDIC_Sin_DMA CORDIC Sines calculation in DMA mode example

  @verbatim
  ******************************************************************************
  * @file    CORDIC/CORDIC_Sin_DMA/readme.txt
  * @author  MCD Application Team
  * @brief   Sines calculation in DMA mode example.
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

How to use the CORDIC peripheral to calculate array of sines in DMA mode.

In this example, the CORDIC peripheral is configured in sine function, q1.31
format for both input and output data, and with 6 cycles of precision.
The input data provided to CORDIC peripheral are angles in radians
divided by PI, in q1.31 format. The output data are sines in q1.31 format.
For 6 cycles of precision, the maximal expected residual error of the
calculated sines is 2^-19.

DMA is used to transfer input data from memory to the CORDIC peripheral and
output data from CORDIC peripheral to memory, so that CPU is offloaded.

The calculated sines are stored in aCalculatedSin[] array.
The residual error of calculation results is verified, by comparing to
reference values in aRefSin[] obtained from double precision floating point
calculation.

STM32 board LED is used to monitor the example status:
  - LED2 is ON when correct CORDIC sine results are calculated.
  - LED2 is blinking (1 second period) when exceeding residual error
    on CORDIC sine results is detected or when there is an initialization error.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents

  - CORDIC/CORDIC_Sin_DMA/Inc/stm32g4xx_nucleo_conf.h     BSP configuration file
  - CORDIC/CORDIC_Sinus_DMA/Inc/stm32g4xx_hal_conf.h    HAL configuration file
  - CORDIC/CORDIC_Sinus_DMA/Inc/stm32g4xx_it.h          Interrupt handlers header file
  - CORDIC/CORDIC_Sinus_DMA/Inc/main.h                  Header for main.c module
  - CORDIC/CORDIC_Sinus_DMA/Src/stm32g4xx_it.c          Interrupt handlers
  - CORDIC/CORDIC_Sinus_DMA/Src/main.c                  Main program
  - CORDIC/CORDIC_Sinus_DMA/Src/stm32g4xx_hal_msp.c     HAL MSP module
  - CORDIC/CORDIC_Sinus_DMA/Src/system_stm32g4xx.c      STM32G4xx system source file


@par Hardware and Software environment

  - This example runs on STM32G431KBTx devices.

  - This example has been tested with STMicroelectronics NUCLEO-G431KB RevA
    board and can be easily tailored to any other supported device
    and development board.

@par How to use it ?

In order to make the program work, you must do the following:
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

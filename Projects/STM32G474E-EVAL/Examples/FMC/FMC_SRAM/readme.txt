/**
  @page FMC_SRAM FMC SRAM basic functionalities use example

  @verbatim
  ******************************************************************************
  * @file    FMC/FMC_SRAM/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the FMC SRAM example.
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

This example describes how to configure the FMC controller to access the SRAM
memory.

The SRAM is IS61WV51216BLL.

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 170 MHz.

The goal of this example is to explain the different steps to configure the FMC
and make the SRAM device ready for access, without using the MSP layer.

In this example, the SRAM device is configured and initialized explicitly
following all initialization sequence steps. After initializing the device, user
can perform read/write operations on it. A data buffer is written to the SRAM
memory, then read back and checked to verify its correctness.

The FMC memory bus width is set to 16bits.

If the data is read correctly from SRAM, the LED1 is ON, otherwise the LED3 is ON.
In case of HAL initialization issue, LED3 is blinking (1 second period).

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents

 - FMC/FMC_SRAM/Inc/stm32g4xx_hal_conf.h        HAL Configuration file
 - FMC/FMC_SRAM/Inc/main.h                      Header for main.c module
 - FMC/FMC_SRAM/Inc/stm32g4xx_it.h              Header for stm32g4xx_it.c
 - FMC/FMC_SRAM/Src/main.c                      Main program
 - FMC/FMC_SRAM/Src/stm32g4xx_hal_msp.c         HAL MSP module
 - FMC/FMC_SRAM/Src/stm32g4xx_it.c              Interrupt handlers
 - FMC/FMC_SRAM/Src/system_stm32g4xx.c          STM32G4xx system clock configuration file


@par Hardware and Software environment

  - This example runs on STM32G474QETx devices.

  - This example has been tested with STM32G474E-EVAL Rev B board and can be
    easily tailored to any other supported device and development board.

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

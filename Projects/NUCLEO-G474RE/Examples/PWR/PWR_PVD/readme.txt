/**
  @page PWR_PVD PWR Programmable Voltage Detector (PVD) example
  
  @verbatim
  ******************************************************************************
  * @file    PWR/PWR_PVD/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the PWR Programmable Voltage Detector (PVD) example
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
How to configure the programmable voltage detector by using an external interrupt 
line. External DC supply must be used to supply Vdd.

In this example, EXTI line 15 is configured to generate an interrupt on each rising
or falling edge of the PVD output signal (which indicates that the Vdd voltage is
moving below or above the PVD threshold). As long as the voltage is above the 
target threshold (2.5V), LED2 is blinking with a 200 ms-period; when the voltage drops
below the threshold, LED2 stops blinking and remains constantly on (or appears
to be turned off if the voltage is getting really low); when the voltage moves back
above the target threshold, LED2 starts blinking again.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Power, PWR, EXTI, PVD, Interrupt, Wakeup, External reset

@par Directory contents 

  - PWR/PWR_PVD/Inc/stm32g4xx_nucleo_conf.h     BSP configuration file
  - PWR/PWR_PVD/Inc/stm32g4xx_hal_conf.h     HAL Configuration file
  - PWR/PWR_PVD/Inc/stm32g4xx_it.h           Header for stm32g4xx_it.c
  - PWR/PWR_PVD/Inc/main.h                         Header file for main.c
  - PWR/PWR_PVD/Src/system_stm32g4xx.c       STM32G4xx system clock configuration file
  - PWR/PWR_PVD/Src/stm32g4xx_it.c           Interrupt handlers
  - PWR/PWR_PVD/Src/stm32g4xx_hal_msp.c      HAL MSP module
  - PWR/PWR_PVD/Src/main.c                         Main program

@par Hardware and Software environment

  - This example runs on STM32G474xx devices
    
  - This example has been tested with STMicroelectronics NUCLEO-G474RE RevC
    board and can be easily tailored to any other supported device
    and development board.

  - NUCLEO-G474RE RevC Set-up :

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

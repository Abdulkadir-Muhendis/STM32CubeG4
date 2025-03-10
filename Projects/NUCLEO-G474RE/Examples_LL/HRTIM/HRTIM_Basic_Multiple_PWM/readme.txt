/**
  @page HRTIM_Basic_Multiple_PWM HRTIM example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/HRTIM/HRTIM_Basic_Multiple_PWM/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the HRTIM_Basic_Multiple_PWM example.
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
  This example describes how to generate basic PWM waveforms PWM on multiple outputs 
  with the HRTIM, as per HRTIM Cookbook basic examples (refer to AN4539 Application note).
  This example is based on the STM32G4xx HRTIM LL API. 
  The peripheral uses LL unitary service functions.

  The PWM are generated on the TD1 and TD2 (resp. PB14 and PB15) outputs with 133kHz frequency
  and TA1 and TA2 outputs (resp. PA8 and PA9) with 100kHz frequency.

  Green LED: blinks during normal operation
  Green LED: ON when the ERROR handler is entered

@par Directory contents 

  - HRTIM/HRTIM_Basic_Multiple_PWM/Inc/stm32g4xx_it.h          IT interrupt handlers header file
  - HRTIM/HRTIM_Basic_Multiple_PWM/Inc/main.h                  Header for main.c module  
  - HRTIM/HRTIM_Basic_Multiple_PWM/Src/stm32g4xx_it.c          IT interrupt handlers
  - HRTIM/HRTIM_Basic_Multiple_PWM/Src/main.c                  Main program
  - HRTIM/HRTIM_Basic_Multiple_PWM/Src/system_stm32g4xx.c      STM32G4xx system source file


@par Hardware and Software environment 

  - This example runs on STM32G474RETx devices.
  
  - This example has been tested with two NUCLEO-G474RE RevC boards embedding
    a STM32G474RET6 device and can be easily tailored to any other supported device 
    and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

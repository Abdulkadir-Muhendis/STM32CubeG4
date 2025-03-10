/**
  @page PWR_SHUTDOWN PWR shutdown example
  
  @verbatim
  ******************************************************************************
  * @file    PWR/PWR_SHUTDOWN/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the PWR SHUTDOWN example.
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
 
This example shows how to enter the system in SHUTDOWN mode and wake-up from this
mode using external RESET or WKUP pin.

In the associated software, the system clock is set to 170 MHz, an EXTI line
is connected to the user button thru PC.13 and configured to generate an 
interrupt on falling edge.
The SysTick is programmed to generate an interrupt each 1 ms and in the SysTick 
interrupt handler, LED2 is toggled in order to indicate whether the MCU is in SHUTDOWN or RUN mode.

When the User push-button is pressed a falling edge is detected on the EXTI line and
an interrupt is generated. In the EXTI handler routine, the wake-up pin PWR_WAKEUP_PIN2 
is enabled and the corresponding wake-up flag cleared. 
Then, the system enters SHUTDOWN mode causing LED2 to stop toggling. 

Next, the user can wake-up the system in pressing the User push-button which is connected
to the wake-up pin PWR_WAKEUP_PIN2.
A falling edge on the wake-up pin wakes-up the system from SHUTDOWN.
Alternatively, an external RESET of the board leads to a system wake-up as well.

After wake-up from SHUTDOWN mode, program execution restarts from the beginning.
Exit from SHUTDOWN is detected thru a flag set in an RTC back-up register; in
such a case, LED2 is kept on for about 4 sec. before toggling again.

USer can re-enter SHUTDOWN in pressing again the User push-button.

LED2 is used to monitor the system state as follows:
 - LED2 toggling: system in RUN mode
 - LED2 is on for about 4 sec.: system is restarting and out-of-shutdown has been detected
 - LED2 off : system in SHUTDOWN mode

These steps are repeated in an infinite loop.

@note To measure the current consumption in SHUTDOWN mode, remove IDD_JP jumper 
      and connect an amperemeter to IDD_JP to measure IDD current.     

@note This example can not be used in DEBUG mode, this is due to the fact 
      that the Cortex-M4 core is no longer clocked during low power mode 
      so debugging features are disabled

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Power, PWR, EXTI, Shutdown mode, Interrupt, Wakeup, External reset, WKUP pin

@par Directory contents 

  - PWR/PWR_SHUTDOWN/Inc/stm32g4xx_nucleo_conf.h     BSP configuration file
  - PWR/PWR_SHUTDOWN/Inc/stm32g4xx_conf.h         HAL Configuration file
  - PWR/PWR_SHUTDOWN/Inc/stm32g4xx_it.h           Header for stm32g4xx_it.c
  - PWR/PWR_SHUTDOWN/Inc/main.h                   Header file for main.c
  - PWR/PWR_SHUTDOWN/Src/system_stm32g4xx.c       STM32G4xx system clock configuration file
  - PWR/PWR_SHUTDOWN/Src/stm32g4xx_it.c           Interrupt handlers
  - PWR/PWR_SHUTDOWN/Src/main.c                   Main program

@par Hardware and Software environment

  - NUCLEO-G431RB RevC Set-up
    - LED2 connected to PA.05 pin
    - User push-button connected to pin PC.13 (External line 15 to 10)
    - WakeUp Pin PWR_WAKEUP_PIN2 connected to PC.13

  - This example runs on STM32G4xx devices
      
  - This example has been tested with STMicroelectronics NUCLEO-G431RB RevC
    evaluation board and can be easily tailored to any other supported device 
    and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

/**
  @page LPTIM_PWMExternalClock LPTIM PWM External clock example
  
  @verbatim
  ******************************************************************************
  * @file    LPTIM/LPTIM_PWMExternalClock/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the LPTIM PWM with an External clock example.
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

How to configure and use, through the HAL LPTIM API, the LPTIM peripheral using an external counter clock, 
to generate a PWM signal at the lowest power consumption.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
The SystemClock_Config() function is used to configure the system clock for STM32G474RETx Devices :
The CPU at 170 MHz  

The Autorelaod equal to 99 so the output frequency (OutputFrequency) will
be equal to the external counter clock (InputFrequency) divided by (99+1).

  OutputFrequency = InputFrequency / (Autoreload + 1)
                  = InputFrequency / 100

Pulse value equal to 49 and the duty cycle (DutyCycle) is computed as follow:

  DutyCycle = 1 - [(PulseValue + 1)/ (Autoreload + 1)]
  DutyCycle = 50%

To minimize the power consumption, after starting generating the PWM signal,
the MCU enters in STOP mode. Note that GPIOs are configured in Low Speed to
lower the consumption.

JOY_SEL pin is configured as input with external interrupt (EXTI line 13),
falling edge. When JOY_SEL is pressed, wakeup event is generated and PWM signal
generation is stopped.

@note This example can not be used in DEBUG mode, this is due to the fact
      that the Cortex-M4 core is no longer clocked during low power mode
      so debugging features are disabled.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note This example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Keywords

Timer, Low Power, PWM, Stop mode, Interrupt, External Clock, Output, Duty Cycle

@par Directory contents  

  - LPTIM/LPTIM_PWMExternalClock/Inc/stm32g4xx_hal_conf.h    HAL configuration file
  - LPTIM/LPTIM_PWMExternalClock/Inc/stm32g4xx_it.h          Interrupt handlers header file
  - LPTIM/LPTIM_PWMExternalClock/Inc/main.h                  Header for main.c module  
  - LPTIM/LPTIM_PWMExternalClock/Src/stm32g4xx_it.c          Interrupt handlers
  - LPTIM/LPTIM_PWMExternalClock/Src/main.c                  Main program
  - LPTIM/LPTIM_PWMExternalClock/Src/stm32g4xx_hal_msp.c     HAL MSP module
  - LPTIM/LPTIM_PWMExternalClock/Src/system_stm32g4xx.c      STM32G4xx system source file


@par Hardware and Software environment

  - This example runs on STM32G474RETx devices.
    
  - This example has been tested with STMicroelectronics B-G474E-DPOW1
    board and can be easily tailored to any other supported device
    and development board.   
	
  - Connect a clock signal to PC0 (pin 18 in CN9 connector).
  - Connect PC1 (pin 28 in CN9 connector) to an oscilloscope 
    to monitor the LPTIM output waveform.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred tool chain 
 - Rebuild all files and load your image into target memory
 - Run the example 

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

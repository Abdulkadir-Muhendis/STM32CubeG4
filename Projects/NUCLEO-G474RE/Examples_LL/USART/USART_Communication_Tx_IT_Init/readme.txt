/**
  @page USART_Communication_Tx_IT_Init USART Transmitter example (IT mode)
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/USART/USART_Communication_Tx_IT_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the USART_Communication_Tx_IT_Init example.
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

This example shows how to configure GPIO and USART peripheral to send characters
asynchronously to HyperTerminal (PC) in Interrupt mode. This example is based on
STM32G4xx USART LL API. Peripheral initialization is done using LL unitary services
functions for optimization purpose (performance and size).

USART Peripheral is configured in asynchronous mode (115200 bauds, 8 data bit, 1 start bit, 1 stop bit, no parity).
No HW flow control is used.
GPIO associated to User push-button is linked with EXTI. 
Virtual Com port feature of STLINK could be used for UART communication between board and PC.

Example execution:
On press on push button , USART TX Empty interrupt is enabled.
First character of buffer to be transmitted is written into USART Transmit Data Register (TDR) in order to initialise transfer procedure.
When character is sent from TDR, a TXE interrupt occurs. 
USART IRQ Handler routine is sending next character on USART Tx line. 
IT will be raised until last byte is to be transmitted : Then, Transmit Complete (TC) interrupt is enabled 
instead of TX Empty (TXE). 
On last byte transmission complete, LED2 is turned on.
In case of errors, LED2 is blinking (1sec period).

Program is written so that, any new press on User push-button will lead to new transmission of complete buffer.

@par Directory contents 

  - USART/USART_Communication_Tx_IT_Init/Inc/stm32g4xx_it.h          Interrupt handlers header file
  - USART/USART_Communication_Tx_IT_Init/Inc/main.h                  Header for main.c module
  - USART/USART_Communication_Tx_IT_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - USART/USART_Communication_Tx_IT_Init/Src/stm32g4xx_it.c          Interrupt handlers
  - USART/USART_Communication_Tx_IT_Init/Src/main.c                  Main program
  - USART/USART_Communication_Tx_IT_Init/Src/system_stm32g4xx.c      STM32G4xx system source file


@par Hardware and Software environment

  - This example runs on STM32G474RETx devices.
    
  - This example has been tested with NUCLEO-G474RE RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-G474RE RevC Set-up
    Connect USART1 TX/RX to respectively RX and TX pins of PC UART (could be done through a USB to UART adapter) :
    - Connect STM32 MCU board USART1 TX pin (GPIO PA.09 connected to pin 21 in CN10)
      to PC COM port RX signal
    - Connect STM32 MCU board USART1 RX pin (GPIO PA.10 connected to pin 33 in CN10)
      to PC COM port TX signal
    - Connect STM32 MCU board GND to PC COM port GND signal

  - Launch serial communication SW on PC (as HyperTerminal or TeraTerm) with proper configuration 
    (115200 bauds, 8 bits data, 1 stop bit, no parity, no HW flow control).

  - Launch the program. Press on User push button on board to initiate data transfer.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

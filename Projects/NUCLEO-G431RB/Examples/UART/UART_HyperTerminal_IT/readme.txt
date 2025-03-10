/**
  @page UART_Hyperterminal_IT UART Hyperterminal IT example

  @verbatim
  ******************************************************************************
  * @file    UART/UART_Hyperterminal_IT/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the UART Hyperterminal example.
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

UART transmission (transmit/receive) in Interrupt mode between a board and
an HyperTerminal PC application.

Board: NUCLEO-G431RB
Tx Pin: PA.02 (available through VCP)
Rx Pin: PA.03 (available through VCP)
   _________________________
  |           ______________|                       _______________
  |          |USART         |                      | HyperTerminal |
  |          |              |                      |               |
  |          |           TX |______________________|RX             |
  |          |              |                      |               |
  |          |              |    ST-Link Cable     |               |
  |          |              |                      |               |
  |          |           RX |______________________|TX             |
  |          |              |                      |               |
  |          |______________|                      |_______________|
  |                         |
  |                         |
  |                         |
  |                         |
  |_STM32_Board_____________|

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 170 MHz for STM32G4xx Devices.

The UART peripheral configuration is ensured by the HAL_UART_Init() function.
This later is calling the HAL_UART_MspInit() function which core is implementing
the configuration of the needed UART resources according to the used hardware (CLOCK,
GPIO and NVIC). You may update this function to change UART configuration.

The UART/Hyperterminal communication is then initiated.
The HAL_UART_Receive_IT() and the HAL_UART_Transmit_IT() functions allow respectively
the reception of Data from Hyperterminal and the transmission of a predefined data
buffer.

The Asynchronous communication aspect of the UART is clearly highlighted as the
data buffers transmission/reception to/from Hyperterminal are done simultaneously.

For this example the TxBuffer (aTxStartMessage) is predefined and the RxBuffer (aRxBuffer)
size is limited to 10 data by the mean of the RXBUFFERSIZE define in the main.c file.

In a first step the TxBuffer buffer content will be displayed in the Hyperterminal
interface and the received data will be stored in the RxBuffer buffer.
In a second step the received data in the RxBuffer buffer will be sent back to
Hyperterminal and displayed.
The end of this two steps are monitored through the HAL_UART_GetState() function
result.

NUCLEO-G431RB RevC board LED is used to monitor the transfer status:
 - LED2 turns ON if transmission/reception is complete and OK.
 - LED2 toggles when when there is an error in transmission/reception process.

The UART is configured as follows:
    - BaudRate = 9600 baud
    - Word Length = 8 Bits (7 data bit + 1 parity bit)
    - One Stop Bit
    - Odd parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Reception and transmission are enabled in the time

@note When the parity is enabled, the computed parity is inserted at the MSB
position of the transmitted data.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Connectivity, UART, Printf, Baud rate, RS-232, HyperTerminal, full-duplex, HyperTerminal,
Transmission, Reception, Asynchronous, interrupt

@par Directory contents

  - UART/UART_HyperTerminal_IT/Inc/stm32g4xx_nucleo_conf.h     BSP configuration file
  - UART/UART_HyperTerminal_IT/Inc/stm32g4xx_hal_conf.h    HAL configuration file
  - UART/UART_HyperTerminal_IT/Inc/stm32g4xx_it.h          IT interrupt handlers header file
  - UART/UART_HyperTerminal_IT/Inc/main.h                  Header for main.c module
  - UART/UART_HyperTerminal_IT/Src/stm32g4xx_it.c          IT interrupt handlers
  - UART/UART_HyperTerminal_IT/Src/main.c                  Main program
  - UART/UART_HyperTerminal_IT/Src/stm32g4xx_hal_msp.c     HAL MSP module
  - UART/UART_HyperTerminal_IT/Src/system_stm32g4xx.c      STM32G4xx system source file


@par Hardware and Software environment

  - This example runs on STM32G431RBTx devices.

  - This example has been tested with STMicroelectronics NUCLEO-G431RB board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-G431RB Set-up
    
    - Connect ST-Link cable to the PC USB port to display data on the HyperTerminal (and to receive data).
      A virtual COM port will then appear in the HyperTerminal.

  - Hyperterminal configuration:
    - Data Length = 7 Bits
    - One Stop Bit
    - Odd parity
    - BaudRate = 9600 baud
    - Flow control: None

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

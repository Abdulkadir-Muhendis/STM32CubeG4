/**
  @page I2C_OneBoard_Communication_PollingAndIT_Init I2C example (Master Polling Mode)

  @verbatim
  ******************************************************************************
  * @file    Examples_LL/I2C/I2C_OneBoard_Communication_PollingAndIT_Init/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the I2C_OneBoard_Communication_PollingAndIT_Init I2C example (Master Polling Mode).
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

How to transmit data bytes from an I2C master device using polling mode
to an I2C slave device using interrupt mode. The peripheral is initialized
with LL unitary service functions to optimize for performance and size.

This example guides you through the different configuration steps by mean of LL API
to configure GPIO and I2C peripherals using only one NUCLEO-G431RB RevC.

I2C1 Peripheral is configured in Slave mode with EXTI (Clock 400Khz, Own address 7-bit enabled).
I2C3 Peripheral is configured in Master mode (Clock 400Khz).
GPIO associated to User push-button is linked with EXTI.

LED2 blinks quickly to wait for user-button press.

Example execution:
Press the User push-button to initiate a write request by Master through Handle_I2C_Master() routine.
This action will generate an I2C start condition with the Slave address and a write bit condition.
When address Slave match code is received on I2C1, an ADDR interrupt occurs.
I2C1 IRQ Handler routine is then checking Address Match Code and direction Write.
This will allow Slave to enter in receiver mode and then acknowledge Master to send the bytes.
When acknowledge is received on I2C3, a TXIS event occurs.
This will allow Master to transmit a byte to the Slave.
Each time a byte is received on I2C1 (Slave), an RXNE interrupt occurs until a STOP condition.
And so each time the Slave acknowledge the byte received a TXIS event occurs on Master side.
Master auto-generate a Stop condition when size of data to transmit is achieved.

The STOP condition generate a STOP interrupt and initiate the end of reception on Slave side.
I2C1 IRQ handler and Handle_I2C_Master() routine are then clearing the STOP flag in both side.

LED2 is On if data are well received.

In case of errors, LED2 is blinking slowly (1s).


@par Directory contents

  - I2C/I2C_OneBoard_Communication_PollingAndIT_Init/Inc/stm32g4xx_it.h          Interrupt handlers header file
  - I2C/I2C_OneBoard_Communication_PollingAndIT_Init/Inc/main.h                  Header for main.c module
  - I2C/I2C_OneBoard_Communication_PollingAndIT_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - I2C/I2C_OneBoard_Communication_PollingAndIT_Init/Src/stm32g4xx_it.c          Interrupt handlers
  - I2C/I2C_OneBoard_Communication_PollingAndIT_Init/Src/main.c                  Main program
  - I2C/I2C_OneBoard_Communication_PollingAndIT_Init/Src/system_stm32g4xx.c      STM32G4xx system source file

@par Hardware and Software environment

  - This example runs on STM32G431RBTx devices.

  - This example has been tested with NUCLEO-G431RB RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-G431RB RevC Set-up
    - Connect GPIOs connected to I2C1 SCL/SDA (PB.8 and PB.9)
    to respectively SCL and SDA pins of I2C3 (PC.8 and PC.9).
      - I2C1_SCL  PB.8 (CN7, pin 7) : connected to I2C3_SCL PC.8 (CN10, pin 2)
      - I2C1_SDA  PB.9 (CN10, pin 5) : connected to I2C3_SDA PC.9 (CN10, pin 1)

  - Launch the program.
  - Press User push-button to initiate a write request by Master
      then Slave receive bytes.

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

/**
  ******************************************************************************
  * @file    Examples_LL/USART/USART_SyncCommunication_FullDuplex_DMA/Src/main.c
  * @author  MCD Application Team
  * @brief   This example describes how to transfer bytes from/to an USART peripheral 
  *          to/from an SPI peripheral (in slave mode) using DMA mode 
  *          through the STM32G4xx USART LL API.
  *          Peripheral initialization done using LL unitary services functions.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics. 
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the 
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32G4xx_LL_Examples
  * @{
  */

/** @addtogroup USART_SyncCommunication_FullDuplex_DMA
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
__IO uint8_t ubButtonPress = 0;

/* Buffer used for transmission */
uint8_t aUSART1TxBuffer[] = "**** USART_SyncCommunication_FullDuplex_DMA USART1 to SPI1 communication ****";
uint8_t ubUSART1NbDataToTransmit = sizeof(aUSART1TxBuffer);
__IO uint8_t ubUSART1TransmissionComplete = 0;
uint8_t aSPI1TxBuffer[] = "**** USART_SyncCommunication_FullDuplex_DMA SPI1 to USART1 communication ****";
uint8_t ubSPI1NbDataToTransmit = sizeof(aSPI1TxBuffer);
__IO uint8_t ubSPI1TransmissionComplete = 0;

/* Buffer used for reception */
uint8_t aUSART1RxBuffer[sizeof(aSPI1TxBuffer)];
uint8_t ubUSART1NbDataToReceive = sizeof(aSPI1TxBuffer);
__IO uint8_t ubUSART1ReceptionComplete = 0;
uint8_t aSPI1RxBuffer[sizeof(aUSART1TxBuffer)];
uint8_t ubSPI1NbDataToReceive = sizeof(aUSART1TxBuffer);
__IO uint8_t ubSPI1ReceptionComplete = 0;

/* Private function prototypes -----------------------------------------------*/
void     SystemClock_Config(void);
void     Configure_USART1_DMA(void);
void     Configure_SPI1_DMA(void);
void     Configure_USART1(void);
void     Configure_SPI1(void);
void     Activate_SPI1(void);
void     StartTransfers(void);
void     LED_Init(void);
void     LED_On(void);
void     LED_Blinking(uint32_t Period);
void     LED_Off(void);
void     UserButton_Init(void);
void     WaitForUserButtonPress(void);
void     WaitAndCheckEndOfTransfer(void);
uint8_t  Buffercmp8(uint8_t* pBuffer1, uint8_t* pBuffer2, uint8_t BufferLength);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* Configure the system clock to 170 MHz */
  SystemClock_Config();

  /* Initialize LED2 */
  LED_Init();

  /* Configure the USART1 parameters */
  Configure_USART1();

  /* Configure the SPI1 parameters */
  Configure_SPI1();

  /* Configure DMA channels for the USART1  */
  Configure_USART1_DMA();

  /* Configure DMA channels for the SPI1  */
  Configure_SPI1_DMA();

  /* Initialize User push-button in EXTI mode */
  UserButton_Init();

  /* Enable the SPI1 peripheral */
  Activate_SPI1();

  /* Wait for User push-button press to start transfer */
  WaitForUserButtonPress();
  
  /* Initiate DMA transfers */
  StartTransfers();
  
  /* Wait for the end of the transfer and check received data */
  WaitAndCheckEndOfTransfer();

  /* Infinite loop */
  while (1)
  {
  }
}

/**
  * @brief  This function configures the DMA Channels for USART1
  * @note   This function is used to :
  *         -1- Enable DMA1 clock
  *         -2- Configure NVIC for DMA1 transfer complete/error interrupts
  *         -3- Configure the DMA1_Channel4 functional parameters for Tx
  *         -4- Configure the DMA1_Channel5 functional parameters for Rx
  *         -5- Enable DMA1_Channel4 and DMA1_Channel5 DMA transfer complete/error interrupts
  * @param  None
  * @retval None
  */
void Configure_USART1_DMA(void)
{
  /* DMA1 used for USART1 Transmission and Reception
   */
  /* (1) Enable the clock of DMA1 */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMAMUX1);

  /* (2) Configure NVIC for DMA transfer complete/error interrupts */
  NVIC_SetPriority(DMA1_Channel4_IRQn, 3);
  NVIC_EnableIRQ(DMA1_Channel4_IRQn);
  NVIC_SetPriority(DMA1_Channel5_IRQn, 2);
  NVIC_EnableIRQ(DMA1_Channel5_IRQn);

  /* (3) Configure the DMA1 functional parameters for transmission */
  LL_DMA_ConfigTransfer(DMA1, LL_DMA_CHANNEL_4, 
                        LL_DMA_DIRECTION_MEMORY_TO_PERIPH | 
                        LL_DMA_PRIORITY_HIGH              | 
                        LL_DMA_MODE_NORMAL                | 
                        LL_DMA_PERIPH_NOINCREMENT         | 
                        LL_DMA_MEMORY_INCREMENT           | 
                        LL_DMA_PDATAALIGN_BYTE            | 
                        LL_DMA_MDATAALIGN_BYTE);
  LL_DMA_ConfigAddresses(DMA1, LL_DMA_CHANNEL_4,
                         (uint32_t)aUSART1TxBuffer,
                         LL_USART_DMA_GetRegAddr(USART1, LL_USART_DMA_REG_DATA_TRANSMIT),
                         LL_DMA_GetDataTransferDirection(DMA1, LL_DMA_CHANNEL_4));
  LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_4, ubUSART1NbDataToTransmit);
  LL_DMA_SetPeriphRequest(DMA1, LL_DMA_CHANNEL_4, LL_DMAMUX_REQ_USART1_TX);

  /* (4) Configure the DMA functional parameters for reception */
  LL_DMA_ConfigTransfer(DMA1, LL_DMA_CHANNEL_5, 
                        LL_DMA_DIRECTION_PERIPH_TO_MEMORY | 
                        LL_DMA_PRIORITY_HIGH              | 
                        LL_DMA_MODE_NORMAL                | 
                        LL_DMA_PERIPH_NOINCREMENT         | 
                        LL_DMA_MEMORY_INCREMENT           | 
                        LL_DMA_PDATAALIGN_BYTE            | 
                        LL_DMA_MDATAALIGN_BYTE);
  LL_DMA_ConfigAddresses(DMA1, LL_DMA_CHANNEL_5,
                         LL_USART_DMA_GetRegAddr(USART1, LL_USART_DMA_REG_DATA_RECEIVE),
                         (uint32_t)aUSART1RxBuffer,
                         LL_DMA_GetDataTransferDirection(DMA1, LL_DMA_CHANNEL_5));
  LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_5, ubUSART1NbDataToReceive);
  LL_DMA_SetPeriphRequest(DMA1, LL_DMA_CHANNEL_5, LL_DMAMUX_REQ_USART1_RX);

  /* (5) Enable DMA transfer complete/error interrupts  */
  LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_4);
  LL_DMA_EnableIT_TE(DMA1, LL_DMA_CHANNEL_4);
  LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_5);
  LL_DMA_EnableIT_TE(DMA1, LL_DMA_CHANNEL_5);
}

/**
  * @brief  This function configures the DMA Channels for SPI1
  * @note   This function is used to :
  *         -1- Enable DMA1 clock
  *         -2- Configure NVIC for DMA1 transfer complete/error interrupts
  *         -3- Configure the DMA1_Channel2 functional parameters for Tx
  *         -4- Configure the DMA1_Channel3 functional parameters for Rx
  *         -5- Enable DMA1_Channel2 and DMA1_Channel3 DMA transfer complete/error interrupts
  * @param  None
  * @retval None
  */
void Configure_SPI1_DMA(void)
{
  /* DMA1 used for SPI1 Transmission and Reception
   */
  /* (1) Enable the clock of DMA1 */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);

  /* (2) Configure NVIC for DMA transfer complete/error interrupts */
  NVIC_SetPriority(DMA1_Channel2_IRQn, 1);
  NVIC_EnableIRQ(DMA1_Channel2_IRQn);
  NVIC_SetPriority(DMA1_Channel3_IRQn, 0);
  NVIC_EnableIRQ(DMA1_Channel3_IRQn);

  /* (3) Configure the DMA1 functional parameters for transmission */
  LL_DMA_ConfigTransfer(DMA1, LL_DMA_CHANNEL_2, 
                        LL_DMA_DIRECTION_MEMORY_TO_PERIPH | 
                        LL_DMA_PRIORITY_HIGH              | 
                        LL_DMA_MODE_NORMAL                | 
                        LL_DMA_PERIPH_NOINCREMENT         | 
                        LL_DMA_MEMORY_INCREMENT           | 
                        LL_DMA_PDATAALIGN_BYTE            | 
                        LL_DMA_MDATAALIGN_BYTE);
  LL_DMA_ConfigAddresses(DMA1, LL_DMA_CHANNEL_2,
                         (uint32_t)aSPI1TxBuffer,
                         (uint32_t)&(SPI1->DR),
                         LL_DMA_GetDataTransferDirection(DMA1, LL_DMA_CHANNEL_2));
  LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_2, ubSPI1NbDataToTransmit);
  LL_DMA_SetPeriphRequest(DMA1, LL_DMA_CHANNEL_2, LL_DMAMUX_REQ_SPI1_TX);


  /* (4) Configure the DMA functional parameters for reception */
  LL_DMA_ConfigTransfer(DMA1, LL_DMA_CHANNEL_3, 
                        LL_DMA_DIRECTION_PERIPH_TO_MEMORY | 
                        LL_DMA_PRIORITY_HIGH              | 
                        LL_DMA_MODE_NORMAL                | 
                        LL_DMA_PERIPH_NOINCREMENT         | 
                        LL_DMA_MEMORY_INCREMENT           | 
                        LL_DMA_PDATAALIGN_BYTE            | 
                        LL_DMA_MDATAALIGN_BYTE);
  LL_DMA_ConfigAddresses(DMA1, LL_DMA_CHANNEL_3,
                         (uint32_t)&(SPI1->DR),
                         (uint32_t)aSPI1RxBuffer,
                         LL_DMA_GetDataTransferDirection(DMA1, LL_DMA_CHANNEL_3));
  LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_3, ubSPI1NbDataToReceive);
  LL_DMA_SetPeriphRequest(DMA1, LL_DMA_CHANNEL_3, LL_DMAMUX_REQ_SPI1_RX);

  /* (5) Enable DMA transfer complete/error interrupts  */
  LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_2);
  LL_DMA_EnableIT_TE(DMA1, LL_DMA_CHANNEL_2);
  LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_3);
  LL_DMA_EnableIT_TE(DMA1, LL_DMA_CHANNEL_3);
}

/**
  * @brief  This function configures USART1.
  * @note   This function is used to :
  *         -1- Enable GPIO clock and configures the USART1 pins.
  *         -2- Enable the USART1 peripheral clock and clock source.
  *         -3- Configure USART1 functional parameters.
  *         -4- Enable USART1.
  * @note   Peripheral configuration is minimal configuration from reset values.
  *         Thus, some useless LL unitary functions calls below are provided as
  *         commented examples - setting is default configuration from reset.
  * @param  None
  * @retval None
  */
void Configure_USART1(void)
{
  /* (1) Enable GPIO clock and configures the USART1 pins ********************/
  /* Enable the peripheral clock of GPIOA */
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);

  /* Configure SCK Pin connected to pin 23 of CN10 connector */
  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_8, LL_GPIO_MODE_ALTERNATE);
  LL_GPIO_SetAFPin_8_15(GPIOA, LL_GPIO_PIN_8, LL_GPIO_AF_7);
  LL_GPIO_SetPinSpeed(GPIOA, LL_GPIO_PIN_8, LL_GPIO_SPEED_FREQ_HIGH);
  LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_8, LL_GPIO_OUTPUT_PUSHPULL);
  LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_8, LL_GPIO_PULL_DOWN);

  /* Configure TX Pin connected to pin 21 of CN10 connector */
  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_9, LL_GPIO_MODE_ALTERNATE);
  LL_GPIO_SetAFPin_8_15(GPIOA, LL_GPIO_PIN_9, LL_GPIO_AF_7);
  LL_GPIO_SetPinSpeed(GPIOA, LL_GPIO_PIN_9, LL_GPIO_SPEED_FREQ_HIGH);
  LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_9, LL_GPIO_OUTPUT_PUSHPULL);
  LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_9, LL_GPIO_PULL_DOWN);

  /* Configure RX Pin connected to pin 33 of CN10 connector */
  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_10, LL_GPIO_MODE_ALTERNATE);
  LL_GPIO_SetAFPin_8_15(GPIOA, LL_GPIO_PIN_10, LL_GPIO_AF_7);
  LL_GPIO_SetPinSpeed(GPIOA, LL_GPIO_PIN_10, LL_GPIO_SPEED_FREQ_HIGH);
  LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_10, LL_GPIO_OUTPUT_PUSHPULL);
  LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_10, LL_GPIO_PULL_DOWN);

  /* (2) Enable the USART1 peripheral clock and clock source ****************/
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1);

  /* Set clock source */
  LL_RCC_SetUSARTClockSource(LL_RCC_USART1_CLKSOURCE_PCLK2);

  /* (3) Configure USART1 functional parameters ********************************/

  /* Disable USART prior modifying configuration registers */
  /* Note: Commented as corresponding to Reset value */
  // LL_USART_Disable(USART1);

  /* TX/RX direction */
  LL_USART_SetTransferDirection(USART1, LL_USART_DIRECTION_TX_RX);

  /* 8 data bit, 1 start bit, 1 stop bit, no parity */
  LL_USART_ConfigCharacter(USART1, LL_USART_DATAWIDTH_8B, LL_USART_PARITY_NONE, LL_USART_STOPBITS_1);

  /* Configure transfer bit order : MSB first */
  LL_USART_SetTransferBitOrder(USART1, LL_USART_BITORDER_LSBFIRST);

  /* Clock configuration : Phase 2 edges, Polarity Low, Last Bit Clock output enabled */
  LL_USART_ConfigClock(USART1, LL_USART_PHASE_2EDGE, LL_USART_POLARITY_LOW, LL_USART_LASTCLKPULSE_OUTPUT);

  /* Oversampling by 8 : To be forced to 8 in USART mode */
  LL_USART_SetOverSampling(USART1, LL_USART_OVERSAMPLING_8);

  /* Set Baudrate to 115200 using APB frequency set to 170000000 Hz */
  /* Frequency available for USART peripheral can also be calculated through LL RCC macro */
  /* Ex :
      Periphclk = LL_RCC_GetUSARTClockFreq(Instance);
  
      In this example, Peripheral Clock is expected to be equal to 170000000 Hz => equal to SystemCoreClock
  */
  LL_USART_SetBaudRate(USART1, SystemCoreClock, LL_USART_PRESCALER_DIV1, LL_USART_OVERSAMPLING_16, 115200); 

  /* Configure peripheral in USART mode for synchronous communication (CLK signal delivered by USRAT peripheral)
  *  Call of this function is equivalent to following function call sequence :
  *         - Clear LINEN in CR2 using LL_USART_DisableLIN() function
  *         - Clear IREN in CR3 using LL_USART_DisableSmartcard() function
  *         - Clear SCEN in CR3 using LL_USART_DisableSmartcard() function
  *         - Clear HDSEL in CR3 using LL_USART_DisableHalfDuplex() function
  *         - Set CLKEN in CR2 using LL_USART_EnableSCLKOutput() function
  */
  LL_USART_ConfigSyncMode(USART1);

  /* (4) Enable USART1 **********************************************************/
  LL_USART_Enable(USART1);

  /* Polling USART initialisation */
  while((!(LL_USART_IsActiveFlag_TEACK(USART1))) || (!(LL_USART_IsActiveFlag_REACK(USART1))))
  { 
  }
}

/**
  * @brief  This function configures SPI1.
  * @note   This function is used to :
  *         -1- Enable GPIO clock and configures the SPI1 pins.
  *         -2- Enable the SPI1 peripheral clock and clock source.
  *         -3- Configure SPI1 functional parameters.
  * @param  None
  * @retval None
  */
void Configure_SPI1(void)
{
  /* (1) Enable GPIO clock and configures the SPI1 pins ********************/

  /* Enable the peripheral clock of GPIOB */
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);

  /* Configure SCK Pin connected to pin 31 of CN10 connector */
  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_3, LL_GPIO_MODE_ALTERNATE);
  LL_GPIO_SetAFPin_0_7(GPIOB, LL_GPIO_PIN_3, LL_GPIO_AF_5);
  LL_GPIO_SetPinSpeed(GPIOB, LL_GPIO_PIN_3, LL_GPIO_SPEED_FREQ_HIGH);
  LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_3, LL_GPIO_OUTPUT_PUSHPULL);
  LL_GPIO_SetPinPull(GPIOB, LL_GPIO_PIN_3, LL_GPIO_PULL_DOWN);

  /* Configure MISO Pin connected to pin 27 of CN10 connector */
  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_4, LL_GPIO_MODE_ALTERNATE);
  LL_GPIO_SetAFPin_0_7(GPIOB, LL_GPIO_PIN_4, LL_GPIO_AF_5);
  LL_GPIO_SetPinSpeed(GPIOB, LL_GPIO_PIN_4, LL_GPIO_SPEED_FREQ_HIGH);
  LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_4, LL_GPIO_OUTPUT_PUSHPULL);
  LL_GPIO_SetPinPull(GPIOB, LL_GPIO_PIN_4, LL_GPIO_PULL_DOWN);

  /* Configure MOSI Pin connected to pin 29 of CN10 connector */
  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_5, LL_GPIO_MODE_ALTERNATE);
  LL_GPIO_SetAFPin_0_7(GPIOB, LL_GPIO_PIN_5, LL_GPIO_AF_5);
  LL_GPIO_SetPinSpeed(GPIOB, LL_GPIO_PIN_5, LL_GPIO_SPEED_FREQ_HIGH);
  LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_5, LL_GPIO_OUTPUT_PUSHPULL);
  LL_GPIO_SetPinPull(GPIOB, LL_GPIO_PIN_5, LL_GPIO_PULL_DOWN);

  /* (2) Enable the SPI1 peripheral clock and clock source ****************/
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);

  /* (3) Configure SPI1 functional parameters ********************************/
  LL_SPI_SetBaudRatePrescaler(SPI1, LL_SPI_BAUDRATEPRESCALER_DIV256);  
  LL_SPI_SetTransferDirection(SPI1,LL_SPI_FULL_DUPLEX);  
  LL_SPI_SetClockPhase(SPI1, LL_SPI_PHASE_2EDGE);
  LL_SPI_SetClockPolarity(SPI1, LL_SPI_POLARITY_LOW);
  LL_SPI_SetTransferBitOrder(SPI1, LL_SPI_LSB_FIRST);  
  LL_SPI_SetDataWidth(SPI1, LL_SPI_DATAWIDTH_8BIT);
  LL_SPI_SetNSSMode(SPI1, LL_SPI_NSS_SOFT);
  LL_SPI_SetMode(SPI1, LL_SPI_MODE_SLAVE);
  LL_SPI_SetRxFIFOThreshold(SPI1, LL_SPI_RX_FIFO_TH_QUARTER);

  /* Configure SPI1 DMA transfer interrupts */
  /* Enable DMA TX Interrupt */
  LL_SPI_EnableDMAReq_TX(SPI1);
  /* Enable DMA RX Interrupt */
  LL_SPI_EnableDMAReq_RX(SPI1);
}

/**
  * @brief  This function Activate SPI1
  * @param  None
  * @retval None
  */
void Activate_SPI1(void)
{
  /* Enable SPI1 */
  LL_SPI_Enable(SPI1);

  /* Enable DMA Channels Tx and Rx */
  LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_2);
  LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_3);
}

/**
  * @brief  This function initiates TX and RX DMA transfers by enabling DMA channels
  * @param  None
  * @retval None
  */
void StartTransfers(void)
{
  /* Enable DMA RX Interrupt */
  LL_USART_EnableDMAReq_RX(USART1);

  /* Enable DMA TX Interrupt */
  LL_USART_EnableDMAReq_TX(USART1);
  
  /* Enable DMA Channel Rx */
  LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_5);

  /* Enable DMA Channel Tx */
  LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_4);
}

/**
  * @brief  Initialize LED2.
  * @param  None
  * @retval None
  */
void LED_Init(void)
{
  /* Enable the LED2 Clock */
  LED2_GPIO_CLK_ENABLE();

  /* Configure IO in output push-pull mode to drive external LED2 */
  LL_GPIO_SetPinMode(LED2_GPIO_PORT, LED2_PIN, LL_GPIO_MODE_OUTPUT);
  /* Reset value is LL_GPIO_OUTPUT_PUSHPULL */
  //LL_GPIO_SetPinOutputType(LED2_GPIO_PORT, LED2_PIN, LL_GPIO_OUTPUT_PUSHPULL);
  /* Reset value is LL_GPIO_SPEED_FREQ_LOW */
  //LL_GPIO_SetPinSpeed(LED2_GPIO_PORT, LED2_PIN, LL_GPIO_SPEED_FREQ_LOW);
  /* Reset value is LL_GPIO_PULL_NO */
  //LL_GPIO_SetPinPull(LED2_GPIO_PORT, LED2_PIN, LL_GPIO_PULL_NO);
}

/**
  * @brief  Turn-on LED2.
  * @param  None
  * @retval None
  */
void LED_On(void)
{
  /* Turn LED2 on */
  LL_GPIO_SetOutputPin(LED2_GPIO_PORT, LED2_PIN);
}

/**
  * @brief  Turn-off LED2.
  * @param  None
  * @retval None
  */
void LED_Off(void)
{
  /* Turn LED2 off */
  LL_GPIO_ResetOutputPin(LED2_GPIO_PORT, LED2_PIN);
}

/**
  * @brief  Set LED2 to Blinking mode for an infinite loop (toggle period based on value provided as input parameter).
  * @param  Period : Period of time (in ms) between each toggling of LED
  *   This parameter can be user defined values. Pre-defined values used in that example are :
  *     @arg LED_BLINK_FAST : Fast Blinking
  *     @arg LED_BLINK_SLOW : Slow Blinking
  *     @arg LED_BLINK_ERROR : Error specific Blinking
  * @retval None
  */
void LED_Blinking(uint32_t Period)
{
  /* Toggle LED2 in an infinite loop */
  while (1)
  {
    LL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);  
    LL_mDelay(Period);
  }
}

/**
  * @brief  Configures User push-button in GPIO or EXTI Line Mode.
  * @param  None 
  * @retval None
  */
void UserButton_Init(void)
{
  /* Enable the BUTTON Clock */
  USER_BUTTON_GPIO_CLK_ENABLE();
  
  /* Configure GPIO for BUTTON */
  LL_GPIO_SetPinMode(USER_BUTTON_GPIO_PORT, USER_BUTTON_PIN, LL_GPIO_MODE_INPUT);
  LL_GPIO_SetPinPull(USER_BUTTON_GPIO_PORT, USER_BUTTON_PIN, LL_GPIO_PULL_NO);
  
  /* Connect External Line to the GPIO*/
  USER_BUTTON_SYSCFG_SET_EXTI();

  /* Enable a rising trigger External line 13 Interrupt */
  USER_BUTTON_EXTI_LINE_ENABLE();
  USER_BUTTON_EXTI_FALLING_TRIG_ENABLE();

  /* Configure NVIC for USER_BUTTON_EXTI_IRQn */
  NVIC_SetPriority(USER_BUTTON_EXTI_IRQn, 3);  
  NVIC_EnableIRQ(USER_BUTTON_EXTI_IRQn); 
}

/**
  * @brief  Wait for User push-button press to start transfer.
  * @param  None 
  * @retval None
  */
  /*  */
void WaitForUserButtonPress(void)
{
  while (ubButtonPress == 0)
  {
    LL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
    LL_mDelay(LED_BLINK_FAST);
  }
  /* Ensure that LED2 is turned Off */
  LED_Off();
}

/**
  * @brief  Wait end of transfer and check if received Data are well.
  * @param  None 
  * @retval None
  */
void WaitAndCheckEndOfTransfer(void)
{
  /* 1 - Wait end of transmission from USART1 */
  while (ubUSART1TransmissionComplete != 1)
  {
  }
  /* Disable DMA1 Tx Channel */
  LL_DMA_DisableChannel(DMA1, LL_DMA_CHANNEL_4);

  /* 2 - Wait end of transmission from SPI1 */
  while (ubSPI1TransmissionComplete != 1)
  {
  }
  /* Disable DMA1 Tx Channel */
  LL_DMA_DisableChannel(DMA1, LL_DMA_CHANNEL_2);

  /* 3 - Wait end of reception from USART1 */
  while (ubUSART1ReceptionComplete != 1)
  {
  }
  /* Disable DMA1 Rx Channel */
  LL_DMA_DisableChannel(DMA1, LL_DMA_CHANNEL_5);

  /* 4 - Wait end of reception from SPI1 */
  while (ubSPI1ReceptionComplete != 1)
  {
  }
  /* Disable DMA1 Rx Channel */
  LL_DMA_DisableChannel(DMA1, LL_DMA_CHANNEL_3);

  /* 5 - Compare received data to transmitted one (USART1 => SPI1) */
  if(Buffercmp8((uint8_t*)aUSART1TxBuffer, (uint8_t*)aSPI1RxBuffer, ubUSART1NbDataToTransmit))
  {
    /* Processing Error */
    LED_Blinking(LED_BLINK_ERROR);    
  }
  /* 6 - Compare received data to transmitted one (SPI1 => USART1) */
  else if(Buffercmp8((uint8_t*)aSPI1TxBuffer, (uint8_t*)aUSART1RxBuffer, ubSPI1NbDataToTransmit))
  {
    /* Processing Error */
    LED_Blinking(LED_BLINK_ERROR);    
  }
  else
  {
    /* Turn On Led if data are well received */
    LED_On();
  }
}

/**
* @brief Compares two 8-bit buffers and returns the comparison result.
* @param pBuffer1: pointer to the source buffer to be compared to.
* @param pBuffer2: pointer to the second source buffer to be compared to the first.
* @param BufferLength: buffer's length.
* @retval   0: Comparison is OK (the two Buffers are identical)
*           Value different from 0: Comparison is NOK (Buffers are different)
*/
uint8_t Buffercmp8(uint8_t* pBuffer1, uint8_t* pBuffer2, uint8_t BufferLength)
{
  while (BufferLength--)
  {
    if (*pBuffer1 != *pBuffer2)
    {
      return 1;
    }

    pBuffer1++;
    pBuffer2++;
  }

  return 0;
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follows :
  *            System Clock source            = PLL (HSI)
  *            SYSCLK(Hz)                     = 170000000
  *            HCLK(Hz)                       = 170000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            PLL_M                          = 4
  *            PLL_N                          = 85
  *            PLL_P                          = 2
  *            PLL_Q                          = 2
  *            PLL_R                          = 2
  *            Flash Latency(WS)              = 8
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  /* Flash Latency configuration */
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_8);

  /* Enable boost mode to be able to reach 170MHz */
  LL_PWR_EnableRange1BoostMode();

  /* HSI configuration and activation */
  LL_RCC_HSI_Enable();
  while(LL_RCC_HSI_IsReady() != 1)
  {
  };

  /* Main PLL configuration and activation */
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI, LL_RCC_PLLM_DIV_4, 85, LL_RCC_PLLR_DIV_2);
  LL_RCC_PLL_Enable();
  LL_RCC_PLL_EnableDomain_SYS();
  while(LL_RCC_PLL_IsReady() != 1)
  {
  };

  /* Sysclk activation on the main PLL */
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_2);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {
  };

  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  /* Insure 1µs transition state at intermediate medium speed clock based on DWT */
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
  while(DWT->CYCCNT < 100);
  /* Set APB1 & APB2 prescaler*/
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);

  /* Set systick to 1ms in using frequency set to 170MHz */
  /* This frequency can be calculated through LL RCC macro */
  /* ex: __LL_RCC_CALC_PLLCLK_FREQ(__LL_RCC_CALC_HSI_FREQ(),
                                  LL_RCC_PLLM_DIV_4, 85, LL_RCC_PLLR_DIV_2)*/
  LL_Init1msTick(170000000);

  /* Update CMSIS variable (which can be updated also through SystemCoreClockUpdate function) */
  LL_SetSystemCoreClock(170000000);
}

/******************************************************************************/
/*   USER IRQ HANDLER TREATMENT Functions                                     */
/******************************************************************************/
/**
  * @brief  Function to manage User push-button
  * @param  None
  * @retval None
  */
void UserButton_Callback(void)
{
  /* Update User push-button variable : to be checked in waiting loop in main program */
  ubButtonPress = 1;
}

/**
  * @brief  Function called from DMA1 IRQ Handler when Tx transfer is completed (USART1)
  * @param  None
  * @retval None
  */
void USART1_DMA1_TransmitComplete_Callback(void)
{
  /* DMA Tx transfer completed */
  ubUSART1TransmissionComplete = 1;
}

/**
  * @brief  Function called from DMA1 IRQ Handler when Tx transfer is completed (SPI1)
  * @param  None
  * @retval None
  */
void SPI1_DMA1_TransmitComplete_Callback(void)
{
  /* DMA Tx transfer completed */
  ubSPI1TransmissionComplete = 1;
}

/**
  * @brief  Function called from DMA1 IRQ Handler when Rx transfer is completed (USART1)
  * @param  None
  * @retval None
  */
void USART1_DMA1_ReceiveComplete_Callback(void)
{
  /* DMA Rx transfer completed */
  ubUSART1ReceptionComplete = 1;
}

/**
  * @brief  Function called from DMA1 IRQ Handler when Rx transfer is completed (SPI1)
  * @param  None
  * @retval None
  */
void SPI1_DMA1_ReceiveComplete_Callback(void)
{
  /* DMA Rx transfer completed */
  ubSPI1ReceptionComplete = 1;
}

/**
  * @brief  Function called in case of error detected in USART IT Handler
  * @param  None
  * @retval None
  */
void USART_TransferError_Callback(void)
{
  /* Disable DMA1 Tx Channel */
  LL_DMA_DisableChannel(DMA1, LL_DMA_CHANNEL_4);

  /* Disable DMA1 Rx Channel */
  LL_DMA_DisableChannel(DMA1, LL_DMA_CHANNEL_5);

  /* Set LED2 to Blinking mode to indicate error occurs */
  LED_Blinking(LED_BLINK_ERROR);
}

/**
  * @brief  Function called in case of error detected in SPI IT Handler
  * @param  None
  * @retval None
  */
void SPI_TransferError_Callback(void)
{
  /* Disable DMA1 Tx Channel */
  LL_DMA_DisableChannel(DMA1, LL_DMA_CHANNEL_2);

  /* Disable DMA1 Rx Channel */
  LL_DMA_DisableChannel(DMA1, LL_DMA_CHANNEL_3);

  /* Set LED2 to Blinking mode to indicate error occurs */
  LED_Blinking(LED_BLINK_ERROR);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

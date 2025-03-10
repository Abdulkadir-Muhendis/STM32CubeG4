/**
  ******************************************************************************
  * @file    Adafruit_LCD_1_8_SD_Joystick/Src/sd.c
  * @author  MCD Application Team
  * @brief   This example code shows how to use the SD Driver
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32G4xx-Nucleo_Demo
  * @{
  */

/** @addtogroup Adafruit_LCD_1_8_SD_Joystick
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define BLOCK_START_ADDR         0     /* Block start address      */
#define NUM_OF_BLOCKS            2     /* Total number of blocks   */
#define BLOCKSIZE                512U  /* Size of blocks           */
#define BUFFER_WORDS_SIZE        ((BLOCKSIZE * NUM_OF_BLOCKS) >> 2) /* Total data size in bytes */

#define BSP_ERROR_NONE           0

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t aTxBuffer[BUFFER_WORDS_SIZE];
uint32_t aRxBuffer[BUFFER_WORDS_SIZE];

/* Private function prototypes -----------------------------------------------*/
static void SD_SetHint(void);
static void Fill_Buffer(uint32_t *pBuffer, uint32_t uwBufferLenght, uint32_t uwOffset);
static uint8_t Buffercmp(uint32_t* pBuffer1, uint32_t* pBuffer2, uint16_t BufferLength);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  SD Demo
  * @param  None
  * @retval None
  */
void SD_demo (void)
{
  int32_t SD_state = BSP_ERROR_NONE;

  SD_SetHint();
  SD_state = ADAFRUIT_802_SD_Init(0);
  ADAFRUIT_802_JOY_Init(JOY1,  JOY_MODE_EXTI, JOY_ALL);

  if(SD_state != BSP_ERROR_NONE)
  {
    GUI_DisplayStringAt(5, 90, (uint8_t *)"SD Initialization", LEFT_MODE);
    GUI_DisplayStringAt(5, 105, (uint8_t *)"     FAILED", LEFT_MODE);
    GUI_DisplayStringAt(5, 120, (uint8_t *)"SD Test Aborted.", LEFT_MODE);
  }
  else
  {
    GUI_DisplayStringAt(5, 75, (uint8_t *)"SD Init : OK.", LEFT_MODE);

    SD_state = ADAFRUIT_802_SD_Erase(0, BLOCK_START_ADDR, BLOCK_START_ADDR + NUM_OF_BLOCKS - 1);
        /* Wait until SD card is ready to use for new operation */
    while(ADAFRUIT_802_SD_GetCardState(0) != SD_TRANSFER_OK);

    if(SD_state != BSP_ERROR_NONE)
    {
      GUI_DisplayStringAt(5, 90, (uint8_t *)"SD ERASE : FAILED.", LEFT_MODE);
      GUI_DisplayStringAt(5, 105, (uint8_t *)"SD Test Aborted.", LEFT_MODE);
    }
    else
    {
      GUI_DisplayStringAt(5, 90, (uint8_t *)"SD ERASE : OK.", LEFT_MODE);

      /* Fill the buffer to write */
      Fill_Buffer(aTxBuffer, BUFFER_WORDS_SIZE, 0x22FF);
      SD_state = ADAFRUIT_802_SD_WriteBlocks(0, aTxBuffer, BLOCK_START_ADDR, NUM_OF_BLOCKS);

      if(SD_state != BSP_ERROR_NONE)
      {
        GUI_DisplayStringAt(5, 105, (uint8_t *)"SD WRITE : FAILED.", LEFT_MODE);
        GUI_DisplayStringAt(5, 120, (uint8_t *)"SD Test Aborted.", LEFT_MODE);
      }
      else
      {
        GUI_DisplayStringAt(5, 105, (uint8_t *)"SD WRITE : OK.", LEFT_MODE);
        SD_state = ADAFRUIT_802_SD_ReadBlocks(0, aRxBuffer, BLOCK_START_ADDR, NUM_OF_BLOCKS);
        if(SD_state != BSP_ERROR_NONE)
        {
          GUI_DisplayStringAt(5, 120, (uint8_t *)"SD READ : FAILED.", LEFT_MODE);
          GUI_DisplayStringAt(5, 135, (uint8_t *)"SD Test Aborted.", LEFT_MODE);
        }
        else
        {
          GUI_DisplayStringAt(5, 120, (uint8_t *)"SD READ : OK.", LEFT_MODE);
          if(Buffercmp(aTxBuffer, aRxBuffer, BUFFER_WORDS_SIZE) > 0)
          {
            GUI_DisplayStringAt(5, 135, (uint8_t *)"SD COMPARE : FAILED.", LEFT_MODE);
            GUI_DisplayStringAt(5, 150, (uint8_t *)"SD Test Aborted.", LEFT_MODE);
          }
          else
          {
            GUI_DisplayStringAt(5, 135, (uint8_t *)"SD Test : OK.", LEFT_MODE);
            GUI_DisplayStringAt(5, 150, (uint8_t *)"SD can be removed.", LEFT_MODE);
          }
        }
      }
    }
  }

  while (1)
  {
    /* Get the Joystick State */
    JoyState = ADAFRUIT_802_JOY_GetState(JOY1);

    if(JoyState == JOY_SEL)
    {
      return;
    }
  }
}

/**
  * @brief  Display SD Demo Hint
  * @param  None
  * @retval None
  */
static void SD_SetHint(void)
{
  uint32_t x_size;

  ADAFRUIT_802_LCD_GetXSize(0, &x_size);

  /* Clear the LCD */
  GUI_Clear(GUI_COLOR_WHITE);

  /* Set SD Demo description */
  GUI_FillRect(0, 0, x_size, 55, GUI_COLOR_BLUE);
  GUI_SetTextColor(GUI_COLOR_WHITE);
  GUI_SetBackColor(GUI_COLOR_BLUE);
  GUI_SetFont(&Font24);

  GUI_SetFont(&Font12);
  GUI_DisplayStringAt(0, 10, (uint8_t *)"SD Demo", CENTER_MODE);
  GUI_DisplayStringAt(0, 25, (uint8_t *)"Shows how to write", CENTER_MODE);
  GUI_DisplayStringAt(0, 40, (uint8_t *)"& read data on SD", CENTER_MODE);

  GUI_SetTextColor(GUI_COLOR_BLUE);
  GUI_SetBackColor(GUI_COLOR_WHITE);
}

/**
  * @brief  Fills buffer with user predefined data.
  * @param  pBuffer: pointer on the buffer to fill
  * @param  uwBufferLenght: size of the buffer to fill
  * @param  uwOffset: first value to fill on the buffer
  * @retval None
  */
static void Fill_Buffer(uint32_t *pBuffer, uint32_t uwBufferLenght, uint32_t uwOffset)
{
  uint32_t tmpIndex = 0;

  /* Put in global buffer different values */
  for (tmpIndex = 0; tmpIndex < uwBufferLenght; tmpIndex++ )
  {
    pBuffer[tmpIndex] = tmpIndex + uwOffset;
  }
}

/**
  * @brief  Compares two buffers.
  * @param  pBuffer1, pBuffer2: buffers to be compared.
  * @param  BufferLength: buffer's length
  * @retval 1: pBuffer identical to pBuffer1
  *         0: pBuffer differs from pBuffer1
  */
static uint8_t Buffercmp(uint32_t* pBuffer1, uint32_t* pBuffer2, uint16_t BufferLength)
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
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

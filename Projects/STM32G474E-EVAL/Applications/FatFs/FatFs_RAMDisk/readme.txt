/**
  @page FatFs_RAMDisk   FatFs with RAM disk drive application
 
  @verbatim
  ******************** (C) COPYRIGHT 2019 STMicroelectronics *******************
  * @file    FatFs/FatFs_RAMDisk/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the FatFs with RAM disk drive application
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

@par Application Description

This application provides a description on how to use STM32Cube firmware with FatFs 
middleware component as a generic FAT file system module, in order to develop an
application exploiting FatFs offered features with RAM disk (SDRAM) drive 
configuration. 

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock
(SYSCLK) to run at 170 MHz.
 
The application is based on writing and reading back a text file from a drive,
and it's performed using FatFs APIs to access the FAT volume as described
in the following steps: 

 - Link the SDRAM disk I/O driver;
 - Register the file system object (mount) to the FatFs module for the SDRAM drive;
 - Create a FAT file system (format) on the SDRAM drive;
 - Create and Open new text file object with write access;
 - Write data to the text file;
 - Close the open text file;
 - Open text file object with read access;
 - Read back data from the text file;
 - Close the open text file;
 - Check on read data from text file;

It is worth noting that the application manages any error occurred during the 
access to FAT volume, when using FatFs APIs.

It is possible to fine tune needed FatFs features by modifying defines values 
in FatFs configuration file �ffconf.h� available under the project includes 
directory, in a way to fit the application requirements. 
 
STM32G474E-EVAL Rev B's board's LEDs can be used to monitor the application status:
  - LED1 ON when the application runs successfully.
  - LED3 ON when any error occurs. 


@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

For more details about FatFs implementation on STM32Cube, please refer to UM1721 "Developing Applications 
on STM32Cube with FatFs".


@par Directory contents
 
  - FatFs/FatFs_RAMDisk/Core/Inc/stm32g4xx_hal_conf.h    HAL configuration file
  - FatFs/FatFs_RAMDisk/Core/Inc/stm32g4xx_it.h          Interrupt handlers header file
  - FatFs/FatFs_RAMDisk/Core/Inc/main.h                        Main program header file
  - FatFs/FatFs_RAMDisk/FATFS/Target/sdram_diskio.h            FatFS sdram diskio driver header file
  - FatFs/FatFs_RAMDisk/FATFS/Target/ffconf.h                  FAT file system module configuration file   
  - FatFs/FatFs_RAMDisk/Core/Src/stm32g4xx_it.c          Interrupt handlers
  - FatFs/FatFs_RAMDisk/Core/Src/main.c                        Main program
  - FatFs/FatFs_RAMDisk/FATFS/Target/sdram_diskio.c            FatFS sdram diskio driver implementation
  - FatFs/FatFs_RAMDisk/Core/Src/system_stm32g4xx.c      stm32g4xx system clock configuration file
  - FatFs/FatFs_RAMDisk/FATFS/App/app_fatfs.c                  FatFs application code
  - FatFs/FatFs_RAMDisk/FATFS/App/app_fatfs.h                  Header file for App_fatfs.c file    
 
@par Hardware and Software environment

  - This application runs on STM32G474QETx devices.
    
  - This application has been tested with STMicroelectronics STM32G474E-EVAL Rev B  
    evaluation boards and can be easily tailored to any other supported device 
    and development board.  


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the application

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
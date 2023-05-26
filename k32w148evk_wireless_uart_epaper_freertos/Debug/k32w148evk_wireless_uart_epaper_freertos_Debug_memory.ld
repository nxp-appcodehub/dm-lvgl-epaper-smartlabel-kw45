/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright (c) 2008-2013 Code Red Technologies Ltd,
 * Copyright 2015, 2018-2019 NXP
 * (c) NXP Semiconductors 2013-2024
 * Generated linker script file for K32W1480xxxA
 * Created from memory.ldt by FMCreateLinkMemory
 * Using Freemarker v2.3.30
 * MCUXpresso IDE v11.7.0 [Build 9198] [2023-01-17] on 26 janv. 2024 à 11:34:08
 */

MEMORY
{
  /* Define each memory region */
  PROGRAM_FLASH (rx) : ORIGIN = 0x0, LENGTH = 0xf6000 /* 984K bytes (alias Flash) */  
  NVM_region (rx) : ORIGIN = 0xf6000, LENGTH = 0x8000 /* 32K bytes (alias Flash2) */  
  PROD_DATA (rx) : ORIGIN = 0xfe000, LENGTH = 0x2000 /* 8K bytes (alias Flash3) */  
  SRAM (rwx) : ORIGIN = 0x20000400, LENGTH = 0x1bc00 /* 111K bytes (alias RAM) */  
  RAM_VECTOR_TABLE (rwx) : ORIGIN = 0x20000000, LENGTH = 0x400 /* 1K bytes (alias RAM2) */  
  rpmsg_sh_mem (rwx) : ORIGIN = 0x489c8800, LENGTH = 0x1800 /* 6K bytes (alias RAM3) */  
}

  /* Define a symbol for the top of each memory region */
  __base_PROGRAM_FLASH = 0x0  ; /* PROGRAM_FLASH */  
  __base_Flash = 0x0 ; /* Flash */  
  __top_PROGRAM_FLASH = 0x0 + 0xf6000 ; /* 984K bytes */  
  __top_Flash = 0x0 + 0xf6000 ; /* 984K bytes */  
  __base_NVM_region = 0xf6000  ; /* NVM_region */  
  __base_Flash2 = 0xf6000 ; /* Flash2 */  
  __top_NVM_region = 0xf6000 + 0x8000 ; /* 32K bytes */  
  __top_Flash2 = 0xf6000 + 0x8000 ; /* 32K bytes */  
  __base_PROD_DATA = 0xfe000  ; /* PROD_DATA */  
  __base_Flash3 = 0xfe000 ; /* Flash3 */  
  __top_PROD_DATA = 0xfe000 + 0x2000 ; /* 8K bytes */  
  __top_Flash3 = 0xfe000 + 0x2000 ; /* 8K bytes */  
  __base_SRAM = 0x20000400  ; /* SRAM */  
  __base_RAM = 0x20000400 ; /* RAM */  
  __top_SRAM = 0x20000400 + 0x1bc00 ; /* 111K bytes */  
  __top_RAM = 0x20000400 + 0x1bc00 ; /* 111K bytes */  
  __base_RAM_VECTOR_TABLE = 0x20000000  ; /* RAM_VECTOR_TABLE */  
  __base_RAM2 = 0x20000000 ; /* RAM2 */  
  __top_RAM_VECTOR_TABLE = 0x20000000 + 0x400 ; /* 1K bytes */  
  __top_RAM2 = 0x20000000 + 0x400 ; /* 1K bytes */  
  __base_rpmsg_sh_mem = 0x489c8800  ; /* rpmsg_sh_mem */  
  __base_RAM3 = 0x489c8800 ; /* RAM3 */  
  __top_rpmsg_sh_mem = 0x489c8800 + 0x1800 ; /* 6K bytes */  
  __top_RAM3 = 0x489c8800 + 0x1800 ; /* 6K bytes */  

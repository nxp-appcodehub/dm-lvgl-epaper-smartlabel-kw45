/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright (c) 2008-2013 Code Red Technologies Ltd,
 * Copyright 2015, 2018-2019 NXP
 * (c) NXP Semiconductors 2013-2024
 * Generated linker script file for K32W1480xxxA
 * Created from linkscript.ldt by FMCreateLinkLibraries
 * Using Freemarker v2.3.30
 * MCUXpresso IDE v11.7.0 [Build 9198] [2023-01-17] on 26 janv. 2024 à 11:34:08
 */

INCLUDE "k32w148evk_wireless_uart_epaper_freertos_Debug_library.ld"
INCLUDE "k32w148evk_wireless_uart_epaper_freertos_Debug_memory.ld"

ENTRY(ResetISR)

SECTIONS
{
     .text_Flash2 : ALIGN(4)
    {
       FILL(0xff)
        *(.text_Flash2) /* for compatibility with previous releases */
        *(.text_NVM_region) /* for compatibility with previous releases */
        *(.text.$Flash2)
        *(.text.$NVM_region)
        *(.text_Flash2.*) /* for compatibility with previous releases */
        *(.text_NVM_region.*) /* for compatibility with previous releases */
        *(.text.$Flash2.*)
        *(.text.$NVM_region.*)
        *(.rodata.$Flash2)
        *(.rodata.$NVM_region)
        *(.rodata.$Flash2.*)
        *(.rodata.$NVM_region.*)            } > NVM_region

    .text_Flash3 : ALIGN(4)
    {
       FILL(0xff)
        *(.text_Flash3) /* for compatibility with previous releases */
        *(.text_PROD_DATA) /* for compatibility with previous releases */
        *(.text.$Flash3)
        *(.text.$PROD_DATA)
        *(.text_Flash3.*) /* for compatibility with previous releases */
        *(.text_PROD_DATA.*) /* for compatibility with previous releases */
        *(.text.$Flash3.*)
        *(.text.$PROD_DATA.*)
        *(.rodata.$Flash3)
        *(.rodata.$PROD_DATA)
        *(.rodata.$Flash3.*)
        *(.rodata.$PROD_DATA.*)            } > PROD_DATA

    /* MAIN TEXT SECTION */
    .text : ALIGN(4)
    {
        FILL(0xff)
        __vectors_start__ = ABSOLUTE(.) ;
        KEEP(*(.isr_vector))
        /* Global Section Table */
        . = ALIGN(4) ;
        __section_table_start = .;
        __data_section_table = .;
        LONG(LOADADDR(.data));
        LONG(    ADDR(.data));
        LONG(  SIZEOF(.data));
        LONG(LOADADDR(.data_RAM2));
        LONG(    ADDR(.data_RAM2));
        LONG(  SIZEOF(.data_RAM2));
        LONG(LOADADDR(.data_RAM3));
        LONG(    ADDR(.data_RAM3));
        LONG(  SIZEOF(.data_RAM3));
        __data_section_table_end = .;
        __bss_section_table = .;
        LONG(    ADDR(.bss));
        LONG(  SIZEOF(.bss));
        LONG(    ADDR(.bss_RAM2));
        LONG(  SIZEOF(.bss_RAM2));
        LONG(    ADDR(.bss_RAM3));
        LONG(  SIZEOF(.bss_RAM3));
        __bss_section_table_end = .;
        __section_table_end = . ;
        /* End of Global Section Table */

        *(.after_vectors*)


            __start_VERSION_TAGS = .;
            KEEP(*(.VERSION_TAGS))
            __stop_VERSION_TAGS = .;
            /* NVM table section */
            __start_NVM_TABLE = .;
            KEEP(*(.NVM_TABLE))
            __stop_NVM_TABLE = .;

            *(.text*)

       KEEP(*freertos*/tasks.o(.rodata*)) /* FreeRTOS Debug Config */
       *(.rodata .rodata.* .constdata .constdata.*)
       . = ALIGN(4);
    } > PROGRAM_FLASH
    /*
     * for exception handling/unwind - some Newlib functions (in common
     * with C++ and STDC++) use this.
     */
    .ARM.extab : ALIGN(4)
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > PROGRAM_FLASH

    .ARM.exidx : ALIGN(4)
    {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > PROGRAM_FLASH
 
    _etext = .;

    .NVM_region :
    {
        FILL(0xFFFFFFFF)
        . = ORIGIN(NVM_region) + LENGTH(NVM_region) - 1;
        BYTE(0xFF);
    } > NVM_region

    /* DATA section for RAM_VECTOR_TABLE */

    .data_RAM2 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM2 = .) ;
        PROVIDE(__start_data_RAM_VECTOR_TABLE = .) ;
        *(.ramfunc.$RAM2)
        *(.ramfunc.$RAM_VECTOR_TABLE)
        *(.data.$RAM2)
        *(.data.$RAM_VECTOR_TABLE)
        *(.data.$RAM2.*)
        *(.data.$RAM_VECTOR_TABLE.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM2 = .) ;
        PROVIDE(__end_data_RAM_VECTOR_TABLE = .) ;
     } > RAM_VECTOR_TABLE AT>PROGRAM_FLASH

    /* DATA section for rpmsg_sh_mem */

    .data_RAM3 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM3 = .) ;
        PROVIDE(__start_data_rpmsg_sh_mem = .) ;
        *(.ramfunc.$RAM3)
        *(.ramfunc.$rpmsg_sh_mem)
        *(.data.$RAM3)
        *(.data.$rpmsg_sh_mem)
        *(.data.$RAM3.*)
        *(.data.$rpmsg_sh_mem.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM3 = .) ;
        PROVIDE(__end_data_rpmsg_sh_mem = .) ;
     } > rpmsg_sh_mem AT>PROGRAM_FLASH

    /* MAIN DATA SECTION */
    .uninit_RESERVED (NOLOAD) : ALIGN(4)
    {
        _start_uninit_RESERVED = .;
        KEEP(*(.bss.$RESERVED*))
       . = ALIGN(4) ;
        _end_uninit_RESERVED = .;
    } > SRAM AT> SRAM

    /* Main DATA section (SRAM) */
    .data : ALIGN(4)
    {
       FILL(0xff)
       _data = . ;
       PROVIDE(__start_data_RAM = .) ;
       PROVIDE(__start_data_SRAM = .) ;
       *(vtable)
       *(.ramfunc*)
       KEEP(*(CodeQuickAccess))
       KEEP(*(DataQuickAccess))
       *(RamFunction)
       *(.data*)
       . = ALIGN(4) ;
       _edata = . ;
       PROVIDE(__end_data_RAM = .) ;
       PROVIDE(__end_data_SRAM = .) ;
    } > SRAM AT>PROGRAM_FLASH

    /* BSS section for RAM_VECTOR_TABLE */
    .bss_RAM2 : ALIGN(4)
    {
       PROVIDE(__start_bss_RAM2 = .) ;
       PROVIDE(__start_bss_RAM_VECTOR_TABLE = .) ;
       *(.bss.$RAM2)
       *(.bss.$RAM_VECTOR_TABLE)
       *(.bss.$RAM2.*)
       *(.bss.$RAM_VECTOR_TABLE.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM2 = .) ;
       PROVIDE(__end_bss_RAM_VECTOR_TABLE = .) ;
    } > RAM_VECTOR_TABLE AT> RAM_VECTOR_TABLE

    /* BSS section for rpmsg_sh_mem */
    .bss_RAM3 : ALIGN(4)
    {
       PROVIDE(__start_bss_RAM3 = .) ;
       PROVIDE(__start_bss_rpmsg_sh_mem = .) ;
       *(.bss.$RAM3)
       *(.bss.$rpmsg_sh_mem)
       *(.bss.$RAM3.*)
       *(.bss.$rpmsg_sh_mem.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM3 = .) ;
       PROVIDE(__end_bss_rpmsg_sh_mem = .) ;
    } > rpmsg_sh_mem AT> rpmsg_sh_mem

    /* MAIN BSS SECTION */
    .bss : ALIGN(4)
    {
        _bss = .;
        PROVIDE(__start_bss_RAM = .) ;
        PROVIDE(__start_bss_SRAM = .) ;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4) ;
        _ebss = .;
        PROVIDE(__end_bss_RAM = .) ;
        PROVIDE(__end_bss_SRAM = .) ;
        PROVIDE(end = .);
    } > SRAM AT> SRAM

    /* NOINIT section for RAM_VECTOR_TABLE */
    .noinit_RAM2 (NOLOAD) : ALIGN(4)
    {
       PROVIDE(__start_noinit_RAM2 = .) ;
       PROVIDE(__start_noinit_RAM_VECTOR_TABLE = .) ;
       *(.noinit.$RAM2)
       *(.noinit.$RAM_VECTOR_TABLE)
       *(.noinit.$RAM2.*)
       *(.noinit.$RAM_VECTOR_TABLE.*)
       . = ALIGN(4) ;
       PROVIDE(__end_noinit_RAM2 = .) ;
       PROVIDE(__end_noinit_RAM_VECTOR_TABLE = .) ;
    } > RAM_VECTOR_TABLE AT> RAM_VECTOR_TABLE

    /* NOINIT section for rpmsg_sh_mem */
    .noinit_RAM3 (NOLOAD) : ALIGN(4)
    {
       PROVIDE(__start_noinit_RAM3 = .) ;
       PROVIDE(__start_noinit_rpmsg_sh_mem = .) ;
       *(.noinit.$RAM3)
       *(.noinit.$rpmsg_sh_mem)
       *(.noinit.$RAM3.*)
       *(.noinit.$rpmsg_sh_mem.*)
       . = ALIGN(4) ;
       PROVIDE(__end_noinit_RAM3 = .) ;
       PROVIDE(__end_noinit_rpmsg_sh_mem = .) ;
    } > rpmsg_sh_mem AT> rpmsg_sh_mem

    /* DEFAULT NOINIT SECTION */
    .noinit (NOLOAD): ALIGN(4)
    {
        _noinit = .;
        PROVIDE(__start_noinit_RAM = .) ;
        PROVIDE(__start_noinit_SRAM = .) ;
        *(.noinit*)
         . = ALIGN(4) ;
        _end_noinit = .;
       PROVIDE(__end_noinit_RAM = .) ;
       PROVIDE(__end_noinit_SRAM = .) ;        
    } > SRAM AT> SRAM

    /* Reserve and place Heap within memory map */
    _HeapSize = 0x0;
    .heap (NOLOAD) :  ALIGN(4)
    {
        _pvHeapStart = .;
        . += _HeapSize;
        . = ALIGN(4);
        _pvHeapLimit = .;
    } > SRAM

     _StackSize = 0x400;
     /* Reserve space in memory for Stack */
    .heap2stackfill (NOLOAD) :
    {
        . += _StackSize;
    } > SRAM
    /* Locate actual Stack in memory map */
    .stack ORIGIN(SRAM) + LENGTH(SRAM) - _StackSize - 0 (NOLOAD) :  ALIGN(4)
    {
        _vStackBase = .;
        . = ALIGN(4);
        _vStackTop = . + _StackSize;
    } > SRAM

    /* Provide basic symbols giving location and size of main text
     * block, including initial values of RW data sections. Note that
     * these will need extending to give a complete picture with
     * complex images (e.g multiple Flash banks).
     */
    _image_start = LOADADDR(.text);
    _image_end = LOADADDR(.data) + SIZEOF(.data);
    _image_size = _image_end - _image_start;

    /* Linker Symbols */
    _RAM_START_ = 0x1FFFC000;
    _RAM_END_ = 0x2000BFFF;
    
    __RAM_VECTOR_TABLE_SIZE_BYTES = 0x400;
    __VECTOR_RAM = __base_RAM_VECTOR_TABLE;
    __VECTOR_TABLE = __base_PROGRAM_FLASH;

    __FIRMWARE_END_ADDRESS = DEFINED(gFirmwareTopAddr_c) ? gFirmwareTopAddr_c : __top_RAM;
	__HEAP_end__ = DEFINED(gUseStackEnd_d) ? _vStackBase -1 : __FIRMWARE_END_ADDRESS;
	__CSTACK_end__ = DEFINED(gUseStackEnd_d) ? __FIRMWARE_END_ADDRESS : __VECTOR_RAM - 1;
    INT_STORAGE_SECTOR_SIZE = 0x2000;
    INT_STORAGE_START = DEFINED(__base_INT_STORAGE) ? __base_INT_STORAGE : 0;
    INT_STORAGE_END =  DEFINED(__top_INT_STORAGE) ? __top_INT_STORAGE : 0;
    INT_STORAGE_SIZE = INT_STORAGE_END - INT_STORAGE_START;
    
    NV_STORAGE_START_ADDRESS = DEFINED(__base_NVM_region) ? __base_NVM_region : 0;
    NV_STORAGE_END_ADDRESS = DEFINED(__top_NVM_region) ? __top_NVM_region : 0;
    NV_STORAGE_SECTOR_SIZE = 0x2000;
    NV_STORAGE_MAX_SECTORS = (NV_STORAGE_END_ADDRESS - NV_STORAGE_START_ADDRESS) / NV_STORAGE_SECTOR_SIZE;

    PROD_DATA_BASE_ADDR = __base_PROD_DATA;
    m_warmboot_stack_end = DEFINED(__top_WARMBOOT_STACK) ? __top_WARMBOOT_STACK : 0;
    m_ram_img_end = DEFINED(gUseNVMLink_d) ? NV_STORAGE_START_ADDRESS - 1 : PROD_DATA_BASE_ADDR - 1;
    m_max_ram_img_size = DEFINED(gRamImageSizeInFlash_c) ? gRamImageSizeInFlash_c : 0x0;
    m_ram_img_start = m_ram_img_end - m_max_ram_img_size + 1;
    m_hadmbuff_start = __base_RAM_VECTOR_TABLE + 0x400;
    m_hadmbuff_size  = 0x2000;
    firmware_ram_upper_limit = __CSTACK_end__;
    firmware_ram_lower_limit = __VECTOR_RAM;}
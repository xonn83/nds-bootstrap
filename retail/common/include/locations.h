#ifndef LOCATIONS_H
#define LOCATIONS_H

#define EXCEPTION_STACK_LOCATION 0x23EFFFC

#define ROM_FILE_LOCATION         0x37D5000
#define ROM_FILE_LOCATION_MAINMEM 0x277FFC0
#define SAV_FILE_LOCATION (ROM_FILE_LOCATION + 32) //+ sizeof(aFile)
#define SAV_FILE_LOCATION_MAINMEM 0x277FFE0

#define LOAD_CRT0_LOCATION 0x06860000 // LCDC_BANK_D

#define CARDENGINE_ARM7_BUFFERED_LOCATION            0x027CD000
#define CARDENGINE_ARM9_BUFFERED_LOCATION            0x027DF000
#define CARDENGINE_ARM9_RELOC_BUFFERED_LOCATION      0x027E2000
#define CARDENGINE_ARM9_DLDI_BUFFERED_LOCATION       0x027E5000
#define DSI_BLOWFISH_LOCATION                        0x027E9000
#define CARDENGINE_ARM9_SDK5_BUFFERED_LOCATION       0x027EC000
#define CARDENGINE_ARM9_SDK5_DLDI_BUFFERED_LOCATION  0x027EF000

#define CARDENGINE_ARM7_LOCATION           0x037C0000
#define CARDENGINE_ARM9_LOCATION           0x02700000
#define CARDENGINE_ARM9_CACHED_LOCATION    0x023DE000
#define CARDENGINE_ARM9_DLDI_LOCATION      0x023DC000
#define CARDENGINE_ARM9_SDK5_LOCATION      0x023FD000
#define CARDENGINE_ARM9_SDK5_DLDI_LOCATION 0x023F9000
#define CARDENGINE_ARM9_GSDD_LOCATION      0x037F0000 // WRAM-A slot 0

#define CARDENGINE_SHARED_ADDRESS 0x027FFB0C

//#define TEMP_MEM 0x02FFE000 // __DSiHeader

#define NDS_HEADER_4MB     0x023FFE00
#define NDS_HEADER         0x027FFE00
#define NDS_HEADER_SDK5    0x02FFFE00 // __NDSHeader
#define NDS_HEADER_POKEMON 0x027FF000

#define ARM9_START_ADDRESS_4MB_LOCATION  (NDS_HEADER_4MB + 0x1F4)  //0x023FFFF4
#define ARM9_START_ADDRESS_LOCATION      (NDS_HEADER + 0x1F4)      //0x027FFFF4
#define ARM9_START_ADDRESS_SDK5_LOCATION (NDS_HEADER_SDK5 + 0x1F4) //0x02FFFFF4

#define ROM_LOCATION          0x0C800000
#define ROM_SDK5_LOCATION     0x0D000000

#define CACHE_ADRESS_START             0x0C800000
#define CACHE_ADRESS_START_low         0x0C480000
#define retail_CACHE_ADRESS_START_SDK5 0x0C800000	// Size is 0x700000

//#define retail_CACHE_ADRESS_SIZE      0x800000
//#define retail_CACHE_ADRESS_SIZE_low  0x280000
//#define retail_CACHE_ADRESS_SIZE_SDK5 0x700000

#define retail_CACHE_SLOTS_32KB      0x100
#define CACHE_SLOTS_32KB_low         0x50
#define retail_CACHE_SLOTS_32KB_SDK5 0xE0

#define dev_CACHE_ADRESS_START_SDK5 0x0D000000

//#define dev_CACHE_ADRESS_SIZE      0x1800000
//#define dev_CACHE_ADRESS_SIZE_SDK5 0x1000000

#define dev_CACHE_SLOTS_32KB      0x300
#define dev_CACHE_SLOTS_32KB_SDK5 0x200

//#define HGSS_CACHE_ADRESS_SIZE 0x1E0000

#define HGSS_CACHE_SLOTS 0xF

#endif // LOCATIONS_H

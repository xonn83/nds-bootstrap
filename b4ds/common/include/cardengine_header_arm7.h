#ifndef CARDENGINE_HEADER_ARM7_H
#define CARDENGINE_HEADER_ARM7_H

#include <nds/ndstypes.h>
#include "module_params.h"

//
// ARM7 cardengine patches of ARM7 functions
//
typedef struct cardengineArm7PatchesArm7Functions {
    u32 eepromProtect;
    u32 eepromPageErase;
    u32 eepromPageVerify;
    u32 eepromPageWrite;
    u32 eepromPageProg;
    u32 eepromRead;
    u32 cardRead;
    u32 cardId;
    u32 saveCluster;
} __attribute__ ((__packed__)) cardengineArm7PatchesArm7Functions;


//
// ARM7 cardengine patches of ARM7 thumb functions
//
typedef struct cardengineArm7PatchesArm7FunctionsThumb {
    u32 eepromProtect;
    u32 eepromPageErase;
    u32 eepromPageVerify;
    u32 eepromPageWrite;
    u32 eepromPageProg;
    u32 eepromRead;
    u32 cardRead;
    u32 cardId;
} __attribute__ ((__packed__)) cardengineArm7PatchesArm7FunctionsThumb;

//
// ARM7 cardengine patches
//
typedef struct cardengineArm7Patches {
    u32* card_pull_out_arm9;
    u32 vblankHandler;
    u32 card_pull;
    u32 cacheFlushRef;
    u32 readCachedRef;
    cardengineArm7PatchesArm7Functions* arm7Functions;
    cardengineArm7PatchesArm7FunctionsThumb* arm7FunctionsThumb;
} __attribute__ ((__packed__)) cardengineArm7Patches;

//
// ARM7 cardengine
//
typedef struct cardengineArm7 {
    cardengineArm7Patches* patches;
    u32 intr_vblank_orig_return;
    const module_params_t* moduleParams;
    u32 cardStruct;
    u32 language;

} __attribute__ ((__packed__)) cardengineArm7;

#endif // CARDENGINE_HEADER_ARM7_H

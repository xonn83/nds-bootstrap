/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2014-2015, Normmatt
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the GNU General Public License Version 2, as described below:
 *
 * This file is free software: you may copy, redistribute and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 2 of the License, or (at your
 * option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://www.gnu.org/licenses/.
 */

#include <stddef.h> // NULL
#include <nds/ndstypes.h>
#include <nds/bios.h>
#include <nds/debug.h>
#include <nds/ipc.h>

#include "my_sdmmc.h"
#include "my_disc_io.h"


extern vu32* volatile sharedAddr;

/* return true if the command is completed and false if it is still ongoing */
static bool sdmmc_check_command_ndma(u32 cmd, int ndmaSlot)
{
	return false;        
}

static void sdmmc_send_command_ndma(u32 cmd, u32 args, int ndmaSlot)
{
}

int my_sdmmc_sdcard_writesectors(u32 sector_no, u32 numsectors, const u8 *in, int ndmaSlot)
{
	return false;
}

int my_sdmmc_sdcard_readsector(u32 sector_no, u8 *out, u32 startOffset, u32 endOffset)
{
	u32 commandRead = 0x53445231;
	int res;

	sharedAddr[0] = sector_no;
	sharedAddr[1] = (vu32)out;
	sharedAddr[2] = startOffset;
	sharedAddr[3] = endOffset;
	sharedAddr[4] = commandRead;

    IPC_SendSync(0x4);
	while (sharedAddr[4] == commandRead);
	res = sharedAddr[4];
	sharedAddr[0] = 0;
	sharedAddr[1] = 0;
	sharedAddr[2] = 0;
	sharedAddr[3] = 0;
	sharedAddr[4] = 0;
	return res;
}

int my_sdmmc_sdcard_readsectors(u32 sector_no, u32 numsectors, u8 *out, int ndmaSlot)
{
	u32 commandRead = 0x53445244;
	int res;

	sharedAddr[0] = sector_no;
	sharedAddr[1] = numsectors;
	sharedAddr[2] = (vu32)out;
	sharedAddr[3] = ndmaSlot;
	sharedAddr[4] = commandRead;

    IPC_SendSync(0x4);
	while (sharedAddr[4] == commandRead);
	res = sharedAddr[4];
	sharedAddr[0] = 0;
	sharedAddr[1] = 0;
	sharedAddr[2] = 0;
	sharedAddr[3] = 0;
	sharedAddr[4] = 0;
	return res;
}

bool my_sdmmc_sdcard_check_command(int cmd, int ndmaSlot) 
{
    return sdmmc_check_command_ndma(cmd,ndmaSlot);    
}

int my_sdmmc_sdcard_readsectors_nonblocking(u32 sector_no, u32 numsectors, u8 *out, int ndmaSlot)
{
	return 0x33C12;
}

int my_sdmmc_get_cid(bool isNand, u32 *info)
{
	return 0;
}

#ifndef IPS_H
#define IPS_H

void applyIpsPatch(const tNDSHeader* ndsHeader, u8* ipsbyte, bool arm9Only, bool higherMem, bool ROMinRAM);

#endif // IPS_H

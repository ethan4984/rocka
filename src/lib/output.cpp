#include <lib/output.h>

namespace kernel {

uint32_t mmioHandler::mmioBaseAddr = 0;
uint32_t mmioHandler::boardType = 0;

void mmioHandler::init() {
    asm volatile ("mrs %0, midr_el1" : "=r"(boardType));
    boardType = (boardType >> 4) & 0xfff;

    switch(boardType) {
        case 0xb76: // raspi1 / raspi0
            mmioBaseAddr = 0x2000000;
            break;
        case 0xc07: // raspi2 
            mmioBaseAddr = 0x3f00000;
            break;
        case 0xd03: // raspi3
            mmioBaseAddr = 0x3f00000;
            break;
        case 0xd08: // raspi4
            mmioBaseAddr = 0xfe00000;
            break;
        default: // we got a problem if this is ever ran
            mmioBaseAddr = 0x69;
    }
}

uint32_t mmioHandler::read(uint32_t reg) {
    return *(uint32_t*)reg;
}

void mmioHandler::write(uint32_t reg, uint32_t data) {
    *(uint32_t*)reg = data;
}

}
#include <kernel/drivers/mmio.h>

namespace kernel {

uint32_t mmioHandler::mmioBaseAddr = 0;
uint32_t mmioHandler::gpioBaseAddr = 0;
uint32_t mmioHandler::uartBaseAddr = 0;
uint32_t mmioHandler::boardType = 0;

void mmioHandler::init() {
    asm volatile ("mrs %0, midr_el1" : "=r"(boardType));
    boardType = (boardType >> 4) & 0xfff;

    switch(boardType) {
        case 0xb76: // raspi1 / raspi0
            mmioBaseAddr = 0x20000000;
            break;
        case 0xc07: // raspi2 
            mmioBaseAddr = 0x3f000000;
            break;
        case 0xd03: // raspi3
            mmioBaseAddr = 0x3f000000;
            break;
        case 0xd08: // raspi4
            mmioBaseAddr = 0xfe000000;
            break;
        default: // we got a problem if this is ever ran
            mmioBaseAddr = 0xf; // once kpanic is implemented, do one here
    }

    gpioBaseAddr = mmioBaseAddr + 0x200000;
    uartBaseAddr = gpioBaseAddr + 0x1000;
}

uint32_t mmioHandler::read(uint64_t reg) {
    return *(volatile uint32_t*)reg;
}

void mmioHandler::write(uint64_t reg, uint32_t data) {
    *(volatile uint32_t*)reg = data;
}

}

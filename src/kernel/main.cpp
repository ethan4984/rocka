#include <kernel/drivers/mmio.h>
#include <kernel/drivers/uart.h>
#include <lib/memUtils.h>
#include <lib/output.h>
#include <stdint.h>
#include <stddef.h>

extern uint64_t bssBegin;
extern uint64_t bssEnd;

namespace kernel {

extern "C" void kernelMain(uint64_t dtb_ptr32, uint64_t x1, uint64_t x2, uint64_t x3) {
    memset8((uint8_t*)bssBegin, 0, bssEnd- bssBegin); // zero out .bss

    mmio.init();
    
    uart.init();

    for(;;);
}

}

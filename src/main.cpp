#include <lib/memUtils.h>
#include <lib/output.h>
#include <stdint.h>

extern uint32_t bssBegin;
extern uint32_t bssEnd;

namespace kernel {

extern "C" void kernelMain(uint64_t dtb_ptr32, uint64_t x1, uint64_t x2, uint64_t x3) {
    memset8((uint8_t*)bssBegin, 0, bssEnd- bssBegin); // zero out .bss

    mmio.init();

    for(;;);
}

}

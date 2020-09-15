#include <lib/memUtils.h>
#include <stdint.h>

extern uint32_t bssBegin;
extern uint32_t bssEnd;

namespace kernel {

extern "C" void kernelMain(uint64_t dtb_ptr32, uint64_t x1, uint64_t x2, uint64_t x3) {
    asm volatile (  "ldr x5, =kernelMain\n"
                    "mov sp, x5" // initalize the stack
                 );

    for(;;);
}

}

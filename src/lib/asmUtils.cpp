#include <lib/asmUtils.h>

namespace kernel {

void wait(uint32_t cnt) {
    asm volatile("__delay_%=: subs %[cnt], %[cnt], #1; bne __delay_%=\n" : "=r"(cnt): [cnt]"0"(cnt) : "cc");
}

}

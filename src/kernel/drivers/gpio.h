#pragma once

#include <kernel/drivers/uart.h>

#define GPIO_REG_GPFSEL0 (gpioBaseAddr + 0x0)
#define GPIO_REG_GPFSEL1 (gpioBaseAddr + 0x4)
#define GPIO_REG_GPFSEL2 (gpioBaseAddr + 0x8)
#define GPIO_REG_GPFSEL3 (gpioBaseAddr + 0xc)
#define GPIO_REG_GPFSEL4 (gpioBaseAddr + 0x10)
#define GPIO_REG_GPFSEL5 (gpioBaseAddr + 0x14)
#define GPIO_REG_GPSET0 (gpioBaseAddr + 0x1c)
#define GPIO_REG_GPSET1 (gpioBaseAddr + 0x20)
#define GPIO_REG_GPCLR0 (gpioBaseAddr + 0x28)
#define GPIO_REG_GPCLR1 (gpioBaseAddr + 0x2c)
#define GPIO_REG_GPLEV0 (gpioBaseAddr + 0x34)
#define GPIO_REG_GPLEV1 (gpioBaseAddr + 0x38)
#define GPIO_REG_GPEDS0 (gpioBaseAddr + 0x40)
#define GPIO_REG_GPEDS1 (gpioBaseAddr + 0x44)
#define GPIO_REG_GPREN0 (gpioBaseAddr + 0x4c)
#define GPIO_REG_GPREN1 (gpioBaseAddr + 0x50)
#define GPIO_REG_GPFEN0 (gpioBaseAddr + 0x58)
#define GPIO_REG_GPFEN1 (gpioBaseAddr + 0x5c)
#define GPIO_REG_GPHEN0 (gpioBaseAddr + 0x64)
#define GPIO_REG_GPHEN1 (gpioBaseAddr + 0x68)
#define GPIO_REG_GPLEN0 (gpioBaseAddr + 0x70)
#define GPIO_REG_GPLEN1 (gpioBaseAddr + 0x74)
#define GPIO_REG_GPAREN0 (gpioBaseAddr + 0x7c)
#define GPIO_REG_GPAREN1 (gpioBaseAddr + 0x80)
#define GPIO_REG_GPAFEN0 (gpioBaseAddr + 0x88)
#define GPIO_REG_GPAFEN1 (gpioBaseAddr + 0x8c)
#define GPIO_REG_GPPUD (gpioBaseAddr + 0x94)
#define GPIO_REG_GPPUDCLK0 (gpioBaseAddr + 0x98)
#define GPIO_REG_GPPUDCLK1 (gpioBaseAddr + 0x9c)

namespace kernel {

struct gpioHandler : protected mmioHandler {
    void gppudclk0(uint32_t data, uint32_t controlSignal);

    void gppudclk1(uint32_t data, uint32_t controlSignal);

    void gppud(uint32_t data);

    static uint32_t gppudSave;
};

inline gpioHandler gpio;

}

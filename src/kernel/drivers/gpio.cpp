#include <kernel/drivers/gpio.h>
#include <lib/asmUtils.h>

namespace kernel {

uint32_t gpioHandler::gppudSave = 0;

void gpioHandler::gppudclk0(uint32_t data, uint32_t controlSignal) {
    gppud(controlSignal);
    wait(150);

    *(uint32_t*)(uint64_t)GPIO_REG_GPPUDCLK0 = data;
    wait(150); 

    gppud(*(uint32_t*)(uint64_t)GPIO_REG_GPPUD & controlSignal);
    *(uint32_t*)(uint64_t)GPIO_REG_GPPUDCLK0 = *(uint32_t*)(uint64_t)GPIO_REG_GPPUDCLK0 & data;
}

void gpioHandler::gppudclk1(uint32_t data, uint32_t controlSignal) {
    gppud(controlSignal);
    wait(150);

    *(uint32_t*)(uint64_t)GPIO_REG_GPPUDCLK1 = data;
    wait(150); 

    gppud(*(uint32_t*)(uint64_t)GPIO_REG_GPPUD & controlSignal);
    *(uint32_t*)(uint64_t)GPIO_REG_GPPUDCLK1 = *(uint32_t*)(uint64_t)GPIO_REG_GPPUDCLK1 & data;
}

void gpioHandler::gppud(uint32_t data) {
    gppudSave = data;
    *(uint32_t*)(uint64_t)GPIO_REG_GPPUD = data;
}

}

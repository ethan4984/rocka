#pragma once

#include <stdint.h>

namespace kernel {

struct mmioHandler {
    void init();

    uint32_t read(uint32_t reg);
    
    void write(uint32_t reg, uint32_t data);

    static uint32_t mmioBaseAddr;

    static uint32_t boardType;
};

inline mmioHandler mmio;

}

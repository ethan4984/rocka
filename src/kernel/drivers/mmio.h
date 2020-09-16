#pragma once 

#include <stdint.h>

namespace kernel {

class mmioHandler {
public:
    void init();

    uint32_t read(uint64_t reg);
    
    void write(uint64_t reg, uint32_t data);
protected:
    static uint32_t mmioBaseAddr;
    static uint32_t boardType;
    static uint32_t gpioBaseAddr;
    static uint32_t uartBaseAddr;
};

inline mmioHandler mmio;

}

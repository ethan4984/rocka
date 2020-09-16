#pragma once

#include <kernel/drivers/mmio.h>

#define UART_REG_DR (uartBaseAddr + 0x0)
#define UART_REG_RSRECR (uartBaseAddr + 0x4)
#define UART_REG_FR (uartBaseAddr + 0x18)
#define UART_REG_ILPR (uartBaseAddr + 0x20)
#define UART_REG_IBRD (uartBaseAddr + 0x24)
#define UART_REG_FBRD (uartBaseAddr + 0x28)
#define UART_REG_LCRH (uartBaseAddr + 0x2c)
#define UART_REG_CR (uartBaseAddr + 0x30)
#define UART_REG_IFLS (uartBaseAddr + 0x34)
#define UART_REG_IMSC (uartBaseAddr + 0x38)
#define UART_REG_RIS (uartBaseAddr + 0x3c)
#define UART_REG_MIS (uartBaseAddr + 0x40)
#define UART_REG_ICR (uartBaseAddr + 0x44)
#define UART_REG_DMACR (uartBaseAddr + 0x48)
#define UART_REG_ITCR (luartBaseAddr + 0x80)
#define UART_REG_ITIP (uartBaseAddr + 0x84)
#define UART_REG_ITOP (uartBaseAddr + 0x88)
#define UART_REG_TDR (uartBaseAddr + 0x8c)

namespace kernel {

class uartHandler : protected mmioHandler {
public:
    void init();

    uint8_t uread();

    void uwrite(uint8_t data); 
private:
    void delay(uint32_t cnt);
};

inline uartHandler uart;

}

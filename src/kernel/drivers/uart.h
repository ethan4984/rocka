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
#define MBOX_BASE_ADDR (mmioBaseAddr + 0xb880)
#define MBOX_READ (MBOX_BASE_ADDR)
#define MBOX_STATUS (MBOX_BASE_ADDR + 0x18)
#define MBOX_WRITE (MBOX_BASE_ADDR + 0x20)

namespace kernel {

class uartHandler : protected mmioHandler {
public:
    void init();

    uint8_t uread();

    void uwrite(uint8_t data); 

    void mboxWrite(uint32_t data);
};

inline volatile uint32_t __attribute__((aligned(16))) mbox[9] = { 9*4, 0, 0x38002, 12, 8, 2, 3000000, 0, 0 };

inline uartHandler uart;

}

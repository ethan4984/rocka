#include <kernel/drivers/uart.h>
#include <kernel/drivers/gpio.h>
#include <lib/asmUtils.h>

namespace kernel {

void uartHandler::init() {
    write(UART_REG_CR, 0); // disable uart0

    gpio.gppudclk0((1 << 14) | (1 << 15), 0); // disable pull up/down on TX/RX
 
    write(UART_REG_ICR, 0x7ff); // clear polled interrupts
 
    uint32_t r = (((uintptr_t)(&mbox) & ~0xF) | 8);
    mboxWrite(r);

    write(UART_REG_IBRD, 1); // set disvisor to 3mhz (input is notted)
    write(UART_REG_FBRD, 40); // set fractional baud rate divisor (input is notted)
    write(UART_REG_LCRH, (1 << 4) | (1 << 5) | (1 << 6)); // enable fifo/data transmissions/no parity
    write(UART_REG_IMSC, 0x7FF); // mask all interrupts

    write(UART_REG_CR, (1 << 0) | (1 << 8) | (1 << 9)); // enable uart0 with receieve and transfer
}

void uartHandler::mboxWrite(uint32_t data) {
    while(read(MBOX_STATUS) & 0x80000000);
    write(MBOX_WRITE, data);
    while((read(MBOX_STATUS) & 0x40000000) || read(MBOX_READ) != data); 
}

void uartHandler::uwrite(uint8_t data) {
    while(read(UART_REG_FR) & (1 << 5));
    write(UART_REG_DR, data);
}

uint8_t uartHandler::uread() {
    while(read(UART_REG_FR) & (1 << 4)) { }
    return read(UART_REG_DR);
}

}

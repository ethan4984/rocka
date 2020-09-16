#include <kernel/drivers/uart.h>

namespace kernel {

void uartHandler::init() {
    write(UART_REG_CR, 0); // disable the uart
}

uint8_t uartHandler::uread() {
    
}

void uartHandler::uwrite(uint8_t data) {

} 

}

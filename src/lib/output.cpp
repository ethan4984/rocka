#include <kernel/drivers/uart.h>
#include <lib/stringUtils.h>
#include <lib/output.h>

namespace kernel {

static void printString(const char *str, void (*putchar)(uint8_t)) {
    for(uint64_t i = 0; i < strlen(str); i++) {
        putchar(str[i]);
    } 
}

static printPrefix_t printPrefix[] = {  { "[KDEBUG]", GREEN, YELLOW },
                                        { "[KMM]", GREEN, LIGHTRED }
                                     };

void kprintDS(const char *prefix, const char *str, ...) {
    for(uint64_t i = 0; i < sizeof(printPrefix) / sizeof(printPrefix_t); i++) {
        if(strcmp(prefix, printPrefix[i].name) == 0) {
            printString(bashColours[printPrefix[i].prefixColour], serialPutchar);
            printString(prefix, serialPutchar);
            printString(bashColours[printPrefix[i].textColour], serialPutchar);
            serialPutchar(' ');
        }
    }

    va_list args;
    va_start(args, str);

    printArgs(str, args, serialPutchar);

    serialPutchar('\n');

    va_end(args);
}

void printArgs(const char *str, va_list args, void (*putchar)(uint8_t)) {
    uint64_t nhold = 0;
    char chold = 0;
    char *shold;

    for(uint64_t i = 0; i < strlen(str); i++) {
        if(str[i] != '%') {
            putchar(str[i]);
        } else {
            switch(str[++i]) {
                case 'x':
                    nhold = va_arg(args, uint64_t);
                    shold = itob(nhold, 16);
                    printString(shold, putchar);
                    break;
                case 'd':
                    nhold = va_arg(args, uint64_t);
                    shold = itob(nhold, 10);
                    printString(shold, putchar);
                    break;
                case 'b':
                    nhold = va_arg(args, uint64_t);
                    shold = itob(nhold, 2);
                    printString(shold, putchar);
                    break; 
                case 's':
                    shold = va_arg(args, char *);
                    printString(shold, putchar);
                    break;
                case 'c':
                    chold = va_arg(args, int);
                    putchar(chold);
            }
        }
    }
}

void serialPutchar(uint8_t data) {
    uart.uwrite(data);  
}

}

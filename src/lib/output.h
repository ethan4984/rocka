#pragma once

#include <stdarg.h>
#include <stdint.h>

namespace kernel {
	
inline const char *bashColours[] = {    "\e[39m", "\e[30m", "\e[31m", "\e[32m",
                                        "\e[33m", "\e[34m", "\e[35m", "\e[36m",
                                        "\e[37m", "\e[90m", "\e[91m", "\e[92m",
                                        "\e[93m", "\e[94m", "\e[95m", "\e[96m",
                                        "\e[97m"
                                   };
enum {
    DEFAULT,
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    LIGHTGRAY,
    RIGHTGRAY,
    LIGHTRED,
    LIGHTGREEN,
    LIGHTYELLOW,
    LIGHTBLUE,
    LIGHTMAGENTA,
    LIGHTCYAN,
    WHITE
};

struct printPrefix_t {
    const char *name;
    uint8_t prefixColour;
    uint8_t textColour;
};

void kprintDS(const char *prefix, const char *str, ...);

void printArgs(const char *str, va_list args, void (*putchar)(uint8_t));

void serialPutchar(uint8_t data);

}

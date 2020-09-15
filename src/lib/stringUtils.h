#pragma once

#include <stdint.h>

namespace kernel {

uint64_t strlen(const char *str);

int64_t strcmp(const char *str, const char *str1);

int64_t strncmp(const char *str, const char *str1, uint32_t n);

}

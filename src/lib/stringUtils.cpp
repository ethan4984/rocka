#include <lib/stringUtils.h>

namespace kernel {

uint64_t strlen(const char *str) {
    uint64_t cnt = 0;
    while(*str++ != '\0') 
        cnt++;
    return cnt;
}

int64_t strcmp(const char *str, const char *str1) {
    while(*str++ == *str1++) {
        if(*str == '\0' && *str1 == '\0') 
            return 0;
    }
    return 1;
}

int64_t strncmp(const char *str, const char *str1, uint64_t n) {
    for(uint64_t i = 0; i < n; i++) {
        if(*str++ != *str1++) 
            return 1;
    }
    return 0;
}

}

.section ".text.boot"

.globl _bootMain

_bootMain:
    ldr x5, =_bootMain
    mov sp, x5

    b kernelMain

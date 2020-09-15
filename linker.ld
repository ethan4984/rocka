ENTRY(kernelMain)
 
SECTIONS {
    . = 0x80000; 
 
    .text : ALIGN(4096) {
        KEEP(*(.text.boot))
        *(.text)
    }
 
    .rodata : ALIGN(4096) {
        *(.rodata)
    }
 
    .data : ALIGN(4096) {
        *(.data)
    }
 
    bssBegin = .;
    .bss : ALIGN(4096) {
        bss = .;
        *(.bss)
    }
    bssEnd = .;
}

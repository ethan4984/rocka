ENTRY(_bootMain)
 
SECTIONS {
    . = 0x80000; 
 
    .text : {
        KEEP(*(.text.boot))
        *(.text)
    }
    . = ALIGN(4096);
 
    .rodata : {
        *(.rodata)
    }
    . = ALIGN(4096);
 
    .data : {
        *(.data)
    }
    . = ALIGN(4096);
 
    bssBegin = .;
    .bss : {
        bss = .;
        *(.bss)
    }
    . = ALIGN(4096);
    bssEnd = .;
}

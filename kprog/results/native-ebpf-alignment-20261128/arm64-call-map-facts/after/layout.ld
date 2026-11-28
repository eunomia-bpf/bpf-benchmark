ENTRY(_start)
SECTIONS { . = 0x400000; .text : { *(.text*) } . = 0x410000; .data : { *(.data*) } }

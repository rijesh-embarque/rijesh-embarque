MEMORY {
FLASH (rx) : ORIGIN = 0x8000000, LENGTH = 128K
RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

__reset_stack_pointer = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS {
.text : {
. = 0;
LONG(__reset_stack_pointer);
LONG(main | 1);
. = 332;
*(.text*)
} > FLASH
}
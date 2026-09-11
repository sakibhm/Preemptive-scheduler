ENTRY(reset_handler)

stack = 0x20020000;

MEMORY
{
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 512K
    RAM(rwx)  : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
    . = 0x08000000 ;

    .vector_table :
    {
        KEEP(*(.vector_table))
    }>FLASH

    .text :
    {
        *(.text.reset_handler)
        *(.text*)
    }>FLASH

    .data :
    {
        *(.data*)
    }>RAM

    .bss :
    {
        *(.bss*)
    }>RAM
}
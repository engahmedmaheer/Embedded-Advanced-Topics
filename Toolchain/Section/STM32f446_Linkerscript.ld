ENTRY(Reset_Handler)

MEMORY
{
	FLASH(rx) : ORIGIN =0x08000000 , LENGTH =512K
	SRAM(rwx) : ORIGIN =0x20000000 , LENGTH =128K
}

SECTIONS
{
	.text :
	{
		*(.isr_vector)
		*(.text)
		*(.rodata)
		. = ALIGN(4);
		_eText = . ;
	}>FLASH
	
	.data :
	{
	_sdata = . ;	
	*(.data)
	_edata = . ;	
	}>SRAM AT> FLASH
	
	.bss :
	{
	_sbss = . ;	
	*(.bss)
	_ebss = . ;
	}>SRAM

}
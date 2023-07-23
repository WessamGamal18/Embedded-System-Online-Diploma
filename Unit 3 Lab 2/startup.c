//startup.c Eng.Wessam

#include<stdint.h>
#define STACK_Start_SP 0x20001000
extern int main(void);

void Reset_Handler (void) ;

void Default_handler()
{
	Reset_Handler();
}

void NMI_handler(void) __attribute__ ((weak, alias ("Default_handler")));;
void H_fault_handler(void) __attribute__ ((weak, alias ("Default_handler")));;
void MM_fault_handler(void) __attribute__ ((weak, alias ("Default_handler")));;
void Bus_Fault(void) __attribute__ ((weak, alias ("Default_handler")));;
void Usage_Fault_handler(void) __attribute__ ((weak, alias ("Default_handler")));;

extern unsigned int _stack_top;

uint32_t vectors[] __attribute__((section(".vectors"))) = {
(uint32_t) &_stack_top,
(uint32_t) &Reset_Handler,
(uint32_t) &NMI_handler,
(uint32_t) &H_fault_handler,
(uint32_t) &MM_fault_handler,
(uint32_t) &Bus_Fault,
(uint32_t) &Usage_Fault_handler
};
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;

void Reset_Handler (void)
{
	int i;
	// copy data from ROM to RAM
	unsigned int DATA_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* P_src = (unsigned char*)_E_text;
	unsigned char* P_dst = (unsigned char*)_S_data;
	for (i=0; i<DATA_size;i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++) ;
	}
	// init .bss with zero
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss;
	for (i=0; i<bss_size;i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0 ;
	}
	// jump to main 
	main();
}

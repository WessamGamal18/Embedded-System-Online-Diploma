//startup.c Eng.Wessam

#include<stdint.h>
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

static unsigned long Stack_top[256];

void (* const g_p_fn_vectors[])() __attribute__((section(".vectors"))) = {
(void (*)()) ((unsigned long)Stack_top + sizeof(Stack_top)),
&Reset_Handler,
&NMI_handler,
&H_fault_handler,
&MM_fault_handler,
&Bus_Fault,
&Usage_Fault_handler
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

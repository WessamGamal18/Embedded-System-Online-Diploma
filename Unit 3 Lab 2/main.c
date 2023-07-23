//Leand-in-depth
//Wessam Gamal

#include<stdint.h>
typedef volatile unsigned int vuint32_t;
// Register Address
#define RCC_Base 0x40021000
#define GPIOA_Base 0x40010800
#define RCC_APB2ENR *(vuint32_t *)(RCC_Base + 0x18)
#define GPIOA_CRH *(vuint32_t *)(GPIOA_Base + 0x04)
#define GPIOA_ODR *(vuint32_t *)(GPIOA_Base + 0x0C)
//Bit fields
#define RCC_IOPAEN (1<<2)
#define GPIOA13 (1UL<<13)
typedef union {
	vuint32_t all_fields;
	struct {
	vuint32_t reserved:13;
	vuint32_t Pin_13:1;
	} Pin;
} R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_Base + 0x0C);
unsigned char g_variables[3] = {1,2,3};
unsigned char const const_variables[3] = {1,2,3};
int main(void)
{
	int i=0;
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1)
	{
		R_ODR->Pin.Pin_13 =1;
		for ( i=0; i<5000;i++);
		R_ODR->Pin.Pin_13 =0;
		for ( i=0; i<5000;i++);

	}
}

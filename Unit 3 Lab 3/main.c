/* learn-in-depth
Wessam Gamal */

// Register Address
#define SYSCTL_RCGC2_R (*((volatile unsigned long*)0X400FE108))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long*)0X400253FC))
#define GPIO_PORTF_DIR_R (*((volatile unsigned long*)0X40025400))
#define GPIO_PORTF_DEN_R (*((volatile unsigned long*)0X4002551C))

int main(void)
{
	volatile unsigned long delay_count;
	SYSCTL_RCGC2_R = 0X00000020;
	for(delay_count=0;delay_count <20000;delay_count++);
	GPIO_PORTF_DEN_R |= 1<<3;
	GPIO_PORTF_DIR_R |= 1<<3;
	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay_count=0;delay_count <200000;delay_count++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_count=0;delay_count <200000;delay_count++);

	}
}

#include "valve.h"

void valveInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 
	GPIO_Init(GPIOB, &GPIO_InitStructure); 

	GPIO_ResetBits(GPIOB, GPIO_Pin_0); 
}

void valveSwitch(u8 state)
{
	GPIO_WriteBit(GPIOB, GPIO_Pin_1, (BitAction)state);
}

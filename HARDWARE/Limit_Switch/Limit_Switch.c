#include "Limit_Switch.h"


void GUA_Limit_Switch_Init(void)
{	
	//IO结构体
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//注意要打开SYSCFG时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

}
 

void GUA_Limit_Switch_Check(void)    
{      
	static int flag = 0;
    //没触发
    if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == 0 && GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == 0 && flag == 0) 
    {
		LED0=0;
		LED1=1;
		valveSwitch(0);
		TIM_SetCompare1(TIM2,97);//95
		
    }
    //触发
    else if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == 1 || GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == 1)
    {
		LED0=1;
		LED1=0; 
		valveSwitch(1);
		TIM_SetCompare1(TIM2,43);
		delay_ms(2000);
		valveSwitch(0);//0开，1关
		delay_ms(1000);
		for(int i=43;i<66;i++)
		{
			TIM_SetCompare1(TIM2,i);
			delay_ms(100);
		}
//		TIM_SetCompare1(TIM2,76);
//		delay_ms(1000);
//		TIM_SetCompare1(TIM2,66);//66中间,80向下，95,43	
		//TIM_SetCompare1(TIM2,35);
		flag =1;
    }  
	else if(flag ==1)
	{
		TIM_SetCompare1(TIM2,66);
		//TIM_SetCompare1(TIM2,43);
	}
} 


 


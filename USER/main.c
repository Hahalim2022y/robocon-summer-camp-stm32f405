#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys.h"
#include "delay.h"
#include "USART.h"
#include "Limit_Switch.h"
#include "servo.h"
#include "valve.h"

 
 
int main(void)
{ 
	u8 res;
	u16 gray_res;
	char command[100];
	u8 commandCnt = 0;
	u8 commandFinish = 0;
	
	u8 Limit_Switch_flag = 0;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//TIM2_PWM_Init(200-1,8400-1);199,7199
	TIM2_PWM_Init(2000 - 1, 1680 - 1);//168000000 100000
	delay_init(168);		  
	LED_Init();	
	valveInit();
	Limit_Switch_Init();
	uart1_init(115200);
	
	
	while(1)
	{
//		LED0=0;
//		LED1=1;
//		delay_ms(1000);
//		LED0=0;
//		LED1=0;

//		for(i = 23; i <= 127; i++)
//		{
//			TIM_SetCompare1(TIM2, i);
//			delay_ms(10);
//		}
//		for(i = 127; i >= 23; i--)
//		{
//			TIM_SetCompare1(TIM2, i);
//			delay_ms(10);
//		}

//		delay_ms(2000);		
//		valveSwitch(0);//0开，1关
//		delay_ms(2000);
//		TIM_SetCompare1(TIM2,95);//66中间,80向下，94,95,43	
//		delay_ms(2000);		
//		valveSwitch(1);//0开，1关
//		delay_ms(2000);
//		TIM_SetCompare1(TIM2,43);//66中间,80向下，94,95,43	
//		delay_ms(2000);
//		valveSwitch(0);//0开，1关
//		delay_ms(2000);
//		TIM_SetCompare1(TIM2,66);//66中间,80向下，95,43	
//		delay_ms(2000);
		
		while(1)
		{
			if(uart1_read(&res) == 1)
			{
				if(res != '\n')
				{
					command[commandCnt] = res;
				}
				else
				{
					command[commandCnt] = '\0';
					commandFinish = 1;
					commandCnt = 0;
					break;
				}
			}
			else
			{
				break;
			}
			commandCnt++;
		}
		if(commandFinish == 1)
		{
			uart1_send(command);
			uart1_send("\n");
			commandFinish = 0;
			
			if(strcmp(command, "putdown\r") == 0)
			{
				valveSwitch(0);
				TIM_SetCompare1(TIM2,97);
			}

	    }
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == 1 || GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == 1)
		{
			LED0=1;
			LED1=0; 
			valveSwitch(1);
			if(Limit_Switch_flag == 0)
			{
				uart1_send("turnback\n");
				Limit_Switch_flag =1;
			}
			if(strcmp(command, "flipped\r") == 0)
			{
				TIM_SetCompare1(TIM2,43);
				delay_ms(2000);
				valveSwitch(0);//0开，1关
				delay_ms(1000);
				for(int i=43;i<67;i++)
				{
					TIM_SetCompare1(TIM2,i);
					delay_ms(100);
				}
				//TIM_SetCompare1(TIM2,35);
				
			}
			
		}  
//		else if(Limit_Switch_flag ==1)
//		{
//			TIM_SetCompare1(TIM2,66);
//			//TIM_SetCompare1(TIM2,43);
//		}

		
	}
}




#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "Limit_Switch.h"
 
 
//ALIENTEK Ì½Ë÷ÕßSTM32F407¿ª·¢°å ÊµÑé22
//PWM DAC ÊµÑé  -¿âº¯Êı°æ±¾
//¼¼ÊõÖ§³Ö£ºwww.openedv.com
//ÌÔ±¦µêÆÌ£ºhttp://eboard.taobao.com  
//¹ãÖİÊĞĞÇÒíµç×Ó¿Æ¼¼ÓĞÏŞ¹«Ë¾  
//×÷Õß£ºÕıµãÔ­×Ó @ALIENTEK
 
int i = 0;
  
int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//TIM2_PWM_Init(200-1,8400-1);199,7199
	TIM2_PWM_Init(2000 - 1, 1680 - 1);//168000000 100000
	delay_init(168);		  //³õÊ¼»¯ÑÓÊ±º¯Êı
	LED_Init();	
	valveInit();
	GUA_Limit_Switch_Init();
	
	
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
//		valveSwitch(0);//0å¼€ï¼Œ1å…³
//		delay_ms(2000);
//		TIM_SetCompare1(TIM2,95);//66ä¸­é—´,80å‘ä¸‹ï¼Œ94,95,43	
//		delay_ms(2000);		
//		valveSwitch(1);//0å¼€ï¼Œ1å…³
//	
//		delay_ms(2000);
//		TIM_SetCompare1(TIM2,43);//66ä¸­é—´,80å‘ä¸‹ï¼Œ94,95,43	
//		delay_ms(2000);
//		valveSwitch(0);//0å¼€ï¼Œ1å…³
//		delay_ms(2000);
//		TIM_SetCompare1(TIM2,66);//66ä¸­é—´,80å‘ä¸‹ï¼Œ95,43	
//		delay_ms(2000);
		

		GUA_Limit_Switch_Check();
		//TIM_SetCompare1(TIM2,35);
	}

		
}





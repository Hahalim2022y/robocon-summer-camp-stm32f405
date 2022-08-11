#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "servo.h"

 
 
//ALIENTEK 探索者STM32F407开发板 实验22
//PWM DAC 实验  -库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK
 

  
int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//TIM2_PWM_Init(200-1,8400-1);199,7199
	TIM2_PWM_Init(199,7199);
	delay_init(168);		  //初始化延时函数
	LED_Init();		        //初始化LED端口
	
	while(1)
	{
//	GPIO_ResetBits(GPIOF,GPIO_Pin_9);  //LED0对应引脚GPIOF.9拉低，亮  等同LED0=0;
//	GPIO_SetBits(GPIOF,GPIO_Pin_10);   //LED1对应引脚GPIOF.10拉高，灭 等同LED1=1;
//	delay_ms(500);  		   //延时300ms
//	GPIO_SetBits(GPIOF,GPIO_Pin_9);	   //LED0对应引脚GPIOF.0拉高，灭  等同LED0=1;
//	GPIO_ResetBits(GPIOF,GPIO_Pin_10); //LED1对应引脚GPIOF.10拉低，亮 等同LED1=0;
//	delay_ms(500);                     //延时300ms
//		LED0=0;
//		LED1=1;
//		delay_ms(1000);
//		LED0=1;
//		LED1=0;
//		delay_ms(1000);
		
//		TIM_SetCompare1(TIM2,194);	//修改比较值，修改占空比对应0度
//		delay_ms(1000);			
//		TIM_SetCompare1(TIM2,190);	//修改比较值，修改占空比对应45度
//		delay_ms(1000);	
//		TIM_SetCompare1(TIM2,185);	//修改比较值，修改占空比对应90度		
//		delay_ms(1000);	 
//		TIM_SetCompare1(TIM2,180);	//修改比较值，修改占空比对应135度		
//		delay_ms(1000);			
//		TIM_SetCompare1(TIM2,177);	//修改比较值，修改占空比对应180度		
//		delay_ms(1000);	 
//		LED0=0;
//		LED1=1;
//		delay_ms(1000);
//		LED0=1;
//		LED1=0;

//		delay_ms(1000);
		delay_ms(1000);	 
		TIM_SetCompare1(TIM2,175);	//修改比较值，修改占空比对应180度
		
// 


 

	}


}





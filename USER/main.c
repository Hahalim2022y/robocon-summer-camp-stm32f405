#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "servo.h"
#include "valve.h"
 
 
//ALIENTEK ̽����STM32F407������ ʵ��22
//PWM DAC ʵ��  -�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK
 
int i = 0;
  
int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//TIM2_PWM_Init(200-1,8400-1);199,7199
	TIM2_PWM_Init(2000 - 1, 1680 - 1);//168000000 100000
	delay_init(168);		  //��ʼ����ʱ����
	LED_Init();	
	valveInit();
	//��ʼ��LED�˿�
	
	
	while(1)
	{
//		LED0=0;
//		LED1=1;

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
		
		TIM_SetCompare1(TIM2, i);
		
		//valveSwitch(0);
//		delay_ms(1000);
//		valveSwitch(1);
//		delay_ms(1000);

	}


}





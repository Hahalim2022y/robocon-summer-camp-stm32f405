#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "servo.h"

 
 
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
	TIM2_PWM_Init(2000 - 1, 1680);//168000000 100000
	delay_init(168);		  //��ʼ����ʱ����
	LED_Init();	
	//��ʼ��LED�˿�
	
	
	while(1)
	{
//		LED0=0;
//		LED1=1;
//		delay_ms(1000);
//		LED0=1;
//		LED1=0;
//		delay_ms(1000);
		
//		TIM_SetCompare1(TIM2,194);	//�޸ıȽ�ֵ���޸�ռ�ձȶ�Ӧ0��
//		delay_ms(1000);			
//		TIM_SetCompare1(TIM2,190);	//�޸ıȽ�ֵ���޸�ռ�ձȶ�Ӧ45��
//		delay_ms(1000);	
//		TIM_SetCompare1(TIM2,185);	//�޸ıȽ�ֵ���޸�ռ�ձȶ�Ӧ90��		
//		delay_ms(1000);	 
//		TIM_SetCompare1(TIM2,180);	//�޸ıȽ�ֵ���޸�ռ�ձȶ�Ӧ135��		
//		delay_ms(1000);			
//		TIM_SetCompare1(TIM2,177);	//�޸ıȽ�ֵ���޸�ռ�ձȶ�Ӧ180��		
//		delay_ms(1000);	 
//		LED0=0;
//		LED1=1;
//		delay_ms(1000);
//		LED0=1;
//		LED1=0;
			 
//		TIM_SetCompare1(TIM2, 60);
//		delay_ms(1000);
//		TIM_SetCompare1(TIM2, 150);
//		delay_ms(1000);
//		TIM_SetCompare1(TIM2, 240);
//		delay_ms(1000);
		
// 
		//TIM_SetCompare1(TIM2, i);
		for(i = 23; i <= 127; i++)
		{
			TIM_SetCompare1(TIM2, i);
			delay_ms(10);
		}
		for(i = 127; i >= 23; i--)
		{
			TIM_SetCompare1(TIM2, i);
			delay_ms(10);
		}

	}


}





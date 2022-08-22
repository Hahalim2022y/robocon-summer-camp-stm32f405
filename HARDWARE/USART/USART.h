#ifndef __USART_H
#define __USART_H

#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "cycleArray.h"

extern CycleArray uart1_fifo;

void uart1_init(u32 baud);


void uart1_send(char str[]);


u8 uart1_read(u8 *buff);


#endif


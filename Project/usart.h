#include <stm32f10x_conf.h>
#include <stdio.h>
#include <misc.h>
#include <stdarg.h>

void usart1_init(void);
int fputc(int ch, FILE *f);
int fgetc(FILE *fp);
void uprintf(USART_TypeDef* USARTx, char *fmt, ...);

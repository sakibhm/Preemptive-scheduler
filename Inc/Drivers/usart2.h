#ifndef USART2H
#define USART2H

void USART2_waitTxe();
void USART2_waitRxne();

void usart2_init();
void usart2_write();
void usart2_write_u32();

#endif
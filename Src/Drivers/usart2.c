#include <stdint.h>
#include "stm32f446.h"
#include "Drivers/usart2.h"

void USART2_waitTxe(){
    while(!(USART2->SR & USART_SR_TXE));
}

void USART2_waitRxne(){
    while(!(USART2->SR & USART_SR_RXNE));
}

void usart2_init(uint32_t Baudrate){

    //clocks enabled
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    //pin configuration
    GPIOA->MODER &= ~( (0b11 << 2*2) | (0b11 << 3*2) );
    GPIOA->MODER |= ( (0b10 << 2*2) | (0b10 << 3*2) );

    GPIOA->AFR[0] &= ~( (0b1111 << 2*4) | (0b1111 << 3*4) );
    GPIOA->AFR[0] |= ( (0b0111 << 2*4) | (0b0111 << 3*4) );



    //usart2 configurations
    USART2->BRR = 16000000/Baudrate;
    USART2->CR1 |= (USART_CR1_TE | USART_CR1_RE | USART_CR1_UE);
}

void usart2_write(const char *data){

    for(int i = 0;data[i] != '\0'; i++){

        USART2_waitTxe();
        USART2->DR = data[i];
    }

}

void usart2_write_u32(uint32_t value)
{
    char buffer[11];
    int i = 0;

    if (value == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
        usart2_write(buffer);
        return;
    }

    while (value > 0)
    {
        buffer[i++] = '0' + (value % 10);
        value /= 10;
    }

    buffer[i] = '\0';

    // digits are currently backwards, so reverse them
    for (int j = 0; j < i / 2; j++)
    {
        char temp = buffer[j];
        buffer[j] = buffer[i - 1 - j];
        buffer[i - 1 - j] = temp;
    }

    usart2_write(buffer);
}
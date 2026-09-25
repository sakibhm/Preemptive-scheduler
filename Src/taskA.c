#include <stdint.h>
#include "Drivers/usart2.h"
#include "stm32f446.h"

void fibonacci_seq(void){
    uint32_t a = 0;
    uint32_t b = 1;
    uint32_t fibonacci_no;

    usart2_write("Fibonacci-sequence: ");
    for(int i = 0; i<100 ; i++){

        fibonacci_no = a+b;
        b = a;
        a = fibonacci_no;

        usart2_write_u32(fibonacci_no);
        usart2_write(" ");
    }
}

void task_a(void){
    while(1){
        GPIOA->ODR |= (1<<5);
        GPIOA->ODR &= ~(1<<6);  //turning on pa5
        //fibonacci_seq();
        //usart2_write("\n");
    }
}
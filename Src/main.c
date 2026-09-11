#include "Drivers/usart2.h"

int main(){

    usart2_init(9600);

    usart2_write("Hello from STM32\n");

    
    return 0;
}
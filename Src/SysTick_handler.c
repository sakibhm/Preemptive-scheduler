#include "stm32f446.h"
#include "Systick_Handler.h"

void Systick_Handler(void){

     GPIOA->ODR ^= (1U << 5);

}
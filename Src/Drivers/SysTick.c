#include "stm32f446.h"
#include "Drivers/SysTick.h"

void SysTick_init(void){
    SysTick->RVR = 15999999;
    SysTick->CVR = 0;

    SysTick->CSR |= (SysTick_CSR_ENABLE | SysTick_CSR_CLKSOURCE | SysTick_CSR_TICKINT) ;
}
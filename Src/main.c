#include <stdio.h>
#include <stdint.h>
#include "Drivers/usart2.h"
#include "task_init.h"
#include "Drivers/SysTick.h"
#include "taskA.h"
#include "taskB.h"
#include "start_first_task.h"
//#include "Systick_Handler.h"
#include "stm32f446.h"

uint32_t taskA_stack[STACK_SIZE];
uint32_t taskB_stack[STACK_SIZE];

TCB Task_A;
TCB Task_B;


TCB *current_task;

int main(){

    SysTick_init();
    usart2_init(9600);

    Task_A.next_task = &Task_B;
    Task_B.next_task = &Task_A;

    task_init(&Task_A, taskA_stack, task_a);
    task_init(&Task_B, taskB_stack, task_b);

    TCB *head = &Task_A;
    current_task = head;
    
    // GPIOA clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // PA5 output
    GPIOA->MODER &= ~(0b11 << 10);
    GPIOA->MODER |=  (0b01 << 10);

    // PA6 output
    GPIOA->MODER &= ~(0b11 << 12);
    GPIOA->MODER |=  (0b01 << 12);    

    start_first_task(Task_A.SP);

    return 0;
}
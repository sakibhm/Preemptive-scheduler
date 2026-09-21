#include <stdio.h>
#include <stdint.h>
#include "Drivers/usart2.h"
#include "task_init.h"
#include "taskA.h"
#include "taskB.h"
#include "start_first_task.h"

uint32_t taskA_stack[STACK_SIZE];
uint32_t taskB_stack[STACK_SIZE];

int main(){

    usart2_init(9600);

    TCB Task_A;
    TCB Task_B;


    Task_A.next_task = &Task_B;
    Task_B.next_task = &Task_A;

    task_init(&Task_A, taskA_stack, task_a);
    task_init(&Task_B, taskB_stack, task_b);

    start_first_task(Task_A.SP);




    return 0;
}
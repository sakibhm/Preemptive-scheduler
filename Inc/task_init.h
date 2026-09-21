#ifndef TASK_INIT_H
#define TASK_INIT_H

#include "TCB.h"

#define xPSR_SET_T_bit (1U<<24)
#define STACK_SIZE 128

void task_init(
        TCB *tcb,
        uint32_t *stack,
        void (*task)(void)
    );


#endif
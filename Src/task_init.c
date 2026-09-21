#include <stdint.h>
#include "TCB.h"
#include "task_init.h"


void task_init(
        TCB *tcb,
        uint32_t *stack,
        void (*task)(void)
    ){
        uint32_t *sp = &stack[STACK_SIZE];

        //hardware stacked registers//
        *--sp = xPSR_SET_T_bit; //xPSR
        *--sp = (uint32_t)task | 1; //PC
        *--sp = 0; //LR
        *--sp = 0; //r12

        *--sp = 0; //r3
        *--sp = 0; //r2
        *--sp = 0; //r1
        *--sp = 0; //r0

        //software stacked registers//
        *--sp = 0; //r11
        *--sp = 0; //r10
        *--sp = 0; //r9
        *--sp = 0; //r8

        *--sp = 0; //r7
        *--sp = 0; //r6
        *--sp = 0; //r5
        *--sp = 0; //r4

        tcb->SP = sp;


    }
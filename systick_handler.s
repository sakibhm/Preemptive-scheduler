.syntax unified
.cpu cortex-m4
.thumb

.global systick_handler

.section .text.systick_handler

systick_handler :

    MRS r0, PSP               //loading SP of Task to r0

    STMDB r0!, {r4-r11}  //saving these registers in stack

    //saving the SP of task
    LDR r1, =current_task 
    LDR r2, [r1]
    STR r0, [r2]

    // pushing EXC_RETURN value onto the MSP stack
    PUSH {lr}

    // branching to C function to take the SP of next task
    bl scheduler

    //loading the Stack of next task
    LDMIA r0!, {r4-r11}
    MSR PSP, r0


    POP {lr}

    // exception return
    BX lr 

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

    PUSH {lr}

    bl scheduler

    LDMIA r0!, {r4-r11}
    MSR PSP, r0


    POP {lr}

    BX lr 

.syntax unified
.cpu cortex-m4
.thumb

.global stack
.global reset_handler
.global main

.section .vector_table,"a",%progbits
.word stack             // 0-Initial SP
.word reset_handler + 1 // 1-Reset

.word 0                 // 2
.word 0                 // 3
.word 0                 // 4
.word 0                 // 5
.word 0                 // 6
.word 0                 // 7
.word 0                 // 8
.word 0                 // 9
.word 0                 // 10

.word svc_handler + 1   // 11-SVC

.word 0              //12
.word 0              //13
.word 0              //14

.word systick_handler + 1              //15-SysTick


.section .text.reset_handler
reset_handler :
    bl main
1:
    b 1b

.syntax unified
.cpu cortex-m4
.thumb

.global svc_handler


.section .text.svc_handler

svc_handler :
    LDMIA r0!, {r4-r11}
    MSR PSP, r0

    LDR lr, =0xFFFFFFFD
    BX lr

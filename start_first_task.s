.syntax unified
.cpu cortex-m4
.thumb

.global start_first_task

.type start_first_task, %function

start_first_task :

    SVC #0

.size start_first_task, .-start_first_task

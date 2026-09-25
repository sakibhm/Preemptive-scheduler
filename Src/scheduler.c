#include <stdint.h>
#include "TCB.h"

extern TCB *current_task;

uint32_t *scheduler(){
    current_task = current_task->next_task;

    return current_task->SP ;
}
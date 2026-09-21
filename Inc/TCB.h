#ifndef TCB_H
#define TCB_H


typedef struct TCB{
     uint32_t *SP;
    struct TCB *next_task;
}TCB;

#endif
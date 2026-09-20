#include <stdio.h>
#include <stdint.h>
#include "Drivers/usart2.h"
#include "taskA.h"
#include "taskB.h"


int main(){

    usart2_init(9600);



    return 0;
}
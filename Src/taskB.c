#include <stdint.h>
#include "Drivers/usart2.h"
#include "stm32f446.h"


void bubble_sort(){
    uint32_t arr[] = {10,6,8,3,5,7,4,2,9,6,1};
    int n =  10;

    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    usart2_write("Bubble-sort: ");
    for(int i=0 ; i<n ; i++){
        usart2_write_u32(arr[i]);
        usart2_write(" ");
    }
}

void task_b(void){
    while(1){
        GPIOA->ODR |= (1<<6);
        GPIOA->ODR &= ~(1<<5);  //turning on pa5
        //bubble_sort();
        //usart2_write("\n");
    }
}
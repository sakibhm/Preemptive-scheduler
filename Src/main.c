#include <stdio.h>
#include <stdint.h>
#include "Drivers/usart2.h"

void fibonacci_seq(){
    uint32_t a = 0;
    uint32_t b = 1;
    uint32_t fibonacci_no;

    usart2_write("Fibonacci-sequence: ");
    for(int i = 0; i<10 ; i++){

        fibonacci_no = a+b;
        b = a;
        a = fibonacci_no;

        usart2_write_u32(fibonacci_no);
        usart2_write(" ");
    }
}

void bubble_sort(){
    uint32_t arr[] = {10,8,4,2,6};
    int n =  5;

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
int main(){

    usart2_init(9600);

    fibonacci_seq();

    usart2_write("\r\n");
    bubble_sort();


    return 0;
}
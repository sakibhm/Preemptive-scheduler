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

void task_b(void){
    while(1){
        bubble_sort();
    }
}
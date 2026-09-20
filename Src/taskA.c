void fibonacci_seq(void){
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

void task_a(void){
    while(1){
        fibonacci_seq();
    }
}
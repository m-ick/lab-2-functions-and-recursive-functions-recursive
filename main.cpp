#include "mbed.h"
#include <cstdio>

/*
    This program prints the Fibonacci sequence to the terminal

    The length of the Fibonacci sequence is set by max_n
    1: Simple loops 
        This will calculate the fib series by adding the current number to the last number, this sum becomes the new current number
        This process runs fir the first max_n numbers in the Fibonacci series. 
        LED1 will blink on and off at the smae times as the number is printed to screen. This time is defined by the variable blink_period

    2: Recursive
        This version uses a recursive function to calculate the Fibonacci series
        If n is equal to 0 or 1 it will use them because the Fibonacci series needs to start with 0,1,1 etc
        For the rest it will generate the sequence for n-1 and add it to the sequence for n-2
        eg. fib(4)  = fib(3) + fib(2) 
                    = fib(2)+fib(1) + fib(1)+fib(0)
                    = fib(1)+1 + 1+0 
                    = 1+1+1+0
            fib(4) = 3

*/

DigitalOut blink(PA_5);
int blink_period = 750;

int t_1 = 0;
int t_2 = 1;
int t_n = 0;

int max_n = 10;

int fib(int n){   
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    else
        return(fib(n-1) + fib(n-2));
}

int main()
{
    // 1: Simple loops
    // printf("Fibonacci sequence for %d numbers\r\n", max_n);
    // printf("Number %d: %d \r\n", 1, 0); 
    // printf("Number %d: %d \r\n", 2, 1);

    // for( int i=2; i<max_n; i++){
    //     blink = 0; // turn led off
        
    //     t_n = t_1 + t_2;
    //     t_1 = t_2;
    //     t_2 = t_n;
    //     printf("Number %d: %d \r\n", i+1, t_n);

    //     thread_sleep_for(blink_period);
    //     blink = 1; // turn led on
    //     thread_sleep_for(blink_period);        
    // }

    // 2: Recursive loop
    printf("Finbonachi sequence for %d numbers using a recursive function\r\n", max_n);
    for(int i=0; i<max_n; i++){
        printf("Number %d: %d \r\n", i+1, fib(i));
        thread_sleep_for(500);
    }

    printf("\r\n");
   
   return 0;
}


#include<stdio.h>

// FUN FOR FIBONACCI NUMBER SERIES
void fibonacci(int n)
{
    int fib[100];
    int i;
    fib[0] = 1; // ASSIGNING FIRST NUMBER
    fib[1] = 1; // ASSIGNING SECOND NUMBER

    for(i = 2; i < n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    //PRINTING FIBONACCI SERIES
    printf("\nfibonacci series is... ");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", fib[i]);
    }

}

void main()
{
    int n;
    
    //TACKING LIMIT FROM USER
    printf("\nenter fibonacci limit: ");
    scanf("%d",&n);
    fibonacci(n);
}
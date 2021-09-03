#include<stdio.h>

void fibonacci(int n)
{
    float fib[100];
    int i;
    fib[0] = 1;
    fib[1] = 1;

    for(i = 2; i < n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("\nfibonacci series is... ");
    for(i = 0; i < n; i++)
    {
        
        printf("%f\t", fib[i]);
    }

}

void main()
{
    // int arr[100];
    int n;
    printf("\nenter fibonacci limit: ");
    scanf("%d",&n);
    fibonacci(n);

    // for(i = 0; i < n; i++)
    // {
    //     printf("enter element at position []");
    //     scanf("%d", arr[i]);
    // }
}
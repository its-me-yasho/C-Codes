#include <stdio.h>

void checkPrime(int n)
{
    int i, flag = 0;
    if(n>1)
    {
        for(i = 2; i < n/2; i++)
        {
            if(n%i == 0)
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\n%d is prime number",n);
        }
        else
        {
            printf("\n%d is not prime number",n);
        }
    }
    
    else
    {
        printf("\n%d is not prime number",n);
    }
}

void main()
{
    int n;
    printf("____CHECK_PRIME_NUMBER____");
    printf("\nenter the number : ");
    scanf("%d",&n);

    checkPrime(n);
}
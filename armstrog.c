#include<stdio.h>

void checkArmstrong(int n)
{
    int i = n,sum = 0;

    while (i>0)
    {
        int r = i % 10;
        sum = sum + (r * r * r);
        i = i/10;
    }

    if (sum == n)
    {
        printf("\n%d is armstrong number",n);
    }

    else
    {
        printf("\n%d is not armstrong number",n);
    }
}

void main()
{
    int n;
    
    printf("____CHECK_ARMSTRONG____");
    printf("\nenter the number : ");
    scanf("%d",&n);
    
    checkArmstrong(n);
}   
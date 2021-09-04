#include <stdio.h>
#include <string.h>

// FUNCTION FOR CHECK PALINDROME
void checkPalindrome(char *str)
{
    int i,j;
    int n = strlen(str);
    char str1[n];

    //SWAPING STRING IN REVERSE OREDER
    for(i = n-1,j = 0; i >= 0 && j < n; i--,j++)
    {
        str1[j] = str[i];       
    }
    str1[n] = '\0';//STRING END WITH NULL CHAR

    if(strcmp(str,str1) == 0)
    {
        printf("\n%s is palindrome", str);
    }
    
    else
    {
        printf("\n%s is not palindrome", str);
    }
}

void main()
{
    char str[100];

    printf("enter string : ");
    scanf("%s",str);
    
    checkPalindrome(str);
}
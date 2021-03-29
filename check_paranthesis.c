//program for stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top = -1;
char arr[100];


void push(char ch)
{
    top++;
    arr[top] = ch;
}

void pop()
{
    top--;
}

int notPair(char ch)
{
	if((ch == ')' && arr[top] == '(') || (ch == '}' && arr[top] == '{') || (ch == ']' && arr[top] == '['))
	{
		return  0;
	}
	else return  1;
}

void main()
{
    int i;
    char str[100];
    
    printf("\n enter the paranthesis :");
    scanf("%s",str);
    printf("\n paranthesis : %s\n",str);
    
	int n = strlen(str);
    for(i=0;i<n;i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if(top == -1 || notPair(str[i]))
			{
				printf("\n paranthesis are not balanced\n");
				return;
			}
			else
			{
				pop();
			}
		}
	}
	if(top == -1)
	{
		printf("\n paranthesis are balanced\n");
	}
	else
	{
		printf("\n paranthesis are not balanced\n");
	}
}
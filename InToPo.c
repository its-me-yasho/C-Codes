//program for stack
#include<stdio.h>
#include<string.h>

int top = -1;
char arr[100];
char exp1[100];
char res[100];

void push(char ch)
{
    top++;
    arr[top] = ch;
}

char pop()
{
    char ch = arr[top];
	top--;
	return ch;
}

int isOperator(char ch)
{
	if(ch == '*' || ch == '-' || ch == '+' || ch == '/' || ch == '%')
	{
		return 1;
	}
	return 0;
}

int isOperand(char ch)
{
	int i = ch;
	if((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
	{
		return 1;
	}
	return 0;
}

int precision(char ch)
{
	if(ch == '-' || ch == '+')
	{
		return 1;
	}
	else if(ch == '*' || ch == '/' || ch == '%')
	{
		return 2;
	}
}

int isHighPre(char ch1, char ch2)
{	
	if (precision(ch1) > precision(ch2))
	{
		return 1;
	}
	return 0;
}

char *infixToPost()
{
	int i, rTop = 0, len = strlen(exp1);
	for(i=0 ; i<len ; i++)								//a+b*c-d*e
	{
		if(isOperand(exp1[i]))
		{
			res[rTop] = exp1[i];
			res[++rTop] = '\0';
		}
		else if(isOperator(exp1[i]))
		{
			if(isHighPre(arr[top],exp1[i]))
			{
				while(top != -1)
				{
					res[rTop] = pop();
					res[++rTop] = '\0';
				}
			}
			push(exp1[i]);
		}
	}	
	while(top != -1)
	{
		res[rTop] = pop();
		res[++rTop] = '\0';
	}
	return res;
}

void main()
{
	printf("\n\tEnter Infix Expression \t:\t");
	scanf("%s",exp1);
	printf("\n\tInfix Expression is \t:\t%s\n",exp1);
	printf("\n\tPostfix Expression is \t:\t%s\n\n",infixToPost());
	
}
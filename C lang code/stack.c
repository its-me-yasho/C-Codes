//program for stack
#include<stdio.h>
#include<stdlib.h>

int top=-1,arr[100];


void push()
{
    int n;
    printf("\n\tenter the no. u want to push \t:\t");
    scanf("%d",&n);
    top++;
    arr[top]=n;
}


void pop()
{
    if(top == -1)
    {
        return;
    }
    top--;
}


void isEmpty()
{
    if(top == -1)
    {
        printf("\n\tstak is Empty...");
    }
    else
    {
        printf("\n\tstack is not Empty...");
    }
}


void Top()
{
	printf("\n\ttop \t:\t %d",top);
}


void print()
{
    int i;
    if(top==-1)
    {
        printf("\n\tstak is Empty...");
        return;
    }
    printf("\n\tstack is\t:\t");
    for(i=0;i<=top;i++)
    {
        printf("%d\t",arr[i]);
    }
	printf("\n");
}


void main()
{
    while(1)
	{
		int ch;
		printf("\n\n\n1. push()\n2. pop()\n3. isEmpty()\n4. top()\n5. print()\n6. exit\n\n\tenter your choice \t:\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
				print();
				break;
			case 2:pop();
				print();
				break;
			case 3:isEmpty();
				break;
			case 4:Top();
				break;
			case 5:print();
				break;
			case 6:exit(0);
				break;
			default:
				printf("\n\tyou entered wrong choice");
		}
    }
}
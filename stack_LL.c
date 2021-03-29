//program for stack using linked list
#include<stdio.h>
#include<stdlib.h>


struct node
{
    int num;
    struct node* next;
};


typedef struct node node;
node* head = NULL;
int top = -1;


node* createNode()
{
    node* temp;
    int x;
    printf("\n\tenter the element\t:\t");
    scanf("%d",&x);
    temp = (node*)malloc(sizeof(node));
    temp->num = x;
    temp->next = NULL;
    return temp;
}


void push()
{
    int i;
    node* temp = head;
    if(head == NULL)
    {
        head = createNode();
        top++;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createNode();
        top++;
    }
}


void isEmpty()
{
    if(top == -1 && head == NULL)
    {
        printf("\n\tstak is Empty...");
    }
    else
    {
        printf("\n\tstack is not Empty...");
    }
}


void pop()
{
    node* temp1 = head;
    node* temp2;
    
	if(head == NULL && top == -1)
    {
        return;
    }
	else if(temp1->next == NULL)
    {
        head=NULL;
        free(temp1);
        top--;
    }
	else
	{
		while(temp1->next->next != NULL)
		{
			temp1 = temp1 -> next;
		}
		temp2 = temp1 -> next;
		temp1->next = NULL;
		free(temp2);
		top--;
	}
}


void print()
{
    if(head == NULL && top == -1)
    {
        printf("\n\tstack is Empty....\n");
    }
    else
    {
        printf("\n\tstack is\t:\t");
        node* temp = head;
        while(temp != NULL)
        {
            printf("%d\t",temp->num);
            temp = temp->next;
        }
		printf("\n");
    }
}


void Top()
{
    printf("\n\ttop \t:\t %d",top);
}


void main()
{
    while(1)
    {
        int ch;
        printf("\n\n1. push()\n2. pop()\n3. print()\n4. top()\n5. isEmpty()\n6. exit\n\n\tenter your choice\t:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                print();
                break;
            case 2:pop();
                print();
                break;
            case 3:print();
                break;
            case 4:Top();
                break;
			case 5:isEmpty();
				break;
            case 6:exit(0);
                break;
            default:
                printf("\n\n\tyou entered wrong choice\n");
        }
    }
}
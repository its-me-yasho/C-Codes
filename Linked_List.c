#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
struct Node* head;
struct Node* CreatNode()
{
    struct Node* temp;
	int x;
	printf("Enter element\t");
	scanf("%d",&x);
	temp =  (struct Node*) malloc(sizeof(struct Node));
	temp->data = x;
	temp->next =NULL;
	return temp;
}
void InsertBegin()
{
	struct Node* temp;
	temp = CreatNode();
	if(head!=NULL) temp->next = head;
	head = temp;
	Print();
}
void InsertLast()
{
    struct Node* temp = head;
    if(head == NULL)
    {
	printf("The Linked List is empty.........\n");
	printf("___________________________________________________\n");
    }
    else
    {
	while(temp->next!=NULL)
	{
	    temp=temp->next;
	}
	temp->next = CreatNode();
    }
    Print();
}
void InsertNth()
{
    int n,i;
    struct Node* temp1;
    printf("enter the position You want to insert the node :\t");
    scanf("%d",&n);
    if(n==1)
    {
	    temp1 = CreatNode();
	    temp1->next = head;
	    head = temp1;
    }
    else
    {
	struct Node* temp2=head;
	for(i=0;i<n-2;i++)
	{
	    if(temp2==NULL||temp2->next==NULL)
	    {
		printf("The entered position is out of range\n");
		printf("___________________________________________\n");
		return;
	    }
	    temp2=temp2->next;
	}
	if(temp2==NULL)
	{
	    printf("The entered position is out of range\n");
	    printf("___________________________________________\n");
	    return;
	}
	temp1 = CreatNode();
	temp1->next=temp2->next;
	temp2->next=temp1;
    }
    Print();
}
void Print()
{
    struct Node* temp=head;
    if(head == NULL)
    {
	printf("The Linked List is empty.........\n");
	printf("___________________________________________________\n");
    }
    else
    {
	printf("\nlinked list is....\t");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
    }
}
void main()
{
	while(1)
	{
	    int x;
	    printf("\n**********************************************\n");
	    printf("Given Choices \n1. Insert At Begin \n2. Insert At Last \n3. Insert At nth position \n4. Print Linked List \n5. Exit \n Enter Your Choice :\t");
	    scanf("%d",&x);
	    switch(x)
	    {
		case 1: InsertBegin();
		break;
		case 2: InsertLast();
		break;
		case 3: InsertNth();
		break;
		case 4: Print();
		break;
		case 5: exit(0);
		break;
		default:printf("You enter wrong input");
		break;
	    }
	}
}

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* pre;
    struct node* next;
};
typedef struct node node;
node* head = NULL;
node* createNode()
{
    node* temp = (node*)malloc(sizeof(node));
    printf("\n\tEnter Data :\t");
    scanf("%d",&(temp->data));
    temp->pre = NULL;
    temp->next = NULL;
    return temp;
}
void insertBegin()
{
    node* temp = createNode();
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        head->pre = temp;
        temp->next = head;
        head = temp;
    }
}
void insertLast()
{
    node* temp1 = head;
    node* temp2 = createNode();
    if(head == NULL)
    {
        head = temp2;
    }
    else
    {
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp2->pre = temp1;
        temp1->next = temp2;
    }
}
void insertNth()
{
    int n,i;
    node* temp1 = head;
    node* temp2;
    node* temp3;
    printf("\n\tEnter The Position(INTEGER) You Want To Add Node = ");
    scanf("%d",&n);
    if(n == 1)
    {
        temp2 = createNode();
        if(head == NULL)
        {
            head = temp2;
        }
        else
        {
            head->pre = temp2;
            temp2->next = head;
            head = temp2;
        }
    }
    else if(head == NULL)
    {
        return;
    }
    else
    {
        for(i=0;i<n-2;i++)
        {
            temp1 = temp1->next;
            if(temp1 == NULL)
            {
                printf("\n\tYou Entered Position Is Out Of Range\n");
                return; 
            }
        }
        temp2 = createNode();
        if(temp1->next == NULL)
        {
            temp2->pre = temp1;
            temp1->next = temp2;
            return;
        }
        temp3 = temp1->next;
        temp3->pre = temp2;
        temp2->next = temp3;
        temp1->next = temp2;
        temp2->pre = temp1;
    }
}
void deleteNth()
{
    int n,i;
    node* temp1 = head;
    node* temp2;
    node* temp3;
    printf("\n\tEnter The Position(INTEGER) You Want To Delete Node = ");
    scanf("%d",&n);
    if(head == NULL)
    {
        return;
    }
    else if(n == 1)
    {
        if(temp1->next == NULL)
        {
            head = NULL;
            return;
        }
        head = temp1->next;
        head->pre = NULL;
        free(temp1);
    }
    else
    {
        for(i=0;i<n-2;i++)
        {
            temp1 = temp1->next;
            if(temp1->next == NULL)
            {
                printf("\n\tYou Entered Position Is Out Of Range\n");
                return;
            }
        }
        temp2 = temp1->next;
        if(temp2->next == NULL)
        {
            temp3 = temp2->pre;
            temp3->next = NULL;
            free(temp2);
            return;
        }
        temp3 = temp2->next;
        temp3->pre = temp1;
        temp1->next = temp3;
        free(temp2);
    }
}
void deleteFullList()
{
	if(head == NULL)
    {
        return;
    }
	node* temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}	
}
void reverseList()
{
	if(head == NULL)
    {
        return;
    }
	node* temp1 = head;
	node* temp2;
	node* temp3;
	while(temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	head = temp1;
	while(temp1 != NULL)
	{
		temp2 = temp1;
		temp3 = temp1->pre;
		temp2->pre = temp1->next;
		temp2->next = temp3;
		temp1 = temp1->next;
	}
}
void printList()
{
    if(head == NULL)
    {
        printf("\n\tLinked List Is Empty....");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        return;
    }
    node* temp = head;
    printf("\n\tLinked List Is....");
    while(temp != NULL)
    {
        printf("\t%d",temp->data);
        temp = temp->next;
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void printReverseList()
{
    if(head == NULL)
    {
        printf("\n\tLinked List Is Empty....");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("\n\tReverse Linked List Is....");
    while(temp !=NULL)
    {
        printf("\t%d",temp->data);
        temp = temp->pre; 
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void main()
{
    int x;
    while(1)
    {
        printf("\n###############################################################\n");
        printf("\n\tGiven Choices \n\n\t1. Insert At Begin \n\t2. Insert At Last \n\t3. Insert At Nth Position \n\t4. Delete At Nth Position \n\t5. Delete Full Doubly Linked List \n\t6. Reverse Doubly Linked List \n\t7. Print Doubly Linked List In Reverse Order \n\t8. Exit \n\n\tEnter Your Choice :\t");
        scanf("%d",&x);
        switch(x)
        {
            case 1: insertBegin();
                printList();
                break;
            case 2: insertLast();
                printList();
                break;
            case 3: insertNth();
                printList();
                break;
            case 4: deleteNth();
                printList();
                break;
            case 5: deleteFullList();
                printList();
                break;
            case 6: reverseList();
                printList();
                break;
            case 7: printReverseList();
                break;
            case 8: exit(0);
                break;
            default: printf("\n\tYou Entered Wrong Choice\n");
        }
    }
}

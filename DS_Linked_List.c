#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node node;
node* head;

node* creatNode()
{
	node* temp;
	int x;
	printf("\n\tEnter element\t:\t");
	scanf("%d",&x);
	temp =  (node*) malloc(sizeof(node));
	temp->data = x;
	temp->next =NULL;
	return temp;
}

void insertBegin()
{
	node* temp;
	temp = creatNode();
	if(head!=NULL) temp->next = head;
	head = temp;
}

void insertLast()
{
	node* temp = head;
	if(head == NULL)
	{
		return;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next = creatNode();
	}
}

void insertNth()
{
	int n,i;
	node* temp1;
	printf("\n\tenter the position You want to insert the node \t:\t");
	scanf("%d",&n);
	if(n==1)
    	{
		temp1 = creatNode();
	    	temp1->next = head;
	    	head = temp1;
    	}
    	else if(head==NULL)
    	{
		return;
    	}
    	else
    	{
		node* temp2=head;
		for(i=0;i<n-2;i++)
		{
			if(temp2==NULL||temp2->next==NULL)
			{
				printf("\n\tThe entered position is out of range\n");
				printf("_________________________________________________________________\n");
				return;
			}
			temp2=temp2->next;
		}
		if(temp2==NULL)
		{
			printf("\n\tThe entered position is out of range\n");
            		printf("_________________________________________________________________\n");
           		return;
		}
		temp1 = creatNode();
		temp1->next=temp2->next;
		temp2->next=temp1;
    	}
}

void deleteNode()
{
    	int n,i;
    	node* temp1;
	node* temp2;
	printf("\n\tEnter the position of node which you have to delete\t:\t");
	scanf("%d",&n);
    	temp1 = head;
    	if(head==NULL)
	{
		return;
	}
    	if(n==1)
    	{
        	head = temp1->next;
        	free(temp1);
    	}
    	else
    	{
        	for(i=0;i<n-2;i++)
        	{
            		if(temp1==NULL||temp1->next==NULL)
	        	{
	            		printf("\n\tThe entered position is out of range\n");
                		printf("_________________________________________________________________\n");
                		return;	        
	        	}
	        	temp1 = temp1->next;
        	}
        	if(temp1->next==NULL)
	    	{
	        	printf("\n\tThe entered position is out of range\n");
            	printf("_________________________________________________________________\n");
            	return ;
	    	}
	    	temp2 = temp1->next;
        	temp1->next = temp2->next;
        	free(temp2);
    	}
}

void deleteAllNode()
{
    	node* temp;
    	if (head==NULL)
    	{
		return ;
    	}
    	else
    	{
        	while(head != NULL)
        	{
            		temp = head;
            		head = head->next;
            		free(temp);
        	}
    	}
}

void recursiveReverse(node* q)
{
    	if (head==NULL)
    	{
        	return;    
    	}
    	else if(q->next == NULL)
    	{
        	head = q;
        	return;
    	}
    	recursiveReverse(q->next);
    	q->next->next = q;
    	q->next= NULL;
}

void reverseList()
{
    	node* pre;
    	node* cur;
    	node* sec;
    	if (head==NULL)
    	{
    		return;    
    	}
    	else
    	{
        	cur = head;
        	pre = NULL;
        	while(cur!=NULL)
        	{
            		sec = cur->next;
            		cur->next = pre;
            		pre = cur;
            		cur = sec;
        	}
        	head = pre;
    	}
}

int recursivePrint(node* p)
{
    	if(head == NULL)
    	{
		printf("\n\tThe Linked List is empty.........\n");
	    	printf("_________________________________________________________________\n");
    	}
    	else if(head == p)
    	{
        	printf("\n\tlinked list is....");
    	}
    	if (p == NULL)
    	{
        	printf("\n_________________________________________________________________\n");
        	return 0;
    	}
    	printf("\t%d",p->data);
   	recursivePrint(p->next);
}    

int printList()
{
    	node* temp=head;
    	if(head == NULL)
    	{
	    	printf("\n\tThe Linked List is empty.........\n");
	    	printf("_________________________________________________________________\n");
    	}
    	else
    	{
	    	printf("\n\tlinked list is....\t");
	    	while(temp!=NULL)
	    	{
    	    	printf("%d\t",temp->data);
    	    	temp=temp->next;
	    	}
	    	printf("\n_________________________________________________________________\n");
	    	return 0;
    	}
}

void main()
{
	while(1)
	{
	    	int x;
	    	printf("\n*****************************************************************\n");
	    	printf("\tGiven Choices \n\t1. Insert At Begin \n\t2. Insert At Last \n\t3. Insert At Nth Position \n\t4. Delete At Nth Position \n\t5. Delete Full Linked List \n\t6. Reverse The Linked List Using Recursion Function \n\t7. Reverse The Linked List \n\t8. Print Linked List Using Recursion Function \n\t9. Print Linked List \n\t10. Exit \n\n\tEnter Your Choice :\t");
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
		    	case 4: deleteNode();
		            	printList();
				break;
		    	case 5: deleteAllNode();
		            	printList();
				break;
		    	case 6: recursiveReverse(head);
		            	recursivePrint(head);
		            	break;
		    	case 7: reverseList();
				printList();
		            	break;
		    	case 8: recursivePrint(head);
		            	break;
		    	case 9: printList();
		            	break;
		    	case 10: exit(0);
		            	break;
		    	default:printf("\n\tYou Enter Wrong Choice....\n");
		            	break;
		}
	}
}

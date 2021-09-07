#include<stdio.h>
#include<stdlib.h>

//PROGRAM FOR IMPLEMENTATION OF TREE AND ITS OPERATION
// STRUCTURE OF THE NODE
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node node;

node* root = NULL;

// THIS FUNCTION WILL RETRUN NODE WITH VALUE AND NULL POINTERS
node* creatNode()
{
    node* temp = (node*)malloc(sizeof(node));

    printf("\n ENTER DATA : ");
    scanf("%d",&temp->data);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//THIS FUNCTION PRINTS MIN VALUE OF THE TREE
void minNode(node* temp)
{
    if (temp == NULL)
    {
        printf("\n _____TREE_IS_EMPTY_____");
        return;
    }
    if (temp->left == NULL)
    {
        printf("\nMIN VALUE IN TREE = %d",temp->data);
        return;
    }
    minNode(temp->left);
}

//THIS FUNCTION PRINTS MAX VALUE OF THE TREE
void maxNode(node* temp)
{
    if (temp == NULL)
    {
        printf("\n _____TREE_IS_EMPTY_____");
        return;
    }
    if (temp->right == NULL)
    {
        printf("\nMAX VALUE IN TREE = %d",temp->data);
        return;
    }
    maxNode(temp->right);
}

//THIS FUNCTION RETURNS MAX VALUE BETWEEN TWO VALUES. IT IS USED IN findHeight() FUNCTION
int max(int a, int b)
{
    return a > b ? a : b;
}

//THIS FUNCTION RETURNS HEIGHT OF THE TREE
int findHeight(node* temp)
{
    if(temp == NULL)
    return -1;
    
    return max(findHeight(temp->left),findHeight(temp->right)) + 1; 
}

//THIS FUNCTION IS USED TO INSERT A NODE IN TREE
void insertNode()
{
    node* temp1 = creatNode();
    if(root == NULL)
    {
        root = temp1;
    }
    else
    {
        node* temp2 = root;
        node* temp3;
        while(temp2 != NULL)
        {
            temp3 = temp2;

            if(temp1->data <= temp2->data)
            {
                temp2 = temp2->left;
            }
            else
            {
                temp2 = temp2->right;
            }
        }
        if(temp1->data <= temp3->data)
        {
            temp3->left = temp1;
        }
        else
        {
            temp3->right = temp1;
        }
    }
}

//THIS IS THE RECURSIVE FUNCTION TO INSERT A NODE IN TREE
void insertNodeRec(node* temp1, node* newNode)
{
    if(root == NULL)
    {
        root = newNode;
        return;
    }
    else if(newNode->data <= temp1->data)
    {
        if(temp1->left == NULL)
        {
            temp1->left = newNode;
        }
        else
        {
            insertNodeRec(temp1->left, newNode);
        }
    }
    else
    {
        if(temp1->right == NULL)
        {
            temp1->right = newNode;
        }
        else
        {
            insertNodeRec(temp1->right, newNode);
        }
    }
}

//THIS IS THE IMPLEMENTATION OF AN QUEUE. IT IS USED IN levelOrder() FUNCTION.
int front = -1, rear = -1;
node* arr[100];

//THIS FUNCTION TAKES NODE AND ADD IT IN AN QUEUE.
void inQueue(node* temp)
{
    if(rear == 99)
    {
        return;
    }
    else if(front == -1 && rear == -1)
    {   
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] =  temp;
}

//THIS FUNCTION DELETE NODE FROM QUEUE.
void deQueue()
{
    if(front == -1 && rear == -1)
    {   
        return;
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

//THIS FUNCTION PRINTS TREE IN "LEVEL ORDER FORMATE"(BREADTH FIRST TRAVERSAL).
void levelOrder()
{
    node* temp = root;
    if (temp == NULL)
    {
        return;
    }
    inQueue(temp);
    printf("\nLEVEL ORDER TRAVERSAL TREE....");   
    while(front != -1 && rear !=-1)
    {
        node* cur = arr[front];
        printf("\t%d ", cur->data);
        if(cur->left != NULL)
        {
            inQueue(cur->left);
        }
        if(cur->right != NULL)
        {
            inQueue(cur->right);
        }
        deQueue();
    }
}

//THIS FUNCTION PRINTS TREE IN "INORDER FORMATE"(DEPTH FIRST TRAVERSAL).
void inOrder(node* temp)
{
    if(temp == NULL)
    {
        return;
    }
    inOrder(temp->left);
    printf("\t%d",temp->data);
    inOrder(temp->right);
}

//THIS FUNCTION PRINTS TREE IN "PREORDER FORMATE"(DEPTH FIRST TRAVERSAL).
void preOrder(node* temp)
{
    if(temp == NULL)
    {
        return;
    }
    printf("\t%d",temp->data);
    preOrder(temp->left);
    preOrder(temp->right);
}

//THIS FUNCTION PRINTS TREE IN "POSTORDER FORMATE"(DEPTH FIRST TRAVERSAL).
void postOrder(node* temp)
{
    if(temp == NULL)
    {
        return;
    }
    postOrder(temp->left);
    postOrder(temp->right);
    printf("\t%d",temp->data);
}

void main()
{
    while (1)
    {
        int n;
        printf("\n\n\n_____BINARY_SEARCH_TREE_____\n\n_____CHOOSE_YOUR_CHOICE_____\n 1. INSERT NODE\n 2. INSERT NODE USING RECURTION\n 3. INOREDER TRAVERSAL PRINT\n 4. PREORDER TRAVERSAL PRINT\n 5. POSTORDER TRAVERSAL\n 6. LEVEL ORDER TRAVERSAL\n 7. HEIGHT OF TREE\n 8. MAX VALUE IN TREE\n 9. MIN VALUE IN TREEE\n 0. EXIT\n\n ENTER YOUR CHOICE : ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            insertNode();
            break;

        case 2:
            insertNodeRec(root, creatNode());
            break;

        case 3:
            printf("\nINORDER TRAVERSAL TREE....\t");
            inOrder(root);
            break;
            
        case 4:
            printf("\nPREORDER TRAVERSAL TREE....\t");
            preOrder(root);
            break;

        case 5:
            printf("\nPOSTORDER TRAVERSAL TREE....\t");
            postOrder(root);
            break;

        case 6:
            levelOrder();
            break;

        case 7:
            printf("\nHEIGHT OF TREE = %d", findHeight(root));
            break;

        case 8:
            maxNode(root);
            break;

        case 9:
            minNode(root);
            break;

        case 0:
            exit(0);
            break;
        
        default:
            printf("_____YOU_ENTER_WRONG_CHOICE_____");
            break;
        }
    }
}
#include<stdio.h>
#include<stdlib.h>
struct btnode
{
int data;
struct btnode *lc;
struct btnode *rc;
};
int front=0,rear=0,i=0;
struct btnode*root;
struct btnode*queue[20];
int isempty()
{
    if(front>rear)
    return 1;
    else
        return 0;
}
void enqueue(struct btnode* node)
{
	rear=rear+1;
	queue[rear]=node;

}
struct btnode*dequeue()
{
 struct btnode*item;
 if(isempty())
 {
     return(NULL);
 }
    else{
        front=front+1;
		item=queue[front];
        return(item);
    }
}
void btcreate()
{
    int item1;
    struct btnode *newnode;
    struct btnode *newnode1;
    int item;
    struct btnode *p;
    printf("Enter the root node");
    root = (struct btnode*)malloc(sizeof(struct btnode));
    scanf("%d",&root->data);
    root->lc=NULL;
    root->rc=NULL;
    enqueue(root);

    while(front<rear)
    {
        p=dequeue();
        printf("\nEnter the left child of %d, Enter -999 if not present \n",p->data);
        scanf("%d",&item);
		if(item!=-999)
		{
        printf("\ncreating left child");
        newnode=(struct btnode*)malloc(sizeof(struct btnode));
		newnode->data=item;
		newnode->lc=NULL;
		newnode->rc=NULL;
		p->lc=newnode;
		enqueue(newnode);
		}
	printf("\nEnter the right child of %d, Enter -999 if not present\n",p->data);
	scanf("%d",&item);
	if(item!=-999)
	{
		newnode=(struct btnode*)malloc(sizeof(struct btnode));
		newnode->data=item;
		newnode->lc=NULL;
		newnode->rc=NULL;
		p->rc=newnode;
		enqueue(newnode);
	}
	}
}
void inorder(struct btnode*root)
{
    if(root==NULL)
return;
else{
    inorder(root->lc);
    printf("   %d",root->data);
    inorder(root->rc);
}
}
void preorder(struct btnode*root)
{
    if(root==NULL)
        return;
    else
    {
        printf("   %d",root->data);
        preorder(root->lc);
        preorder(root->rc);
    }
    }
void postorder(struct btnode*root)
{
    if(root==NULL)
        return;
    else{
        postorder(root->lc);
        postorder(root->rc);
        printf("   %d",root->data);
    }
}
struct btnode *searchnode(struct btnode *temp, int value){
    int status=0;
    if(temp == NULL){
        return temp;
    }
    else {
        searchnode(temp->lc,value);
        searchnode(temp->rc,value);
        if(temp->data == value){
          status=1;
    printf("Element found");
    }
    }
    if(status!=1){
    printf("Element not found\n");
    }
    return temp;
    }
    struct btnode *searchparent(struct btnode *q, int item, struct btnode *parent)
{
    struct btnode *ptr;
    static struct btnode *temp = NULL;
    ptr = q;
    if (ptr != NULL){
        if (ptr->data == item)
            temp = parent;
        searchparent(ptr->lc, item, ptr);
        searchparent(ptr->rc, item, ptr);
    }
    return temp;
}

void insertleaf(){
struct btnode *ptr, *new;
    int term, key, opt;
    printf("Enter the parent node to enter : ");
    scanf("%d",&key);
    printf("Enter the term to insert : ");
    scanf("%d",&term);
    ptr = searchnode(root,key);
    if (ptr == NULL)
    {
        printf("Parent not found");
        return;
    }
    else
    {
        printf("Enter the position to enter :");
        printf("\n1-lef\n2-right\nEnter the position : ");
        scanf("%d",&opt);
        if(opt == 1 && ptr->lc == NULL)
        {
            new = (struct btnode *)malloc(sizeof(struct btnode));
            new->data = term;
            new->lc = NULL;
            new->rc = NULL;
            ptr->lc = new;
        }
        else if(opt == 2 && ptr->rc == NULL)
        {
            new = (struct btnode *)malloc(sizeof(struct btnode));
            new->data = term;
            new->lc = NULL;
            new->rc = NULL;
            ptr->rc = new;
        }
        else
        {
            printf ("Insertion not possible");
        }
    }}
    void delete()
{
    struct btnode *ptr1, *ptr2, *parent;
    int item;
    if (root == NULL)
    {
        printf("Tree does not exist yet !!");
        return;
    }
    else
    {
        printf("Enter the term to delete : ");
        scanf("%d",&item);
        if (item == root->data)
        {
            printf("Root node cannot be deleted !!\n");
            return;
        }
        parent = searchparent(root, item, root);
        if (parent == NULL)
            printf("Item does not exist in the tree !!");
        else
        {
            ptr1 = parent->lc;
            ptr2 = parent->rc;
            if (ptr1->data == item)
            {
                if(ptr1->lc == NULL && ptr1->rc == NULL)
                    parent->lc = NULL;
                else
                    printf("Not a leaf node !!");
            }
            else if (ptr2->data == item)
            {
                if(ptr2->lc == NULL && ptr2->rc == NULL)
                    parent->rc = NULL;
                else
                    printf("Not a leaf node !!");
            }
        }
    }
}

void main()
{
     int opt,element,n;
while(opt!=8){
    printf("\nEnter the operation to perform: 1.Create 2.Inorder 3.Preorder 4.Postorder 5.Search 6.InsertLeaf 7.Delete 8.Exit");
    scanf("%d",&opt);
    if(opt==1||opt==2||opt==3||opt==4||opt==5||opt==6||opt==7||opt==8)
    {
        switch(opt){
        case 1: btcreate();
        break;
        case 2: printf("\nThe inorder sequence is : \n");
        inorder(root);
        break;
        case 3:printf("\nThe preorder sequence is : \n");
        preorder(root);
        break;
        case 4:printf("\nThe postorder sequence is : \n");
        postorder(root);
        break;
        case 5: printf("\nEnter the element to be searched");
        scanf(" %d",&element);
        searchnode(root,element);
        break;
        case 6:
        insertleaf();
        break;
        case 7:
        delete();
        break;
        case 8:
        exit(0);
    }
    }
    else
    printf("Operation not valid");
}
}

#include<stdlib.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 0
int visited[50];
int queue[50];
int n,front=0,rear=-1;

struct graph
{
    int data;
    struct graph *link;
};
struct graph *vertex[50];

void bfs(int v)
{
    struct graph *p;
    enqueue(v);
    int w;
    while(front!=rear)
    {
        v=dequeue();
        if(visited[v]==FALSE)
        {
        visited[v]=TRUE;
        printf("%d ",v);
        p=vertex[v];
        while(p!=NULL)
        {
            p=p->link;
            if(visited[p->data]==FALSE)
            enqueue(p->data);
        }
        }
    }
}

int create()
{
    int i,item;
    struct graph *p,*temp;
    printf("\nEnter the number of vertices in the graph :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        vertex[i]=(struct graph*)malloc(sizeof(struct graph));
        vertex[i]->data=i;
        vertex[i]->link=NULL;
        temp=vertex[i];
        printf("\n Enter the vertices adjacent to vertex %d (-999 to stop)\n",i);

    do{
        scanf("%d",&item);
        if(item==-999)
        {
          break;
        }
        else{
            p=(struct graph *)malloc(sizeof(struct graph));
            p->data=item;
            p->link=NULL;
            temp->link=p;
            temp=p;
        }
        }while(1);
    }
    return n;
}

int dequeue()
{
    int item;
    item=queue[front];
    front = front+1;
    return item;
}


void enqueue(int item)
{
    rear = rear+1;
    queue[rear]=item;
}

void main()
{
    int i;
    n=create();
    for(i=0;i<n;i++)
    {
        visited[i]=FALSE;
    }
    printf("Depth First traversal of the graph:\n");
    bfs(0);
}

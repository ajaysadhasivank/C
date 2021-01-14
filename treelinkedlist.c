#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1;

struct bintree{
int data;
struct bintree *LC;
struct bintree *RC;
};
struct bintree*queue[20];
struct bintree*root, *newnode, *p;

void enqueue(int n){
if(front==-1&&rear==-1){
front=0;
rear = 0;
}
queue[rear] = item;
rear++;
}

int dequeue(){
int temp;
temp = queue[front];
front++;
return temp;
}

void create(){
int item;
printf("Enter the root value");
scanf("%d",&item);
newnode = (struct bintree*)malloc(sizeof(struct bintree));
newnode->data = item;
newnode->LC = NULL;
newnode->RC = NULL;
root = newnode;
enqueue(item);
while(){

}
}

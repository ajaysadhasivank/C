#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,dq[50],maxsize=0,status=0;

int isfull(){
if(rear+1==maxsize){
return 1;
}
else{
return 0;
}
}

int isempty(){
if(front==-1||front>rear){
return 1;
}
else{
return 0;
}
}

void enqueuefront(int item){
if(rear==-1||front==-1){
rear = 0;
front = 0;
}
if(front==0){
printf("Addition from front is not possible now\n");
}
else{
front = front-1;
dq[front] = item;
}
}

void enqueuerear(int item){
if(front==-1){
front=0;
}
status=isfull();
if(status==1){
printf("The deque is full\n");
}
else{
rear = rear+1;
dq[rear] = item;
}
}

int dequeuefront(){
int del = 0;
status = isempty();
if(status==1){
printf("The deque is empty\n");
}
else{
del = dq[front];
front = front+1;
return del;
}
}

int dequeuerear(){
int del=0;
if(rear==-1||rear<front){
printf("Deletion from rear is not possible\n");
}
else{
  del = dq[rear];
  rear = rear-1;
  return del;
}
}

void display(){
    int i=0;
    status = isempty();
    if(status==1){
    printf("The deque is empty\n");
    }
    else{
    printf("The dequeue is ");
  for(i=front;i<=rear;i++){
    printf("%d",dq[i]);
  }
  printf("\n");
  }
}

void main(){
int op=0,item=0,dele=0;
printf("Enter the maximum number of elements");
scanf("%d",&maxsize);
while(op!=6){
printf("Enter the operation 1-insert front 2-insert rear 3- delete front 4- delete rear 5-display 6-Exit");
scanf("%d",&op);
switch(op){
case 1:
printf("Enter the number to be added");
scanf("%d",&item);
enqueuefront(item);
break;
case 2:
printf("Enter the number to be added");
scanf("%d",&item);
enqueuerear(item);
break;
case 3:
dele = dequeuefront();
printf("The deleted element is %d \n",dele);
break;
case 4:
dele = dequeuerear();
printf("The deleted element is %d \n",dele);
break;
case 5:
display();
break;
case 6:
exit(0);
break;
}
}
}

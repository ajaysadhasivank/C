#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,dq[50],status,maxsize;

void create(){
  front=-1;
  rear=-1;
}

void enqueuefront(){
  int item;
  printf("Enter the element to be added");
  scanf("%d",&item);
  if((rear+1)%maxsize==front){
    printf("The Circular Deque is full\n");
  }
  else if(front==-1 && rear==-1){
    front = 0;
    rear = 0;
    dq[front] = item;
  }
  else if(front==0){
    front = maxsize - 1;
    dq[front] = item;
  }
  else{
    front = front-1;
    dq[front] = item;
  }
  }


void enqueuerear(){
  int item;
  printf("Enter the element to be added");
  scanf("%d",&item);
    if((rear+1)%maxsize==front){
      printf("The Circular Deque is full\n");
    }
    else if(front==-1 && rear==-1){
      front = 0;
      rear = 0;
      dq[front] = item;
    }
    else if(rear ==maxsize-1){
      rear = 0;
      dq[rear] = item;
    }
    else{
      rear = rear+1;
      dq[rear] = item;
    }
}

void dequeuefront(){
  if(front==-1&&rear==-1){
    printf("The Circular Deque is empty\n");
  }
  else if(front==rear){
    printf("The deleted element is %d\n",dq[front]);
    front = -1;
    rear = -1;
  }
  else if(front==maxsize-1){
    printf("The deleted element is %d\n",dq[front]);
    front = 0;
  }
  else{
    printf("The deleted element is %d\n",dq[front]);
    front = front+1;
  }
}
void dequeuerear(){
  if(front==-1&&rear==-1){
    printf("The Circular Deque is empty\n");
  }
  else if(front==rear){
    printf("The deleted element is %d\n",dq[rear]);
    front = -1;
    rear = -1;
  }
  else if(rear==0){
    printf("The deleted element is %d\n",dq[rear]);
    rear = maxsize - 1;
  }
  else{
    printf("The deleted element is %d\n",dq[rear]);
    rear = rear-1;
  }
}

void display(){
  int i=front;
  if(front==-1&&rear==-1){
    printf("The Circular Deque is empty\n");
  }
  else{
  printf("The Circular deque is \n");
  for(i=front;i!=rear;i=(i+1)%maxsize){
    printf("%d",dq[i]);
  }
  printf("%d",dq[rear]);
  printf("\n");
}
}

void main(){
  int opt=0;
  printf("Enter the maximum number of elements in the deque");
  scanf("%d",&maxsize);
  while(opt!=7){
    printf("Enter the operation to perform 1-Create 2-Enqueuefront 3-Enqueuerear 4-Dequeuefront 5-Dequeuerear 6-Display 7-Exit");
    scanf("%d",&opt);
    switch(opt){
      case 1:
      create();
      printf("Dequeu initialised");
      break;
      case 2:
      enqueuefront();
      break;
      case 3:
      enqueuerear();
      break;
      case 4:
      dequeuefront();
      break;
      case 5:
      dequeuerear();
      break;
      case 6:
      display();
      break;
      case 7:
      exit(0);
    }
  }
}

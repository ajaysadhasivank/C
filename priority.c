#include<stdio.h>
#include<stdlib.h>
int maxsize,front=-1,rear=-1,max,i,status,inde;

struct priority{
  int value;
  int prio;
}queue[50];

int isfull(){
  if(rear==maxsize-1){
    return 1;
  }
  else
  return 0;
}

int isempty(){
  if(front==-1||front>rear){
    return 1;
  }
  else
  return 0;
}

int enqueue(int val, int pri){
  if(front==-1){
    front=0;
  }
  status = isfull();
  if(status==1){
    printf("The queue is full");
    return 0;
  }
  else{
    rear = rear+1;
    queue[rear].value = val;
    queue[rear].prio = pri;
    return 1;
  }
}

int dequeue(){
  status = isempty();
  if(status == 1){
    printf("The queue is empty");
    return 0;
  }
  else{
  max = queue[front].prio;
  for(i=front;i<=rear;i++){
    if(queue[i].prio>max){
      inde = i;
      max = queue[i].prio;
    }
    }
  for(i=inde;i<=rear;i++){
    queue[i].value = queue[i+1].value;
    queue[i].prio = queue[i+1].prio;
  }
  rear = rear-1;
  return 1;
}
}

void display(){
  status = isempty();
  if(status==1){
    printf("The queue is empty");
  }
  else{
    for(i=front;i<=rear;i++){
      printf("%d - %d",queue[i].value,queue[i].prio);
      printf("\n");
    }
  }
}

void main(){
  int ch=0,item,prio;
  printf("Enter the number of elements in the queue");
  scanf("%d",&maxsize);
  while(ch!=6){
  printf("\nEnter the operation to perform 1-Isempty 2-Isfull 3-Enqueue 4-Dequeue 5-Display 6-exit");
  scanf("%d",&ch);
  if(ch==1||ch==2||ch==3||ch==4||ch==5||ch==6){
    switch(ch){
      case 1:
      status = isempty();
      if(status==1){
        printf("The queue is empty");
      }
       else{
         printf("The queue is not empty");
       }
       break;
      case 2:
      status=isfull();
      if(status==1){
        printf("The queue is full");
      }
      else{
        printf("The queue is not full");
      }
      break;
      case 3:
      printf("Enter the queue value");
      scanf("%d",&item);
      printf("Enter the priority value");
      scanf("%d",&prio);
      status = enqueue(item, prio);
      if(status==1){
        printf("The numbers are added succesfully");
      }
      else{
        printf("\n failed");
      }
      break;
      case 4:
      status=dequeue();
      if(status==1){
        printf("The Numbers are deleted succesfully ");
      }
      else{
        printf("\n failed");
      }
      break;
       case 5:
       display();
       break;
       case 6:
       exit(0);
    }
  }
  else
  printf("The option is not valid");
}
}

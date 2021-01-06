#include<stdio.h>
#include<stdlib.h>
int maxsize=0,front=1,rear=1,max,i=0,status,inde=0;

struct cirpriority{
  int value;
  int prio;
}queue[50];

int isfull(){
  if((rear+1)%maxsize==front){
    return 1;
  }
  else
  return 0;
}

int isempty(){
  if(front==rear){
    return 1;
  }
  else
  return 0;
}

int enqueue(int val, int pri){
  status = isfull();
  if(status==1){
    printf("The queue is full");
    return 0;
  }
  else{
    rear = (rear+1)%maxsize;
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
  max = queue[(front+1)%maxsize].prio;
  inde = (front+1)%maxsize;
  for(i=(front+1)%maxsize;i!=(rear+1)%maxsize;i=(i+1)%maxsize){
    if(queue[i].prio>max){
      inde = i;
      max = queue[i].prio;
    }
    }
  for(i=inde;i!=(rear+1)%maxsize;i=(i+1)%maxsize){
  queue[i].value = queue[(i+1)%maxsize].value;
   queue[i].prio = queue[(i+1)%maxsize].prio;
  }
  if(rear=0){
    rear = maxsize-1;
  }
  else{
  rear = (rear-1)%maxsize;
  }
  return 1;
}
}

void display(){
  status = isempty();
  if(status==1){
    printf("The queue is empty");
  }
  else{
    for(i=(front+1)%maxsize;i!=(rear+1)%maxsize;i=(i+1)%maxsize){
      printf("%d - %d\n",queue[i].value,queue[i].prio);
    }
  }
}

void main(){
  int ch=0,item,prio;
  printf("Enter the number of elements in the queue");
  scanf("%d",&maxsize);
  while(ch!=6){
  printf("\nEnter the operation to perform 1-isempty 2-isfull 3-Enqueue 4-Dequeue 5-Display 6-exit");
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

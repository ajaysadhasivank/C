# include<stdio.h>
# include<stdlib.h>
int maxsize=0,front=1,rear=1,status;
int cqueue[50];

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

int enqueue(int item){
status = isfull();
if(status==1){
  printf("The circular queue is full");
  return 0;
}
else
rear = (rear+1)%maxsize;
cqueue[rear] = item;
return 1;
}

int dequeue(){
  int del;
  status = isempty();
  if(status==1){
    printf("The circular queue is empty");
    return 0;
  }
  else
  front = (front+1)%maxsize;
  return 1;
}

void display(){
  int i=0;
  status = isempty();
  if(status==1){
  printf("The circular queue is empty");
  }
  else{
  for(i=((front+1)%maxsize);(i!=(rear+1)%maxsize);(i=(i+1)%maxsize)){
  printf("%d",cqueue[i]);
}
}
}

void main(){
  int ch=0,item;
  printf("Enter the number of elements in the array");
  scanf("%d",&maxsize);
  while(ch!=6){
  printf("\nChoose the operation 1-Enqueue 2-Dequeue 3-isfull 4-isempty 5-Display 6-Exit");
  scanf("%d",&ch);
  if(ch==1||ch==2||ch==3||ch==4||ch==5||ch==6){
  switch(ch){
    case 1:
    printf("Enter the number to add");
    scanf("%d",&item);
    status = enqueue(item);
    if(status==1){
      printf("Number added successfully");
    }
    else
      printf("\nfailed");
    break;
    case 2:
    status = dequeue();
    if(status==1){
      printf("Number deleted successfully");;
    }
    else
      printf("\nFailed");
    break;
    case 3:
    status = isfull();
    if(status==1){
      printf("The circular queue is full");
    }
    else
      printf("The circular queue is not full");
    break;
    case 4:
    status = isempty();
    if(status==1){
      printf("The circular queue is empty");
    }
    else
      printf("The circular queue is not empty");
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

#include<stdio.h>
#include<stdlib.h>
int queue[50],maxsize,status=0,rear=-1,front=-1;

int create(){
  rear=-1;
  front=-1;
  return 1;
}

int isfull(){
	if(rear == maxsize-1){
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

int enqueue(int item){
status = isfull();
if(status==1){
	printf("The queue is full");
	return 0;
}
else{
	if(front==-1){
		front = 0;
	}
	rear = rear+1;
	queue[rear] = item;
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
    front = front+1;
    return 1;
	}
}

void display(){
    int i;
    status = isempty();
    if(status==1){
	printf("Empty queue");
    }
    else
    for(i=front;i<=rear;i++){
	printf("%d",queue[i]);
    }
}
   

void main(){
	int opt=0,item;
	printf("Enter the size of the queue");
	scanf("%d",&maxsize);
	while(opt!=7){
	printf("\nChoose an option 1-enqueue 2-dequeue 3-isempty 4-isfull 5-display 6-create 7-Exit");
	scanf("%d",&opt);
	if(opt==1||opt==2||opt==3||opt==4||opt==5||opt==6||opt==7){
	switch(opt){
	case 1:
	  printf("Enter the number to be added");
	  scanf("%d",&item);
	  status = enqueue(item);
	  if(status==1)
	  printf("Number added succesfully");
	  else
	  printf("\nfailed");
	  break;
	case 2:
      status = dequeue();
      if(status==1)
      printf("Deleted succesfully");
      else
      printf("\nfailed");
      break;
    case 3:
      status = isempty();
      if(status==1)
      printf("The queue is empty");
      else
      printf("The queue is not empty");
      break;
    case 4:
      status = isfull();
      if(status==1)
      printf("The queue is full");
      else
      printf("The queue is not full");
      break;
    case 5:
      display();
      break;
    case 6:
	  status = create();
	  if(status==1)
	  printf("Queue created successfully");
	  break;
	case 7:
	  exit(0);
}
}
else
printf("The operation is not valid");
}
}

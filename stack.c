#include <stdio.h>
#include <stdlib.h>
int stack[50],top=-1,maxsize;

void create(){
top = -1;
}

int isfull(){
if(top+1==maxsize)
return 1;
else
return 0;
}

int isempty(){
if(top==-1)
return 1;
else
return 0;
}

int push(int item){
if(isfull()==1){
printf("The stack is full");
return 0;
}
else{
top = top+1;
stack[top] = item;
return 1;
}
}

int pop(){
int del;
if(isempty()==1){
printf("The stack is empty");
return 0;
}
else{
del = stack[top];
top = top-1;
return 1;
}
}

void display(){
int status=0,i=0;
status = isempty();
if(status == 1){
    printf("The stack is empty");
}
else{
for(i=0;i<=top;i++){
printf("%d",stack[i]);
}
}
}

void main(){
int opt=0,new,status,choose=7;
create();
printf("Enter the size of the stack");
scanf("%d",&maxsize);
while(opt!=7){
printf("\nChoose an option 1. push 2. pop 3. isempty 4. isfull 5. Display 6. Create 7. Exit");
scanf("%d",&opt);
if(opt==1||opt==2||opt==3||opt==4||opt==5||opt==6||opt==7){
switch(opt){
case 1:
  printf("Enter the new element to be added");
  scanf("%d",&new);
  status = push(new);
  if(status == 1)
    printf("The number was added succesfully");
  else
    printf("\nFailed");
  break;
case 2:
  status = pop();
  if(status == 1)
    printf("Deleted succesfully");
  else
    printf("\nDeletion unsuccessful");
  break;
 case 3:
    status=isempty();
   if(status==1)
   printf("The stack is empty");
   else
   printf("The stack contains elements");
   break;
 case 4:
   status=isfull();
   if(status==1){
   printf("The stack is full");
   }
   else
   printf("The stack is not full");
   break;
 case 5:
   display();
   break;
 case 6: 
   create();
   printf("Stack was created succesfully");
   break;
 case 7:
   exit(0);
}
}
 else
printf("The option is not valid");
}
}

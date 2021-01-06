#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *link;
};
struct node*head, *newnode, *p ,*q;
//head = NULL;

void create(){
int item;
printf("To exit the loop enter -999");
while(1){
printf("\nEnter the number to be added");
scanf("%d",&item);
if(item==-999){
break;
}
else{
newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = item;
newnode->link = NULL;
if(head==NULL){
head = newnode;
}
else{
p = head;
while(p->link!=NULL){
  p = p->link;
}
p->link = newnode;
}
}
}
}

void merge(){
  int item=0;
  p=head;
  while(p!=NULL){
  p=p->link;
  }
  printf("To exit the loop enter -999");
  while(1){
  printf("\nEnter the number to be added");
  scanf("%d",&item);
  if(item==-999){
  break;
  }
  else{
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = item;
  newnode->link = NULL;
  if(head==NULL){
  head = newnode;
  }
  else{
  while(q->link!=NULL){
    printf("%d",q->data);
    q = q->link;
  }
  q->link = newnode;
  }
  }
  }
  p->link = q;
  //p=q;
}

void display(){
  printf("The linked list is");
  for(p=head;p!=NULL;p=p->link){
    printf("%d",p->data);
  }
  printf("\n");
}

void reverse(){
int i=0,rev[50];
printf("The reversed list is");
for(p=head;p!=NULL;p=p->link){
rev[i] = p->data ;
i++;
}
for(p=head;p!=NULL;p=p->link){
p->data = rev[i-1];
i--;
}
}

void duplicate(){
p = head;
if(p==NULL){
exit(0);
}
while(p->link!=NULL){
if(p->data==p->link->data){
q = p->link->link;
p->link = q;
free(p->link);
}
else{
p = p->link;
}
}
}

void main(){
int ch=0;
create();
display();
while(ch!=4){
printf("Enter the operation to perform 1-Merge 2 linked lists 2-Reverse the linked list 3-remove duplicates 4-exit");
scanf("%d",&ch);
switch(ch){
case 1:
merge();
display();
break;
case 2:
reverse();
display();
break;
case 3:
duplicate();
display();
break;
case 4:
exit(0);
break;
}
}
}

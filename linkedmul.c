#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
int exp;
struct node *link;
};
struct node*newnode, *head, *p, *head2, *q, *head3, *r;

void create(){
int item=0,expo=0;
printf("Enter the First polynomial values");
printf("Enter -999 to exit the loop\n");
while(1){
printf("Enter the coefficiant value");
scanf("%d",&item);
if(item==-999){
break;
}
else{
printf("Enter the exponential value");
scanf("%d",&expo);
newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = item;
newnode->exp = expo;
newnode->link = NULL;
if(head==NULL){
head = newnode;
}
else{
for(p=head;p->link!=NULL;p=p->link);
p->link=newnode;
}
}
}
}

void create2(){
  int item=0,expo=0;
  printf("Enter the second polynomial values");
  printf("Enter -999 to exit the loop\n");
  while(1){
  printf("Enter the coefficiant value");
  scanf("%d",&item);
  if(item==-999){
  break;
  }
  else{
  printf("Enter the exponential value");
  scanf("%d",&expo);
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = item;
  newnode->exp = expo;
  newnode->link = NULL;
  if(head2==NULL){
    head2 = newnode;
  }
  else{
  for(q=head2;q->link!=NULL;q=q->link);
  q->link = newnode;
  }
  }
}
}

void display(){
printf("The linked list is ");
for(p=head3;p!=NULL;p=p->link){
printf(" %d",p->data);
if(p->exp==0){
NULL;
}
else{
printf("x^%d",p->exp);
}
if(p->link!=NULL){
  printf("+");
}
}
}

void calcul(){
for(p=head;p!=NULL;p=p->link){
 for(q=head2;q!=NULL;q=q->link){
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = p->data*q->data;
  newnode->exp = p->exp+q->exp;
  newnode->link = NULL;
  if(head3==NULL){
    head3 = newnode;
  }
  else{
    for(r=head3;r->link!=NULL;r=r->link);
    r->link = newnode;
  }
 }
}
}

void main(){
create();
create2();
calcul();
display();
}

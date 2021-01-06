#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
int exp;
struct node *link;
};
struct node*p=NULL, *q=NULL, *r=NULL;

void create(struct node *newnode){
int item=0,expo=0;
printf("Enter -999 to terminate\n");
do{
printf("Enter the coefficient part");
scanf("%d",&item);
if(item==-999){
break;
}
else{
printf("Enter the exponent part");
scanf("%d",&expo);
newnode->data = item;
newnode->exp = expo;
newnode->link = (struct node*)malloc(sizeof(struct node));
newnode = newnode->link;
newnode->link = NULL;
}
}while(item!=-999);
}

void display(struct node *newnode){
while(newnode->link!=NULL){
printf(" %d",newnode->data);
if(newnode->exp==0){
NULL;
}
else{
printf("x^%d",newnode->exp);
}
if(p->link!=NULL){
printf("+");
}
newnode = newnode->link;
}
}

void calcul(struct node *p, struct node *q, struct node *r){
while(p->link &&q->link){
if(p->exp>q->exp){
r->data = p->data;
r->exp = p->exp;
p = p->link;
}
else if(q->exp>p->exp){
r->data = q->data;
r->exp = q->exp;
q = q->link;
}
else{
r->data = p->data+q->data;
r->exp = p->exp;
p = p->link;
q = q->link;
}
r->link = (struct node*)malloc(sizeof(struct node));
r = r->link;
r->link = NULL;
}
while(p->link || q->link){
if(p->link){
r->data = p->data;
r->exp = p->exp;
p=p->link;
}
if(q->link){
r->data = q->data;
r->exp = q->exp;
q=q->link;
}
r->link = (struct node*)malloc(sizeof(struct node));
r = r->link;
r->link = NULL;
}
}

void main(){
p = (struct node*)malloc(sizeof(struct node));
q = (struct node*)malloc(sizeof(struct node));
r = (struct node*)malloc(sizeof(struct node));
printf("Enter the first polynomial details\n");
create(p);
printf("Enter the second polynomial details");
create(q);
calcul(p, q, r);
printf("The linked list is");
display(r);
}

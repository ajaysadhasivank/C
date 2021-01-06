#include<stdio.h>
#include<stdlib.h>

//defining node
struct node{
  int data;
  struct node *link;
};
struct node*head, *newnode, *p; //global

void create(){ //function to create LL
  int item;
  printf("To exit the loop enter -999\n");
  while(1){
    //read item
    printf("Enter an item");
    scanf("%d",&item);
    if(item==-999)
    break;
    else{
    //create a newnode
    newnode = (struct node*)malloc(sizeof(struct node));
    // -> dereference to use pointer inside a structure like . in structure
    newnode->data = item;
    newnode->link = NULL;
    // checking if list is empty
    if(head==NULL){
      head = newnode;
    }
    else{
      p = head;
      while(p->link!=NULL){//traversing until end of node
        p = p->link;
      }
      p->link = newnode;
    }
  }
  }
}

void display(){
  printf("The linked list is ");
  for(p=head;p!=NULL;p=p->link){
    printf("%d ",p->data);
  }
  printf("\n");
}

void insert1(int pos,int item){
  int count=0;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = item;
  newnode->link = NULL;
  p = head;
  for(count=0;count<pos;count++){
  count++;
    p = p->link;
  }
  newnode->link = p->link;
  p->link = newnode;
}

int delete1(int pos){
  struct node *q;
  int count = 0,item;
  p = head;
  while(count<pos){
    q = p->link;
    count ++;
    if(count<pos){
    p = p->link;
  }
  }
  item = q->data;
  p->link = q->link;//deletion
  free(q);
  return(item);
}

void append(int item){
newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = item;
newnode->link = NULL;
for(p=head;p->link!=NULL;p=p->link);
p->link = newnode;
display();
}

void prepend(int item){
newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = item;
newnode->link = NULL;
newnode->link = head;
head = newnode;
display();
}

int del_head(){
int delterm;
p = head;
head = head->link;
delterm = head->data;
free(p);
return(delterm);
}

int del_tail(){
struct node *q;
int delterm;
p = head;
while(p->link!=NULL){
  q = p;
  p = p->link;
}
q->link = NULL;
delterm = p->data;
free(p);
return(delterm);
}

void main(){
  int opt=0,position,pos,del,item;
  create();
  display();
  while(opt!=8){
    printf("Enter the operation 1.Display 2.Insert 3.Delete 4.append 5.prepend 6.delete_head 7.delete_tail 8.Exit");
    scanf("%d",&opt);
    switch(opt){
      case 1:
      display();
      break;
      case 2:
      printf("Enter the position to add");
      scanf("%d",&position);
      printf("Enter the number to be added");
      scanf("%d",&item);
      insert1(position,item);
      display();
      break;
      case 3:
      printf("Enter the position from which the node is to be deleted");
      scanf("%d",&pos);
      del = delete1(pos);
      printf("The deleted element is %d \n",del);
      display();
      break;
      case 4:
      printf("Enter the term to append");
      scanf("%d",&item);
      append(item);
      break;
      case 5:
      printf("Enter the number to Prepend");
      scanf("%d",&item);
      prepend(item);
      break;
      case 6:
      del = del_head();
      printf("\nThe delted elementis %d \n",del);
      display();
      break;
      case 7:
      del = del_tail();
      printf("\nThe delted elementis %d \n",del);
      display();
      break;
      case 8:
      exit(0);
      break;
    }
  }
}

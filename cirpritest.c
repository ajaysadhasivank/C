#include<stdio.h>
#include<stdlib.h>
int max,f=1,r=1,in,i,del,high;
struct priorityc
{
  int val,prio;
}p[30];
int IsFull()
{
  if(((r+1)%max)==f)
  return 1;
  else
  return 0;
}
int IsEmpty()
{
  if(f==r)
    return 1;
  else
    return 0;
}
void Enqueue(int item,int pr)
{
  if(IsFull())
  {
    printf("\nQueue is full");
  }
  else
  {
    r=(r+1)%max;
    p[r].val=item;
    p[r].prio=pr;
  }
}
int Dequeue()
{
    if(IsEmpty())
      return (-999);
    else
    {
      high=p[(f+1)%max].prio;
      in=(f+1)%max;
      for(i=(f+1)%max;i!=(r+1)%max;i=(i+1)%max)
      {
        if(p[i].prio>high){
        in=i;
        high=p[i].prio;
      }

      }del=p[in].val;
      for(i=in;i!=(r+1)%max;i=(i+1)%max)
      {
        p[i].val=p[(i+1)%max].val;
          p[i].prio=p[(i+1)%max].prio;
      }r=(r-1)%max;
    }
    return del;
}
void Display()
{
  if(IsEmpty())
  {
    printf("\nEmpty!!");
  }
  else
  {
    for(i=(f+1)%max;i!=(r+1)%max;i=(i+1)%max)
    printf("%d\t%d\n",p[i].val,p[i].prio);
  }

}

void main()
{
  int ch,result,item,pr;
  printf("\nEnter the size of the queue:");
  scanf("%d",&max);
  do{
  printf("\nEnter your choice:\n1.IsEmpty\n2.IsFull\n3.Enqueue\n4.Dequeue\n5.Display\n6.Exit");
  scanf("%d",&ch);
  switch(ch)
  {

    case 1:
      result=IsEmpty();
      if(result==1)
      printf("\nEmpty!!");
      else
      printf("\nQueue has elements");
      break;

    case 2:
      result=IsFull();
      if(result==1)
      printf("\nFull");
      else
      printf("\nNot full!!");
      break;


    case 3:
    {
    printf("\nEnter the item:");
    scanf("%d",&item);
    printf("\nEnter the priority:");
    scanf("%d",&pr);
    Enqueue(item,pr);
  }break;
    case 4:
    {
      result=Dequeue();
      if(result==-999)
      {
        printf("\nQueue is empty ");
      }
      else
      {
        printf("\nThe element %d was deleted",del);
      }
    }break;



    case 5:
      Display();break;

    case 6:
      exit(0);

    }
  }while(ch!=6);
  }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top,j=-1;
char stack[10];
char post[50];
int stackop[50];
void create()
{
top=0;
stack[top]='$';
}
void push(char a)
{
top=top+1;
stack[top]=a;
}
char pop()
{
char g;
g=stack[top];
top=top-1;
return g;
}
int isp(char f)
{
switch(f)
{
case '^':
return 3;
break;
case '*':
case '/':
return 2;
break;
case '+':
case '-':
return 1;
break;
case '(':
return 0;
break;
case '$':
return -1;
break;
}
}
int icp(char f)
{
switch(f)
{
case '^':
return 4;
break;
case '*':
case '/':
return 2;
break;
case '+':
case '-':
return 1;
break;
case '(':
return 4;
break;
}
}

void pushop(int temp){
j=j+1;
stackop[j] = temp;
}

int popop(){
int temp=0;
temp = stackop[j];
j=j-1;
return(temp);
}

void resul(char post []){
int i=0,a=0,b=0,res=0,temp=0;
char ch;
ch = post[i];
while(ch!='\0'){
if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='0'){
temp = ch - '0';
pushop(temp);
}
else{
  b = popop();
  a = popop();
  switch(ch){
    case '+':
    res = a+b;
    break;
    case '-':
    res = a-b;
    break;
    case '*':
    res = a*b;
    break;
    case '/':
    res = a/b;
    break;
    case '^':
    res = a/b;
    break;
}
pushop(res);
}
i++;
ch = post[i];
}
}

void main()
{
  int i,p=0;
char str[20],y;
 create();
printf("\nEnter a infix expression: ");
scanf("%s",str);
 printf("\nThe post fix expression is: ");
for(i=0; str[i] != '\0'; i++)
{
 if ((str[i]>='0' && str[i]<='9') )
{printf("%c",str[i]);
post[p] = str[i];
p++;

}
else if(str[i]==')')
{
while(stack[top]!='(')
 {
 y=pop();
 printf("%c",y);
 post[p] = y;
 p++;
}
y=pop();
}
else
{
while(isp(stack[top])>=icp(str[i]))
{
y=pop();
printf("%c",y);
post[p] = y;
p++;
}
push(str[i]);
}
}
while(stack[top]!='$')
{
y=pop();
printf("%c",y);
post[p] = y;
p++;
}
resul(post);
printf("\nThe result is");
printf("%d",stackop[0]);
}

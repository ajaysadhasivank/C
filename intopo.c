#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int top=-1,x,j=0,topop=-1,res[50];
char ch,stack[50],check1,check2,item,post[50];

int digit(char ch){
if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='0'){
  return 1;
}
else{
return 0;
}
}

void push(int item){
  top = top+1;
  stack[top] = item;
}

char pop(){
 if(top<0){
   printf("Stack underflow: invalid expression");
   exit(1);
 }
 else{
   item = stack[top];
   top = top-1;
   return(item);
 }
}

int isp(char check1){
if(check1=='^'){
  return 3;
}
else if(check1=='*'||check1=='/'||check1=='%'){
  return 2;
}
else if(check1=='+'||check1=='-'){
  return 1;
}
else if(check1=='('){
  return 0;
}
else{
  return -1;
}
}

int icp(char check2){
  if(check2=='^'){
    return 4;
  }
  else if(check2=='*'||check2=='/'||check2=='%'){
    return 2;
  }
  else if(check2=='+'||check2=='-'){
    return 1;
  }
  else if(check2=='('){
    return 4;
  }
}

int isoperator(char ch){
  if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
    return 1;
  }
  else{
    return 0;
  }
}

void intopo(char str[], char post[]){
  int i=0;
  push('(');
  strcat(str,")");
  ch = str[i];
  while(ch!='\0'){
    if(ch=='('){
      push(ch);
    }
    else if(digit(ch)==1){
      post[j] = ch;
      j++;
    }
    else if(isoperator(ch)==1){
      x = pop();
      while(isoperator(x)==1 && isp(x)>=icp(ch)){
        post[j] = x;
        j++;
        x = pop();
      }
      push(x);
      push(ch);
      }
      else if(ch==')'){
        x = pop();
        while(x!='('){
          post[j] = x;
          j++;
          x = pop();
        }
      }
      else{
        printf("Invalid expression input");
        exit(0);
      }
      i++;
      ch = str[i];
}
}

int popop(){
  int sent=0;
  if(topop==-1){
    printf("empty");
  }
  else{
  sent = res[topop];
  topop = topop-1;
  return(sent);
}
}

void pushop(char ch){
  int conv;
  topop = topop+1;
  conv = ch - '0';
  res[topop] = conv;
}

void calc(char post[]){
  int i,a=0,b=0,result=0;
  char conv1;
for(i=0;post[i]!='\0';i++){
  ch = post[i];
  if(digit(ch)==1){
    pushop(ch);
  }
 else if(isoperator(ch) == 1){
   b = popop();
   a = popop();
  switch(ch){
    case '+':
    result = a+b;
      break;
    case '-':
    result = a-b;
      break;
    case '*':
    result = a*b;
      break;
    case '/':
    result = a/b;
      break;
    case '^':
    result = a^b;
      break;
  }
  conv1 = result +'0';
  pushop(conv1);
}
}
}

void main(){
  char str[50];
  printf("Enter the infix expression");
  scanf("%s",str);
  intopo(str,post);
  printf("The postfix expression is");
  puts(post);
  calc(post);
  printf("The result is ");
  printf("%d",res[0]);
}

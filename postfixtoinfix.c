#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void main(){
  char stack[50];
  char ch;
  int a,b,res,i=-1,top,j;
  printf("Enter the postfix expression elements");
  scanf("%s",stack);
    while(top>=2){
      i = i+1;
    if(stack[i]=='+'||stack[i]=='-'||stack[i]=='*'||stack[i]=='/'||stack[i]=='%'){
      ch = stack[i];
      a = atoi(stack[i-2]);
      b = atoi(stack[i-1]);
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
        case '%':
        res = a%b;
        break;
      }
      stack[i-2] = itoa(res);
      for(j=i-1;j<top;j++){
        stack[j] = stack[j+2];
      }
      top = top-2;
    }
  }
  for(i=0;i<top;i++){
  printf("The value is %s",stack[i]);
}
}

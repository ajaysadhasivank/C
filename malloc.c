#include<stdio.h>
#include<stdlib.h>

void main(){
int n,i,sum=0;
int *p;
printf("Enter the limit of numbers to be added in the list");
scanf("%d",&n);
p = (int*)malloc(n*sizeof(int));
for(i=0;i<n;i++){
  p[i] = i+1;
}
printf("The sum of the numbers in the list is\n");
for(i=0;i<n;i++){
  sum = sum+p[i];
}
  printf("%d",sum);
}

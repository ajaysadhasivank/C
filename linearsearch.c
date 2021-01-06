#include  <stdio.h>

void main()
{
  int n,i=0,x,flag=0,a[10];
  printf("Enter the number of elements in the array");
  scanf("%d",&n);
  printf("Enter the array elements");
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("Enter the number to be searched");
  scanf("%d",&x);
   for(i=0;i<n;i++){
       if(a[i]==x){
           printf("The number is present at %d position in the array",i+1);
           flag=1;
       }
   }
    if(flag==0){
        printf("The number is not present in the array");
    }
}

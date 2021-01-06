#include<stdio.h>
void main()
{
    int a[10],i,n=0,low=0,high=0,mid=0,key,mark=0;
    printf("Enter the number of elements in the array");
    scanf("%d",&n);
    printf("Enter the array elements in asscending order");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the number to be searched");
    scanf("%d",&key);
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low<=high){
    if(a[mid]<key)
        low=mid+1;
    else if (a[mid]==key){
        printf("%d was found in %d position",key,mid+1);
        mark = 1;
        break;
    }
        else
            high=mid-1;
            mid = (high+low)/2;
    }
    if(mark==1){
          return 0;
    }
    else{
        printf("The number was not found");
    }
}

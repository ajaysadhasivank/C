#include<stdio.h>
void main()
{
    int m,n,spm[50][3],i=0,j=0,arr[10][10],k;
    printf("Enter the number of elements in the row");
    scanf("%d",&m);
    printf("Enter the number of elements in the column");
    scanf("%d",&n);
    for(i=0;i<m;i++){
       printf("Enter the %d row elements",i+1);
        for(j=0;j<n;j++){
           scanf("%d",&arr[i][j]);
        }
    }
    spm[0][0]=m;
    spm[0][1]=n;
    k=1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(arr[i][j] != 0){
                spm[k][0]=i;
                spm[k][1]=j;
                spm[k][2]=arr[i][j];
                k++;
            }
        }
    }
    spm[0][2]=k-1;
    for(i=0;i<k;i++){
        printf("%d \t",spm[i][0]);
        printf("%d \t",spm[i][1]);
        printf("%d \n",spm[i][2]);
    }
}

#include  <stdio.h>

void main()
{
 int n=0,m=0,i=0,tr[5][3],j,a=0,b=0,arr[10][10],r=0,k,l,v;
    printf("Enter the number of rows and columns in the sparse matrix");
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            arr[i][j]=0;
        }
    }

    printf("Enter the number of rows in the triplet table");
    scanf("%d",&r);
    for(i=0;i<r;i++){
        printf("Enter the row and column value");
        scanf("%d%d",&k,&l);
        printf("Enter the value");
        scanf("%d",&v);
        arr[k][l]=v;
    }
    printf("The sparse matrix is \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d \t",arr[i][j]);
        }
        printf("\n");
    }
}

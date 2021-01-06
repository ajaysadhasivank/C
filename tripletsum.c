#include<stdio.h>

int n=0,m=0,i,j,r=0,k,l,v,res[50][50],fir[50][50],sec[50][50];
void tritospar(int arr[50][50])
{
    printf("Enter the number of rows and columns in the sparse matrix");
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            arr[i][j]=0;
        }
    }
    printf("Enter the number of rows in the triplet table\n");
    scanf("%d",&r);
    for(i=1;i<=r;i++){
        printf("Enter the row and column value");
        scanf("%d%d",&k,&l);
        printf("Enter the value");
        scanf("%d",&v);
        arr[k][l]=v;
    }
    }

    void display(int arr[50][50]){
    printf("The sparse matrix is \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%d \t",arr[i][j]);
        }
        printf("\n");
    }
  }

  void calcul(int arr[50][50], int arr1[50][50], int res[50][50]){
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            res[i][j]=arr[i][j]+arr1[i][j];
        }
    }
  }

    void main(){
    printf("Enter the first triplet table\n");
    tritospar(fir);
    display(fir);
    printf("Enter the second triplet table\n");
    tritospar(sec);
    display(sec);
    calcul(fir,sec,res);
    display(res);
    }

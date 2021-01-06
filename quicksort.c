#include<stdio.h>
#include<stdlib.h>

void sort(int* a, int* b){
int temp;
temp = *a;
*a = *b;
*b = temp;
}

int partition (int arr[], int l, int h)
{
	int pivot;
	int i;
  pivot = arr[h];
	i = l-1;
	for (int j = l; j <= h- 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			sort(&arr[i], &arr[j]);
		}
	}
	sort(&arr[i + 1], &arr[h]);
	return (i + 1);
}

void quickSort(int arr[], int l, int h)
{
	int p;
	if (l<h)
	{
	p = partition(arr, l, h);
		quickSort(arr, l, p - 1);
		quickSort(arr, p + 1, h);
	}
}

void main()
{
	int n,i;
	int arr[50];
	printf("Enter the number of elements in the array");
	scanf("%d",&n);
	printf("Enter the elements");
	for(i=0;i<n;i++){
	scanf("%d",&arr[i]);
	}
	quickSort(arr, 0, n-1);
	printf("Sorted array: \n");
	for(i=0;i<n;i++){
	printf("%d ",arr[i]);
	}
}

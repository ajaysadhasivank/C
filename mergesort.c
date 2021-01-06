#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int mid, int h)
{
	int i, j, k, n1, n2;
	int temp1[50], temp2[50];
	n1 = mid - l + 1;
	n2 = h - mid;
	for (i = 0; i < n1; i++)
		temp1[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		temp2[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (temp1[i] <= temp2[j]) {
			arr[k] = temp1[i];
			i++;
			k++;
		}
		else {
			arr[k] = temp2[j];
			j++;
			k++;
		}
	}

	while (i < n1) {
		arr[k] = temp1[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = temp2[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int h)
{
	int mid;
	if (l < h) {
		mid = l + (h - l) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, h);
		merge(arr, l, mid, h);
	}
}

void main()
{
	int arr[50],n,i;
	printf("Enter the number of elements in the array");
	scanf("%d",&n);
	printf("Enter the elements");
  for(i=0;i<n;i++){
	scanf("%d",&arr[i]);
	}
	mergeSort(arr, 0, n - 1);
	printf("Sorted array is \n");
	for (i = 0; i < n; i++)
	printf("%d ", arr[i]);
}

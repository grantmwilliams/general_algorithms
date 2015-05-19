//QuickSort C++ Implementation (NonParallel)
#include <iostream>

void quickSort(int arr[], int left, int right){
	int i = left, j = right;
	int temp;
	int pivot = arr[(left + right)/2];

	/* Begin Partition */
	while (i <= j){
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j){
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	/* Recursion */
	if (left < j)
		quickSort(arr,left, j);
	if (i < right)
		quickSort(arr, i, right);
}
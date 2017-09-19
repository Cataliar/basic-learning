#include <stdio.h>

#define N 20

int partition(int a[], int low, int high) {
	int pivot = a[low];
	while(low < high) {
		while(low < high && a[high] >= pivot) 
			--high;
		a[low] = a[high];
		while(low < high && a[low] <= pivot) 
			++low;
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}

void qsort(int a[], int low, int high) {
	if(low < high) {
		int pivotloc = partition(a, low, high);
		qsort(a, low, pivotloc-1);
		qsort(a, pivotloc+1, high);
	}
}

void quicksort(int a[], int n) {
	qsort(a, 0, n - 1);
}

int main(void) {
	int n = 8, i;
	int arr[N] = {49, 38, 65, 97, 76, 13, 27, 49};
	quicksort(arr, n);
	for(i = 0; i < n; ++i) {
		printf("%d", arr[i]);
		if(i == n-1)
			printf("\n");
		else 
			printf(" ");
	}
	return 0;
}

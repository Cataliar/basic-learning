#include <stdio.h>

#define N 20

void selectsort(int a[], int n) {
	int i, j, k;
	for(i = 0; i < n; ++i) {
		int min = a[i];
		for(j = i+1; j < n; ++j) {
			if(a[j] < min) {
				min = a[j];
				k = j;
			}
		}
		a[k] = a[i];  //a[k] == min
		a[i] = min;
	}
}

int main(void) {
	int n = 8, i;
	int arr[N] = {49, 38, 65, 97, 76, 13, 27, 49};
	selectsort(arr, n);
	for(i = 0; i < n; ++i) {
		printf("%d", arr[i]);
		if(i == n-1)
			printf("\n");
		else 
			printf(" ");
	}
	return 0;
}

#include <stdio.h>

#define N 20

void insertsort(int a[], int n) {
	int i, j;
	for(i = 1; i < n; ++i) {
		if(a[i] < a[i-1]) {
			int tmp = a[i];
			for(j = i; j > 0 && a[j-1] > tmp; --j) {
				a[j] = a[j-1];
			}
			a[j] = tmp;
		}
	}
}

int main(void) {
	int n = 8, i;
	int arr[N] = {49, 38, 65, 97, 76, 13, 27, 49};
	insertsort(arr, n);
	for(i = 0; i < n; ++i) {
		printf("%d", arr[i]);
		if(i == n-1)
			printf("\n");
		else 
			printf(" ");
	}
	return 0;
}

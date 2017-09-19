#include <stdio.h>

#define N 20

void shellinsert(int a[], int n, int d) {
	int i, j;

	for(i = d; i < n;++i) {
		if(a[i] < a[i-d]) {
			int tmp = a[i];
			for(j = i-d; j >= 0 && a[j] > tmp; j -= d) {
				a[j+d] = a[j];
			}
			a[j+d] = tmp;
		}
	}
}

void shellsort(int a[], int n, int dlta[], int t) {
	int k;
	for(k = 0; k < t; ++k) {
		shellinsert(a, n, dlta[k]);
	}
}

int main(void) {
	int n = 8, i;
	int arr[N] = {49, 38, 65, 97, 76, 13, 27, 49};
	int t = 3;
	//dlta[k] = 2 ^ (t - k) - 1, 0 <= k < t <= log(n+1)
	int dlta[N] = {7, 3, 1};
	shellsort(arr, n, dlta, t);
	for(i = 0; i < n; ++i) {
		printf("%d", arr[i]);
		if(i == n-1)
			printf("\n");
		else 
			printf(" ");
	}
	return 0;
}

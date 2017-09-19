#include <stdio.h>

#define N 20

void heapadjust(int a[], int low, int high) {
	//assume that a[low...high] is a heap except a[low], 
	//now we must find the right location of a[low]
	int tmp = a[low];
	int i;
	//0 <= i <= n-1, root: i, left: 2*(i+1)-1, right: 2*(i+1)
	for(i = 2 * (low + 1) - 1; i <= high; i = 2 * (i + 1) - 1) {
		if(i < high && a[i] < a[i+1]) 
			++i;
		if(tmp >= a[i]) 
			break;
		a[low] = a[i];  //swap a[low] and a[i], then a[i] is the new a[low]
		low = i;
	}
	a[low] = tmp;
}

void heapsort(int a[], int n) {
	int i;
	//make a[n] into a heap
	for(i = (n - 1) / 2; i >=0; --i) 
		heapadjust(a, i, n - 1);
	for(i = n - 1; i > 0; --i) {
		//swap a[0] and a[i]
		int tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		heapadjust(a, 0, i - 1);
	}
}

int main(void) {
	int n = 8, i;
	int arr[N] = {49, 38, 65, 97, 76, 13, 27, 49};
	heapsort(arr, n);
	for(i = 0; i < n; ++i) {
		printf("%d", arr[i]);
		if(i == n-1)
			printf("\n");
		else 
			printf(" ");
	}
	return 0;
}

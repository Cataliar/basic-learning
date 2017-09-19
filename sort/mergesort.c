#include <stdio.h>

#define N 20

//merge sa[low...mid] and sa[mid+1...high] into ta[low...high]
void merge(int sa[], int ta[], int low, int mid, int high) {
	int i, k;

	k = low;
	for(i = mid + 1; low <= mid && i <= high;) {
		if(sa[low] <= sa[i]) 
			ta[k] = sa[low++];
		else
			ta[k] = sa[i++];
		++k;
	}
	while(low <= mid) 
		ta[k++] = sa[low++];
	while(i <= high) 
		ta[k++] = sa[i++];
}

void msort(int sa[], int ta[], int low, int high) {
	int ta1[N];
	if(low == high) 
		ta[low] = sa[low];
	else {
		int mid = (low + high) / 2;
		msort(sa, ta1, low, mid);
		msort(sa, ta1, mid+1, high);
		merge(ta1, ta, low, mid, high);
	}
}

void mergesort(int a[], int n) {
	msort(a, a, 0, n - 1);
}

int main(void) {
	int n = 8, i;
	int arr[N] = {49, 38, 65, 97, 76, 13, 27, 49};
	mergesort(arr, n);
	for(i = 0; i < n; ++i) {
		printf("%d", arr[i]);
		if(i == n-1)
			printf("\n");
		else 
			printf(" ");
	}
	return 0;
}

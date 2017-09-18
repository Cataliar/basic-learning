#include <stdio.h>

#define N 10
#define INF 65536

int line[N];  //assume a position in each row
//y = k * x + b, in this case k = 1, 
//so y = x + b, then one b represents a line
int b1[N];
//y = -x + b
int b2[N];

int unattack(int x, int y) {
	int i;
	for(i = 0; i < x; ++i) {
		if(line[i] == y) 
			return 0;
	}
	for(i = 0; i < x; ++i) {
		if(b1[i] == y - x) 
			return 0;
		if(b2[i] == y + x) 
			return 0;
	}
	return 1;
}

void trial(int i, int n) {
	//assume that we had put i-1 pieces which does not attack each other
	//in the first i-1 lines in n * n chessboard
	//from now on we find a suitable position for line i
	int j;
	if(i >= n) {
		return;
	}
	for(j = 0; j < n; ++j) {
		if(unattack(i, j)) {
			line[i] = j;
			b1[i] = j - i;
			b2[i] = j + i;
			trial(i+1, n);
		}
	}
}

int main(void) {
	int i;
	int n = 8;

	for(i = 0; i < n; ++i) {
		b1[i] = INF;
		b2[i] = INF;
	}
	trial(0, n);
	for(i = 0; i < n; ++i) {
		printf("%d ", b1[i]);
	}
	printf("\n");
	for(i = 0; i < n; ++i) {
		printf("%d ", b2[i]);
	}
	printf("\n");
	for(i = 0; i < n; ++i) {
		printf("(%d, %d)", i, line[i]);
	}
	printf("\n");
	return 0;
}

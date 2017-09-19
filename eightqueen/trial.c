#include <stdio.h>

#define N 10
#define INF 65536

int line[N];  //assume a position in each row
int col[N];
//y = k * x + b, in this case k = 1, 
//so y = x + b, then one b represents a line
int b1[2 * N];
//y = -x + b
int b2[2 * N];

int unattack(int x, int y) {
	if(col[y] == 1) 
		return 0;
	if(b1[y-x+N] == 1) 
		return 0;
	if(b2[x+y] == 1) 
		return 0;
	return 1;
}

int trial_oneanswer(int i, int n) {
	int j, ret = 0;
	if(i >= n) {
		return 1;
	}
	for(j = 0; j < n; ++j) {
		if(unattack(i, j)) {
			line[i] = j;
			col[j] = 1;
			b1[j-i+N] = 1;
			b2[j+i] = 1;
			ret = trial_oneanswer(i+1, n);
			if(ret == 1) 
				break;
			col[j] = 0;
			b1[j-i+N] = 0;
			b2[j+i] = 0;
		}
	}
	return ret;
}

int k = 0;

void trial(int i, int n) {
	//assume that we had put i-1 pieces which does not attack each other
	//in the first i-1 lines in n * n chessboard
	//from now on we find a suitable position for line i
	int j;
	if(i >= n) {
		printf("%d:", ++k);
		for(j = 0; j < n; ++j) {
			printf("(%d, %d)", j, line[j]);
		}
		printf("\n");
		return;
	}
	for(j = 0; j < n; ++j) {
		if(unattack(i, j)) {
			line[i] = j;
			col[j] = 1;
			b1[j-i+N] = 1;
			b2[j+i] = 1;
			trial(i+1, n);
			col[j] = 0;
			b1[j-i+N] = 0;
			b2[j+i] = 0;
		}
	}
}

int main(void) {
	//int i;
	int n = 8;

	trial(0, n);
	/*i = trial_oneanswer(0, n);
	if(i > 0) {
		for(i = 0; i < n; ++i) {
			printf("(%d, %d)", i, line[i]);
		}
		printf("\n");
	}
	else
		printf("no answer\n");*/
	return 0;
}

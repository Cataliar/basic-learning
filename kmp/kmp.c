#include <stdio.h>
#include <string.h>

/**
 * str:'S0S1...Sn-1', substr:'P0P1...Pm-1'
 * if str[i] != substr[j], then str[i] should compare with substr[k],
 * 0 < k < j, in this case there is 'P0P1...Pk' == 'Si-kSi-k+1...Si-1',
 * k should be as large as it can.
 * and we know that 'Pj-kPj-k+1..Pj-1' == 'Si-kSi-k+1...Si-1',
 * so 'P0P1...Pk-1' == 'Pj-kPj-k+1...Pj-1'
 * let next[j] = k, then
 *           -1, j == 0(str[i] != substr[0], increase i)
 * next[j] = max{k|0<k<j&&'P0P1...Pk-1'=='Pj-kPj-k+1...Pj-1'}, if k exists
 *           0, other cases
 */

#define N 100

char str[N] = "acabaabaabcacaabc";
char substr[N] = "abaabcac";

void get_next(char s[], int n, int next[]) {
	int i, j;
	next[0] = -1;
	i = 0;
	j = -1;
	while(i < n) {
		if(j == -1 || s[i] == s[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else 
			j = next[j];
	}
}

int index_kmp(char s[], int slen, char t[], int tlen, int pos, int next[]) {
	int i = pos, j = 0;
	while(i < slen && j < tlen) {
		if(j == 0 || s[i] == t[j]) {
			++i;
			++j;
		}
		else 
			j = next[j];
	}
	if(j >= tlen) 
		return i - tlen;
	return 0;
}

int main(void) {
	int i, n;
	int next[N];
	n = strlen(substr);
	get_next(substr, n, next);
	printf("next[j]:");
	for(i = 0; i < n; ++i) {
		printf("%d ", next[i]);
	}
	printf("\n");
	i = index_kmp(str, strlen(str), substr, n, 0, next);
	printf("index = %d\n", i);
	return 0;
}

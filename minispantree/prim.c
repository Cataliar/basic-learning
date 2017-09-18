#include <stdio.h>

#define DEBUG 1

#define N 10
#define INF 65535

int vexnum = 6;
int graph[N][N] = {
	{  0,   6, 1,   5, INF, INF},
	{  6,   0, 5, INF,   3, INF},
	{  1,   5, 0,   5,   6,   4},
	{  5, INF, 5,   0, INF,   2},
	{INF,   3, 6, INF,   0,   6},
	{INF, INF, 4,   2,   6,   0}
};

int lowcost[N];
int adjvex[N];

int prim(int start) {
	int i, k = 0;
	int min;
	int cost = 0;

	adjvex[k] = start;  //add the first vertex
	for(i = 0; i < vexnum; ++i) {
		lowcost[i] = graph[start][i];  //init lowcost
	}

#if DEBUG
	printf("\n");
#endif
	for(k = 1; k < vexnum; ++k) {
		min = INF;
		for(i = 0; i < vexnum; ++i) {
#if DEBUG
			printf("%d", lowcost[i]);
			if(i != vexnum - 1) 
				printf(" ");
			else
				printf("\n");
#endif
			//select min lowcost
			if(lowcost[i] != 0 && lowcost[i] < min) {
				min = lowcost[i];
				adjvex[k] = i;  //add next vertex
			}
		}
		lowcost[adjvex[k]] = 0;  //set reached vertex cost as 0
		cost += min;  //accumlate total cost

		//update lowcost
		for(i = 0; i < vexnum; ++i) {
			if(lowcost[i] != 0 && graph[adjvex[k]][i] != 0 
					&& graph[adjvex[k]][i] < lowcost[i]) {
				lowcost[i] = graph[adjvex[k]][i];
			}
		}
	}
#if DEBUG
	printf("\n");
	for(i = 0; i < vexnum; ++i) {
		printf("%d", adjvex[i]);
		if(i != vexnum - 1) 
			printf(" ");
		else 
			printf("\n");
	}
#endif
	return cost;
}

int main(void) {
	int i, j;
	int start = 0, cost;
	/*scanf("%d", &vexnum);
	for(i = 0; i < vexnum; ++i) {
		for(j = 0; j < vexnum; ++j) {
			scanf("%d", &graph[i][j]);
		}
	}*/
#if DEBUG
	for(i = 0; i < vexnum; ++i) {
		for(j = 0; j < vexnum; ++j) {
			printf("%d", graph[i][j]);
			if(j == vexnum - 1) 
				printf("\n");
			else 
				printf(" ");
		}
	}
	printf("\n");
#endif
	cost = prim(start);
	printf("cost = %d\n", cost);
	return 0;
}

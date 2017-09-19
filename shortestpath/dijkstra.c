#include <stdio.h>

#define N 20
#define INF 65535

int vexnum = 6;
int graph[N][N] = {
	{INF, INF,  10, INF,  30, 100},
	{INF, INF,   5, INF, INF, INF},
	{INF, INF, INF,  50, INF, INF},
	{INF, INF, INF, INF, INF,  10},
	{INF, INF, INF,  20, INF,  60},
	{INF, INF, INF, INF, INF, INF}
};  //directed graph
int visited[N];
//path[i][j] means there is a path from i to j, 
//but not like adjacency table, we see it from start,
//if there is no path from start to i, then path[i][k] == 0, 0<=k<=vexnum
//this means that we don not care vertices at which we can not arrive
//we can find paths using path array
//e.g.: if path[start][k] == 1 && path[k][i] == 1,
//then there is a path: start->k->i
int path[N][N];

void shortestpath(int start, int dis[]) {
	int i, j;
	for(i = 0; i < vexnum; ++i) {
		visited[i] = 0;
		dis[i] = graph[start][i];
		for(j = 0; j < vexnum; ++j) {
			path[i][j] = 0;
		}
		if(dis[i] < INF) {
			path[start][i] = 1;
		}
		//path[i][i] = 1;
	}
	dis[start] = 0;
	visited[start] = 1;
	for(i = 1; i < vexnum; ++i) {
		int v = start;
		int min = INF; //minimum distance from start to v
		for(j = 0; j < vexnum; ++j) {
			if(!visited[j]) {
				if(dis[j] < min) {
					min = dis[j];
					v = j;
				}
			}
		}
		visited[v] = 1;
		for(j = 0; j < vexnum; ++j) {
			if(!visited[j] && min + graph[v][j] < dis[j]) {
				dis[j] = min + graph[v][j];
				path[v][j] = 1;
			}
		}
	}
}  //shortest path dijkstra

int main(void) {
	int start = 0;
	int dis[N];
	int i, j;
	shortestpath(start, dis);
	for(i = 0; i < vexnum; ++i) {
		for(j = 0; j < vexnum; ++j) {
			printf("%d", path[i][j]);
			if(j == vexnum - 1) 
				printf("\n");
			else 
				printf(" ");
		}
	}
	printf("\n");
	for(i = 0; i < vexnum; ++i) {
		printf("%d", dis[i]);
		if(i == vexnum - 1) 
			printf("\n");
		else 
			printf(" ");
	}
	return 0;
}

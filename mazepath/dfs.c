#include <stdio.h>

#define M 20
#define N 20
#define STACK_CAP 10000

#define R 0  //road
#define W 1  //wall
#define V 2  //visited

int m = 10, n = 10;
int graph[M][N] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int visited[M][N];

typedef struct pos_t {
	int x, y;
} pos_t;

typedef struct maz_t {
	int ord;
	pos_t seat;
	int di;
} maz_t;

maz_t stack[STACK_CAP];
int top = -1;

int canpass(pos_t seat) {
	if(seat.x >= 0 && seat.x < m && seat.y >= 0 && seat.y < n) {
		if(graph[seat.x][seat.y] == R && visited[seat.x][seat.y] != V)
			return 1;
	}
	return 0;
}

pos_t nextpos(pos_t cur, int di) {
	pos_t nex = cur;
	switch(di) {
		case 0:
			nex.y = cur.y + 1;
			break;
		case 1:
			nex.x = cur.x + 1;
			break;
		case 2:
			nex.y = cur.y - 1;
			break;
		case 3:
			nex.x = cur.x - 1;
			break;
	}
	return nex;
}

void visit_stack() {
	int i;
	for(i = 0; i <= top; ++i) {
		printf("[%d, (%d, %d), %d]\n", stack[i].ord, stack[i].seat.x, stack[i].seat.y, stack[i].di);
	}
}

int dfs(pos_t start, pos_t end, int ord, int di) {
	maz_t maze;
	pos_t nex;
	int ret = 0, i;

	maze.ord = ord;
	maze.seat = start;
	maze.di = di;
	if(start.x == end.x && start.y == end.y) {  //end condition
		stack[++top] = maze;  //push
		visited[start.x][start.y] = V;
		return 1;
	}
	if(canpass(start)) {  //can pass
		stack[++top] = maze;  //push
		visited[start.x][start.y] = V;  //mark visit
		for(i = 0; i < 4; ++i) {  //try all directions
			nex = nextpos(start, i);
			ret = dfs(nex, end, ord + 1, i);
			if(ret == 1) 
				return 1;
		}
		--top;  //pop
	}
	return 0;
}

int main(void) {
	pos_t start = {1, 1};
	pos_t end = {8, 8};
	int i, j;

	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}

	if(dfs(start, end, 0, 0)) {
		visit_stack();
	}
	else 
		printf("no path\n");

	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	return 0;
}

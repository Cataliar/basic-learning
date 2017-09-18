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

int mazepath(pos_t start, pos_t end) {
	pos_t curpos = start;
	int curstep = 0;
	maz_t maze;

	do {
		if(canpass(curpos)) {
			visited[curpos.x][curpos.y] = V;
			maze.ord = curstep;
			maze.seat = curpos;
			maze.di = 0;
			stack[++top] = maze;  //push
			if(curpos.x == end.x && curpos.y == end.y) 
				return 1;
			curpos = nextpos(curpos, 0);  //next position
			++curstep;
		} //if
		else {
			if(top != -1) {  //stack not empty
				maze = stack[top--];  //pop
				//all directions have been searched
				while(maze.di == 3 && top != -1) {
					//markprint(maze.seat);  //mark cannot pass
					maze = stack[top--];  //pop
				} //while
				if(maze.di < 3) {  //change direction
					++maze.di;
					stack[++top] = maze;  //push
					curpos = nextpos(maze.seat, maze.di);
				} //if
			}  //if
		} //else
	} while(top != -1);  //stack not empty
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

	if(mazepath(start, end)) {
		visit_stack();
	}
	else 
		printf("no path\n");
	return 0;
}

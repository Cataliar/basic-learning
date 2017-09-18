#include <stdio.h>

#define M 20
#define N 20
#define QUEUE_CAP 10000

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

maz_t queue[QUEUE_CAP];
int front = 0, rear = 0;

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

void visit_queue() {
	int i;
	for(i = front; i != rear; i = (i+1)%QUEUE_CAP) {
		printf("[%d, (%d, %d), %d]\n", queue[i].ord, queue[i].seat.x, queue[i].seat.y, queue[i].di);
	}
}

int bfs(pos_t start, pos_t end) {
	int i, ord = 1;
	maz_t maze, tmp;
	pos_t curpos;

	maze.ord = ord;
	maze.seat = start;
	maze.di = 0;
	queue[rear++] = maze;
	visited[start.x][start.y] = V;
	while(front != rear) {
		maze = queue[front];
		curpos = maze.seat;
		if(curpos.x == end.x && curpos.y == end.y) {
			ord = maze.ord;
			break;
		}
		visit_queue();
		printf("\n");
		front = (front + 1) % QUEUE_CAP;
		for(i = 0; i < 4; ++i) {
			pos_t nex = nextpos(curpos, i);
			if(canpass(nex)) {
				if((rear-front+QUEUE_CAP)%QUEUE_CAP < QUEUE_CAP-1) {
					tmp.ord = maze.ord+1;
					tmp.seat = nex;
					tmp.di = i;
					queue[rear] = tmp;
					visited[nex.x][nex.y] = V;
					++rear;
					rear = rear % QUEUE_CAP;
				}
				else 
					return -2;
			}
		}
	}
	if(front == rear) 
		return -1;
	return ord;
}

int main(void) {
	pos_t start = {1, 1};
	pos_t end = {8, 8};
	int i, j;
	int dis = 0;

	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}

	dis = bfs(start, end);
	printf("dis = %d\n", dis);

	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
#include "bitree.h"

void postorder_re(struct binode *tree) {
	if(tree) {
		postorder_re(tree->lchild);
		postorder_re(tree->rchild);
		printf("%d ", tree->data);
	}
}

#define STACK_CAP 100
struct binode *stack[STACK_CAP];
int top = -1;

void postorder(struct binode *tree) {
	struct binode *p = tree, *visited = NULL;

	while(p || top != -1) {
		if(p) {
			stack[++top] = p;
			p = p->lchild;
		}
		else {
			p = stack[top];
			if(p->rchild && p->rchild != visited) {
				p = p->rchild;
			}
			else {
				printf("%d ", p->data);
				--top;  //pop
				visited = p;  //last visited
				p = NULL;
			}
		}
	}
}

int main(void) {
	struct binode *tree = NULL;
	create_bitree(&tree);
	postorder_re(tree);
	printf("\n");
	postorder(tree);
	printf("\n");
	destroy_bitree(&tree);
	return 0;
}

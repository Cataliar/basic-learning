#include <stdio.h>
#include "bitree.h"

void preorder_re(struct binode *tree) {
	if(tree) {
		printf("%d ", tree->data);
		preorder_re(tree->lchild);
		preorder_re(tree->rchild);
	}
}

#define STACK_CAP 100

struct binode *stack[STACK_CAP];
int top = -1;

void preorder(struct binode *tree) {
	struct binode *p = tree;

	while(p || top != -1) {
		if(p) {
			printf("%d ", p->data);
			if(p->rchild) 
				stack[++top] = p->rchild;
			p = p->lchild;
		}
		else {
			p = stack[top--];
		}
	}
}

int main(void) {
	struct binode *tree = NULL;
	create_bitree(&tree);
	preorder_re(tree);
	printf("\n");
	preorder(tree);
	printf("\n");
	destroy_bitree(&tree);
	return 0;
}

#include <stdio.h>
#include "bitree.h"

void inorder_re(struct binode *tree) {
	if(tree) {
		inorder_re(tree->lchild);
		printf("%d ", tree->data);
		inorder_re(tree->rchild);
	}
}

#define STACK_CAP 100
struct binode *stack[STACK_CAP];
int top = -1;

void inorder(struct binode *tree) {
	struct binode *p = tree;
	while(p || top != -1) {
		if(p) {
			stack[++top] = p;
			p = p->lchild;
		}
		else {
			p = stack[top--];
			printf("%d ", p->data);
			p = p->rchild;
		}
	}
}

int main(void) {
	struct binode *tree = NULL;
	create_bitree(&tree);
	inorder_re(tree);
	printf("\n");
	inorder(tree);
	printf("\n");
	destroy_bitree(&tree);
	return 0;
}

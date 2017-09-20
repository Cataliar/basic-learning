#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"

#define NIL -1

int arr[20] = {1, 2, 3, 4, 5, NIL, NIL, NIL, NIL, 6, 7};
int n = 11;

int create_bitree_core(struct binode **tree, int i) {
	int ret = 0;
	if(i >= n || arr[i] == NIL) 
		*tree = NULL;
	else {
		*tree = (struct binode *) malloc(sizeof(struct binode));
		if(!*tree) 
			return -1;
		(*tree)->data = arr[i];
		ret = create_bitree_core(&(*tree)->lchild, 2 * (i + 1) - 1);
		if(ret < 0) 
			return -1;
		ret = create_bitree_core(&(*tree)->rchild, 2 * (i + 1));
		if(ret < 0) 
			return -1;
	}
	return 0;
}

int create_bitree(struct binode **tree) {
	return create_bitree_core(tree, 0);
}

void destroy_bitree(struct binode **tree) {
	if(*tree == NULL) 
		return;
	destroy_bitree(&(*tree)->lchild);
	destroy_bitree(&(*tree)->rchild);
	free(*tree);
	*tree = NULL;
}

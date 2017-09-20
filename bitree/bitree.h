#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdlib.h>

struct binode {
	int data;
	struct binode *lchild, *rchild;
};

int create_bitree(struct binode **tree);
void destroy_bitree(struct binode **tree);

#endif /* bitree.h */

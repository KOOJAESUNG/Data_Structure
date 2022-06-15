#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


typedef struct _node node;
struct _node {
	int data;
	node* lchild;
	node* rchild;
};

node* makenode() {
	node* nnode = (node*)malloc(sizeof(node));
	nnode->lchild = NULL;
	nnode->rchild = NULL;
	return nnode;
}

int getdata(node *bt) {
	return bt->data;
}

void setdata(node* bt, int data) {
	bt->data = data;
}

node* getleftsubtree(node* bt) {
	return bt->lchild;
}

node* getrightsubtree(node* bt) {
	return bt->rchild;
}

void makeleftsubtree(node* main, node* sub) {
	if (main->lchild != NULL) {
		free(main->rchild);
	}
	main->lchild = sub;
}

void makerightsubtree(node* main, node* sub) {
	if (main->rchild != NULL)
		free(main->rchild);
	main->rchild = sub;
}

void inordertrav(node* bt) {
	if (bt == NULL)
		return;
	inordertrav(bt->lchild);
	printf("%d \n", bt->data);
	inordertrav(bt->rchild);
}

int main() {
	node* bt1 = makenode();
	node* bt2 = makenode();
	node* bt3 = makenode();
	node* bt4 = makenode();
	node* bt5 = makenode();

	setdata(bt1, 1);
	setdata(bt2, 2);
	setdata(bt3, 3);
	setdata(bt4, 4);
	setdata(bt5, 5);

	makeleftsubtree(bt1, bt2);
	makerightsubtree(bt1, bt3);
	makeleftsubtree(bt2, bt4);
	makerightsubtree(bt2, bt5);

	inordertrav(bt1);
}
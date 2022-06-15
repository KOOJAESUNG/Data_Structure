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
	nnode->data = -1;
	nnode->lchild = NULL;
	nnode->rchild = NULL;
	return nnode;
}

int getdata(node* bt) {
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

int get_max(node* bt) {
	int a = 0;
	if (bt->rchild != NULL) {
		get_max(bt->rchild);
	}
	else
		return bt->data;
}

void insert(node *bt, int x) {
	if (bt->data == -1) {
		bt->data = x;
		return;
	}
	if (bt->data == x) {
		printf("이미 있습니다.\n");
	}
	else if (bt->data > x) {
		if (bt->lchild != NULL)
			insert(bt->lchild, x);
		else {
			bt->lchild = (node*)malloc(sizeof(node));
			bt->lchild->data = x;
			bt->lchild->lchild = NULL;
			bt->lchild->rchild = NULL;
		}
	}
	else {
		if (bt->rchild != NULL)
			insert(bt->rchild, x);
		else {
			bt->rchild = (node*)malloc(sizeof(node));
			bt->rchild->data = x;
			bt->rchild->lchild = NULL;
			bt->rchild->rchild = NULL;
		}
	}
}

void search(node* bt, int x) {
	if (x == bt->data)
		printf("here\n");
	else if (x < bt->data) {
		if (bt->lchild != NULL)
			search(bt->lchild,x);
		else printf("not found\n");
	}
	else {
		if (bt->rchild != NULL)
			search(bt->rchild, x);
		else printf("not found\n");
	}
}

int delete(node* bt, int x) {
	if (x == bt->data) {
		if (bt->lchild == NULL && bt->rchild == NULL)
			return 1;
		if (bt->lchild == NULL && bt->rchild != NULL) {
			bt->data = bt->rchild->data;
			bt->lchild = bt->rchild->lchild;
			bt->rchild = bt->rchild->rchild;
			return 0;
		}
		if (bt->lchild != NULL && bt->rchild == NULL) {
			bt->data = bt->lchild->data;
			bt->rchild = bt->lchild->rchild;
			bt->lchild = bt->lchild->lchild;
			return 0;
		}
		if (bt->lchild != NULL && bt->rchild != NULL) {
			bt->data = get_max(bt->lchild);
			if (delete(bt->lchild, bt->data) == 1)
				bt->lchild == NULL;
			return 0;
		}
	}

	else if (x < bt->data) {
		if (bt->lchild != NULL) {
			if (delete(bt->lchild, x) == 1)
				bt->lchild = NULL;
		}
		else
			printf("%d가 없음.\n");
		return 0;
	}

	else {
		if (bt->rchild != NULL) {
			if (delete(bt->rchild, x) == 1)
				bt->rchild = NULL;
		}
		else
			printf("%d가 없음.\n");
		return 0;
	}
}
int main() {
	node* bt1 = makenode();
	insert(bt1, 14);
	insert(bt1, 12);
	insert(bt1, 17);
	insert(bt1, 10);
	insert(bt1, 13);
	insert(bt1, 28);

	printf("%d", get_max(bt1));
}
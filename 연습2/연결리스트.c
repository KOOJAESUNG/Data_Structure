#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct _node node;
struct _node {
	int data;
	node* link;
};

typedef struct _hnode hnode;
struct _hnode {
	node* link;
};

hnode* first;

void create() {
	first = (hnode*)malloc(sizeof(hnode));
	first->link= NULL;
}

int is_empty() {
	if (first->link == NULL)
		return 1;
	else return 0;
}

void insert(int x) {
	node* nnode;
	nnode = (node*)malloc(sizeof(node));
	nnode->data = x;
	node* curr = first->link;
	if (first->link == NULL || curr->data>=x) {
		nnode->link = first->link;
		first->link = nnode;
		return;
	}
	while (curr->link != NULL) {
		if (curr->link->data >= x)
			break;
		curr = curr->link;
	}
	nnode->link = curr->link;
	curr->link = nnode;
}

void delete(int x) {
	if (is_empty() == 1) {
		return -1;
	}
	node* dnode;
	node* curr;
	curr = first->link;
	if (curr->data == x) {
		dnode = first->link;
		first->link = dnode->link;
		free(dnode);
		return;
	}
	while (curr->link != NULL) {
		if (curr->link->data == x) {
			dnode = curr->link;
			curr->link = dnode->link;
			return;
		}
		curr = curr->link;
	}
	printf("존재하지않습니다.\n");
}

int search(int x) {
	if (is_empty == 1)
		return -1;
	int count = 0;
	node* curr = first->link;
	while (curr != NULL) {
		count++;
		if (curr->data == x)
			return count;
		curr = curr->link;
	}
	return -1;
}

void print() {
	if (is_empty == 1) {
		printf("배열이 비어있습니다.\n");
		return;
	}
	node* curr;
	curr = first->link;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->link;
	}
	printf("\n");
}

int main()
{
	create();
	insert(3);
	insert(1);
	insert(6);
	insert(8);
	insert(4);
	insert(5);
	insert(2);
	insert(10);

	print();

	printf("%d\n", search(6));
	printf("%d\n", search(5));
	printf("%d\n", search(2));
	printf("%d\n", search(10));

	delete(10);
	delete(100);
	print();
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct _node node;
struct _node {
	char data;
	node* link;
};

typedef struct _hnode hnode;
struct _hnode {
	node* link;
};

hnode* first;

void init() {
	first = (hnode*)malloc(sizeof(hnode));
	first->link = NULL;
}

int is_empty() {
	if (first->link == NULL) return 1;
	else return 0;
}

void enqueue(char x) {
	node* nnode = (node*)malloc(sizeof(node));
	nnode->data = x;
	node* curr = first->link;
	if (first->link == NULL) {
		nnode->link = first->link;
		first->link = nnode;
		return;
	}
	while (curr->link != NULL) {
		curr = curr->link;
	}
	nnode->link = NULL;
	curr->link = nnode;
}

char dequeue() {
	if (is_empty() == 1) {
		printf("비어있습니다.\n");
		return;
	}
	node* dnode;
	dnode = first->link;
	first->link = dnode->link;
	char de_data = dnode->data;
	free(dnode);
	return de_data;
}

int main() {
	init();
	char into_queue[10];
	printf("큐에 저장할 문자열을 입력하시오: ");
	scanf("%s", into_queue);
	for (int i = 0; into_queue[i] != NULL; i++) {
		enqueue(into_queue[i]);
	}
	for (; is_empty() != 1;) {
		printf("%c ", dequeue());
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct _node node;
struct _node {
	char data;
	node* link;
};

typedef struct _fnode fnode;
struct _fnode {
	node* link;
};

node first;

void process_create_queue() {
	first.link = NULL;
}

int is_empty() {
	if (first.link == NULL) {
		printf("큐가 비어있습니다.\n");
		return 1;
	}
	else
		return 0;
}

void enqueue(char a) {
	node* curr;
	node* nnode = (node*)malloc(sizeof(node));
	nnode->data = a;
	curr = first.link;
	if (first.link == NULL) {
		nnode->link = first.link;
		first.link = nnode;
		return;
	}
	while (curr->link != NULL) {
		curr = curr->link;
	}
	nnode->link = curr->link;
	curr->link = nnode;
}

char dequeue() {
	node *dnode;
	dnode = first.link;
	first.link = dnode->link;
	char dequeue_data = dnode->data;
	free(dnode);
	return dequeue_data;
}

int main()
{
	char into_queue[10];
	printf("큐에 저장할 문자열을 입력하시오: ");
	scanf("%s", into_queue);
	process_create_queue();
	for (int i = 0; into_queue[i] != NULL; i++) {
		enqueue(into_queue[i]);
	}
	for (; is_empty() != 1;) {
		printf("%c ", dequeue());
	}
}
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
	nnode->link = NULL;
	curr = first.link;
	if (first.link == NULL) {
		first.link = nnode;
		return;
	}
	while (curr->link != NULL) {
		curr = curr->link;
	}
	curr->link = nnode;
}

char dequeue() {
	if (is_empty() == 1) {
		return;
	}
	node* dnode;
	char dequeue_data;
	dnode = first.link;
	first.link = dnode->link;
	dequeue_data = dnode->data;
	free(dnode);
	return dequeue_data;

}

int queue_count() {
	node* curr;
	int count = 0;
	curr = first.link;
	while (curr->link != NULL) {
		curr = curr->link;
		count++;
	}
	return count + 1;
}
int main()
{
	int count = 0;
	process_create_queue();
	for (int i = 1; i <= 41; i++) {
		enqueue(i);
	}
	int turns = 0;
	int item;
	int k = 3;
	while (queue_count() >= k) {
		turns++;
		item = dequeue();
		if (turns % 3 != 0) {
			enqueue(item);
		}
	}
	int i = 0;
	while (is_empty()!=1) {
		printf("%d ", dequeue());
	}
}
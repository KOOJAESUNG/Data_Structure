#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node node;
struct _node {
	char data;
	node* link;
};

typedef struct _fnode fnode;
struct _fnode {
	node* link;
};

fnode* first;
void init() {
	first = (fnode*)malloc(sizeof(fnode));
	first->link = NULL;
}

int is_empty() {
	if (first->link == NULL) {
		return 1;
	}
	else return 0;
}

void push(int x) {
	node* nnode = (node*)malloc(sizeof(node));
	nnode->data = x;
	nnode->link= first->link;
	first->link = nnode;
}

char pop() {
	if (is_empty() == 1) {
		printf("비어있습니다.\n");
		return;
	}
	node* dnode;
	dnode = first->link;
	char pop_data = dnode->data;
	first->link = dnode->link;
	free(dnode);
	return pop_data;
}

char top() {
	if (is_empty() == 1) {
		printf("비어있습니다.\n");
		return;
	}
	return first->link->data;
}


int main()
{
	char push_str[30];
	char pop_str[30];
	int i = 0;
	init();
	printf("문자열을 입력하시오: ");
	scanf("%s", push_str);
	for (int i = 0; push_str[i] != NULL; i++) {
		push(push_str[i]);
	}
	for (i = 0; is_empty() != 1; i++) {
		pop_str[i] = pop();
	}
	pop_str[i] = NULL;

	if (strcmp(pop_str, push_str) == 0)
		printf("회문입니다.");
	else
		printf("회문이 아닙니다.");
}

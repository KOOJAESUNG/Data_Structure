#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node node;
struct _node {
    char data;
    node* link;
};

typedef struct _fnode fnode;
struct _fnode {
    node* link;
	int size;
    int count;
};

fnode first;
node* nnode;
fnode curr;

void init() {
    first.link = NULL;
    first.count = 0;
	first.size = 15;
}

int Is_empty() {
	if (first.link == NULL)
		return 1;
	else
		return 0;
}

int Is_full() {
	if (first.count == first.size) {
		printf("스택이 꽉 찼습니다.\n");
		return 1;
	}
	else {
		return 0;
	}

}

void push(char data) {
    nnode = (node*)malloc(sizeof(node));
    nnode->data = data;
    nnode->link = first.link;
    first.link= nnode;
	first.count++;
}

char pop() {
	if (Is_empty() == 1) {
		printf("스택이 비어있습니다.\n");
		return;
	}
	char pop_char;
	node* dnode = NULL;
	pop_char = first.link->data;
	dnode = first.link;
	first.link = dnode->link;
	free(dnode);
	first.count--;
	return pop_char;
}

char top() {
	if (Is_empty() == 1) {
		printf("스택이 비어있습니다.\n");
		return;
	}
	char pop_char;
	pop_char = first.link->data;
	return pop_char;
}

void make_pop_string(char pop_string[]) {
	int i = 0;
	while (Is_empty() == 0) {
		pop_string[i] = pop();
		i++;
	}
	pop_string[i] = '\0';
	i = 0;
}

void Is_palindrome(char pop_string[],char tok[]) {
	if (strcmp(pop_string, tok) == 0)
		printf("%s는 회문입니다.\n", tok);
	else
		printf("%s는 회문이 아닙니다.\n", tok);
}

int main()
{
	FILE* fp = fopen("input.txt", "r+t");

	if (fp == NULL) {
		printf("fail to read file\n");
		return 0;
	}

	char input[30];
	char tok[30];
	char pop_string[30];
	
	while (fgets(input, 30, fp) != NULL) {
		init();
		sscanf(input, "%s", tok);
		for (int k = 0; tok[k] != '\0'&&Is_full() != 1; k++) {
				push(tok[k]);
		}
		if (Is_full() != 1) {
			make_pop_string(pop_string);
			Is_palindrome(pop_string, tok);
		}
	 }
	fclose(fp);
	return 0;
}
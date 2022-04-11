#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

char *data;
int top;
int count;
int size;

void init() {
	data = (char*)calloc(50, sizeof(char));
	
	top = 0;
	size = 30;
}

int is_empty() {
	if (top == 0)
		return 1;
	else
		return 0;
}

int is_full() {
	if (top == size)
		return 1;
	else
		return 0;
}

void push(char chr) {
	if (is_full() == 1) {
		printf("스택이 꽉 찼습니다.");
		return;
	}
	//data[0] = 'a';
	data[top] = chr;
	top++;
}

char pop() {
	if (is_empty() == 1) {
		printf("스택이 비어있습니다.");
		return;
	}
	top--;
	return data[top];
}

char is_top() {
	if (is_empty() == 1) {
		printf("스택이 비어있습니다.");
		return;
	}
	char pop_data;
	top--;
	pop_data = data[top];
	top++;
	return pop_data;
}

int main()
{
	char push_str[30];
	char pop_str[30];
	int i = 0;
	init();
	printf("문자열을 입력하시오: ");
	scanf("%s", push_str);
	for (int i = 0; push_str[i]!=NULL; i++) {
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
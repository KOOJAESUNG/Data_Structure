#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


typedef struct _stack stack;
struct _stack {
	int size;
	int top;
	int* arr;
};

stack* sta;

void init() {
	sta = (stack*)malloc(sizeof(stack));
	sta->arr = (int*)calloc(50, sizeof(int));
	sta->size = 50;
	sta->top = 0;
}

int is_full() {
	if (sta->top == sta->size)
		return 1;
	else return 0;
}

int is_empty() {
	if (sta->top == 0)
		return 1;
	else return 0;
}

void push(int x) {
	if (is_full() == 1) {
		printf("������ �� ���ֽ��ϴ�.\n");
		return;
	}
	sta->arr[sta->top] = x;
	sta->top++;
}

int pop() {
	if (is_empty() == 1) {
		printf("������ ����ֽ��ϴ�.\n");
		return;
	}
	sta->top--;
	int pop_data = sta->arr[sta->top];
	return pop_data;
}

int top() {
	if (is_empty() == 1) {
		printf("������ ����ֽ��ϴ�.\n");
		return;
	}
	sta->top--;
	int pop_data = sta->arr[sta->top];
	sta->top++;
	return pop_data;
}

int main()
{
	char push_str[30];
	char pop_str[30];
	int i = 0;
	init();
	printf("���ڿ��� �Է��Ͻÿ�: ");
	scanf("%s", push_str);
	for (int i = 0; push_str[i] != NULL; i++) {
		push(push_str[i]);
	}
	for (i = 0; is_empty() != 1; i++) {
		pop_str[i] = pop();
	}
	pop_str[i] = NULL;

	if (strcmp(pop_str, push_str) == 0)
		printf("ȸ���Դϴ�.");
	else
		printf("ȸ���� �ƴմϴ�.");
}



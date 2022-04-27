#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//플 엠티 인큐 디큐 생성

typedef struct _queue queue;
struct _queue {
	int size;
	int count;
	int rear;
	int front;
	char* arr;
};

queue* que;

void init() {
	que = (queue*)malloc(sizeof(queue));
	que->arr = (char*)calloc(50, sizeof(char));
	que->size = 50;
	que->count = 0;
	que->rear = que->size - 1;
	que->front = que->size - 1;
}

int is_full() {
	if (que->count == que->size)
		return 1;
	else return 0;
}

int is_empty() {
	if (que->count == 0)
		return 1;
	else return 0;
}

void enqueue(int x) {
	if (is_full() == 1) {
		printf("큐가 꽉 차있습니다.\n");
		return;
	}
	que->rear = (que->rear + 1) % que->size;
	que->arr[que->rear] = x;
	que->count++;
}

char dequeue() {
	if (is_empty() == 1) {
		printf("비어있습니다.\n");
		return;
	}
	que->front = (que->front + 1) % que->size;
	char de_data = que->arr[que->front];
	que->count--;
	return de_data;
}

int main() {
	init();
	char en_str[50];
	char de_str[50];
	scanf("%s", en_str);
	int i = 0;
	while (en_str[i] != NULL) {
		enqueue(en_str[i]);
		i++;
	}
	for (i = 0; is_empty() != 1; i++) {
		de_str[i] = dequeue();
	}
	de_str[i] = NULL;
	printf("%s", de_str);
}

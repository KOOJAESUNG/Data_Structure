#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

char* queue;
int rear;
int front;
int count;
int size;

void process_create_queue() {
	queue = (char*)malloc(10);
	size = 10;
	rear = size-1;
	front = size-1;
	count = 0;

}

int is_empty() {
	if (count == 0) {
		printf("queue is empty\n");
		return 1;
	}
	else
		return 0;
}

int is_full() {
	if (count == size) {
		printf("queue is full\n");
		return 1;
	}
	else
		return 0;
}

void enqueue(char a) {
	if (is_full == 1) {
		return;
	}
	rear = (rear + 1) % size;
	queue[rear] = a;
	count += 1;
}

char dequeue() {
	if (is_full() == 1) {
		return;
	}
	count -= 1;
	front = (front + 1) % size;
	return queue[front];
	
}

int main()
{
	char into_queue[10];
	printf("큐에 저장할 문자열을 입력하시오: ");
	scanf("%s", into_queue);
	process_create_queue();
	for (int i = 0; into_queue[i]!=NULL; i++) {
		enqueue(into_queue[i]);
	}
	for (; is_empty() != 1;) {
		printf("%c ", dequeue());
	}
}
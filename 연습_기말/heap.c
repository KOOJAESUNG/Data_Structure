#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct _node heap;
struct _node {
	int count;
	int n;
	int* arr;
};

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify_up(heap* a, int idx) {
	if (idx == 1)
		return;
	else {
		if (a->arr[idx / 2] < a->arr[idx]) {
			swap(&a->arr[idx / 2], &a->arr[idx]);
			heapify_up(a, idx / 2);
		}
	}
}

void heapify_down(heap* a, int idx) {
	if (idx * 2 > a->count)
		return;
	else if (idx * 2 == a->count) {
		if (a->arr[idx * 2] < a->arr[a->count]) {
			swap(&a->arr[idx], &a->arr[a->count]);
		}
		return;
	}
	else {
		if (a->arr[idx * 2] > a->arr[idx * 2 + 1] && a->arr[idx] < a->arr[idx * 2]) {
			swap(&a->arr[idx], &a->arr[idx * 2]);
			heapify_down(a, idx * 2);
		}
		else if (a->arr[idx * 2 + 1] > a->arr[idx * 2] && a->arr[idx] < a->arr[idx * 2 + 1]) {
			swap(&a->arr[idx], &a->arr[idx * 2 + 1]);
			heapify_down(a, idx * 2 + 1);
		}
	}
}

void init(heap* a) {
	a->count = 0;
	a->n = 100;
	a->arr = (int*)calloc(a->n, sizeof(int));
}

void insert(heap* a, int x) {
	a->count++;
	a->arr[a->count] = x;
	heapify_up(a, a->count);
}

void pop(heap* a) {
	printf("%d ", a->arr[1]);
	a->arr[1] = a->arr[a->count];
	a->count--;
	heapify_down(a, 1);
}

int top(heap* a) {
	return a->arr[1];
}

void print_heap(heap* a) {
	for (int i = 1; i <= a->count; i++) {
		printf("%d ", a->arr[i]);
	}
}


int main() {
	heap* h;
	h = (heap*)malloc(sizeof(heap));
	init(h);
	insert(h, 5);
	insert(h, 1);
	insert(h, 9);
	insert(h, 7);
	insert(h, 2);
	insert(h, 3);

	//print_heap(h);

	pop(h);
	pop(h);
	pop(h);
	pop(h);
	pop(h);
	pop(h);
}
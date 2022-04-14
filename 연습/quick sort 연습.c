#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
	int x;
	x = *a;
	*a = *b;
	*b = x;
}

void quick_sort(int s, int e, int a[]) {
	if (s >= e)
		return;
	int pivot = split(s, e, a);
	quick_sort(s, pivot - 1, a);
	quick_sort(pivot + 1, e, a);
}

int split(int s, int e, int a[]) {
	int pivot = s;
	int front = s + 1;
	int rear = e;
	while (front <= rear) {
		while (a[front] <= a[pivot] && front <= rear) {
			front++;
		}
		while (a[rear] >= a[pivot] && front <= rear) {
			rear--;
		}
		if (front <= rear) {
			swap(&a[front], &a[rear]);
		}
	}
	swap(&a[pivot], &a[rear]);
	return rear;
}

int main()
{
	int a[] = { 99,88,77,66,55,44,33,22,11,98,87,76,54,43,32,21,97,79,87,78,98,89,45,54,56,65,46,64,12,21,13,31,23,32 };
	quick_sort(0, sizeof(a) / sizeof(int) - 1, a);

	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		printf("%d ", a[i]);
	}

}
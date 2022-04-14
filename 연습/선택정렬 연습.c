#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


void swap(int* a, int* b) {
	int x;
	x = *a;
	*a = *b;
	*b = x;
}

int select_min(int s,int e,int a[]) {
	int min_idx = s;
	for (int i = s + 1; i <= e; i++) {
		if (a[i] < a[min_idx])
			min_idx = i;
	}
	return min_idx;
}

void selection_sort(int n, int a[]) {
	int i;
	int min_idx;
	for (i = 0; i < n - 1; i++) {
		min_idx = select_min(i, n - 1, a);
		swap(&a[i], &a[min_idx]);
	}
}

int main() {
	int a[] = { 81,61,5,30,74,5,40,10,1,30,61,99 };
	selection_sort(sizeof(a) / sizeof(int), a);

	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		printf("%d ", a[i]);
	}
}
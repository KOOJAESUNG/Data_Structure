#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void swap(int* a, int* b) {
	int x = *a;
	*a = *b;
	*b = x;
}

void select_sort(int a[], int size) {
	int min_idx;
	for (int i = 0; i < size-1; i++) {
		min_idx = i;
		for (int k = i + 1; k < size; k++) {
			if (a[min_idx] > a[k]) {
				min_idx = k;
			}
		}
		swap(&a[i], &a[min_idx]);
	}
}

int main() {
	int a[30] = { 9,8,7,6,5,4,3,2,1,99,88,77,66,55,44,33,22,11,95,85,75,45,55,65,35,25,15 };
	int count = 0;
	for (int i = 0; a[i] != NULL; i++) {
		count++;
	}
	printf("%d\n", count);
	select_sort(a, count);
	for (int i = 0; i < count; i++)
		printf("%d ", a[i]);
}


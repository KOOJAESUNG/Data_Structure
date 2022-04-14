#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


void swap(int *a, int *b) {
	int x;
	x = *a;
	*a = *b;
	*b = x;
}

void bubble_sort(int n, int a[]) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				swap(&a[j], &a[j - 1]);
			}
		}
	}
}

int main()
{
	int a[] = { 81,61,5,30,74,5,40,10,1,30,61,99 };
	bubble_sort(sizeof(a) / sizeof(int), a);

	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		printf("%d ", a[i]);
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void swap(int* a, int* b) {
	int x = *a;
	*a = *b;
	*b = x;
}

int split(int s, int e, int a[]) {
	int pivot = s;
	int left = s + 1;
	int right = e;
	while (left <= right) {
		while (a[left] <= a[pivot] && left <= right) left++;
		while (a[right] >= a[pivot] && left <= right) right--;
		if (left <= right) swap(&a[left], &a[right]);
	}
	swap(&a[right], &a[pivot]);
	return right;
}

void quick(int s,int e,int a[]) {
	if (s >= e)
		return;
	int pivot = split(s, e, a);
	quick(s, pivot - 1,a);
	quick(pivot + 1, e,a);
}

int main() {
	int a[30] = { 9,8,7,6,5,4,3,2,1,99,88,77,66,55,44,33,22,11,95,85,75,45,55,65,35,25,15 };
	int count = 0;
	for (int i = 0; a[i] != NULL; i++) {
		count++;
	}
	printf("%d\n", count);
	quick(0, count-1,a);
	for (int i = 0; i < count; i++)
		printf("%d ", a[i]);
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int insert(int x,int n,int a[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] > x) {
			for (int k = n - 1; k > i; k--) {
				a[k] = a[k - 1];
			}
			a[i] = x;
			break;
		}
	}
}

int insert_sort(int a[],int size) {
	for (int i = 1; i < size; i++) {
		insert(a[i], i + 1, a);
	}
}

int main() {
	int a[30] = { 9,8,7,6,5,4,3,2,1,99,88,77,66,55,44,33,22,11,95,85,75,45,55,65,35,25,15 };
	int count = 0;
	for (int i = 0; a[i] != NULL; i++) {
		count++;
	}
	printf("%d\n", count);
	insert_sort(a, count);
	for (int i = 0; i < count; i++)
		printf("%d ", a[i]);
}
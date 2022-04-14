#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


void insert(int x, int n, int b[]) {
	int i, j;
	for (i = 0; i < n; i++) {
		if (b[i] >= x) {
			for (j = n - 1; j > i; j--) {
				b[j] = b[j - 1];
			}
				
			b[i] = x;
			break;
		}
	}
}

void insertion_sort(int n, int a[]) {
	int i;

	for (i = 1; i < n; i++)
		insert(a[i], i + 1, a);
}

int main()
{
	int a[] = { 81,61,5,30,74,5,40,10,1,30,61 };
	insertion_sort(sizeof(a) / sizeof(int), a);
	
	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		printf("%d ", a[i]);
	}
	
}
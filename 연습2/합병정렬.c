#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[30] = { 9,8,7,6,5,4,3,2,1,99,88,77,66,55,44,33,22,11,95,85,75,45,55,65,35,25,15 };

void merge(int ls, int le, int  rs, int re) {
	int lptr = ls, rptr = rs, bptr = 0;
	int* brr = (int*)calloc(re-ls+1,sizeof(int));
	while (lptr <= le && rptr <= re) {
		if (a[lptr] > a[rptr])	brr[bptr++] = a[rptr++];
		else brr[bptr++] = a[lptr++];
	}
	if (lptr > le)
		for (int i = rptr; i <= re; i++)
			brr[bptr++] = a[i];
	if (rptr > re)
		for (int i = lptr; i <= le; i++)
			brr[bptr++] = a[i];
	for (int i = ls; i <= re; i++) {
		a[i] = brr[i-ls];
	}
	free(brr);
}


void merge_sort(int s, int e) {
	if (s == e) return;
	int mid = (s + e) / 2;
	merge_sort(s, mid);
	merge_sort(mid + 1, e);
	merge(s, mid, mid + 1, e);
}


int main() {
	int count = 0;
	for (int i = 0; a[i] != NULL; i++) {
		count++;
	}
	printf("%d\n", count);
	merge_sort(0, count-1);
	for (int i = 0; i < count; i++)
		printf("%d ", a[i]);
}
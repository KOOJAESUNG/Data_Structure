#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void insert_sort(int a[],int n,int x) {
	int i, k;
	for (i = 0; i < n+1; i++) {
		if (a[i] >= x) {
			for (k = n; k > i; k--) {
				a[k] = a[k - 1];
			}
			a[i] = x;
			break;
		}
	}
}
void insert(int a[], int x,int *count) {
	if (*count == 0){
		a[0] = x;
	}
	int i;
	for (i = 0; i < *count; i++) {
		if (a[i] > x) {
			for (int k = *count; k > i; k--) {
				a[k] = a[k - 1];
			}
			a[i] = x;
			(* count)++;
			return;
		}
	}
	a[i] = x;
}

void delete(int a[],int x,int *count) {
	for (int i = 0; i < *count; i++) {
		if (a[i] == x) {
			for (int k = i; k < *count - 1; k++) {
				a[k] = a[k + 1];
			}
			(* count)--;
			return;
		}
	}
	printf("값이 존재하지 않습니다.\n");
}

int main() {
	int x;
	int a[100] = { 7,9,2,34};
	int count = 4;
	//삽입정렬
	for (int i = 1; i < count; i++) {
		insert_sort(a, i, a[i]);
	}
	for (int i = 0; i < count; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("추가할 값을 입력하시오: ");
	scanf("%d", &x);
	insert(a,x,&count);
	for (int i = 0; i < count; i++) {
		printf("%d ", a[i]);
	}
	printf("제거할 값을 입력하시오: ");
	scanf("%d", &x);
	delete(a, x, &count);
	for (int i = 0; i < count; i++) {
		printf("%d ", a[i]);
	}

}
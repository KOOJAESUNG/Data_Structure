#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//풀 엠티 추가 검색 제거 카운트

typedef struct _array array;
struct _array {
	int size;
	int count;
	int *arr;
};

void create(array *array) {
	array->size = 30;
	array->count = 0;
	array->arr = (int*)calloc(30, sizeof(int));
}

int is_full(array* array) {
	if (array->count == array->size)
		return 1;
	else return 0;
}

int is_empty(array* array) {
	if (array->count == 0)
		return 1;
	else return 0;
}

void insert(array* array,int x) {
	if (is_full(array) == 1)
		return -1;
	int i = 0;
	for (i = 0; i < array->count; i++) {
		if (array->arr[i] >= x) {
			for (int k = array->count - 1; k >= i; k--) {
				array->arr[k + 1] = array->arr[k];
			}
			array->arr[i] = x;
			array->count++;
			return;
		}
	}
	array->arr[i] = x;
	array->count++;
	return;
}

void delete(array* array,int x) {
	if (is_empty(array) == 1)
		return -1;
	for (int i = 0; i < array->count; i++) {
		if (array->arr[i] == x) {
			for (int k = i; k < array->count-1; k++) {
				array->arr[k] = array->arr[k + 1];
			}
			array->count--;
			return;
		}
	}
	return -1;
}

int search(array* array, int x) {
	if (is_empty(array) == 1)
		return -1;
	for (int i = 0; i < array->count; i++) {
		if (array->arr[i] == x) {
			return i+1;
		}
	}
	return 0;
}

void print(array* array) {
	if (is_empty(array) == 1)
		return -1;
	for (int i = 0; i < array->count; i++) {
		printf("%d ", array->arr[i]);
	}
	printf("\n");
}

int main()
{
	array arr1;
	create(&arr1);
	insert(&arr1, 3);
	insert(&arr1, 1);
	insert(&arr1, 6);
	insert(&arr1, 8);
	insert(&arr1, 4);
	insert(&arr1, 2);
	insert(&arr1, 5);
	insert(&arr1, 10);
	insert(&arr1, 30);
	print(&arr1);

	printf("%d\n", search(&arr1, 6));
	printf("%d\n", search(&arr1, 5));
	printf("%d\n", search(&arr1, 70));
	printf("%d\n", search(&arr1, 2));
	printf("%d\n", search(&arr1, 10));

	delete(&arr1, 10);
	print(&arr1);
}
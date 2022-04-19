#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int* arr;
int count;

void create() {
	arr = (int*)calloc(50, sizeof(int));
	count = 0;
}

void process_insert(int x) {
	int i;
	for ( i = 0; i < count; i++) {
		if (arr[i] >= x)
		{
			for (int j = count; j > i; j--)
				arr[j] = arr[j - 1];
			arr[i] = x;
			count++;
			return;
		}
	}
	arr[i] = x;
	count++;
}

void process_delete(int x) {
	for (int i = 0; i < count; i++) {
		if (arr[i] == x) {
			for (int j = i; j < count - 1; j++) {
				arr[j] = arr[j + 1];
			}
			count--;
			return;
		}
	}
}

int process_search(int x) {
	for (int i = 0; i < count; i++)
		if (arr[i] == x)
			return i+1;
	return -1;
}

int print() {
	for (int i = 0; i < count; i++) {
		printf("%d ", arr[i]);
	}
}

int main() {
	create();
	int num;
	for (int i = 0; i < 4; i++) {
		printf("������ ���ڸ� �Է��Ͻÿ�: ");
		scanf("%d", &num);
		process_insert(num);
	}

	print();

	printf("ã����� ���ڸ� �Է��Ͻÿ�: ");
	scanf("%d", &num);
	int result = process_search(num);
	printf("%d �� %d��°�� ��ġ�մϴ�\n", num, result);

	printf("���� ���ڸ� �Է��Ͻÿ�: ");
	scanf("%d", &num);
	process_delete(num);
	print();
}
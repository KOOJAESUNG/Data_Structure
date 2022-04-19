#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct _node node;
struct _node {
	int data;
	node* link;
};

typedef struct _fnode fnode;
struct _fnode {
	node* link;
};

fnode* first;

void process_create() {
	first = (fnode*)malloc(sizeof(fnode));
	first->link = NULL;
}

void insert(int x) {
	node* nnode = (node*)malloc(sizeof(node));
	nnode->data = x;
	nnode->link = NULL;
	if (first->link == NULL) {
		first->link = nnode;
		return;
	}
	node* curr;
	curr = first->link;
	if (curr->data >= x) {
		nnode->link = first->link;
		first->link = nnode;
		return;
	}
	curr = first->link;
	while (curr->link != NULL) {
		if (curr->link->data >= x)
			break;
		curr = curr->link;
	}
	nnode->link = curr->link;
	curr->link = nnode;
}


int search(int x) {
	if (first->link == NULL) {
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
		return;
	}
	node* curr;
	int count = 0;
	curr = first->link;
	while (curr != NULL) {
		count++;
		if (curr->data == x)
			return count;
		curr = curr->link;
	}
	return -1;
}

void delete(int x) {
	if (first->link == NULL) {
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
		return;
	}
	node* dnode = (node*)malloc(sizeof(node));
	node* curr;
	curr = first->link;
	if (curr->data == x) {
		dnode = curr;
		first->link = dnode->link;
		free(dnode);
		return;

	}
	while (curr->link != NULL) {
		if (curr->link->data == x)
			break;
		curr = curr->link;
	}
	if (curr->link == NULL) {
		printf("���� �������� �ʽ��ϴ�.\n");
		return;
	}

	dnode = curr->link;
	curr->link = dnode->link;
	free(dnode);
}

void print() {
	if (first->link == NULL) {
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
		return;
	}
	node* curr;
	curr = first->link;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->link;
	}
}

int main() {
	process_create();
	int num;
	for (int i = 0; i < 4; i++) {
		printf("������ ���ڸ� �Է��Ͻÿ�: ");
		scanf("%d", &num);
		insert(num);
	}

	print();

	printf("ã����� ���ڸ� �Է��Ͻÿ�: ");
	scanf("%d", &num);
	int result = search(num);
	printf("%d �� %d��°�� ��ġ�մϴ�\n", num, result);

	printf("���� ���ڸ� �Է��Ͻÿ�: ");
	scanf("%d", &num);
	delete(num);
	print();
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _sinfo {
	char name[8];
	char sex;
	char city[8];
	char dept[16];
	float gpa;
	int height;
	int weight;
}sinfo;

int count_student(FILE* fp) {
	char str[256];
	int i = 0;
	while (fgets(str, 256, fp) != NULL)
		i++;
	return i;
}

int process_create() {

}

int process_load(char adress[]) {
	FILE* fp = fopen(adress, "r+t");
	if (fp == NULL) {
		printf("fail to read file");
		return 0;
	}
	sinfo read[100];

	int n = count_student(fp);
	rewind(fp);
	int least, i, k;
	for (i = 0; i < n; i++) {
		fscanf(fp, "%s %c %s %s %f %d %d", read[i].name, &read[i].sex, read[i].city, &read[i].dept, &read[i].gpa, &read[i].height, &read[i].weight);
	}

	for (i = 0; i < n; i++) {
		sinfo trash;
		least = read[i].name;
		for (k = 0; k < i; k++) {
			if (strcmp(read[i].name, read[k].name) == -1) {
				trash = read[i];
				read[i] = read[k];
				read[k] = trash;
			}
		}
	}
	rewind(fp);

	for (i = 0; i < n; i++) {
		fprintf(fp, "%s %c %s %s %f %d %d\n", read[i].name, read[i].sex, read[i].city, read[i].dept, read[i].gpa, read[i].height, read[i].weight);
	}
	fclose(fp);
}


int process_print() {
	FILE* fp = fopen("list.txt", "r + t");
	if (fp == NULL) {
		printf("fail to read file");
		return 0;
	}
	sinfo read[100];

	int n = count_student(fp);
	rewind(fp);

	int i, k;
	for (i = 0; i < n; i++) {
		fscanf(fp, "%s %c %s %s %f %d %d", read[i].name, &read[i].sex, read[i].city, &read[i].dept, &read[i].gpa, &read[i].height, &read[i].weight);
	}
	for (i = 0; i < n; i++) printf("%s %c %s %s %f %d %d\n", read[i].name, read[i].sex, read[i].city, read[i].dept, read[i].gpa, read[i].height, read[i].weight);
	fclose(fp);
}

int process_insert(char tok2[], char tok3[], char tok4[], char tok5[], char tok6[], char tok7[], char tok8[]) {
	FILE* fp = fopen("list.txt", "a+");
	if (fp == NULL) {
		printf("fail to read file");
		return 0;
	}
	fprintf(fp, "%s %s %s %s %s %s %s\n\0", tok2, tok3, tok4, tok5, tok6, tok7, tok8);
	fclose(fp);

	process_load("list.txt");

}

int process_delete(char name[]) {
	FILE* fp = fopen("list.txt", "r+t");
	if (fp == NULL) {
		printf("fail to read file");
		return 0;
	}
	int n = count_student(fp);
	printf("%d\n", n);
	rewind(fp);
	sinfo read[100];
	int i, k;
	for (i = 0; i < n; i++) {
		fscanf(fp, "%s %c %s %s %f %d %d", read[i].name, &read[i].sex, read[i].city, &read[i].dept, &read[i].gpa, &read[i].height, &read[i].weight);
	}
	rewind(fp);
	fclose(fp);
	for (i = 0; i < n; i++)
		if (strcmp(name, read[i].name) == 0)
			break;
	if (i == n) {
		printf("없음");
		return;
	}
	for (int j = i; j < n - 1; j++)
		read[j] = read[j + 1];
	n--;
	printf("%d\n", n);
	FILE* fp1 = fopen("list.txt", "w");
	for (i = 0; i < n; i++) {
		fprintf(fp1, "%s %c %s %s %f %d %d\n", read[i].name, read[i].sex, read[i].city, read[i].dept, read[i].gpa, read[i].height, read[i].weight);
	}
	fclose(fp1);
}

void process_search(char tok2[]) {
	FILE* fp = fopen("list.txt", "r+t");
	if (fp == NULL) {
		printf("fail to read file");
		return 0;
	}
	int n = count_student(fp);
	printf("%d\n", n);
	rewind(fp);
	sinfo read[100];
	int i, k;
	for (i = 0; i < n; i++) {
		fscanf(fp, "%s %c %s %s %f %d %d", read[i].name, &read[i].sex, read[i].city, &read[i].dept, &read[i].gpa, &read[i].height, &read[i].weight);
	}
	rewind(fp);
	for (i = 0; i < n; i++)
		if (strcmp(tok2, read[i].name) == 0) {
			printf("%s %c %s %s %f %d %d\n", read[i].name, read[i].sex, read[i].city, read[i].dept, read[i].gpa, read[i].height, read[i].weight);
			break;
		}
			
			
	if (i == n) {
		printf("없음");
		return;
	}
}

int main()
{
	FILE* fp = fopen("input.txt", "r+t");
	if (fp == NULL) {
		printf("fail to read file");
		return 0;
	}
	char input[512];
	char tok1[32], tok2[32], tok3[32], tok4[32], tok5[32], tok6[32], tok7[32], tok8[32], tok9[32];
	sinfo slist[100];

	while (fgets(input, 512, fp) != NULL) {
		sscanf(input, "%s%s%s%s%s%s%s%s%s", tok1, tok2, tok3, tok4, tok5, tok6, tok7, tok8, tok9);
		if (strcmp(tok1, "CREATE") == 0) {
			process_create();
			printf("%s is done ======================\n\n", tok1);
		}
		else if (strcmp(tok1, "LOAD") == 0) {
			process_load(tok2);
			printf("%s is done ======================\n\n", tok1);
		}
		else if (strcmp(tok1, "PRINT") == 0) {
			process_print();
			printf("%s is done ======================\n\n", tok1);
		}
		else if (strcmp(tok1, "INSERT") == 0) {
			process_insert(tok2, tok3, tok4, tok5, tok6, tok7, tok8);
			printf("%s is done ======================\n\n", tok1);
		}
		else if (strcmp(tok1, "DELETE") == 0) {
			process_delete(tok2);
			printf("%s is done ======================\n\n", tok1);
		}
		else if (strcmp(tok1, "SEARCH") == 0) {
			process_search(tok2);
			printf("%s is done ======================\n\n", tok1);
		}
		else {
			printf("%s is not a keyword\n\n", tok1);
		}
	}
	fclose(fp);
}
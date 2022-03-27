#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _node node;
struct _node {
    char name[8];
    char sex;
    char city[8];
    char dept[16];
    float gpa;
    int height;
    int weight;
    node* link;
};

node* first;
node* curr;
node* nnode;

void process_create() {
    first = NULL;
    curr = NULL;
    nnode = NULL;
}

void process_insert_1(node tinfo) {

    nnode = (node*)malloc(sizeof(node));
    nnode->link = NULL;
    strcpy(nnode->name, tinfo.name);
    nnode->sex = tinfo.sex;
    strcpy(nnode->city, tinfo.city);
    strcpy(nnode->dept, tinfo.dept);
    nnode->gpa = tinfo.gpa;
    nnode->height = tinfo.height;
    nnode->weight = tinfo.weight;

    if (first == NULL) {
        first = nnode;
        return;
    }
    curr = first;
    while (curr->link != NULL) {
        if (strcmp(curr->link->name, nnode->name) == 1) {
            break;
        }
        curr = curr->link;
    }
    nnode->link = curr->link;
    curr->link = nnode;
}

void process_load(char adress[]) {
    FILE* fp_list = fopen(adress, "r+t");

    if (fp_list == NULL) {
        printf("fail to load file\n");
        return;
    }

    rewind(fp_list);

    node tinfo;
    char str[512];

    while (fgets(str, 512, fp_list) != NULL) {
        sscanf(str, "%s %c %s %s %f %d %d", tinfo.name, &tinfo.sex, tinfo.city, &tinfo.dept, &tinfo.gpa,
            &tinfo.height, &tinfo.weight);
        process_insert_1(tinfo);
    }
    fclose(fp_list);
}

void process_insert(char tok2[], char tok3[], char tok4[], char tok5[], char tok6[], char tok7[], char tok8[]) {
    node tinfo;

    strcpy(tinfo.name, tok2);
    tinfo.sex = tok3[0];
    strcpy(tinfo.city, tok4);
    strcpy(tinfo.dept, tok5);
    tinfo.gpa = atof(tok6);
    tinfo.height = atoi(tok7);
    tinfo.weight = atoi(tok8);

    process_insert_1(tinfo);
}

void process_delete(char tok2[]) {
    if (first == NULL) {
        printf("값이 존재하지 않습니다\n");
        return;
    }

    node* dnode = NULL;

    curr = first;

    if (strcmp(curr->name, tok2) == 0) {
        dnode = curr;
        first->link = dnode->link;
        free(dnode);
        printf("%s 를 삭제했습니다.\n", tok2);
        return;
    }
    while (curr->link != NULL) {
        if (strcmp(curr->link->name, tok2) == 0) {
            dnode = curr->link;
            curr->link = dnode->link;
            free(dnode);
            printf("%s 을(를) 삭제했습니다.\n", tok2);
            return;
        }
        curr = curr->link;
    }
    printf("%s 을(를) 찾을 수 없습니다.\n", tok2);
}

void process_search(char tok2[]) {
    if (first == NULL) {
        printf("값이 존재하지 않습니다\n");
        return;
    }

    curr = first;

    while (curr != NULL) {
        if (strcmp(curr->name, tok2) == 0) {
            printf("%s %c %s %s %f %d %d\n", curr->name, curr->sex, curr->city, curr->dept, curr->gpa, curr->height, curr->weight);
            return;
        }
        curr = curr->link;
    }
    printf("%s 이(가) 존재하지 않습니다.\n", tok2);
}

void process_print() {
    if (first == NULL) {
        printf("저장된 값이 없습니다.");
    }
    else {
        curr = first;

        while (curr->link != NULL) {
            printf("%s %c %s %s %f %d %d\n", curr->name, curr->sex, curr->city, curr->dept, curr->gpa, curr->height, curr->weight);
            curr = curr->link;
        }
        printf("%s %c %s %s %f %d %d\n", curr->name, curr->sex, curr->city, curr->dept, curr->gpa, curr->height, curr->weight);
    }
}

void memory_free() {
    if (first == NULL)
        return;
    else {
        curr = first;

        while (curr != NULL) {
            first = curr->link;
            free(curr);
            curr = first;
        }
    }
    printf("메모리 해제 완료.\n");
}

int main()
{
    FILE* fp = fopen("input.txt", "r+t");

    if (fp == NULL) {
        printf("fail to read file\n");
        return 0;
    }

    char input[512];
    char tok1[32], tok2[32], tok3[32], tok4[32], tok5[32], tok6[32], tok7[32], tok8[32], tok9[32];

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
    memory_free();
    return 0;
}
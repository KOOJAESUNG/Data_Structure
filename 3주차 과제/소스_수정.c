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

sinfo* slist;
int cnt = 0;
int n;

void process_insert_1(sinfo tinfo) {
    if (cnt == 0) {
        slist[cnt++] = tinfo;
        return;
    }
    int i, j;
    for (i = 0; i < cnt; i++) {
        if (strcmp(tinfo.name, slist[i].name) <= 0)
            break;
    }
    for (j = cnt - 1; j >= i; j--) {
        slist[j + 1] = slist[j];
    }
    slist[i] = tinfo;
    cnt++;
}

void process_create() {
    n = 100;
    slist = (sinfo*)calloc(n, sizeof(sinfo));
}

void process_load(char adress[]) {
    FILE* fp_list = fopen(adress, "r+t");
    if (fp_list == NULL) {
        printf("fail to load file\n");
        return 0;
    }
    sinfo tinfo;
    char str[512];
    while (fgets(str, 512, fp_list) != NULL) {
        fscanf(fp_list, "%s %c %s %s %f %d %d", tinfo.name, &tinfo.sex, tinfo.city, &tinfo.dept, &tinfo.gpa,
            &tinfo.height, &tinfo.weight);
        process_insert_1(tinfo);
    }
    fclose(fp_list);
}



void process_insert(char tok2[], char tok3[], char tok4[], char tok5[], char tok6[], char tok7[], char tok8[]) {
    sinfo tinfo;

    strcpy(tinfo.name, tok2);
    tinfo.sex = tok3[0];
    strcpy(tinfo.city, tok4);
    strcpy(tinfo.dept, tok5);
    tinfo.gpa = atof(tok6);
    tinfo.height = atoi(tok7);
    tinfo.weight = atoi(tok8);

    process_insert_1(tinfo);
}


void process_delete(char* tok2) {
    int i, j;
    for (i = 0; i < cnt; i++) {
        if (strcmp(slist[i].name, tok2) == 0)
            break;
    }
    if (i == cnt) {
        printf("NO %s IN THE LIST\n", tok2);
        return;
    }
    for (j = i; j < cnt - 1; j++)
        slist[j] = slist[j + 1];
    cnt--;
    printf("%s is deleted.\n", tok2);
}

void process_print() {

    int i;
    for (i = 0; i < cnt; i++)
        printf("%s %c %s %s %f %d %d\n", slist[i].name, slist[i].sex, slist[i].city, slist[i].dept, slist[i].gpa, slist[i].height, slist[i].weight);
}


void process_search(char tok2[]) {
    int i;
    for (i = 0; i < cnt; i++) {
        if (strcmp(slist[i].name, tok2) == 0) {
            printf("%s if found: %s %c %s %s %f %d %d\n", tok2, slist[i].name, slist[i].sex, slist[i].city, slist[i].dept, slist[i].gpa, slist[i].height, slist[i].weight);
            return;
        }
    }
    printf("%s not found\n", tok2);
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
    return 0;
}
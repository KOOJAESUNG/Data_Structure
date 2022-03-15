#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define file_name "list.txt"
typedef struct people_information {
    char name[7];
    char gender[2];
    char region[7];
    char major[15];
    float score;
    int tall;
    int weight;

} people_info;


int main(void)
{
    people_info* people[100];
    for (int i = 0; i < 100; i++) {
        people[i] = (people_info*)malloc(sizeof(people_info));
    }
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("fail to read file");
        return 0;
    }
    char buffer[1001], * token;

    int i = 0;
    int idx = 0;
    while (!feof(fp)) {
        i = 0;
        fgets(buffer, 1001, fp);
        token = strtok(buffer, " ");
        while (token != NULL) {

            if (i == 0) {
                strcpy(people[idx]->name, token);
            }
            else if (i == 1) {
                strcpy(people[idx]->gender, token);
            }
            else if (i == 2) {
                strcpy(people[idx]->region, token);
            }
            else if (i == 3) {
                strcpy(people[idx]->major, token);
            }
            else if (i == 4) {
                people[idx]->score = atof(token);
            }
            else if (i == 5) {
                people[idx]->tall = atoi(token);
            }
            else if (i == 6) {
                people[idx]->weight = atoi(token);
            }
            i++;
            token = strtok(NULL, " ");
        }
        idx++;
    }

    for (int i = 0; i < idx; i++) {
        printf("%s %s %s %s %lf %d %d\n", people[i]->name, people[i]->gender, people[i]->region, people[i]->major, people[i]->score, people[i]->tall, people[i]->weight);
    }
    fclose(fp);
    for (i = 0; i < 100; i++) {
        free(people[i]);
    }
    return 0;
}
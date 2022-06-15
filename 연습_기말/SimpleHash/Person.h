#pragma once
typedef struct _person {
	int ssn;
	char name[50];
	char addr[50];
 }Person;

int GetSSN(Person* p);
void ShowPerInfo(Person* p);
Person* MakePersonData(int ssn, char* name, char* addr);

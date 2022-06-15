#pragma once

#include "Slot.h"

typedef int (*HashFunc)(int K);

typedef struct _table {
	Slot tbl[100];
	HashFunc hf;
}Table;

void TBLInit(Table* pt, HashFunc f);

Person* TBLDelete(Table* pt, int k);

Person* TBLSearch(Table* pt, int k);
#include<stdio.h>
#include<stdlib.h>
#include "Table.h"

void TBLInit(Table* pt, HashFunc f) {
	int i;
	for (i = 0; i < 100; i++)
		pt->tbl[i].status = EMPTY;

	pt->hf = f;
}

void TBLInsert(Table* pt, int k, Person* v) {
	int hv = pt->hf(k);
	pt->tbl[hv].val = v;
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
}

Person* TBLDelete(Table* pt, int k) {
	int hv = pt->hf(k);
	if ((pt->tbl[hv].status != INUSE))
		return NULL;
	else {
		pt->tbl[hv].status = DELETED;
		return (pt->tbl[hv]).val;
	}
}

Person* TBLSearch(Table* pt, int k) {
	int hv = pt->hf(k);

	if (pt->tbl[hv].status != INUSE)
		return NULL;
	else
		return pt->tbl[hv].val;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int (* PriorityComp)(char d1, char d2);

typedef struct _heap Heap;
struct _heap {
	PriorityComp comp;
	int numOfData;
	char heapArr[100];
};

void Heapinit(Heap* ph, PriorityComp pc) {
	ph->numOfData = 0;
	ph->comp = pc;
}

int H_is_empty(Heap* ph) {
	if (ph->numOfData == 0)
		return 1;
	else return 0;
}

int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}

int GetRChildIDX(int idx) {
	return GetLChildIDX(idx) + 1;
}

int Get_HiPri_Child_idx(Heap* ph, int idx) {
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	else {
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)],ph->heapArr[GetRChildIDX(idx)])<0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, char data) {
	int idx = ph->numOfData + 1;//idx 0가 존재하지 않기 때문.

	while (idx != 1) {
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) {
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else break;
	}

	ph->heapArr[idx] = data;
	ph->numOfData++;
}

char HDelete(Heap* ph) {
	char retdata = ph->heapArr[1];
	char lastElem = ph->heapArr[ph->numOfData];

	int parent_idx = 1;
	int child_idx;

	while (child_idx = Get_HiPri_Child_idx(ph, parent_idx)) {
		if (ph->comp(lastElem, ph->heapArr[child_idx]) >= 0)
			break;
		ph->heapArr[parent_idx] = ph->heapArr[child_idx];
		parent_idx = child_idx;
	}

	ph->heapArr[parent_idx] = lastElem;
	ph->numOfData--;
	return retdata;
}

int DataPriorityComp(char ch1, char ch2) {
	return ch2 - ch1;
}

int main() {
	Heap heap;
	Heapinit(&heap, DataPriorityComp);

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	while (!H_is_empty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}
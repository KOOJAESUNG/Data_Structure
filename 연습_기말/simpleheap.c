#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct _heapElem HeapElem;
struct _heapElem {
	int pr;//우선순위
	char data;
};

typedef struct _heap Heap;
struct _heap {
	int numOfData;
	HeapElem heapArr[100];
};

void Heapinit(Heap* ph) {
	ph->numOfData = 0;
}

int H_is_empty(Heap* ph) {
	if (ph->numOfData == 0)
		return 1;
	else return 0;
}

int Get_Parent_idx(int idx) {
	return idx / 2;
}

int Get_Lchild_idx(int idx) {
	return idx * 2;
}

int Get_Rchild_idx(int idx) {
	return idx * 2 + 1;
}

int Get_HiPri_Child_idx(Heap* ph, int idx) {
	if (Get_Lchild_idx(idx) > ph->numOfData)
		return 0;
	else if (Get_Lchild_idx(idx) == ph->numOfData)
		return Get_Lchild_idx(idx);
	else {
		if (ph->heapArr[Get_Lchild_idx(idx)].pr > ph->heapArr[Get_Rchild_idx(idx)].pr)
			return Get_Rchild_idx(idx);
		else
			return Get_Lchild_idx(idx);
	}
}

void HInsert(Heap* ph, char data, int pr) {
	int idx = ph->numOfData + 1;//idx 0가 존재하지 않기 때문.
	HeapElem nelem = { pr,data };

	while (idx != 1) {
		if (pr < (ph->heapArr[Get_Parent_idx(idx)].pr)) {
			ph->heapArr[idx] = ph->heapArr[Get_Parent_idx(idx)];
			idx = Get_Parent_idx(idx);
		}
		else break;
	}
	ph->heapArr[idx] = nelem;
	ph->numOfData++;
}

char HDelete(Heap* ph) {
	char retdata = ph->heapArr[1].data;
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	int parent_idx = 1;
	int child_idx;

	while (child_idx = Get_HiPri_Child_idx(ph, parent_idx)) {
		if (lastElem.pr <= ph->heapArr[child_idx].pr)
			break;
		ph->heapArr[parent_idx] = ph->heapArr[child_idx];
		parent_idx = child_idx;
	}

	ph->heapArr[parent_idx] = lastElem;
	ph->numOfData--;
	return retdata;
}

int main() {
	Heap heap;
	Heapinit(&heap);

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);

	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	while(!H_is_empty(&heap))
		printf("%c \n", HDelete(&heap));


}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int binary_search(int x, int s, int e, int a[]) {
	if (s == e) {
		if (a[s] == x)
			return s;
		else
			return -1;
	}

	int mid = (s + e) / 2;
	if (a[mid] == x)
		return mid;
	else if (a[mid] > x)
		return binary_search(x, s, mid - 1,a);
	else return binary_search(x, mid + 1, e,a);
}

int main() {
	int x;
	int a[] = { 1,3,4,5,7,11,22,33,44,55,66,77 };
	printf("검색할 수를 입력하시오: ");
	scanf("%d", &x);
	int idx = binary_search(x, 0, sizeof(a) / sizeof(int) - 1, a);
	printf("%d는 %d번째에 위치합니다.", x, idx+1);
}



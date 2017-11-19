#include <iostream>
#include <stdlib.h>

#define ITEM_SIZE 10

using namespace std;

void print_arr(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

void max_heapify(int a[], int size, int idx) {
	int left = idx * 2;
	int right = (idx * 2) + 1;
	int largest = idx;
	int tmp = 0;

	// 왼쪽 자식 노드와 비교
	if (left < size && a[left] > a[largest]) {
		largest = left;
	}

	// 오른쪽 자식 노드와 비교
	if (right < size && a[right] > a[largest]) {
		largest = right;
	}

	// 부모 노드보다 자식 노드가 큰 경우 교환
	if (largest != idx) {
		tmp = a[largest];
		a[largest] = a[idx];
		a[idx] = tmp;
		// 재귀 호출
		max_heapify(a, size, largest);
	}
}

void build_max_heap(int a[], int size) {
	for (int i = size / 2; i > 0; i--) {
		max_heapify(a, size, i);
	}
}

void heap_sort(int a[], int size) {
	int tmp = 0;

	build_max_heap(a, size);
	for (int count = size - 1; count > 0; count--) {
		// 루트 노드를 가장 마지막 노드와 교환
		tmp = a[count];
		a[count] = a[1];
		a[1] = tmp;
		// 힙 구조 유지
		max_heapify(a, count, 1);
	}
}

int main() {
	int a[ITEM_SIZE] = { 0, }; // 루트 노드는 1번 인덱스 부터 시작
	for (int i = 1; i < ITEM_SIZE; i++) {
		a[i] = (rand() % (ITEM_SIZE * 10)) + 1;
	}

	print_arr(a, ITEM_SIZE);
	heap_sort(a, ITEM_SIZE);
	print_arr(a, ITEM_SIZE);
	return 0;
}
#include <iostream>

#define ITEM_SIZE 10

using namespace std;

void print_arr(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int partition(int a[], int left, int right) {
	int pivot = right;
	int i = left - 1;
	int j = left;
	int tmp;

	if (left < right) {
		while (j < right) {
			if (a[j] < a[pivot]) {
				tmp = a[j];
				a[j] = a[i + 1];
				a[i + 1] = tmp;
				i++;
			}
			j++;
		}
		tmp = a[pivot];
		a[pivot] = a[i + 1];
		a[i + 1] = tmp;
	}
	pivot = i + 1;

	return pivot;
}

void quick_sort(int a[], int left, int right) {
	if (left < right) {
		int pivot = partition(a, left, right);
		quick_sort(a, left, pivot - 1);
		quick_sort(a, pivot + 1, right);
	}
}

int main() {
	int a[ITEM_SIZE] = { 15, 2, 24, 18, 7, 13, 12, 4, 21, 9 };
	print_arr(a, ITEM_SIZE);
	quick_sort(a, 0, ITEM_SIZE - 1);
	print_arr(a, ITEM_SIZE);
	return 0;
}
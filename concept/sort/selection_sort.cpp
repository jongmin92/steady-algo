#include <iostream>

using namespace std;

void print_arr(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

void selection_sort(int a[], int size) {
	int min_idx, tmp;

	for (int i = 0; i < size - 1; i++) {
		min_idx = i;
		for (int j = i + 1; j < size; j++) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		tmp = a[min_idx];
		a[min_idx] = a[i];
		a[i] = tmp;
	}
}

int main() {
	int a[] = { 15, 2, 24, 18, 7, 13, 12, 4, 21, 9 };
	int size = sizeof(a) / sizeof(int);
	print_arr(a, size);
	selection_sort(a, size);
	print_arr(a, size);
	return 0;
}
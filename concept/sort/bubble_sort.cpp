#include <iostream>

using namespace std;

void print_arr(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

void buuble_sort(int a[], int size) {
	int tmp;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (a[i] > a[j]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main() {
	int a[] = { 15, 2, 24, 18, 7, 13, 12, 4, 21, 9 };
	int size = sizeof(a) / sizeof(int);
	print_arr(a, size);
	buuble_sort(a, size);
	print_arr(a, size);
	return 0;
}
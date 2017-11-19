#include <iostream>

using namespace std;

void print_arr(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

void insert_sort(int a[], int size) {
	int tmp;

	for (int i = 1; i < size; i++) {
		tmp = a[i];
		int j = i;

		while (j > 0 && a[j - 1] > tmp) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tmp;
	}
}

int main() {
	int a[] = { 15, 2, 24, 18, 7, 13, 12, 4, 21, 9 };
	int size = sizeof(a) / sizeof(int);
	print_arr(a, size);
	insert_sort(a, size);
	print_arr(a, size);
	return 0;
}
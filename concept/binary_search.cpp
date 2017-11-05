#include <iostream>

using namespace std;

int binary_search(int A[], int target, int begin, int end) {
	if (begin > end) {
		return -1;
	}
	int mid = (begin + end) / 2;

	if (A[mid] > target) {
		return binary_search(A, target, begin, mid - 1);
	}
	else if (A[mid] < target) {
		return binary_search(A, target, mid + 1, end);
	}
	else {
		return mid;
	}
}

int main() {
	int data_list[] = { 2, 3, 5, 9, 15, 17, 20 };

	int index = binary_search(data_list, 17, 0, 6);
	if (index == -1) {
		cout << "찾을 수 없음" << endl;
	}
	else {
		cout << "결과 : " << index << endl;
	}

	return 0;
}
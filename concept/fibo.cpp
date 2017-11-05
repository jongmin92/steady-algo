#include <iostream>

using namespace std;
int* memo;

// 메모이제이션 사용 O
int fibo(int n) {
	if (memo[n] != -1) {
		return memo[n];
	}

	memo[n] = fibo(n - 2) + fibo(n - 1);
	return memo[n];
}

// 메모이제이션 사용 X
int fibo2(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fibo2(n - 1) + fibo2(n - 2);
	}
}

int main() {
	int num;
	cin >> num;
	memo = new int[num + 1];
	memset(memo, -1, sizeof(int) * (num +1));

	memo[0] = 0;
	memo[1] = 1;

	cout << fibo(num) << '\n';

	return 0;
}
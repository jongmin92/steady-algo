#include <iostream>
#include <math.h>

using namespace std;

/*
 * 에라토스테네스의 체는 주어진 수 까지의 모든 소수를 구해야 하는 경우에
 * 사용하는 것이 좋다.
 */
int main() {
	unsigned int num;
	cout << "소수를 구할 수를 입력하세요 : ";
	cin >> num;
	
	bool* prime = new bool[num + 1];
	memset(prime, 0, sizeof(bool) * (num + 1));

	for (int i = 2; i <= num; i++) {
		if (prime[i] == false) {
			for (int j = i * 2; j <= num; j += i) {
				prime[j] = true;
			}
		}
	}

	for (int i = 0; i <= num; i++) {
		prime[i] = !prime[i];
	}

	if (prime[num]) {
		cout << num << "은 소수입니다." << endl;
	}
	else {
		cout << num << "은 소수가 아닙니다." << endl;
	}

	return 0;
}
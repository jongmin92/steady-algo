#include <iostream>

using namespace std;

/*
 * 소수(Prime Number)는 약수로 1과 자기 자신만을 가지는 정수이다.
 * 정수론의 기본 정리에 의해 모든 자연수는 단 하나의 수수들의 곱으로 표현된다. 
 */
int main() {
	unsigned int num;;
	cout << "소수를 구할 수를 입력하세요 : ";
	cin >> num;
	bool isPrime = true;

	// 2부터 N-1의 수로 나눠서 나눠지는 수가 있으면 반복문 종료
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			isPrime = false;
			break;
		}
	}

	if (isPrime) {
		cout << num << "은 소수입니다." << endl;
	}
	else {
		cout << num << "은 소수가 아닙니다." << endl;
	}

	return 0;
}
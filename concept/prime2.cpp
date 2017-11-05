#include <iostream>
#include <math.h>

using namespace std;

/*
 * 주여진 자연수 N이 소수이기 위한 필요충분 조건은 N이 N의 제곱근보다 크지 않은
 * 어떤 소수로도 나눠지지 않는다. 수가 수를 나누면 몫이 발생하게 되는데 목과
 * 나누는 수, 둘 중 하나는 반드시 루트N 이하이기 때문이다.
 * 즉, 2부터 루트N 까지 나눠보면 된다.
 */
int main() {
	unsigned int num;
	cout << "소수를 구할 수를 입력하세요 : ";
	cin >> num;
	bool isPrime = true;

	// 2부터 루트N의 수로 나눠서 나눠지는 수가 있으면 반복문 종료
	for (int i = 2; i <= sqrt(num); i++) {
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
#include <iostream>
#include <math.h>

using namespace std;

/*
 * �����佺�׳׽��� ü�� �־��� �� ������ ��� �Ҽ��� ���ؾ� �ϴ� ��쿡
 * ����ϴ� ���� ����.
 */
int main() {
	unsigned int num;
	cout << "�Ҽ��� ���� ���� �Է��ϼ��� : ";
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
		cout << num << "�� �Ҽ��Դϴ�." << endl;
	}
	else {
		cout << num << "�� �Ҽ��� �ƴմϴ�." << endl;
	}

	return 0;
}
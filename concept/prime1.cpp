#include <iostream>

using namespace std;

/*
 * �Ҽ�(Prime Number)�� ����� 1�� �ڱ� �ڽŸ��� ������ �����̴�.
 * �������� �⺻ ������ ���� ��� �ڿ����� �� �ϳ��� �������� ������ ǥ���ȴ�. 
 */
int main() {
	unsigned int num;;
	cout << "�Ҽ��� ���� ���� �Է��ϼ��� : ";
	cin >> num;
	bool isPrime = true;

	// 2���� N-1�� ���� ������ �������� ���� ������ �ݺ��� ����
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			isPrime = false;
			break;
		}
	}

	if (isPrime) {
		cout << num << "�� �Ҽ��Դϴ�." << endl;
	}
	else {
		cout << num << "�� �Ҽ��� �ƴմϴ�." << endl;
	}

	return 0;
}
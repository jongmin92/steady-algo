#include <iostream>
#include <math.h>

using namespace std;

/*
 * �ֿ��� �ڿ��� N�� �Ҽ��̱� ���� �ʿ���� ������ N�� N�� �����ٺ��� ũ�� ����
 * � �Ҽ��ε� �������� �ʴ´�. ���� ���� ������ ���� �߻��ϰ� �Ǵµ� ���
 * ������ ��, �� �� �ϳ��� �ݵ�� ��ƮN �����̱� �����̴�.
 * ��, 2���� ��ƮN ���� �������� �ȴ�.
 */
int main() {
	unsigned int num;
	cout << "�Ҽ��� ���� ���� �Է��ϼ��� : ";
	cin >> num;
	bool isPrime = true;

	// 2���� ��ƮN�� ���� ������ �������� ���� ������ �ݺ��� ����
	for (int i = 2; i <= sqrt(num); i++) {
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
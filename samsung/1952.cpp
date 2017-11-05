#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int price[4];
int table[13];
int min_value = INT_MAX;

void go(int month, int sum) {
	if (month >= 13) {
		min_value = min(min_value, sum);
		return;
	}

	if (table[month] == 0) {
		go(month + 1, sum);
		return;
	}

	// 1일 이용권
	go(month + 1, sum + (table[month] * price[0]));

	// 1달 이용권
	go(month + 1, sum + price[1]);

	// 3달 이용권
	go(month + 3, sum + price[2]);

	// 1년 이용권
	if (month == 1) {
		go(month + 12, sum + price[3]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;

	for (int k = 1; k <= tc; k++) {
		cin >> price[0] >> price[1] >> price[2] >> price[3];

		for (int i = 1; i < 13; i++) {
			cin >> table[i];
		}

		go(1, 0);

		cout << '#' << k << ' ' << min_value << '\n';
		min_value = INT_MAX;
	}

	return 0;
}
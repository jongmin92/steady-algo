#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		if (i == 0) {
			continue;
		}
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
	}
	
	cout << *max_element(d.begin(), d.end()) << '\n';
	system("pause");

	return 0;
}
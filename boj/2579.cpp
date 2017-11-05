#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> d(n, vector<int>(3));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	d[0][1] = d[0][2] = a[0];
	d[1][1] = a[1];
	d[1][2] = a[0] + a[1];
	for (int i = 2; i < n; i++) {
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	int ans = max(d[n - 1][1], d[n - 1][2]);
	cout << ans << '\n';

	system("pause");
	return 0;
}
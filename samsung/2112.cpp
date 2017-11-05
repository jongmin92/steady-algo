#include <iostream>
#include <algorithm>
#include <limits.h>

#define SHELL_MAX_DEPTH_SIZE 13
#define SHELL_MAX_WIDTH_SIZE 20
using namespace std;

int shell[SHELL_MAX_DEPTH_SIZE][SHELL_MAX_WIDTH_SIZE];
int D, W, K;// 두께, 가로크기, 합격기준
bool check[SHELL_MAX_DEPTH_SIZE];
int min_cnt = INT_MAX;

void init_shell() {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			cin >> shell[i][j];
		}
	}
}

bool check_test_pass() {
	for (int y = 0; y < W; y++) {
		bool pass = false;
		int x = 0;

		while (x <= D - K) {
			int sum = 0;

			for (int k = 0; k < K; k++) {
				sum += shell[x + k][y];
			}

			if (sum == 0 || sum == K) {
				pass = true;
				break;
			}
			else {
				x++;
			}
		}

		if (!pass) {
			return false;
		}
	}

	return true;
}

void go(int x, int cnt) { // x = 행, cnt = 회수
	if (check_test_pass()) {
		min_cnt = min(min_cnt, cnt);
		return;
	}

	if (x >= D) {
		min_cnt = min(min_cnt, K);
		return;
	}

	if (cnt >= K) {
		min_cnt = min(min_cnt, K);
		return;
	}

	// 값 변환 X
	go(x + 1, cnt);

	// 값 변환 O
	for (int value = 0; value <= 1; value++) {
		int tmp_value[SHELL_MAX_WIDTH_SIZE];
		for (int y = 0; y < W; y++) {
			tmp_value[y] = shell[x][y];
			shell[x][y] = value;
		}

		go(x + 1, cnt + 1);

		for (int y = 0; y < W; y++) {
			shell[x][y] = tmp_value[y];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++) {
		cin >> D >> W >> K;

		init_shell();

		if (check_test_pass()) {
			min_cnt = 0;
		}
		else {
			go(0, 0);
		}

		cout << '#' << tc << ' ' << min_cnt << '\n';
		min_cnt = INT_MAX;
	}

	return 0;
}
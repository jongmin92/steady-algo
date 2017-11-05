#include <iostream>
#include <algorithm>

#define MAP_MAX_SIZE 20
using namespace std;

int map[MAP_MAX_SIZE][MAP_MAX_SIZE];
int N;
int max_dp[12];

void init_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}

bool check_same(int(*map)[MAP_MAX_SIZE], int(*tmp_map)[MAP_MAX_SIZE]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != tmp_map[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void copy_map(int(*map)[MAP_MAX_SIZE], int(*tmp_map)[MAP_MAX_SIZE]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
}

void recovery_map(int(*map)[MAP_MAX_SIZE], int(*tmp_map)[MAP_MAX_SIZE]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = tmp_map[i][j];
		}
	}
}

void combine_map(int dir) {
	// 상
	if (dir == 0) {
		for (int c = 0; c < N; c++) {
			for (int r = 0; r < N - 1; r++) {
				int data1 = map[r][c];

				if (data1 == 0) {
					continue;
				}

				for (int k = r + 1; k < N; k++) {
					int data2 = map[k][c];

					if (data2 == 0) {
						continue;
					}
					else {
						if (data1 == data2) {
							map[r][c] *= 2;
							map[k][c] = 0;
							r = k;
						}
						break;
					}
				}
			}
		}
	}
	// 하
	else if (dir == 1) {
		for (int c = 0; c < N; c++) {
			for (int r = N - 1; r > 0; r--) {
				int data1 = map[r][c];

				if (data1 == 0) {
					continue;
				}

				for (int k = r - 1; k >= 0; k--) {
					int data2 = map[k][c];

					if (data2 == 0) {
						continue;
					}
					else {
						if (data1 == data2) {
							map[r][c] *= 2;
							map[k][c] = 0;
							r = k;
						}
						break;
					}
				}
			}
		}
	}
	// 좌
	else if (dir == 2) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N - 1; c++) {
				int data1 = map[r][c];

				if (data1 == 0) {
					continue;
				}

				for (int k = c + 1; k < N; k++) {
					int data2 = map[r][k];

					if (data2 == 0) {
						continue;
					}
					else {
						if (data1 == data2) {
							map[r][c] *= 2;
							map[r][k] = 0;
							c = k;
						}
						break;
					}
				}
			}
		}
	}
	// 우
	else if (dir == 3) {
		for (int r = 0; r < N; r++) {
			for (int c = N - 1; c > 0; c--) {
				int data1 = map[r][c];

				if (data1 == 0) {
					continue;
				}

				for (int k = c - 1; k >= 0; k--) {
					int data2 = map[r][k];

					if (data2 == 0) {
						continue;
					}
					else {
						if (data1 == data2) {
							map[r][c] *= 2;
							map[r][k] = 0;
							c = k;
						}
						break;
					}
				}
			}
		}
	}
}

int move_map(int dir) {
	int max_value = 0;

	// 상
	if (dir == 0) {
		for (int c = 0; c < N; c++) {
			for (int r = 0; r < N; r++) {
				max_value = max(max_value, map[r][c]);

				if (map[r][c] == 0 && r != N - 1) {
					for (int k = r + 1; k < N; k++) {
						if (map[k][c] != 0) {
							map[r][c] = map[k][c];
							map[k][c] = 0;
							max_value = max(max_value, map[r][c]);
							break;
						}
					}
				}
			}
		}
	}
	// 하
	else if (dir == 1) {
		for (int c = 0; c < N; c++) {
			for (int r = N - 1; r >= 0; r--) {
				max_value = max(max_value, map[r][c]);

				if (map[r][c] == 0 && r != 0) {
					for (int k = r - 1; k >= 0; k--) {
						if (map[k][c] != 0) {
							map[r][c] = map[k][c];
							map[k][c] = 0;
							max_value = max(max_value, map[r][c]);
							break;
						}
					}
				}
			}
		}
	}
	//좌
	else if (dir == 2) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				max_value = max(max_value, map[r][c]);

				if (map[r][c] == 0 && c != N - 1) {
					for (int k = c + 1; k < N; k++) {
						if (map[r][k] != 0) {
							map[r][c] = map[r][k];
							map[r][k] = 0;
							max_value = max(max_value, map[r][c]);
							break;
						}
					}
				}
			}
		}
	}
	//우
	else if (dir == 3) {
		for (int r = 0; r < N; r++) {
			for (int c = N - 1; c >= 0; c--) {
				max_value = max(max_value, map[r][c]);

				if (map[r][c] == 0 && c != 0) {
					for (int k = c - 1; k >= 0; k--) {
						if (map[r][k] != 0) {
							map[r][c] = map[r][k];
							map[r][k] = 0;
							max_value = max(max_value, map[r][c]);
							break;
						}
					}
				}
			}
		}
	}

	return max_value;
}

void dfs(int cnt, int max_value) {
	if (max_dp[cnt + 1] > max_value * 2) {
		return;
	}
	else {
		max_dp[cnt] = max(max_dp[cnt], max_value);
	}

	if (cnt >= 10) {
		return;
	}

	// 상, 하, 좌, 우
	for (int dir = 0; dir < 4; dir++) {
		int tmp_map[MAP_MAX_SIZE][MAP_MAX_SIZE];
		copy_map(map, tmp_map);

		combine_map(dir);  				// 기울인 방향으로 합치기
		int value = move_map(dir);      // 빈칸 땡기기 & 현재 최대값 반환

		if (!check_same(map, tmp_map)) {
			dfs(cnt + 1, value);
		}

		recovery_map(map, tmp_map);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;

	init_map();
	dfs(0, 2);

	cout << max_dp[10] << '\n';

	return 0;
}
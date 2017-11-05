#include <iostream>
#include <queue>
#include <algorithm>

#define MAP_MAX_SIZE 20
using namespace std;

int map[MAP_MAX_SIZE][MAP_MAX_SIZE];
int N, M;
int price[MAP_MAX_SIZE*2];

// ╩С, го, аб, ©Л
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void init_price() {
	for (int i = 1; i <= MAP_MAX_SIZE * 2 - 1; i++) {
		price[i] = i * i + (i - 1) * (i - 1);
	}
}

void init_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}

int dfs(int x, int y) {
	bool visited[MAP_MAX_SIZE][MAP_MAX_SIZE] = { false };
	int house_cnt_at_k[MAP_MAX_SIZE * 2] = { 0 };
	queue<pair<pair<int, int>, int> > q; // x, y, k
	
	visited[x][y] = true;
	q.push(make_pair(make_pair(x, y), 1));

	while (!q.empty()) {
		pair<int, int> point = q.front().first;
		int x = point.first;
		int y = point.second;
		int k = q.front().second;
		q.pop();

		house_cnt_at_k[k] += map[x][y];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nk = k + 1;

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) {
				continue;
			}

			visited[nx][ny] = true;
			q.push(make_pair(make_pair(nx, ny), nk));
		}
	}

	int house_cnt_by_k = 0;
	int max_house_cnt = 0;
	for (int i = 1; i <= MAP_MAX_SIZE * 2 - 1; i++) {
		house_cnt_by_k += house_cnt_at_k[i];
		if (house_cnt_by_k * M >= price[i]) {
			max_house_cnt = max(max_house_cnt, house_cnt_by_k);
		}
	}

	return max_house_cnt;
}

int main() {
	ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;

	init_price();

	for (int tc = 1; tc <= testcase; tc++) {
		cin >> N >> M;
		init_map();

		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int house_cnt = dfs(i, j);
				ans = max(ans, house_cnt);
			}
		}

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}
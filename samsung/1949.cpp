#include <iostream>
#include <queue>
#include <algorithm>

#define MAP_MAX_SIZE 8
using namespace std;

int map[MAP_MAX_SIZE][MAP_MAX_SIZE];
bool visited[MAP_MAX_SIZE][MAP_MAX_SIZE];
int N, K;
int top_height = 0;
int max_value = 0;

// ╩С го аб ©Л
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void init_map() {
	top_height = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			top_height = max(top_height, map[i][j]);
		}
	}
}

void dfs(int x, int y, int road_cnt, bool is_cut) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) {
			continue;
		}

		if (map[nx][ny] < map[x][y]) {
			visited[nx][ny] = true;
			dfs(nx, ny, road_cnt + 1, is_cut);
			visited[nx][ny] = false;
		}
		else {
			if (map[nx][ny] - K < map[x][y]) {
				if (is_cut) {
					continue;
				}
				
				int origin_height = map[nx][ny];
				map[nx][ny] = map[x][y] - 1;
				visited[nx][ny] = true;
				dfs(nx, ny, road_cnt + 1, true);
				map[nx][ny] = origin_height;
				visited[nx][ny] = false;
			}
		}
	}

	max_value = max(max_value, road_cnt);
}

int main() {
	ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++) {
		cin >> N >> K;

		init_map();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == top_height) {
					visited[i][j] = true;
					dfs(i, j, 1, false);
					visited[i][j] = false;
				}
			}
		}

		cout << '#' << tc << ' ' << max_value << '\n';
		max_value = 0;
	}

	return 0;
}
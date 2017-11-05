#include <iostream>
#include <algorithm>
#include <stdlib.h>
#define MAX_SIZE 500

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];

int n, m;
int max_value;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		max_value = max(max_value, sum);
		return;
	}

	// で, ぬ, っ, た
	if (cnt == 2) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			else {
				if (visit[nx][y] == true && nx != x) {
					if (y - 1 >= 0 && y + 1 < m) {
						dfs(nx, ny, cnt + 2, sum + map[x][y - 1] + map[x][y + 1]);
					}
				}
				else if (visit[x][ny] == true && ny != y) {
					if (x - 1 >= 0 && x + 1 < n) {
						dfs(nx, ny, cnt + 2, sum + map[x - 1][y] + map[x + 1][y]);
					}
				}

			}
		}
	}


	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}

		if (visit[nx][ny] == false) {
			visit[nx][ny] = true;
			dfs(nx, ny, cnt + 1, sum + map[nx][ny]);
			visit[nx][ny] = false;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = true;
			dfs(i, j, 1, map[i][j]);
			visit[i][j] = false;
		}
	}

	cout << max_value << '\n';

	return 0;
}
#include <iostream>
#include <algorithm>

#define MAX_SIZE 20

using namespace std;


int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
bool eated[101];
bool direction[5];

int n;
int max_value;
int dx[5] = {0, -1, 1, 1, -1};
int dy[5] = {0, 1, 1, -1, -1};
int sx;
int sy;

void dfs(int x, int y, int pre_direction, int cnt) {
	for (int i = 1; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
			continue;
		}

		if (sx == nx && sy == ny) {
			max_value = max(max_value, cnt);
			return;
		}

		if (visited[nx][ny] == false && eated[map[nx][ny]] == false) {
			if (direction[i] == false || (direction[i] == true && pre_direction == i)) {
				direction[i] = true;
				visited[nx][ny] = true;
				eated[map[nx][ny]] = true;
				dfs(nx, ny, i, cnt + 1);
				if (i != pre_direction) {
					direction[i] = false;
				}
				visited[nx][ny] = false;
				eated[map[nx][ny]] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;

	for (int k = 1; k <= tc; k++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sx = i;
				sy = j;
				visited[i][j] = true;
				eated[map[i][j]] = true;
				dfs(i, j, -1, 1);
				visited[i][j] = false;
				eated[map[i][j]] = false;
			}
		}

		if (max_value >= 4) {
			cout << '#' << k << ' ' << max_value << '\n';
		}
		else {
			cout << '#' << k << ' ' << -1 << '\n';
		}

		max_value = 0;
	}

	return 0;
}
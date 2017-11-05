#include <iostream>
#include <queue>
#define MAX_SIZE 50

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
// ��, ��, ��, ��
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m, ttime;
bool enable[8][4] = {
	{ false, false, false, false }, // �� ����
	{ true, true, true, true }, // Ÿ�� 1
	{ true, true, false, false }, // Ÿ�� 2
	{ false, false, true, true }, // Ÿ�� 3
	{ true, false, false, true }, // Ÿ�� 4
	{ false, true, false, true }, // Ÿ�� 5
	{ false, true, true, false }, // Ÿ�� 6
	{ true, false, true, false }, // Ÿ�� 7
};

queue<pair<pair<int, int>, int> > q; // x, y, time

int get_deposit_dir(int dir) {
	switch (dir) {
	case 0:
		return 1;
	case 1:
		return 0;
	case 2:
		return 3;
	case 3:
		return 2;
	}
}

void bfs(int sx, int sy) {
	visited[sx][sy] = true;
	q.push(make_pair(make_pair( sx, sy ), 1));
	
	while (!q.empty()) {
		pair<int, int> p = q.front().first;
		int x = p.first;
		int y = p.second;
		int t = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = t + 1;

			if (nt > ttime) {
				break;
			}

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			if (visited[nx][ny] == true) {
				continue;
			}

			int type = map[x][y];
			int dir = i;
			if (enable[type][dir]) { // ���� ��ġ���� ���� ��ġ�� ����Ǿ� �ִ��� Ȯ��
				type = map[nx][ny];
				dir = get_deposit_dir(dir);
				
				if (enable[type][dir]) { // ���� ��ġ���� ���� ��ġ�� ����Ǿ� �ִ��� Ȯ��
					visited[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), nt));
				}
			}
		}
	}
}

int clac_and_clear() {
	int place_cnt = 0;;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == true) {
				place_cnt++;
				visited[i][j] = false;
			}
		}
	}

	return place_cnt;
}

int main() {
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;

	for (int k = 1; k <= tc; k++) {
		int sx, sy;
		cin >> n >> m >> sx >> sy >> ttime;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}

		bfs(sx, sy);
		int ans = clac_and_clear();
		cout << '#' << k << ' ' << ans << '\n';
	}

	return 0;
}
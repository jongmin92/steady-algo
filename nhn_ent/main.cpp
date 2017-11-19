/*
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int m, n;
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
vector<vector<int>> timesMap;
vector<vector<bool>> visited;

void bfs(int sx, int sy) {
queue<pair<pair<int, int>, int> > q;
q.push(make_pair(make_pair(sx, sy), 0));
timesMap[sx][sy] = 0;
visited[sx][sy] = true;

while(!q.empty()) {
pair<int, int> point = q.front().first;
int x = point.first;
int y = point.second;
int times = q.front().second;
q.pop();

for (int i = 0; i < 8; i++) {
int nx = x + dx[i];
int ny = y + dy[i];

if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
continue;
}

q.push(make_pair(make_pair(nx, ny), times + 1));
timesMap[sx][sy] = times + 1;
visited[nx][ny] = true;
}
}
}

int main(int argc, char* argv[]) {
ios::sync_with_stdio(false);

cin >> m >> n;
visited.resize(m, vector<bool>(n));
timesMap.resize(m, vector<int>(n));
bfs(0, 0);

bool isSuccess = true;
int maxTimes = 0;
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
if (!visited[i][j]) {
isSuccess = false;
}

maxTimes = max(maxTimes, timesMap[i][j]);
}
}

if (isSuccess) {
cout << 'T' << maxTimes << '\n';
} else {
cout << 'F' << maxTimes << '\n';
}

return 0;
}
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "./pieces/Piece.h"
#include "./pieces/Knight.h"

using namespace std;

int m, n;
vector<vector<int>> timesMap;
vector<vector<bool>> visited;

void bfs(int sx, int sy) {
	queue<Piece*> q;
	q.push(new Knight(sx, sy));
	timesMap[sx][sy] = 0;
	visited[sx][sy] = true;

	int count = 1;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			Piece* piece = q.front();
			q.pop();

			while (piece->checkExistNextDir()) {
				pair<int, int> nextPoint = piece->getNextPoint();
				int nx = nextPoint.first;
				int ny = nextPoint.second;

				if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
					continue;
				}

				q.push(new Knight(nx, ny));
				timesMap[nx][ny] = count;
				visited[nx][ny] = true;
			}

			delete piece;
		}
		count++;
	}
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);

	cin >> m >> n;
	visited.resize(m, vector<bool>(n));
	timesMap.resize(m, vector<int>(n));
	bfs(0, 0);

	bool isSuccess = true;
	int maxTimes = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				isSuccess = false;
			}

			maxTimes = max(maxTimes, timesMap[i][j]);
		}
	}

	if (isSuccess) {
		cout << 'T' << maxTimes << '\n';
	}
	else {
		cout << 'F' << maxTimes << '\n';
	}

	return 0;
}
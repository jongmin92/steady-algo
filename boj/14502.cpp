#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 8

using namespace std;

int n, m;
int map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
vector<pair<int, int> > virus;
int max_value;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int recovery(int (*a)[MAX_SIZE], int (*b)[MAX_SIZE]) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                ret++;
            }
            
            a[i][j] = b[i][j];
        }
    }
    
    return ret;
}

void copy_map(int (*a)[MAX_SIZE], int (*b)[MAX_SIZE]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
    
    return;
}

void bfs() {
    queue<pair<int, int> > q;
    for (int i = 0; i < virus.size(); i++) {
        q.push(virus[i]);
    }
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] != 0) {
                continue;
            }
            map[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
    
    return;
}

void dfs(int x, int y, int cnt) {
    if (cnt == 3) {
        int tmp_map[MAX_SIZE][MAX_SIZE];
        copy_map(tmp_map, map);
        
        bfs();
        max_value = max(max_value, recovery(map, tmp_map));
        return;
    }
    
    for (int i = x; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visit[i][j] || map[i][j] != 0) {
                continue;
            }
            map[i][j] = 1;
            visit[i][j] = true;
            dfs (i, j, cnt+1);
            
            map[i][j] = 0;
            visit[i][j] = false;
        }
    }
    
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }
    
    dfs(0, 0, 0);
    
    cout << max_value << endl;
    
    return 0;
}

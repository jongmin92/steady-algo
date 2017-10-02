#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 10
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
int n, m, c; // 벌통의 크기, 벌통의 개수, 채취할 수 있는 꿀의 최대 양
int visit[MAX_SIZE][MAX_SIZE];
int honey[2][MAX_SIZE];
int max1, max2, max_sum;

void get_max_value(int row, int idx, int all_honey, int sum) {
    if (idx < m) {
        if (all_honey + honey[row][idx] <= c) {
            get_max_value(row, idx+1, all_honey + honey[row][idx], sum + (honey[row][idx] * honey[row][idx]));
            if (row == 0) {
                max1 = max(max1, sum + (honey[row][idx] * honey[row][idx]));
            } else {
                max2 = max(max2, sum + (honey[row][idx] * honey[row][idx]));
            }
        }
        get_max_value(row, idx+1, all_honey, sum);
    }
}

void calc() {
    get_max_value(0, 0, 0, 0);
    get_max_value(1, 0, 0, 0);
    
    max_sum = max(max_sum, max1 + max2);
}

void dfs(int x, int y, int cnt) {
    if (cnt == 2) {
        calc();
        max1 = 0;
        max2 = 0;
        return;
    }
    
    for (int i = x; i < n; i++) {
        for (int j = y; j < n; j++) {
            if (visit[i][j] == true || j + m - 1 >= n) {
                continue;
            }
            
            vector<int> tmp;
            for (int k = 0; k < m; k++) {
                honey[cnt][k] = map[i][j+k];
                visit[i][j+k] = true;
            }
            
            dfs(i, j, cnt+1);
            
            for (int k = 0; k < m; k++) {
                honey[cnt][k] = 0;
                visit[i][j+k] = false;
            }
        }
        y = 0;
    }
}

int main() {
    int tc;
    cin >> tc;
    
    for (int i = 1; i <= tc; i++) {
        cin >> n >> m >> c;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }
        
        dfs(0, 0, 0);
        cout << '#' << i << ' ' << max_sum << '\n';
        max_sum = 0;
    }
    
    return 0;
}

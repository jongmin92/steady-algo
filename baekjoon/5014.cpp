#include <iostream>
#include <queue>
#include <vector>

#define MAX_SIZE 1000001
using namespace std;

bool visit[MAX_SIZE];
int cnt[MAX_SIZE];

int main() {
    int f, s, g, u, d; // 전체 층, 현재 층, 목표 층, 업 층, 다운 층
    cin >> f >> s >> g >> u >> d;
    
    queue<int> q; // 층수
    visit[s] = true;
    cnt[s] = 0;
    q.push(s);
    
    while(!q.empty()) {
        int now_floor = q.front();
        int now_cnt = cnt[now_floor];
        q.pop();
        
        int next1 = now_floor + u;
        int next2 = now_floor - d;
        
        if (next1 < MAX_SIZE && visit[next1] == false) {
            q.push(next1);
            visit[next1] = true;
            cnt[next1] = now_cnt + 1;
        }
        
        if (next2 > 0 && visit[next2] == false)  {
            q.push(next2);
            visit[next2] = true;
            cnt[next2] = now_cnt + 1;
        }
    }
    
    if (visit[g] == true) {
        cout << cnt[g] << '\n';
    } else {
        cout << "use the stairs" << '\n';
    }
    
    return 0;
}

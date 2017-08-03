#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    
    queue<int> q;
    for (int i=1; i<=n; i++) {
        q.push(i);
    }
    
    cout << '<';
    for (int k=1; k<=n; k++) {
        for (int i=0; i<m-1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if (k != n) {
            cout << ", ";
        }
    }
    cout << '>' << '\n';
    
    return 0;
}

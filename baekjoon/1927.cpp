#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    int n;
    priority_queue<int> q;
    
    cin >> n;
    
    while (n--) {
        int x;
        cin >> x;
        
        if (x == 0) {
            cout << (q.empty()? 0 : -q.top()) << '\n';
            if (!q.empty()) {
                q.pop();
            }
        } else {
            q.push(-x);
        }
    }
    
    return 0;
}

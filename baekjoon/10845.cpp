#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    queue<int> d;
    
    int n;
    cin >> n;
    
    while(n--) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "push") {
            int n;
            cin >> n;
            d.push(n);
        } else if (cmd == "pop") {
            cout << (d.empty() ? -1 : d.front()) << '\n';
            
            if (!d.empty()) {
                d.pop();
            }
        } else if (cmd == "size") {
            cout << d.size() << '\n';
        } else if (cmd == "empty") {
            cout << (d.empty() ? 1 : 0) << '\n';
        } else if (cmd == "front") {
            if (d.empty()) {
                cout << -1 << '\n';
            } else {
                cout << d.front() << '\n';
            }
        } else if (cmd == "back") {
            cout << (d.empty() ? -1 : d.back()) << '\n';
        }
    }
    
    return 0;
}

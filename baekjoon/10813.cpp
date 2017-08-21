#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n, 0);
    
    for (int i=0; i<n; i++) {
        v[i] = i+1;
    }
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        swap(v[a-1], v[b-1]);
    }
    
    for (int x : v) {
        cout << x << " ";
    }
    
    cout << "\n";
}

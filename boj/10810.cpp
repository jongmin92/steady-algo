#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n);
    
    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        
        fill(v.begin()+i-1, v.begin()+j, k);
    }
    
    for (int i=0; i<n; i++) {
        cout << v[i] << ' ';
    }
    
    cout << '\n';
    
    return 0;
}

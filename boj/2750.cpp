#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int n, b;
    cin >> n;
    
    vector<int> a(n,0);
    
    for (int i=0; i<n; i++) {
        cin >> b;
        a[i] = b;
    }
    
    sort(a.begin(), a.end());
    
    for (int x : a) {
        cout << x << '\n';
    }
    
    return 0;
}

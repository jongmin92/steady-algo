#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> d(n);
    
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    for (int i=n-1; i>=0; i--) {
        d[i] = 1;
        
        for (int j=i+1; j<=n-1; j++) {
            if (a[i] > a[j] && d[i] < d[j]+1) {
                d[i] = d[j] + 1;
            }
        }
    }
    
    int ans = *max_element(d.begin(), d.end());
    cout << ans << '\n';
    
    return 0;
}

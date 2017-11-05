#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[20][20];
int main(void) {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<int> d(n-1);
    for (int i=1; i<n; i++) {
        d[i-1] = i;
    }
    
    int ans = 2147483647;
    
    do {
        bool ok = true;
        int sum = 0;
        for (int i=0; i<n-2; i++) {
            if (a[d[i]][d[i+1]] == 0) {
                ok = false;
            } else {
                sum += a[d[i]][d[i+1]];
            }
        }
        if (ok && a[0][d[0]] != 0 && a[d[n-2]][0] != 0) {
            sum += a[0][d[0]] + a[d[n-2]][0];
            if (ans > sum) {
                ans = sum;
            }
        }
    } while (next_permutation(d.begin(), d.end()));
    
    cout << ans << '\n';
    return 0;
}

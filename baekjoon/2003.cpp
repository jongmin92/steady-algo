#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    int a[n];
    
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int left = 0, right = 0;
    int sum = a[0];
    int ans = 0;
    
    while (left <= right && right < n) {
        if (sum < m) {
            right += 1;
            sum += a[right];
        } else if (sum == m) {
            ans += 1;
            right += 1;
            sum += a[right];
        } else if (sum > m) {
            sum -= a[left];
            left++;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}

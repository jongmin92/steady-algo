#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    vector<bool> c(n+1);
    vector<int> p;
    for (int i=2; i<=n; i++) {
        if (c[i] == false) {
            p.push_back(i);
            for (int j=i*2; j<=n; j+=i) {
                c[j] = true;
            }
        }
    }
    
    int left = 0, right = 0;
    int sum = p.empty() ? 0 : p[0];
    int ans = 0;
    
    while (left <= right && right < p.size()) {
        if (sum <= n) {
            if (sum == n) {
                ans += 1;
            }
            right++;
            if (right < p.size()) {
                sum += p[right];
            }
        } else {
            sum -= p[left++];
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}

#include <iostream>
using namespace std;

int n;
int day[16];
int pay[16];

int sum;

bool cal(int now, int money) {
    if (now == n+1) {
        sum = max(sum, money);
        return false;
    }
    
    if (now + day[now] <= n+1) {
        cal(now + day[now], money + pay[now]);
    }
    
    if (now+1 <= n+1) {
        cal(now+1, money);
    }
    
    return true;
}

int main(void) {
    cin >> n;
    
    for (int i=1; i<n+1; i++) {
        cin >> day[i] >> pay[i];
    }
    
    cal(1, 0);
    cout << sum << "\n";
    
    return 0;
}

#include <iostream>
using namespace std;

int d[1001];

int main(void) {
    d[0] = 1;
    d[1] = 1;
    int n;
    cin >> n;
    
    for (int i=2; i<=n; i++) {
        d[i] = d[i-1] + (d[i-2] * 2);
        d[i] %= 10007;
    }
    
    cout << d[n];
    
    return 0;
}

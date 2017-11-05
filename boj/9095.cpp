#include <iostream>
using namespace std;

int go(int count, int sum, int goal) {
    if (sum > goal) {
        return 0;
    }
    if (sum == goal) {
        return 1;
    }
    
    int now = 0;
    
    for (int i=1; i<=3; i++) {
        now += go(count+1, sum+i, goal);
    }
    return now;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << go(0, 0, n) << '\n';
    }
    
    return 0;
}

/* 2 */
/*
 #include <iostream>
 usting namespace std;
 
 int d[11];
 
 int main() {
    d[0] = 1;
    for (int i=1; i<=10; i++) {
        if (i-1 >= 0) {
            d[i] += d[i-1];
        }
        if (i-2 >= 0) {
            d[i] += d[i-2];
        }
        if (i-3 >= 0) {
            d[i] += d[i-3];
        }
    }
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << d[n];
    }
 }
*/

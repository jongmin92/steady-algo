#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n, {0,0});
    
    for (int i=0; i<n; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    sort(a.begin(), a.end());
    
    for (int i=0; i<a.size(); i++) {
        printf("%d %d\n", a[i].first, a[i].second);
    }
    
    return 0;
}

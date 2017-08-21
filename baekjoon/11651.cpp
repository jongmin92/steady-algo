#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &u, const pair<int, int> &v) {
    if (u.second == v.second) return u.first < v.first;
    else return u.second < v.second;
}

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n, {0,0});
    
    for (int i=0; i<n; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    sort(a.begin(), a.end(), cmp);
    
    for (int i=0; i<a.size(); i++) {
        printf("%d %d\n", a[i].first, a[i].second);
    }
    
    return 0;
}

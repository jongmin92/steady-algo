#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (string a, string b) {
    if (a.size() < b.size()) {
        return true;
    } else if (a.size() == b.size()) {
        return a < b;
    } else {
        return false;
    }
}

int main(void) {
    int n;
    string w;
    cin >> n;
    vector<string> a(n, "");
    
    for (int i=0; i<n; i++) {
        cin >> w;
        a[i] = w;
    }

    sort(a.begin(), a.end(), cmp);
    a.erase(unique(a.begin(), a.end()), a.end());
    
    for (string x : a) {
        cout << x << '\n';
    }
    
    return 0;
}

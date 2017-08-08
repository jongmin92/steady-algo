#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int m, n;
    cin >> m >> n;
    
    vector<int> v;
    for (int i=0; i<m; i++) {
        v.push_back(i+1);
    }
    
    while (n--) {
        int start, end;
        cin >> start >> end;
        
        reverse(v.begin() + start - 1, v.begin() + end);
    }
    
    for (int x : v) {
        cout << x << " ";
    }
    
    cout << "\n";
    
    return 0;
}

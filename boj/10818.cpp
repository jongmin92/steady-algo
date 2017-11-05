#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
//    int n, num, min=1000000, max=-1000000;
//    cin >> n;
//    
//    while (n--) {
//        cin >> num;
//        
//        if (min > num) {
//            min = num;
//        }
//        
//        if (max < num) {
//            max = num;
//        }
//    }
//    
//    cout << min << " " << max;

    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
//    cout << *min_element(a.begin(), a.end()) << ' ' << *max_element(a.begin(), a.end()) << '\n';
    auto p = minmax_element(a.begin(), a.end());
    
    cout << *p.first << ' ';
    cout << *p.second << '\n';
    
    return 0;
}

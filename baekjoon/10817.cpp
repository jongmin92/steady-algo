#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b  >> c;
    cout << (a+b+c) - min({a, b, c}) - max({a, b, c,}) << '\n';
    
//    auto p = minmax({a, b, c});
//    cout << (a+b+c) - p.first - p.second << '\n';
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    vector<int> num;
    int n;
    cin >> n;
    
    while (n--) {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }
    
    int v;
    cin >> v;
    cout << count(num.begin(), num.end(), v) << '\n';
    
    return 0;
}

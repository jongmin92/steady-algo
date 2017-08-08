#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    
    for (int i='a'; i<='z'; i++) {
        auto it = find(s.begin(), s.end(), i);
        
        if (it == s.end()) {
            cout << "-1";
        } else {
            cout << (it-s.begin());
        }
        
        cout << " ";
    }
    
    cout << "\n";
    
    return 0;
}

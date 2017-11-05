#include <iostream>
using namespace std;

int main(void) {
    int cnt;
    string s;
    
    cin >> cnt;
    cin.ignore();
    
    while(cnt--) {
        getline(cin, s);
        cout << atoi(&s[0]) + atoi(&s[2]) << endl;
    }
    
    return 0;
}

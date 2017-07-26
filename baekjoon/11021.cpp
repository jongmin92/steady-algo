#include <iostream>
using namespace std;

int main(void) {
    int cnt;
    string s;
    
    cin >> cnt;
    cin.ignore();
    
    for (int i = 0; i < cnt; i++) {
        getline(cin, s);
        cout << "Case #" << i+1 << ": " << atoi(&s[0]) + atoi(&s[2]) << endl;
    }
    
    return 0;
}

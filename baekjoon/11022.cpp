#include <iostream>
using namespace std;

int main(void) {
    int cnt, a, b;
    string s;
    
    cin >> cnt;
    cin.ignore();
    
    for (int i = 0; i < cnt; i++) {
        getline(cin, s);
        a = atoi(&s[0]);
        b = atoi(&s[2]);
        cout << "Case #" << i+1 << ": " << a << " + " << b << " = " << a+b << endl;
    }
    
    return 0;
}

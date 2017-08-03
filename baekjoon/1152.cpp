#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int cnt = 0;
    string s;
   
    while (cin >> s) {
        cnt += 1;
    }
    
    cout << cnt << '\n';
    return 0;
}

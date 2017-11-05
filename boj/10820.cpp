#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string s;
    
    while(getline(cin, s)) {
        int lower = 0;
        int upper = 0;
        int number = 0;
        int space = 0;
        
        for (char x : s) {
            if (x >= 'a' && x <= 'z') {
                lower++;
            } else if (x >= 'A' && x <='Z') {
                upper++;
            } else if  (x >= '0' && x <= '9') {
                number++;
            } else if (x == ' ') {
                space++;
            }
        }
        
        cout << lower << ' ' << upper << ' ' << number << ' ' << space << '\n';
    }
    
    return 0;
}

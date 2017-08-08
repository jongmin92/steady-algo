#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(void) {
    string s;
    string line;
    
    while(cin >> line) {
        s += line;
    }
    
    istringstream sin(s);
    
    string number;
    int sum = 0;
    
    while (getline(sin, number, ',')) {
        sum += stoi(number);
    }
    
    cout << sum << '\n';
    return 0;
}

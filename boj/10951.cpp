#include <iostream>
using namespace std;

int main(void) {
    int a, b;

    while(cin >> a >> b) {
        cout << a+b << endl;
    }
    
    return 0;
}

/*
Line 7: 계속 a와 b에 값을 읽는다. int가 아닌 값이 읽히거나 cin이 닫히자마자 loop가 종료된다.
*/

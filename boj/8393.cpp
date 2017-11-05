#include <iostream>
using namespace std;

int main(void) {
    int n, sum = 0;
    cin >> n;

    while (n) {
        sum += n;
        n--;
    }
    
    cout << sum;
    
    return 0;
}

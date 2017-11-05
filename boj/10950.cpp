#include <iostream>
using namespace std;

int main(void) {
    int count, a, b;
    int* sum;
    
    cin >> count;
    sum = new int[count];
    
    for (int i = 0; i < count; i++) {
        cin >> a >> b;
        sum[i] = a+b;
    }
    
    for (int i = 0; i < count; i++) {
        cout << sum[i] << endl;;
    }
    
    return 0;
}

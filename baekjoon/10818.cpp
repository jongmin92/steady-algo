#include <iostream>
using namespace std;

int main(void) {
    int n, num, min=1000000, max=-1000000;
    cin >> n;
    
    while (n--) {
        cin >> num;
        
        if (min > num) {
            min = num;
        }
        
        if (max < num) {
            max = num;
        }
    }
    
    cout << min << " " << max;
    
    return 0;
}

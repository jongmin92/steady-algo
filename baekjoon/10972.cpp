#include <iostream>
using namespace std;

bool cumstom_next_permutation(int *a, int n) {
    int i = n-1;
    while (i > 0 && a[i-1] >= a[i]) {
        i -= 1;
    }
    if (i <= 0) {
        return false; // 마지막 순열
    }
    int j = n-1;
    while(a[j] <= a[i-1]) {
        j -= 1;
    }
    swap(a[i-1], a[j]);
    j = n-1;
    while (i < j) {
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main(void) {
    int n;
    cin >> n;
    int* arr = new int[n];
    
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    if (cumstom_next_permutation(arr, n)) {
        for (int i=0; i<n; i++) {
            cout << arr[i] << ' ';
        }
    } else {
        cout << -1;
    }
        
    cout << '\n';
    
    return 0;
}

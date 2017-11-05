#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    
    sort(a.begin(), a.end());
    
    int m;
    scanf("%d", &m);
    
    for (int i=0; i<m; i++) {
        int number;
        scanf("%d", &number);
        printf("%d ", binary_search(a.begin(), a.end(), number));
    }
    
    printf("\n");
    return 0;
}

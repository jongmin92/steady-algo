#include <iostream>
#include <set>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    
    set<int> s;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    
    int m;
    cin >> m;
    
    for (int i=0; i<m; i++) {
        int x;
        scanf("%d", &x);
        printf("%lu ", s.count(x));
    }
    
    printf("\n");
    
    return 1;
}

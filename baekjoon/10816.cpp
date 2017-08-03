#include <iostream>
#include <set>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    
    multiset<int> cards;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        cards.insert(x);
    }
    
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        printf("%lu ", cards.count(x));
    }
    
    printf("\n");
    
    return 0;
}


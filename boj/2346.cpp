#include <iostream>
#include <list>
using namespace std;

int main(void) {
    int n;
    list<pair<int, int>> balloon;
    
    cin >> n;
    
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        balloon.push_back({x, i});
    }

    auto it = balloon.begin();
    for (int i=0; i<n-1; i++) {
        cout << (it->second) << ' ';
        int step = it->first;
        
        if (step > 0) {
            auto temp = it;
            ++temp;
            if (temp == balloon.end()) {
                temp = balloon.begin();
            }
            balloon.erase(it);
            it = temp;
            for (int i=1; i<step; i++) {
                ++it;
                if (it == balloon.end()) {
                    it = balloon.begin();
                }
            }
        } else if (step < 0) {
            step = -step;
            auto temp = it;
            if (temp == balloon.begin()) {
                temp = balloon.end();
            }
            --temp;
            balloon.erase(it);
            it = temp;
            for (int i=1; i<step; i++) {
                if (it == balloon.begin()) {
                    it = balloon.end();
                }
                --it;
            }
        }
    }
    
    cout << balloon.front().second << '\n';
    
    return 0;
}

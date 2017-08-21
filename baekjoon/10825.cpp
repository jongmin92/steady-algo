#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int ko, en, ma;
};

bool cmp(const Student &u, const Student &v) {
    if (u.ko > v.ko) {
        return true;
    } else if (u.ko == v.ko) {
        if (u.en < v.en) {
            return true;
        } else if (u.en == v.en) {
            if (u.ma > v.ma) {
                return true;
            } else if (u.ma == v.ma) {
                return u.name < v.name;
            }
        }
    }
    return false;
}

int main(void) {
    int n;
    cin >> n;
    vector<Student> a(n);
    
    for (int i=0; i<n; i++) {
        cin >> a[i].name >> a[i].ko >> a[i].en >> a[i].ma;
    }
    
    sort(a.begin(), a.end(), cmp);
    
    for (int i=0; i<n; i++) {
        cout << a[i].name << '\n';
    }
    
    return 0;
}

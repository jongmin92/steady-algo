#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    int age, join;
    string name;
};

bool cmp(const Person &u, const Person &v) {
    if (u.age < v.age) {
        return true;
    } else if (u.age == v.age) {
        if (u.join < v.join) {
            return true;
        }
    }
    
    return false;
}

int main(void) {
    int n;
    cin >> n;
    vector<Person> a(n);
    
    for (int i=0; i<n; i++) {
        a[i].join = i;
        cin >> a[i].age >> a[i].name;
    }
    sort(a.begin(), a.end(), cmp);
    
    for (int i=0; i<n; i++) {
        cout << a[i].age << ' ' << a[i].name << '\n';
    }
    
    return 0;
}

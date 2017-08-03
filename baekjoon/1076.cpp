#include <iostream>
#include <map>
using namespace std;

int main(void) {
    map<string, pair<int, int>> bulb;
    bulb["black"] = {0, 1};
    bulb["brown"] = {1, 10};
    bulb["red"] = {2, 100};
    bulb["orange"] = {3, 1000};
    bulb["yellow"] = {4, 10000};
    bulb["green"] = {5, 100000};
    bulb["blue"] = {6, 1000000};
    bulb["violet"] = {7, 10000000};
    bulb["grey"] = {8, 100000000};
    bulb["white"] = {9, 1000000000};
    
    string bulb1, bulb2, bulb3;
    cin >> bulb1 >> bulb2 >> bulb3;
    
    long long ans = (long long)((bulb[bulb1].first) * 10 + bulb[bulb2].first) * bulb[bulb3].second;
    
    cout << ans << '\n';
    
    return 0;
}

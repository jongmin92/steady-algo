// dfs
#include <iostream>
#include <algorithm>

#define MAX_SIZE 16

using namespace std;

int day[MAX_SIZE];
int pay[MAX_SIZE];
int n;

int sum = 0;

void go(int d, int s) {
    if (d == n + 1) {
        sum = max(sum, s);
        return;
    }
    
    if (d + day[d] <= n + 1) {
        go(d + day[d], s + pay[d]);
    }
    if (d + 1 <= n + 1) {
        go(d + 1, s);
    }
}

int main(void) {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> day[i] >> pay[i];
    }
   
    //std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();

    go(1, 0);
    
    cout << sum << '\n';

//    std::chrono::system_clock::time_point EndTime = std::chrono::system_clock::now();
//    std::chrono::nanoseconds nano = EndTime - StartTime;
//    std::cout << "Test() 함수를 수행하는 걸린 시간: " << nano.count()  << endl;
    
    return 0;
}
 

/*
// dp
#include <iostream>
#include <algorithm>
#include <chrono>

#define MAX_SIZE 16

using namespace std;

int day[MAX_SIZE];
int pay[MAX_SIZE];
int dp[MAX_SIZE];

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> day[i] >> pay[i];
    }
    
    int sum = 0;
    
//    std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();
 
    
    for (int i = 1; i <= n; i++) {
        int next1 = i + day[i];
        int next2 = i + 1;
        
        if (next1 <= n + 1) {
            dp[next1] = max(dp[next1], dp[i] + pay[i]);
        }
        if (next2 <= n + 1) {
            dp[next2] = max(dp[next2], dp[i]);
        }
        
        sum = max(max(sum, dp[next1]), dp[next2]);
    }
    
    cout << sum << '\n';

//    std::chrono::system_clock::time_point EndTime = std::chrono::system_clock::now();
//    std::chrono::nanoseconds nano = EndTime - StartTime;
//    std::cout << "Test() 함수를 수행하는 걸린 시간: " << nano.count()  << endl;
    
    return 0;
}
*/

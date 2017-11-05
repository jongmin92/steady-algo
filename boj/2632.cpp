#include <iostream>
#include <vector>
#include <map>

#define MAX_SIZE 1000
using namespace std;

int target;
int m, n;
int a[MAX_SIZE], b[MAX_SIZE];
map<int, int> a_sum, b_sum;

void get_all_sum(int* arr, map<int, int>& sum_map, int size) {
    for (int i = 1; i < size; i++) { // 1개~suze-1개로 만들 수 있는 경우 모두 구하기
        for (int j = 0; j < size; j++) { // 시작하는 피자 순서
            int sum = 0;
            for (int k = 1; k <= i; k++) { // j번째 피자부터 i개 만큼 더하기
                if (j+k-1 < size) {
                    sum += arr[j+k-1];
                } else {
                    sum += arr[j+k-1-size];
                }
            }
            sum_map[sum] = sum_map[sum] + 1;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < size; i++) { // 피자의 모든 조각(size) 합
        sum += arr[i];
    }
    sum_map[sum] = 1;
    
    return ;
}

int main() {
    ios_base::sync_with_stdio (false);
    
    cin >> target >> m >> n;
    
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++) {
        cin >> b[j];
    }
    
    get_all_sum(a, a_sum, m);
    get_all_sum(b, b_sum, n);
    
    int cnt = a_sum[target] + b_sum[target]; // a와 b 각각의 피자만 사용해서 만드는 경우
    for (int i = 1; i < target; i++) { // a와 b피자 같이 사용해서 만드는 경우
        if (a_sum[i] && b_sum[target-i]) {
            cnt += (a_sum[i] * b_sum[target-i]);
        }
    }

    cout << cnt << '\n';

    return 0;
}

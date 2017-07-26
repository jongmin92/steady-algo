#include <iostream>
using namespace std;

int get_day_of_month(int month) {
    int day = 0;
    
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            day = 31;
            break;
        case 4: case 6: case 9: case 11:
            day = 30;
            break;
        case 2:
            day = 28;
            break;
    }
    
    return day;
}

int cal_total_day_of_period(int month, int day) {
    int total_day = 0;
    
    for (int i = 1; i < month; i++) {
        total_day += get_day_of_month(i);
    }
    
    total_day += (day - 1);
    
    return total_day;
}

string get_en_day_by_day_diff(int day_diff) {
    string en_day;
    
    switch (day_diff % 7) {
        case 0:
            en_day = "MON";
            break;
        case 1:
            en_day = "TUE";
            break;
        case 2:
            en_day = "WED";
            break;
        case 3:
            en_day = "THU";
            break;
        case 4:
            en_day = "FRI";
            break;
        case 5:
            en_day = "SAT";
            break;
        case 6:
            en_day = "SUN";
            break;
    }
    
    return en_day;
}

int main(void) {
    int m, d, total_day;
    cin >> m >> d;
    
    total_day = cal_total_day_of_period(m, d);
    
    cout << get_en_day_by_day_diff(total_day);
    
    return 0;
}

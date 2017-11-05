#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define MAP_MAX_SIZE 10
#define PERSON_MAX_SIZE 10
using namespace std;

struct Person
{
	bool is_end;
	int x;
	int y;
	int stair_type; // 1 or 2
	int go_stair_remain_time; // 계단 까지 갈때, 남은 시간
	int on_stair_remain_time; // 계단 위 남은 시간
};

int map[MAP_MAX_SIZE][MAP_MAX_SIZE];
Person person_list[PERSON_MAX_SIZE];
pair<pair<int, int>, int> fir_stair, sec_stair;
vector<Person*> fir_stair_v, sec_stair_v;
int N;
int person_size;
int min_value = INT_MAX;

void init_map_and_person() {
	int stair_idx = 0;
	person_size = 0;

	// map
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			// person
			if (map[i][j] == 1) {
				int idx = person_size;
				person_list[idx].x = i;
				person_list[idx].y = j;
				person_list[idx].go_stair_remain_time = -1;
				person_list[idx].on_stair_remain_time = -1;
				person_list[idx].is_end = false;
				person_size++;
			}
			// stair
			else if (map[i][j] > 1) {
				if (stair_idx == 0) {
					fir_stair = make_pair(make_pair(i, j), map[i][j]);
					stair_idx++;
				}
				else {
					sec_stair = make_pair(make_pair(i, j), map[i][j]);
				}
			}
		}
	}
}

void decide_stair(int order) {
	for (int i = 0; i < person_size; i++) {
		int person_x = person_list[i].x;
		int person_y = person_list[i].y;

		if ((1 << i) & order) {
			int stair_x = fir_stair.first.first;
			int stair_y = fir_stair.first.second;
			person_list[i].stair_type = 1;
			person_list[i].go_stair_remain_time = abs(person_x - stair_x) + abs(person_y - stair_y);
			person_list[i].on_stair_remain_time = fir_stair.second;
		}
		else {
			int stair_x = sec_stair.first.first;
			int stair_y = sec_stair.first.second;
			person_list[i].stair_type = 2;
			person_list[i].go_stair_remain_time = abs(person_x - stair_x) + abs(person_y - stair_y);
			person_list[i].on_stair_remain_time = sec_stair.second;
		}
		person_list[i].is_end = false;
	}
}

bool check_all_person_end() {
	for (int i = 0; i < person_size; i++) {
		if (!person_list[i].is_end) {
			return false;
		}
	}

	return true;
}

void next_time(int t) {
	// 계단에 있는 사람들 이동
	int fir_stair_on_person_cnt = 0;
	int sec_stair_on_person_cnt = 0;
	for (int i = 0; i < fir_stair_v.size(); i++) {
		if (fir_stair_on_person_cnt < 3) {
			Person* person = fir_stair_v[i];

			if (person->is_end) {
				continue;
			}

			if (person->on_stair_remain_time == 0) {
				person->is_end = true;
				continue;
			}

			person->on_stair_remain_time--;
			fir_stair_on_person_cnt++;
		}
	}
	for (int j = 0; j < sec_stair_v.size(); j++) {
		if (sec_stair_on_person_cnt < 3) {
			Person* person = sec_stair_v[j];

			if (person->is_end) {
				continue;
			}

			if (person->on_stair_remain_time == 0) {
				person->is_end = true;
				continue;
			}

			person->on_stair_remain_time--;
			sec_stair_on_person_cnt++;
		}
	}

	// 계단에 도착하지 못한 사람들 이동
	for (int i = 0; i < person_size; i++) {
		Person *person = &person_list[i];
		if (person->is_end) {
			continue;
		}

		if (person->go_stair_remain_time > 0) {
			person->go_stair_remain_time--;

			// 계단에 도착하면 계단 vector에 넣는다.
			if (person->go_stair_remain_time == 0) {
				if (person->stair_type == 1) {
					fir_stair_v.push_back(person);
				}
				else {
					sec_stair_v.push_back(person);
				}
			}
		}
	}
}

void clear_vector() {
	fir_stair_v.clear();
	sec_stair_v.clear();
}

int main() {
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;

	for (int k = 1; k <= tc; k++) {
		cin >> N;

		init_map_and_person();
		
		// 완전 탐색
		for (int i = 0; i < (1 << person_size); i++) {
			decide_stair(i);

			int t = 1;
			while (!check_all_person_end()) {
				next_time(t);
				t++;
			}
			clear_vector();

			min_value = min(min_value, t);
		}
		
		cout << '#' << k << ' ' << min_value - 1 << '\n';
		min_value = INT_MAX;
	}

	return 0;
}
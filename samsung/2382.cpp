#include <iostream>
#include <vector>
#include <string.h>

#define GROUP_MAX_SIZE 1000
#define MAP_MAX_SIZE 100
using namespace std;

struct Group {
	int x;
	int y;
	int size;
	int dir;
	int dead;
	int pre_size;
};

int n, times, group_cnt;
Group group_list[GROUP_MAX_SIZE];
// 해당 좌표에 그룹이 있으면 index, 없으면 -1
int exist[MAP_MAX_SIZE][MAP_MAX_SIZE];

// 무시, 상, 하, 좌, 우
int dx[5] = {0, -1, 1, 0, 0 };
int dy[5] = {0, 0, 0, -1, 1 };

int get_deposit_dir(int dir) {
	switch (dir) {
	case 1:
		return 2;
	case 2:
		return 1;
	case 3:
		return 4;
	case 4:
		return 3;
	default:
		return -1;
	}
}

// a가 b를 합치면 리턴 1
// b가 a를 합치면 리턴 0
int combine_group(Group *a, Group *b) {
	if (a->size > b->pre_size) {
		a->size += b->size;
		b->dead = true;
		return 1;
	}
	else {
		b->size += a->size;
		a->dead = true;
		return 0;
	}
}

void next_time() {
	for (int i = 0; i < group_cnt; i++) {
		Group *g = &group_list[i];
		if (g->dead) {
			continue;
		}

		g->x = g->x + dx[g->dir];
		g->y = g->y + dy[g->dir];
		g->pre_size = g->size;

		// 원래 있는것과 합치기
		int index = exist[g->x][g->y];
		if (index != -1) {
			Group *tmp = &(group_list[index]);
			if (combine_group(g, tmp) == 1) {
				exist[g->x][g->y] = i;
			}
		}
		else {
			exist[g->x][g->y] = i;
		}

		// 약품 구간
		if (g->x == 0 || g->x == n - 1 || g->y == 0 || g->y == n - 1) {
			g->size /= 2;
			g->dir = get_deposit_dir(g->dir);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;

	for (int k = 1; k <= tc; k++) {
		cin >> n >> times >> group_cnt;

		for (int i = 0; i < group_cnt; i++) {
			int x, y, size, dir;
			cin >> x >> y >> size >> dir;
			group_list[i].x = x;
			group_list[i].y = y;
			group_list[i].size = size;
			group_list[i].dir = dir;
			group_list[i].dead = false;
			group_list[i].pre_size = size;
		}

		while (times--) {
			memset(exist, -1, sizeof(exist));
			next_time();
		}

		int live_cnt = 0;
		for (int i = 0; i < group_cnt; i++) {
			if (!group_list[i].dead) {
				live_cnt += group_list[i].size;
			}
		}

		cout << '#' << k << ' ' << live_cnt << endl;;
	}	

	return 0;
}
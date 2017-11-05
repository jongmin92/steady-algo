#include <iostream>
#include <algorithm>

#define MAP_MAX_SIZE 10
#define ANS_MAX 11
using namespace std;

char map[MAP_MAX_SIZE][MAP_MAX_SIZE];
int N, M;
int ans = ANS_MAX;
int rx, ry, bx, by, hx, hy;
bool is_r_hall_in, is_b_hall_in;

void init_map() {
	char c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			map[i][j] = c;

			if (c == 'R') {
				rx = i;
				ry = j;
			}
			else if (c == 'B') {
				bx = i;
				by = j;
			}
			else if (c == 'O') {
				hx = i;
				hy = j;
			}
		}
	}
}

int get_deposit_dir(int dir) {
	if (dir == 0) {
		return 1;
	}
	else if (dir == 1) {
		return 0;
	}
	else if (dir == 2) {
		return 3;
	}
	else if (dir == 3) {
		return 2;
	}
}

int get_priority(int dir) { // 0 = 빨간공, 1 = 파란공
	int priority = -1;

	// 상
	if (dir == 0) {
		priority = bx < rx;
	}
	// 하
	else if (dir == 1) {
		priority = bx > rx;
	}
	// 좌
	else if (dir == 2) {
		priority = by < ry;
	}
	// 우
	else if (dir == 3) {
		priority = by > ry;
	}

	return priority;
}

int move_x(int x, int y, int dir) {
	int nx = x;
	char type;

	if (dir == 0) {
		for (int i = x - 1; i > 0; i--) {
			type = map[i][y];
			if (type == '#') {
				break;
			}
			else if (type == 'O') {
				nx = i;
				break;
			}
			else {
				nx = i;
			}
		}
	}
	else {
		for (int i = x + 1; i < N - 1; i++) {
			type = map[i][y];
			if (type == '#') {
				break;
			}
			else if (type == 'O') {
				nx = i;
				break;
			}
			else {
				nx = i;
			}
		}
	}
	
	return nx;
}

int move_y(int x, int y, int dir) {
	int ny = y;
	char type;

	if (dir == 2) {
		for (int i = y - 1; i > 0; i--) {
			type = map[x][i];
			if (type == '#') {
				break;
			}
			else if (type == 'O') {
				ny = i;
				break;
			}
			else {
				ny = i;
			}
		}
	}
	else {
		for (int i = y + 1; i < M - 1; i++) {
			type = map[x][i];
			if (type == '#') {
				break;
			}
			else if (type == 'O') {
				ny = i;
				break;
			}
			else {
				ny = i;
			}
		}
	}

	return ny;
}

void move(int dir) {
	if (dir == 0 || dir == 1) { // 상, 하
		rx = move_x(rx, ry, dir);
		bx = move_x(bx, by, dir);
	}
	else { // 좌, 우
		ry = move_y(rx, ry, dir);
		by = move_y(bx, by, dir);
	}
}

void check_hall_in() {
	if (bx == hx && by == hy) {
		is_b_hall_in = true;
	}

	if (rx == hx && ry == hy) {
		is_r_hall_in = true;
	}
}

void priority_move(int priority, int dir) {
	if (dir == 0) {
		if (priority == 0) {
			bx = bx + 1;
		}
		else {
			rx = rx + 1;
		}
	}
	else if (dir == 1) {
		if (priority == 0) {
			bx = bx - 1;
		}
		else {
			rx = rx - 1;
		}
	}
	else if (dir == 2) {
		if (priority == 0) {
			by = by + 1;
		}
		else {
			ry = ry + 1;
		}
	}
	else if (dir == 3) {
		if (priority == 0) {
			by = by - 1;
		}
		else {
			ry = ry - 1;
		}
	}
}

void dfs(int pre_dir, int cnt) {
	if (cnt > 10) {
		is_b_hall_in = false;
		is_r_hall_in = false;
		return;
	}

	if (is_b_hall_in) {
		is_b_hall_in = false;
		is_r_hall_in = false;
		return;
	}
	else {
		if (is_r_hall_in) {
			is_b_hall_in = false;
			is_r_hall_in = false;
			ans = min(ans, cnt);
			return;
		}
	}

	int brx = rx;
	int bry = ry;
	int bbx = bx;
	int bby = by;

	// 상, 하, 좌, 우
	for (int dir = 0; dir < 4; dir++) {
		if (dir == pre_dir || dir == get_deposit_dir(pre_dir)) {
			continue;
		}

		int priority = get_priority(dir);

		// 이동 & 홀 인 체크
		move(dir);
		check_hall_in();

		// 공이 겹칠 경우, 우선순위에 따라 이동
		if (rx == bx && ry == by) {
			priority_move(priority, dir);
		}
		
		if (brx != rx || bry != ry || bbx != bx || bby != by) {
			dfs(dir, cnt + 1);
		}

		rx = brx;
		ry = bry;
		bx = bbx;
		by = bby;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;

	init_map();
	dfs(-1, 0);

	if (ans == ANS_MAX) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}
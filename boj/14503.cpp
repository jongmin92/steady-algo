#include <iostream>
//#include <stdlib.h>

#define MAX_SIZE 50
using namespace std;

int n, m;
int map[MAX_SIZE][MAX_SIZE]; // 0=ºó Ä­, 1=º®, 2=Ã»¼Ò
int ans; // Ã»¼Ò °³¼ö

int change_direction(int d) { // ¹æÇâ(0=ºÏ, 1=µ¿, 2=³², 3=¼­)
	switch (d) {
		case 0:
			return 3;
		case 1:
			return 0;
		case 2:
			return 1;
		case 3:
			return 2;
	}
}

int get_next_x(int x, int d, int size) {
	if (d == 0) {
		x = x - size;
	}
	else if (d == 2) {
		x = x + size;
	}
	
	if (x < 0 || x > n - 1) {
		x = -1;
	}

	return x;
}

int get_next_y(int y, int d, int size) {
	if (d == 3) {
		y = y - size;
	}
	else if (d == 1) {
		y = y + size;
	}

	if (y < 0 || y > m - 1) {
		y = -1;
	}

	return y;
}

bool check_enable_clean(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}

	if (map[x][y] == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool check_enalbe_back(int x, int y, int d) {
	if (d == 0) { // ºÏ
		x = x + 1;
	}
	else if (d == 1) { // µ¿
		y = y - 1;
	}
	else if (d == 2) { // ³²
		x = x - 1;
	}
	else if (d == 3) { // ¼­
		y = y + 1;
	}

	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	if (map[x][y] == 1) {
		return false;
	}

	return true;
}

void go(int x, int y, int d) {
	// ÇöÀç À§Ä¡¸¦ Ã»¼Ò
	if (map[x][y] == 0) {
		map[x][y] = 2;
		ans++;
	}

	int direction_change_cnt = 0;
	do {
		int next_x, next_y;
		direction_change_cnt++;
		d = change_direction(d);
		next_x = get_next_x(x, d, 1);
		next_y = get_next_y(y, d, 1);
		if (check_enable_clean(next_x, next_y)) {
			go(next_x, next_y, d);
			return;
		}
	} while (direction_change_cnt < 4);			

	// 2-3
	if (check_enalbe_back(x, y, d)) {
		int next_x = get_next_x(x, d, -1);
		int next_y = get_next_y(y, d, -1);

		if (next_x != -1 || next_y != -1) {
			go(next_x, next_y, d);
		}
	}
	
	// 2-4
	return;
}

int main() {
	cin >> n >> m;
	int x, y, d; // xÁÂÇ¥, yÁÂÇ¥, ¹æÇâ(0=ºÏ, 1=µ¿, 2=³², 3=¼­)
	cin >> x >> y >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	go(x, y, d);

	cout << ans << '\n';

	return 0;
}
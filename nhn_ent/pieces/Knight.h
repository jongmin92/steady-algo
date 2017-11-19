#ifndef __KNIGHT__
#define __KNIGHT__

#include "./Piece.h"

using namespace std;

class Knight : public Piece {
private:
	int dir = 0;
	static int dx[8];
	static int dy[8];

public:
	Knight(int _x, int _y) : Piece(_x, _y) {};
	bool checkExistNextDir() {
		return dir < 8;
	};

	pair<int, int> getNextPoint() {
		int nx = getX() + dx[dir];
		int ny = getY() + dy[dir];
		dir++;
		return make_pair(nx, ny);
	};
};

int Knight::dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int Knight::dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

#endif
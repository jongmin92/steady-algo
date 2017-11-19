#ifndef __PIECE__
#define __PIECE__

#include <utility>
using namespace std;

class Piece {
private:
	int x;
	int y;

public:
	Piece(int _x, int _y) {
		x = _x;
		y = _y;
	};
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}

	virtual bool checkExistNextDir() = 0;
	virtual pair<int, int> getNextPoint() = 0;
};

#endif
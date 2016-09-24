#include <fstream>
#include <iostream>
#include <vector>
class passTable {
	bool **Table;
	int *up, *down;
	int h, l;
public:
	void printTable(int x, int y) {
		using namespace std;
		for (int j = h - 1; j >= 0; j--) {
			for (int i = 0; i < l; i++) {
				if (i == 1 && j == y)
					cout << "B ";
				else
					cout << Table[i][j] << " ";
			}
			cout << endl;
		}
		system("pause");
	}
	int getheight() const {
		return h;
	}
	int getwedith()const {
		return l;
	}
	passTable(int h, int l) {
		Table = new bool*[l];
		for (int i = 0; i < l; i++) {
			Table[i] = new bool[h];
			for (int j = 0; j < h; j++) {
				Table[i][j] = false;
			}
		}
		up = new int[h];
		down = new int[h];
		this->h = h;
		this->l = l;
	}
	void setUpAndDown(int x, int up, int down) {
		this->up[x] = up;
		this->down[x] = down;
	}
	int getup(int x) const {
		return up[x];
	}
	int getdown(int x) const {
		return down[x];
	}
	void initcolumn(int x, int up, int down) {
		for (int i = 0; i < h; i++) {
			if (i > up || i < down)
				Table[x][i] = true;
		}
	}
	bool getIfBlocked(int x, int y) const {
		if (y < h)
			return Table[x][y];
		else
			return Table[x][h - 1];
	}
};
passTable* PassTable;
bool canPass = false;
int touchCount;
int maxPass = -1;//the length not the num
void move(int x, int y, int up, int touchcount);
int main() {
	using namespace std;
	ifstream infile("in.txt");
	int n, m, k;
	infile >> n >> m >> k;
	PassTable = new passTable(m, n);
	for (int i = 0; i < n; i++) {
		int up, down;
		infile >> up >> down;
		PassTable->setUpAndDown(i, up, down);
	}
	for (int i = 0; i < k; i++) {
		int x, up, down;
		infile >> x >> down >> up;
		PassTable->initcolumn(x, up, down);
	}
	for (int i = 0; i < m; i++) {
		int j = 0;
		for (; j*PassTable->getup(0) + i < m; j++) {
			move(0, i, j, 0);
		}
		move(0, i, j, 0);
	}
	cout << canPass << endl << canPass ? touchCount : maxPass;
	system("pause");
	return 0;
}
void move(int x, int y, int up, int touchcount) {
	PassTable->printTable(x, y);
	touchcount += up;
	if (x >= PassTable->getwedith()) {
		if (!canPass) {
			canPass = true;
			touchCount = touchcount;
		}
		else {
			if (touchcount < touchCount) {
				touchCount = touchcount;
			}
		}
		return;
	}
	if (up == 0) {
		if (y <= PassTable->getdown(x)) {
			if (canPass)return;
			else if (x <= maxPass)return;
			else {
				maxPass = x;
				return;
			}
		}
		else if (PassTable->getIfBlocked(x + 1, y - PassTable->getdown(x))) {
			if (canPass)return;
			else if (x <= maxPass)return;
			else {
				maxPass = x;
				return;
			}
		}
		else {
			int j = 0;
			for (; j*PassTable->getup(0) + x < PassTable->getheight(); j++) {
				move(x + 1, y - PassTable->getdown(x), j, touchcount);
			}
			move(x + 1, y - PassTable->getdown(x), j, touchcount);
		}
	}
	else {
		if (PassTable->getIfBlocked(x + 1, y + PassTable->getdown(x)*up)) {
			if (canPass)return;
			else if (x <= maxPass)return;
			else {
				maxPass = x;
				return;
			}
		}
		else {
			int j = 0;
			int Y = (y + PassTable->getdown(x)*up)>PassTable->getheight() - 1 ? y + PassTable->getdown(x)*up : PassTable->getheight() - 1;
			for (; j*PassTable->getup(0) + x < PassTable->getheight(); j++) {
				move(x + 1, Y, j, touchcount);
			}
			move(x + 1, Y, j, touchcount);
		}
	}
}
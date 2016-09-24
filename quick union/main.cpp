#include <array>
#include <fstream>
using namespace std;
void root(int& tm1, array<int, 10> a) {
	while (a.at(tm1) != tm1)tm1 = a.at(tm1);
}
void union1(int m1, int m2, array<int, 10>& a) {
	int tm1 = a.at(m1), tm2 = a.at(m2);
	for (int &i : a) {
		if (i == tm1)i = tm2;
	}
}
void Union2(int m1,int m2,array<int,10>& a, array<int, 10>& sz) {
	int tm1 = a.at(m1);
	int tm2 = a.at(m2);
	root(tm1, a);
	root(tm2, a);
	if (tm1 == tm2)return;
	if (sz.at(tm1) >= sz.at(tm2)) {
		a.at(tm2) = tm1;
		sz.at(tm1) += sz.at(tm2);
	}
	else {
		a.at(tm1) = tm2;
		sz.at(tm2) += sz.at(tm1);
	}
}
int main() {
	array<int, 10>a = { 0,1,2,3,4,5,6,7,8,9 };
	array<int, 10> sz = { 1,1,1,1,1,1,1,1,1,1 };

	fstream cin("a.txt");
	int  b,c;

	for (int i = 0; i < 6; i++) {
		cin >> b >> c;
		union1(b, c, a);
	}
	a = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 9; i++) {
		cin >> c >> b;
		Union2(c, b, a, sz);
	}
	system("pause");
}
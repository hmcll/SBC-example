#include <iostream>
using namespace std;
#define square(X) X*X
inline void m() {
	cout << "d";
}
struct s {
	int a;
	int b;
	s(int _a, int _b) {
		a = _a;
		b = _b;
	}
};
int main() {
	m();
	int s = 0;
	int& d = s;
	int* f = &s;
	d++;
	*f++;

}
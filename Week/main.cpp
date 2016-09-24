//for循环与自运算符

#include <iostream>
#include <vector>

namespace s{
	struct m {
		int a;
		double b;
		double getb() const;
		m operator=(int a);
	};
	m m::operator=(int input) {
		this->a = input;
		this->b = 1.23;
		return *this;
	}
	double m::getb() const {
		return b;
	}
}
using namespace std;
int main() {
	int m = 1;
	for (int i = 0; i < 5; i++) {
		m *= (i+1);
	}
	//赋值语句
	m = 1;
	cout << (m = 2) << endl;
	int a, b, c, d;
	cout << (a = b = c = d = 1) << a << b << c << d << endl;

	s::m n;
	cout << (n = 1).getb();


	cout << true << " " << false << endl;
	cout.setf(ios_base::boolalpha);
	cout << true << " " << false << endl;

	a = b = 20;
	cout << a++ << " " << ++b << endl;
	cout << a << " " << b << endl;// 自加

	a++;
	a--;
	a += 1;
	a -= 1;
	a *= 2;
	a /= 2;
	a %= 2;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	system("pause");
}
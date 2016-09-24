#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

enum menu :int {
	a,
	b,
	c,
	d
};

int main() {

	if (!true && false) {
		int a;
	} else if (1 == 2 || 1 != 3) {
		int a;
	} else {
		int a;
	}
	//运算符优先级
	//（百度表）
	//各种 左移位两次
	4 >> 4;//右移位4次
	4 << 2;//二进制转换后左移两位
	4 >> 2;//上右移
	//bit运算符
	4
	100
	5
	101


	15 & 4;//与
	15 | 4;//或
	15 ^ 4;//异或
	~15; //取反
	//关系运算
	if (2 > 1 ? true : false);
	int ttt = 15 > 5 ? 20 : 25;

	menu choice = menu::a;
	switch (choice) {
		case a: {
			cout << 1;
		}
			break;
		case b:
			cout << 2;
			break;
		case c:
			cout << 3;
			break;
		case d:
			cout << 4;
			break;
		default:
			break;
	}
	//break & continue
	for (int i = 0; i < 5; i++) {
		if (i = 2)
			continue;
		else if (i = 4)
			break;
		cout << i << endl;
	}

	ofstream outf("2.txt");
	ifstream inf("1.txt");
	string a;
	inf >> a;
	outf << a;
	outf.close();
	outf.open("1.txt");


	system("pause");
}


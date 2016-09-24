//指针
#include <iostream>
#include <vector>
#include <array>
using namespace std;
int main() {
	int * a;//地址
	int b = 1;//数据
	a = &b;
	cout << a << " " << &b << endl;
	cout << *a << " " << b << endl;
	//字符串
	char* c = "sojeon";
	int* d = new int[4]{ 1,2,3,4 };
	//指针与数组的区别
	int * e = new int[*a];
	//int s[*a];    error a need to be a const pointer/const variable
	for (int i = 0; i < 4; i++) {
		cout << *d+i;
	}
	cout << *d+4;
	int * g = new int{ 1 };
	//delete
	//delete a; error support only memory space that declarated by oprator new
	system("cls");
	delete g;
	system("cls");
	delete []d;
	system("cls");

	//模板类   oop(Object Oriented Programming)
	vector<int> inv = {1,2,3,4};
	array<int, 3> ina;

	inv.push_back(1);
	inv.insert(inv.begin() + 1, 1);
	ina = { 1,2,3 };
	ina.fill(2);
	system("pause");
}
//ָ��
#include <iostream>
#include <vector>
#include <array>
using namespace std;
int main() {
	int * a;//��ַ
	int b = 1;//����
	a = &b;
	cout << a << " " << &b << endl;
	cout << *a << " " << b << endl;
	//�ַ���
	char* c = "sojeon";
	int* d = new int[4]{ 1,2,3,4 };
	//ָ�������������
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

	//ģ����   oop(Object Oriented Programming)
	vector<int> inv = {1,2,3,4};
	array<int, 3> ina;

	inv.push_back(1);
	inv.insert(inv.begin() + 1, 1);
	ina = { 1,2,3 };
	ina.fill(2);
	system("pause");
}
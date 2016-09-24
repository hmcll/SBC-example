//简单应用

#include <iostream>

using namespace std;//2.4.5
//函数声明2.4
//实参，虚参
bool check(int);

int main() {
	//变量声明2.2.1
	int pass = 0;//2.3.3类简介
	int cont;
	cont = 0;
start:
	//变量初始化2.2.2(赋值)
	pass = 0;
	cont++;
	cout << "****************" << endl;
	//退格符
	cout << "*输入：--------*\b\b\b\b\b\b\b\b\b";
	//////////////////////////
	cin >> pass;////2.3.1/////
	//////////////////////////
	cout << "****************" << endl;

	//分支
	if (check(pass)) {
		cout << "OK";
	}
	else {
		cout << "WRONG" << cont/*2.2.3cout变量*/ << endl;
		system("pause");
		system("cls");
		//返回start：的位置
		goto start;
	}
	system("pause");
}

//函数实现2.4.1，2.4.2，2.4.3，2.4.4
bool check(int pass) {
	if (pass == 1203) {
		return true;
	}
	else {
		return false;
	}
	//return false;
}


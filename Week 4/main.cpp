//week4 数组与字符串
#include <iostream>
#include <string>
#include <array>
int main() {
	//数组声明与初始化
	//int类型数组
	int arrayexpi[9] = { 1,2,3,4,5,6,7,7,1 };
	//float类型数组
	float arrayexpf[]{ float(21.4),float(553.2) };
	//int hh[9] = arrayexpi;  error
	//int hh[]; error
	//字符串
	char a[] = { 'a','b','c','\0' };//字符转义 \n \0 \b \t \\ \" \'
	char b[4] = "abc";
	char c[] = "abc";
	char d[] = "a"        "bc";
	char e[] = "a"
		"bc";
	a[0];//数组调用第一个元素
	a[1];//数组调用第二个元素
	a[3];//最后一个元素

	char a1[20], a2[20];
	using namespace std;
	cin >> a1 >> a2;
	cin.getline(a1, 20);//超长设置失效位，不接受输入
	cin.get(a1, 20);
	cin.get();
	system("pause");

	//c++11字符串类 namespace std;
	string st1 = "abc", st2("sss"), st3(a), st4, st5, st6, st7, st8;
	st4 = st1;
	st5 = st1 + st4;
	st6 += st2;
	getline(cin, st6);
	st7 = R"(gnsojg\d[[nlmgfnpbnvoifdg\n\f\d\s\r\we\\wte\t


				we\t\ew\tw\et'''''''"""""""""""")";
	st8 = R"++=(   djsojigoeirnjaugissj   )++=";
	std::array<float, 200>kfc;
	kfc.at(5);
}
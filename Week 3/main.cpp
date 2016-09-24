//week3 变量基础,简单运算

#include <iostream>
using std::cout;
using std::endl;

int main() {
	/*
	int _ShuirongC100;
	int zhe_ge_bian_liang_hen_chang_dui_ni_mei_kan_cuo_ta_jiu_shi_zhe_me_chang_123;//3.1.1变量名
	short b = 100;
	int a = 100000000;//3.1.3v
	unsigned long j = 100ul;
	long c = 100000000l;
	long long d = 100ll;
	unsigned long long e = 100ull;//3.1.4
	char f = '?';//3.1.8  // 4 b
	wchar_t w = L'我'; // 8 b
	char16_t w16 = u'へ'; // 16b
	char32_t w32 = U'?'; // 32b

	signed char g = 200;
	
	bool g;//3.1.9

	const int h = 0;//3.2

	float i = 1.223;//3.3.1
	double j = 1.223e200;//3.3.2
	
	
	cout << (3 + 5 * 6 / 6 - 7) << endl;//3.4.1
	cout << 7 / 5 << "  " << 66 / 66 << "  " << 6.6 / 6.67 << endl;//3.4.2
	cout << 5 % 2 << "  " << 5 % 7 << endl;//3.4.3
	

	auto k = 1.0;
	auto l = 1;

	int a, b, c, d, e, f, g, h, i, j, k;
	a = 1 + 1;
	b = 1 - 1;
	c = 1 * 1;
	d = 1 / 1;
	

	//\
		9/5...4  \
	9.0/5.0=error
	e = 9 % 5;
	

	//优先级3.4.1
	f = (1 + 2 * 3 / 4 + 5 - 6) * 7;
	//类型转换
	
	
	const int code = 66;
	int x = 66;
	//char c1{ 31325 };//narrowing
	char c2{66};//allowed
	char c3{code};//ok?
	//char c4{ x };//narrowing
	x = 31325;
	char c5 = x;// allowed
	*/

	//整型提升
	short chickens = 13333;
	short ducks = 11333;
	//提	升成int后计算
	long fowl = chickens * ducks * 1111111;

	//强制类型转换
	long lllll = 10 + double(10);
	(long)100000000;
	long(100000000);
	/**/
	system("pause");
}


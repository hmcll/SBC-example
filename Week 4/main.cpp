//week4 �������ַ���
#include <iostream>
#include <string>
#include <array>
int main() {
	//�����������ʼ��
	//int��������
	int arrayexpi[9] = { 1,2,3,4,5,6,7,7,1 };
	//float��������
	float arrayexpf[]{ float(21.4),float(553.2) };
	//int hh[9] = arrayexpi;  error
	//int hh[]; error
	//�ַ���
	char a[] = { 'a','b','c','\0' };//�ַ�ת�� \n \0 \b \t \\ \" \'
	char b[4] = "abc";
	char c[] = "abc";
	char d[] = "a"        "bc";
	char e[] = "a"
		"bc";
	a[0];//������õ�һ��Ԫ��
	a[1];//������õڶ���Ԫ��
	a[3];//���һ��Ԫ��

	char a1[20], a2[20];
	using namespace std;
	cin >> a1 >> a2;
	cin.getline(a1, 20);//��������ʧЧλ������������
	cin.get(a1, 20);
	cin.get();
	system("pause");

	//c++11�ַ����� namespace std;
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
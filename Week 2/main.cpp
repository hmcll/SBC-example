//��Ӧ��

#include <iostream>

using namespace std;//2.4.5
//��������2.4
//ʵ�Σ����
bool check(int);

int main() {
	//��������2.2.1
	int pass = 0;//2.3.3����
	int cont;
	cont = 0;
start:
	//������ʼ��2.2.2(��ֵ)
	pass = 0;
	cont++;
	cout << "****************" << endl;
	//�˸��
	cout << "*���룺--------*\b\b\b\b\b\b\b\b\b";
	//////////////////////////
	cin >> pass;////2.3.1/////
	//////////////////////////
	cout << "****************" << endl;

	//��֧
	if (check(pass)) {
		cout << "OK";
	}
	else {
		cout << "WRONG" << cont/*2.2.3cout����*/ << endl;
		system("pause");
		system("cls");
		//����start����λ��
		goto start;
	}
	system("pause");
}

//����ʵ��2.4.1��2.4.2��2.4.3��2.4.4
bool check(int pass) {
	if (pass == 1203) {
		return true;
	}
	else {
		return false;
	}
	//return false;
}


#include <iostream>
#include <array>
#include <string>
#include <vector>
using namespace std;

int main() {
	int a = 9;
	while (a) {
		cout << a--;
	}
	a = 1;
	do {
		cout << a--;
	} while (a);

	cout << endl;
	vector<char> tma = {1,2,3,4,5,6};
	for (char tme : tma) {
		cout << tme;
	}
	int tmaa[9] = {1,2,3,4,5,6,7,8,9};
	for (int& i : tmaa) {
		i++;
	}
	a = 1 , 024;
	string fin;
	char ch;
	//cin >> ch;
	ch = cin.get();
	//ch = cin.get(ch).get(ch).get(ch).get();

	while (ch != '%') {
		fin.push_back(ch);
		cin.get(ch);
	}
	cout << fin;
	//¶þÎ¬Êý×é¼ò½é
	int x = 10, y = 20;
	int sd[10][20];
	//int sr[x][y];error
	const int x1 = 10, y1 = 20;
	int sr[x1][y1] = {
		{1,2,3},
		{4,5,6}
		//...
	};
	system("pause");
}


#include <fstream>
#include <iostream>
#include <string>
int main() {
	using namespace std;
	ifstream in("in.txt");
	char inc;
	int out = 0;
	std::string full;
	while ((inc = in.get())!=-1)
	{
		static char i = 0;
		static char j = 0;
		full.push_back(inc);
		if (inc == '-') {
			j++;
			if (j == 3)break;
			continue; 
		}
		i++;
		out += (i * (inc-48));
	} 
	out %= 11;
	char a;
	switch (out) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			a = out + 48;
			break;
		case 10:
			a = 'X';
	}
	if (a == in.get()) {
		cout << "Right";
	}
	else {
		cout << full + a;
	}
	cout << out;
	system("pause");
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	char ch = cin.get();
	string a;
	while (ch !='\n')
	{
		a.push_back(ch);
		cin.get(ch);
	}
	vector<string> lines;
	for (int i = 0, num = 0;num<a.size(); i++) {
		lines.push_back("");
		for (int j = 0; j <= i&& num<a.size(); j++) {
			lines[i].push_back(a[num++]);
		}
	}
	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < lines.size() - i - 1; j++) {
			cout << " ";
		}
		cout << lines[i] << endl;
	}
	system("pause");
}
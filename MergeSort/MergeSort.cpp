#include <iostream>
#include <fstream>
#include <array>
#include <vector>
using namespace std;
void merge(std::vector<int>& a, std::vector<int>& b, int lo, int hi, int mid) {
	static int count = 0;
	count++;
	if (count > 7)throw "end";
	b = a;
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; k++) {
		if (i > mid)a.at(k) = b.at(j++);
		else if (j > hi)a.at(k) = b.at(i++);
		else if (b.at(j) < b.at(i)) a.at(k) = b.at(j++);
		else a.at(k) = b.at(i++);
	}
}
void mergeSort(std::vector<int>& a, std::vector<int>& b, int lo, int hi) {
	if (hi <= lo)return;
	int mid = lo + (hi - lo) / 2;
	mergeSort(a, b, lo, mid);
	mergeSort(a, b, mid + 1, hi);
	merge(a, b, lo, hi, mid);
}
void mergeSort(std::vector<int>& a) {
	vector<int> b;
	a.shrink_to_fit();
	for (int i = 0; i < a.size(); i++) {
		b.push_back(0);
	}
	b.shrink_to_fit();
	mergeSort(a, b, 0, a.size() - 1);
}
void TDmerge() {
	vector<int> a;
	ifstream in("i.txt");
	for (int i = 0; i < 12; i++) {
		int g;
		in >> g;
		a.push_back(g);
	}
	try {
		mergeSort(a);
	}
	catch (char* a) {
		cout << "";
	}
	ofstream b("a.txt");
	for (int i = 0; i < a.size(); i++)
		b << a.at(i) << " ";
	system("pause");
}
void BmergeSort(std::vector<int>& a) {
	int N = a.size();
	std::vector<int> b;
	for (int i = 0; i < a.size(); i++) {
		b.push_back(0);
	}
	for (int sz = 1; sz < N; sz *= 2)
		for (int lo = 0; lo < N - sz; lo += (sz * 2))
			merge(a, b, lo, (lo + sz + sz - 1) < (N - 1) ? (lo + sz + sz - 1) : (N - 1), lo + sz - 1);
}
void BUmerge() {
	vector<int> a;
	ifstream in("i.txt");
	for (int i = 0; i < 10; i++) {
		int g;
		in >> g;
		a.push_back(g);
	}
	try {
		BmergeSort(a);
	}
	catch (char* a) {
		cout << "";
	}
	ofstream b("a.txt");
	for (int i = 0; i < a.size(); i++)
		b << a.at(i) << " ";
	system("pause");
}
int main() {
	BUmerge();
}
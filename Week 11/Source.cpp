#include <array>
#include<iostream>
int a(int b) {
	return b;
}
int b(int a) {
	if (a == 0) {
		return 0;
	}
	else {
		return a;
	}
}
int c(int b);
int d(int e) {
	return c(e);
}
int c(int b) {
	return b;
}
void f(int m) {
	m++;
}
void e(int & j) {
	j++;
}
int g(int m) {
	f(m);
	e(m);
	return m;
}
int h(int m,int s) {
	return m;
}
int i(int m[]) {
	return m[0]++;
}
void j(int m[]) {
	i(m);
}
void j(const int m[]) {
	//m[0]++;
}
void k(std::array<int, 3> s) {//结构与类	
	s.at(0)++;
}
void l(const std::array<int, 3> s) {
	s.at(1);
}
void m(int j) {
	if (j < 5) {
		j++;
		m(j);
	}
	else {
		return;
	}
}

void n(void (*m)(int),int in) {
	m(in);
}
struct  box {
	char marker[40];
	float height, width, length;
	float volume;
};
void print(box in) {
	using namespace std;
	cout << "height\t" << in.height <<endl;
	cout << "width\t" << in.width << endl;
	cout << "length\t" << in.length << endl;
}
void setVolume(box & in) {
	in.volume = in.height*in.length*in.width;
}
long double probability(unsigned numbers, unsigned picks);
int main() {
	std::cout << probability(47, 5)*probability(27, 1) << std::endl;
	system("pause");
}

long double probability(unsigned numbers, unsigned picks) {
	long double ret = 1.0;
	long double n;
	for (n = numbers; picks > 0; n--, picks--) {
		ret = ret * picks / n;
	}
	return ret;
}
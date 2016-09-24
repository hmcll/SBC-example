#include <fstream>
struct student {
	int total;
	int chinese;
	int num;
};
bool inline compare(student A, student B);
void swap(student &a, student &b);
int main() {
	using namespace std;
	ifstream infile("in.txt");
	int n;
	infile >> n;
	student * students =new student[n];
	for (int i = 0; i < n; i++) {
		int c, m, e;
		infile >> c >> m >> e;
		students[i].chinese = c;
		students[i].num = i + 1;
		students[i].total = c+m+e;
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (!compare(students[i], students[j]))
				swap(students[i], students[j]);
		}
	}
	ofstream outfile("out.txt");
	for (int i = 0; i < 5; i++)
		outfile << students[i].num << " " << students[i].total << endl;
}
bool inline compare(student A, student B) {
	if (A.total != B.total) {
		return A.total>B.total;
	}
	else if (A.chinese != B.chinese) {
		return A.chinese > B.chinese;
	}
	else if (A.num != B.num) {
		return A.num < B.num;
	}
	else {
		return false;
	}
}
void inline swap(student &a, student &b) {
	student temp;
	temp.chinese = a.chinese;
	temp.num = a.num;
	temp.total = a.total;

	a.chinese = b.chinese;
	a.num = b.num;
	a.total = b.total;

	b.chinese = temp.chinese;
	b.num = temp.num;
	b.total = temp.total;
}

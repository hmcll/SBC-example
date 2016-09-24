#include <fstream>
#include <iostream>
struct point {
	int con;
	int w;
};

template<typename p>
p** new2darray(int n) {
	p** ret = new p *[n];
	for (int i = 0; i < n; i++) {
		ret[i] = new p[n];
	}
	return ret;
}

int main(){
	using namespace std;
	ifstream infile("in.txt");
	int n;
	infile >> n;
	int ** com = new2darray<int>(n);
	//init com
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			com[i][j] = 0;
		}
	}
	//load com
	for (int i = 0; i < n-1; i++) {
		int u, v;
		infile >> u >> v;
		u--;
		v--;
		com[u][v] = 1;
		com[v][u] = 1;
	}

	point **points = new2darray<point>(n);
	//init points;
	for (int i = 0; i < n; i++) {
		int a;
		infile >> a;
		for (int j = 0; j < n; j++) {
			points[i][j].con = com[i][j];
			points[i][j].w = a;
		}
	}
	
	int total=0,max=0;
	//main
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (points[i][j].con) {
				for (int k = 0; k < n; k++) {
					if (points[j][k].con && k!=i) {
						int tw= points[k][0].w * points[i][0].w;
						if (tw>max) {
							max = tw;
						}
						total += tw;
						total %= 10007;
					}
				}
			}
		}
	}
	cout << total << " " << max;
	system("pause");
}

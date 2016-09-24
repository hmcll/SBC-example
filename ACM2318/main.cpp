#include <fstream>
#include <vector>
using namespace std;
struct line{
	int startX, endX;
	line(){}
	line(int X1, int X2){
		startX = X1;
		endX = X2;
	}
};
struct point{
	int x, y;
	point(){
	}
	point(int x, int y){
		this->x = x;
		this->y = y;
	}
};
int main(){
	fstream infile("input.txt");
	fstream outfile("output.txt");
	for (;;){
		int n=0, m=0, x1=0, y1=0, x2=0, y2=0;
		infile >> n;
		if (n == 0)break;
		infile >> m >> x1 >> y1 >> x2 >> y2;
		vector < line >  lines;
		vector < point > points;
		vector < int > columns;
		lines.clear();
		points.clear();
		columns.clear();
		for (int i = 0; i < n; i++){
			int startX, endX;
			infile >> startX >> endX;
			lines.push_back(line(startX, endX));
		}
		for (int i = 0; i < m; i++){
			int x, y;
			infile >> x >> y;
			points.push_back(point(x,y));
		}
		for (int i = 0; i < n + 1; i++){
			columns.push_back(0);
		}
		for (int i = 0; i < m; i++){
			vector<float> line;
			line.clear();
			for (int j = 0; j < n; j++){
				line.push_back(((y1 - points[i].y)*(lines[j].endX - lines[j].startX)) / y1 + lines[j].startX);
			}
			line.push_back(x2);
			for (int j = 0; j < n + 1; j++){
				if (points[i].x < line[j]){
					columns[j]++;
					break;
				}
			}
		}
		for (int i = 0; i < n + 1; i++){
			outfile << i + 1 << ": " << columns[i] << endl;
		}
		outfile << endl;
	}
}
#include <fstream>
#include <cmath>
#include <sstream>
double td(double t, double d);
double dh(double d, double h);
double th(double t, double h);
void out(std::ofstream & outfile,double t,double d, double h);
int main(){
	using namespace std;
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	while (true){
		string s1, s2;
		double f1, f2,f3;
		infile >> s1;
		if (s1=="E"){
			break;
		}
		infile >> f1 >> s2 >> f2;
		if (s1 == "T"){
			if (s2 == "D"){
				f3 = td(f1, f2);
				out(outfile, f1, f2, f3);
			}
			else if (s2 == "H"){
				f3 = th(f1, f2);
				out(outfile, f1, f3, f2);
			}
		}
		else if (s1 == "D"){
			if (s2 == "T"){
				f3 = td(f2, f1);
				out(outfile, f2, f1, f3);
			}
			else if (s2 == "H"){
				f3 = dh(f1, f2);
				out(outfile, f3, f1, f2);
			}
		}
		else if (s1 == "H"){
			if (s2 == "T"){
				f3 = th(f2, f1);
				out(outfile, f2, f3, f1);
			}
			else if (s2 == "D"){
				f3 = dh(f2, f1);
				out(outfile, f3, f2, f1);
			}
		}
	}
}
void out(std::ofstream & outfile, double t, double d, double h){
	outfile << "T " << t << " D " << d << " H " << h << std::endl;
}
double td(double t, double d){
	return t + (0.5555)*(6.11*exp(5417.7530 *((1 / 273.16) - (1 / (d + 273.16)))) - 10.0);
}
double th(double t, double h){
	return 1 / ((1 / 273.16) - (log((((h - t) / 0.5555) + 10.0) / 6.11) / 5417.7530)) - 273.16;
}
double dh(double d, double h){
	return h - (0.5555)*(6.11*exp(5417.7530 *((1 / 273.16) - (1 / (d + 273.16)))) - 10.0);
}
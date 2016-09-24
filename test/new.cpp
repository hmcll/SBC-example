#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#define DIM 1024
#define DM1 (DIM-1)
#define _sq(x) ((x)*(x)) // square
#define _cb(x) abs((x)*(x)*(x)) // absolute value of cube
#define _cr(x) (unsigned char)(pow((x),1.0/3.0)) // cube root

unsigned char GR(int, int);
unsigned char BL(int, int);

unsigned char RD(int i, int j) {
	// YOUR CODE HERE
	char a = char(int(i*std::log10(GR(DIM - i, DIM - j))*j*std::log10(BL(DIM - i, DIM - j)) * 10000) % 255);
	return a;
}
unsigned char GR(int i, int j) {
	// YOUR CODE HERE
	return char(int(i*j*BL(std::log10(i*(DIM - i)*j), std::log10(i*(DIM - j)*j)) * 10000) % 255);
}
unsigned char BL(int i, int j) {
	// YOUR CODE HERE
	return char(int(10000 * std::log10(i*(DIM - i)*j)*std::log10(i*(DIM - j)*j)) % 255);
}

void pixel_write(int, int);
FILE *fp;
std::ofstream of;
int main() {
	of = std::ofstream("MathPic.ppm");
	of << "P6\n" << DIM << " " << DIM << "\n255\n";
	for (int j = 0; j < DIM; j++) {
		for (int i = 0; i < DIM; i++)
			pixel_write(i, j);
		of << std::endl;
	}
	of.close();
	return 0;
}
void pixel_write(int i, int j) {
	of << RD(i, j) << " " << GR(i, j) << " " << BL(i, j) << " ";
}
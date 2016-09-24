#include <fstream>
#include <utility>
#include <iostream>
#include <exception>

class f {

};

int main() {
	using namespace std;
	auto l = [=](int i) -> int {
		std::cout << "lambdatest" << endl;
	};
}
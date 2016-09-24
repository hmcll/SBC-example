#include <fstream>
#include <vector>

int main(){
	using namespace std;
	std::ifstream infile("rps.in");
	std::ofstream outfile("rps.out");
	int N, NA, NB;
	infile >> N >> NA >> NB;
	const int wingraph[5][5] = { 
	{ 0, -1, 1, 1, -1 },
	{ 1, 0, -1, 1, -1 },
	{ -1, 1, 0, -1, 1 },
	{ -1,-1, 1, 0, 1 },
	{ 1, 1, -1, -1, 0 }
	};
	vector<int> A, B;
	for (int i = 0; i < NA; i++){
		int a;
		infile >> a;
		A.push_back(a);
	}
	for (int i = 0; i < NB; i++){
		int b;
		infile >> b;
		B.push_back(b);
	}
	int awin = 0, bwin = 0;
	for (int i = 0, j = 0, k = 0; i < N; i++, j < NA-1 ? j++ : j = 0, k < NB-1 ? k++ : k = 0){
		if (wingraph[A[j]][B[k]] == 1){
			awin++;
		}
		else if (wingraph[A[j]][B[k]] == -1){
			bwin++;
		}
	}
	outfile << awin << " " << bwin;
}
#include <vector>

const bool LEARN = false;

using std::vector;

enum class win{
	Xwin,
	Owin,
	Nwin
};
enum class PawnType{
	O,
	X,
	N
};
struct point{
	int x;
	int y;
	PawnType type;
	point();
	point(int ,int ,PawnType);
};
struct ss{
	vector < point > moves;
	win rr;
};

void split(std::vector<std::string> &tokens, const std::string &text, char sep);
class GameMain{

	vector <ss> allmove;

	int checkIfWin(point [9],bool);
	void make(point[9], ss, bool, int, int);
	std::string print(PawnType);
	std::string print(win);
	void print(point[9]);
	void selflearn(point[9]);
	int XMove(int, int, vector <ss> &,int);
	int Render(vector <ss> &, int);
public:
	int Main();
};
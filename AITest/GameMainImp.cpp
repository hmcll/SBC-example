#include "GameMain.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int GameMain::Main(){
	
	point tboard[9] = {
		point(0, 0, PawnType::N),
		point(1, 0, PawnType::N),
		point(2, 0, PawnType::N),
		point(0, 1, PawnType::N),
		point(1, 1, PawnType::N),
		point(2, 1, PawnType::N),
		point(0, 2, PawnType::N),
		point(1, 2, PawnType::N),
		point(2, 2, PawnType::N)
	};
	if (LEARN){
	}
	else{
		cout << "loading..." << endl;
		selflearn(tboard);
		system("Pause");
	}
	for (;;){
		point board[9] = {
			point(0, 0, PawnType::N),
			point(1, 0, PawnType::N),
			point(2, 0, PawnType::N),
			point(0, 1, PawnType::N),
			point(1, 1, PawnType::N),
			point(2, 1, PawnType::N),
			point(0, 2, PawnType::N),
			point(1, 2, PawnType::N),
			point(2, 2, PawnType::N)
		};
		int x, y;
		cout << "welcome" << endl;
		vector <ss> allPossibleRotes = allmove;
		for (int i = 0; i < 9;){
			print(board);
		input:
			cin >> x >> y;
			if (x >= 3 || y >= 3){
				cout << "Error" << endl;
				goto input;
			}
			board[x + 3 * y].type = PawnType::X;
			if (checkIfWin(board, true) == 1){
				cout << endl << "Xwin" <<endl;
				continue;
			}
			XMove(x, y, allPossibleRotes, i);
			print(board);
			i++;
			if (i >= 9)break;
			board[Render(allPossibleRotes, i)].type = PawnType::O;
			if (checkIfWin(board, false) == 2){
				cout << endl << "Owin" << endl;
				continue;
			}
			i++;
		}
		cout << "Nwin" << endl;
	}
	return 0;
}
std::string GameMain::print(PawnType type){
	switch (type)
	{
		case PawnType::N:
			return "N";
		case PawnType::O:
			return "O";
		case PawnType::X:
			return "X";
		default:
			return "N";
	}
	return "N";
}
void GameMain::make(point board[9], ss Path,bool isXMoving,int MoveNum, int win){
	switch (win){
		case 0:
			if (MoveNum < 9)
				for (int i = 0; i < 9; i++)
					if (board[i].type == PawnType::N){
						point temp;
						temp.x = board[i].x;
						temp.y = board[i].y;
						if (isXMoving){
							temp.type = PawnType::X;
						}
						else{
							temp.type = PawnType::O;
						}
						ss tempPath = Path;
						tempPath.moves.push_back(temp);
						point tempBoard[9] = { board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8] };
						tempBoard[i] = temp;
						make(tempBoard, tempPath, !isXMoving, MoveNum, checkIfWin(tempBoard, isXMoving));
					}
					else{
						continue;
					}
			break;
		case 1:
			Path.rr = win::Xwin;
			allmove.push_back(Path);
			break;
		case 2:
			Path.rr = win::Owin;
			allmove.push_back(Path);
			break;
	}
}
point::point(int xn,int yn,PawnType typen){
	x = xn;
	y = yn;
	type = typen;
}
point::point(){
	x = 0;
	y = 0;
	type = PawnType::N;
}
void split(vector<string> &tokens, const string &text, char sep) {
	int start = 0, end = 0;
	while ((end = text.find(sep, start)) != string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
}
int GameMain::checkIfWin(point board[9],bool isXMoving){
	int Return = 0;
	if (isXMoving){
		Return = 1;
	}
	else {
		Return = 2;
	}
	
	if (board[0].type == board[1].type && board[1].type == board[2].type && board[0].type != PawnType::N&& board[1].type != PawnType::N&& board[2].type != PawnType::N){
		return Return;
	}
	else if (board[3].type == board[4].type && board[4].type == board[5].type&& board[5].type != PawnType::N&& board[3].type != PawnType::N&& board[4].type != PawnType::N){
		return Return;
	}
	else if (board[6].type == board[7].type && board[7].type == board[8].type&& board[6].type != PawnType::N&& board[7].type != PawnType::N&& board[8].type != PawnType::N){
		return Return;
	}
	else if (board[0].type == board[3].type && board[3].type == board[6].type&& board[0].type != PawnType::N&& board[3].type != PawnType::N&& board[6].type != PawnType::N){
		return Return;
	}
	else if (board[1].type == board[4].type && board[4].type == board[7].type&& board[1].type != PawnType::N&& board[4].type != PawnType::N&& board[7].type != PawnType::N){
		return Return;
	}
	else if (board[2].type == board[5].type && board[5].type == board[8].type&& board[2].type != PawnType::N&& board[5].type != PawnType::N&& board[8].type != PawnType::N){
		return Return;
	}
	else if (board[0].type == board[4].type && board[4].type == board[8].type&& board[0].type != PawnType::N&& board[4].type != PawnType::N&& board[8].type != PawnType::N){
		return Return;
	}
	else if (board[6].type == board[4].type && board[4].type == board[2].type&& board[2].type != PawnType::N&& board[4].type != PawnType::N&& board[6].type != PawnType::N){
		return Return;
	}
	else{
		return 0;
	}
}
std::string GameMain::print(win win){
	switch (win)
	{
		case win::Xwin:
			return "X";
			break;
		case win::Owin:
			return "Y";
			break;
		case win::Nwin:
			break;
		default:
			break;
	}
}
void GameMain::selflearn(point board[9]){
	std::ifstream inf;
//	std::ofstream of;
	inf.open("D:\AI.txt");

	/*
	ss path;
	make(board,path,true,0,0);
	of << allmove.size() << std::endl;
	for (int i = 0; i < allmove.size(); i++){
	for (int j = 0; j < allmove[i].moves.size();j++){
	of << allmove[i].moves[j].x << "," << allmove[i].moves[j].y << "," << print(allmove[i].moves[j].type).c_str() << ";";
	}
	of << print(allmove[i].rr).c_str() << std::endl;
	}
	
	*/
	int count;
	inf >> count;
	for (int i = 0; i < count; i++){
		std::string temp;
		point tempBoard[9] = { board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8] };
		inf >> temp;
		vector<string> tokens;
		split(tokens, temp, ';');
		ss a;
		for (int m = 0; m < tokens.size() - 1; m++){
			point temppoint;
			vector<string> am;
			split(am, tokens[m], ',');

			if (am[0] == "0"){
				temppoint.x = 0;
			}
			else if (am[0] == "1"){
				temppoint.x = 1;
			}
			else if (am[0] == "2"){
				temppoint.x = 2;
			}

			if (am[1] == "0"){
				temppoint.y = 0;
			}
			else if (am[1] == "1"){
				temppoint.y = 1;
			}
			else if (am[1] == "2"){
				temppoint.y = 2;
			}

			if (am[2] == "X"){
				temppoint.type = PawnType::X;
			}
			else if (am[2] == "O"){
				temppoint.type = PawnType::O;
			}

			a.moves.push_back(temppoint);
		}
		if (tokens[tokens.size()-1] == "X"){
			a.rr = win::Xwin;
		}
		else {
			a.rr = win::Owin;
		}
		allmove.push_back(a);
	}
}
int GameMain::XMove(int x,int y, vector <ss> &allPossibleRotes,int num){
	vector <ss> temp;
	for (int i = 0; i < allPossibleRotes.size(); i++){
		if (allPossibleRotes[i].moves[num].x == x&&allPossibleRotes[i].moves[num].y == y){
			temp.push_back(allPossibleRotes[i]);
		}
	}
	allPossibleRotes = temp;
	return 1;
}
int GameMain::Render(vector <ss> & allPossibleRotes, int num){
	vector <ss> XwillWinIn1Step;
	vector <ss> OwillWinIn1Step;
	vector <ss> XwillWinIn2Step;
	vector <ss> OwillWinIn2Step;
	vector <ss> XwillWinIn3Step;
	vector <ss> OwillWinIn3Step;

for (int i = 0; i < allPossibleRotes.size(); i++){
		if (allPossibleRotes[i].moves.size() == num + 1 && allPossibleRotes[i].rr==win::Owin)
			OwillWinIn1Step.push_back(allPossibleRotes[i]);
		else if (allPossibleRotes[i].moves.size() == num + 2 && allPossibleRotes[i].rr == win::Xwin)
			XwillWinIn1Step.push_back(allPossibleRotes[i]); 
		else if (allPossibleRotes[i].moves.size() == num + 3 && allPossibleRotes[i].rr == win::Owin)
			OwillWinIn2Step.push_back(allPossibleRotes[i]);
		else if (allPossibleRotes[i].moves.size() == num + 4 && allPossibleRotes[i].rr == win::Xwin)
			XwillWinIn2Step.push_back(allPossibleRotes[i]);
		else if (allPossibleRotes[i].moves.size() == num + 5 && allPossibleRotes[i].rr == win::Owin)
			OwillWinIn3Step.push_back(allPossibleRotes[i]);
		else if (allPossibleRotes[i].moves.size() == num + 6 && allPossibleRotes[i].rr == win::Xwin)
			XwillWinIn3Step.push_back(allPossibleRotes[i]);
	}
	int ReturnX,ReturnY;
	if (OwillWinIn1Step.size()>0){
		ReturnX = OwillWinIn1Step[0].moves[num].x;
		ReturnY = OwillWinIn1Step[0].moves[num].y;
	}
	else if (XwillWinIn1Step.size() > 0){
		ReturnX = XwillWinIn1Step[0].moves[num + 1].x;
		ReturnY = XwillWinIn1Step[0].moves[num + 1].y;
	}
	else if (OwillWinIn2Step.size() > 0){
		ReturnX = OwillWinIn2Step[0].moves[num].x;
		ReturnY = OwillWinIn2Step[0].moves[num].y;
	}
	else if (XwillWinIn2Step.size() > 0){
		ReturnX = XwillWinIn2Step[0].moves[num].x; 
		ReturnY = XwillWinIn2Step[0].moves[num].y;
	}
	else if (OwillWinIn3Step.size() > 0){
		ReturnX = OwillWinIn3Step[0].moves[num].x;
		ReturnY = OwillWinIn3Step[0].moves[num].y;
	}
	else if (XwillWinIn3Step.size() > 0){
		ReturnX = XwillWinIn3Step[0].moves[num].x;
		ReturnY = XwillWinIn3Step[0].moves[num].y;
	}
	vector <ss> temp;
	for (int i = 0; i < allPossibleRotes.size(); i++){
		if (allPossibleRotes[i].moves[num].x == ReturnX &&allPossibleRotes[i].moves[num].y == ReturnY){
			temp.push_back(allPossibleRotes[i]);
		}
	}
	allPossibleRotes = temp;
	return ReturnX + ReturnY * 3;
}
void GameMain::print(point board[9]){
	cout << print(board[6].type) << "|" << print(board[7].type) << "|" << print(board[8].type) << endl;
	cout << "-+-+-" << endl;
	cout << print(board[3].type) << "|" << print(board[4].type) << "|" << print(board[5].type) << endl;
	cout << "-+-+-" << endl;
	cout << print(board[0].type) << "|" << print(board[1].type) << "|" << print(board[2].type) << endl;
}
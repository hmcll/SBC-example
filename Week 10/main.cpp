#include <fstream>
#include <iostream>
#include <array>
#include "time.h"
using namespace std;
struct cell
{
	int row, col;
	bool on = false;
	cell() {
		row = 0;
		col = 0;
	}
	cell(int row, int col) {
		this->row = row;
		this->col = col;
	}
	cell operator= (cell a) {
		this->col = a.col;
		this->on = a.on;
		this->row = a.row;
		return *this;
	}
	cell operator! () {
		this->on = !this->on;
		return *this;
	}
};
bool check(array<cell, 25> table) {
	for (int i = 0; i < table.size(); i++) {
		if (table.at(i).on)
			return true;
	}
	return false;
}
void turn(array<cell,25> & table, int row,int col) {
	table.at(row * 5 + col).on = !table.at(row * 5 + col).on;
	if (col != 0)
		table.at(row * 5 + col - 1).on = !table.at(row * 5 + col - 1).on;
	if (col != 4)
		table.at(row * 5 + col + 1).on = !table.at(row * 5 + col + 1).on;
	if (row != 4)
		table.at((row + 1) * 5 + col).on = !table.at((row + 1) * 5 + col).on;
	if (row != 0)
		table.at((row - 1) * 5 + col).on = !table.at((row - 1) * 5 + col).on;
}
int main() {
	for (;;) {
		srand((unsigned)time(NULL));
		for (int mainNum = 0;; mainNum++) {
			array<cell, 25> table;
			for (int i = 0; i < table.size(); i++) {
				cell tempcell = cell(i / 5+1, i % 5+1);
				table.at(i) = tempcell;
			}
			for (int i = 0; i <= mainNum; i++) {
				int row = rand() % (5);
				int col = rand() % (5);
				turn(table, row, col);
			}
			int time =0;
 			while(check(table)) {
				cout << "Level:" << mainNum + 1 << endl;
				for (int i = 0; i < table.size(); i++) {
					if (table.at(i).on)
						cout << "O ";
					else
						cout << "X ";
					if (!((i + 1) % 5))
						cout << endl;
				}
				int x, y;
				cout << endl << "点击次数：" << time <<endl << "请输入点击位置(x/y)：";
				cin >> y >> x;
				turn(table, x-1, y-1);
				time++;
				system("cls");
			}
			cout << "Level:" << mainNum + 1 << endl;
			for (int i = 0; i < table.size(); i++) {
				if (table.at(i).on)
					cout << "O ";
				else
					cout << "X ";
				if (!((i + 1) % 5))
					cout << endl;
			}
			cout << endl << "OK";
			system("pause");
			system("cls");
		}
		system("pause");
	}
}
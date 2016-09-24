/*
1.log±Ì
2.∂¡»°
3.getb
4.solve
*/

#include <fstream>
#include <iostream>
#include <string>

const std::string logSheetPath = "logsheet.sheet";

int init();
void logbiao();
void load();
void getb();
void solve();

std::ifstream logsheet;

int main(){
	if (init()){
		logbiao();
	}
	load();
	for (;;){
		getb();
		solve();
	}
}

int init(){
	logsheet.open(logSheetPath);
	int isok;
	logsheet >> isok;
	if (isok)return 0;
	return 1;
}
void logbiao(){

}
void load(){

}
void getb(){

}
void solve(){

}
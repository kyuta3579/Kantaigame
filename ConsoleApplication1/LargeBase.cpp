#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LargeBase.h"

using namespace std;

LargeBase::LargeBase() {									//縦長か横長かを決める
	if (rand() % 2) {
		if (X == 24) 
			X = X - 1;
		sharp = 1;
	}

	else{
		if (Y == 24)
			Y = Y - 1;
		sharp = 0;
	}
}


void LargeBase::LargeDamage(int ax ,int ay) {

	////////////////////命中時///////////////////////////

	if (sharp) {
		if ((X == ax ||ax == X + 1) && (Y == ay)) {			//当たっていたとき
			cout << "命中！" << endl;
			HP_L = HP_L - 1;								//自身のHPを1だけ減らす
		}


		////////////////////近接弾の判定/////////////////////
		else if (X == ax ||ax == X + 1) {
			if ((ay == Y - 1) || (ay == Y + 1)) {
				cout << "近くにあります。" << endl;
			}
			else
				cout << "近くにはありません。" << endl;
		}
		else if (Y == ay) {
			if ((ax == X + 2) || (ax == X - 1)) {
				cout << "近くにあります。" << endl;
			}
			else
				cout << "近くにはありません。" << endl;
		}
		//近接弾がなかったとき
		else
			cout << "近くにはありません。" << endl;
	}



	////////////////////命中時///////////////////////////
	else if(!sharp){
		if ((X == ax) && (Y == ay || ay == Y + 1)) {		//当たっていたとき
			cout << "命中！" << endl;
			HP_L = HP_L - 1;								//自身のHPを1だけ減らす
		}


		////////////////////近接弾の判定/////////////////////
		else if ((Y == ay ||ay == Y+ 1)) {
			if ((ax == X + 1) || (ax == X - 1)) {
				cout << "近くにあります。" << endl;
			}
			else
				cout << "近くにはありません。" << endl;
		}
		else if (X == ax) {
			if ((ay == Y + 2) || (ay == Y - 1)) {
				cout << "近くにあります。" << endl;
			}
			else
				cout << "近くにはありません。" << endl;
		}
		//近接弾がなかったとき
		else
			cout << "近くにはありません。" << endl;
	}
}


int LargeBase::Get_Sharp() {
	return sharp;
}

int LargeBase::Get_HP_L() {
	return HP_L;
}


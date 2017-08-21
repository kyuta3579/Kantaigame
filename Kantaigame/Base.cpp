#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Base.h"

using namespace std;

Base::Base() {												//Baseのコンストラクタ、座標を乱数で定義
	X = rand() % 25;
	Y = rand() % 25;
}

void Base::NormalDamage(int ax, int ay) {

	////////////////////命中時///////////////////////////
	if ((X == ax) && (Y == ay)) {							//当たっていたとき
		cout << "命中！";
		HP = HP - 1;										//自身のHPを1だけ減らす
	}


	////////////////////近接弾の判定/////////////////////
	else if (ay == 0) {										
		if (ax == 0) {
			if (X == ax) {
				if (Y == ay + 1) {
					cout << "近くにあります。" << endl;
				}
				//近接弾がなかったとき
				else
					cout << "近くにはありません。" << endl;
			}

			else if (Y == ay) {
				if (X == ax + 1) {
					cout << "近くにあります。" << endl;
				}
				//近接弾がなかったとき
				else
					cout << "近くにはありません。" << endl;
			}
		}
		else if (X == ax) {
			if (Y == ay + 1) {
				cout << "近くにあります。" << endl;
			}
			//近接弾がなかったとき
			else
				cout << "近くにはありません。" << endl;
		}

		else if (Y == ay) {
			if ((X == ax + 1) || (X == ax - 1)) {
				cout << "近くにあります。" << endl;
			}
			//近接弾がなかったとき
			else
				cout << "近くにはありません。" << endl;
		}
	}
	else if (ay == 24) {
		if (ax == 24) {
			if (X == ax) {
				if (Y == ay - 1) {
					cout << "近くにあります。" << endl;
				}
				//近接弾がなかったとき
				else
					cout << "近くにはありません。" << endl;
			}
			else if (Y == ay) {
				if (X == ax - 1) {
					cout << "近くにあります。" << endl;
				}
				//近接弾がなかったとき
				else
					cout << "近くにはありません。" << endl;
			}
		}
		else if (X == ax) {
			if (Y == ay - 1) {
				cout << "近くにあります。" << endl;
			}
			//近接弾がなかったとき
			else
				cout << "近くにはありません。" << endl;
		}

		else if (Y == ay) {
			if ((X == ax + 1) || (X == ax - 1)) {
				cout << "近くにあります。" << endl;
			}
			//近接弾がなかったとき
			else
				cout << "近くにはありません。" << endl;
		}
	}

	/*else if (((X == ax + 1) && (Y == ay )) || ((X == ax - 1) && (Y == ay))||((X == ax) && (Y == ay + 1)) || ((X == ax)||(Y == ay - 1)))
		cout << "近くにあります。" << endl;*/

	else if (X == ax) {
		if ((Y == ay + 1) || (Y == ay - 1)) {
			cout << "近くにあります。" << endl;
		}
		//近接弾がなかったとき
		else
			cout << "近くにはありません。" << endl;
	}

	else if (Y == ay) {
		if ((X == ax + 1) || (X == ax - 1)) {
			cout << "近くにあります。" << endl;
		}
		//近接弾がなかったとき
		else
			cout << "近くにはありません。" << endl;
	}
	///////////////////////////////////////////////////////
	//近接弾がなかったとき
	else
		cout << "近くにはありません。" << endl;
}

int Base::Get_X() {
	return X;
}

int Base::Get_Y() {
	return Y;
}

int Base::Get_HP() {
	return HP;
}
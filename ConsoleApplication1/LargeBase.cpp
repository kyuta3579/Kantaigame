#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LargeBase.h"

using namespace std;

LargeBase::LargeBase() {									//�c���������������߂�
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

	////////////////////������///////////////////////////

	if (sharp) {
		if ((X == ax ||ax == X + 1) && (Y == ay)) {			//�������Ă����Ƃ�
			cout << "�����I" << endl;
			HP_L = HP_L - 1;								//���g��HP��1�������炷
		}


		////////////////////�ߐڒe�̔���/////////////////////
		else if (X == ax ||ax == X + 1) {
			if ((ay == Y - 1) || (ay == Y + 1)) {
				cout << "�߂��ɂ���܂��B" << endl;
			}
			else
				cout << "�߂��ɂ͂���܂���B" << endl;
		}
		else if (Y == ay) {
			if ((ax == X + 2) || (ax == X - 1)) {
				cout << "�߂��ɂ���܂��B" << endl;
			}
			else
				cout << "�߂��ɂ͂���܂���B" << endl;
		}
		//�ߐڒe���Ȃ������Ƃ�
		else
			cout << "�߂��ɂ͂���܂���B" << endl;
	}



	////////////////////������///////////////////////////
	else if(!sharp){
		if ((X == ax) && (Y == ay || ay == Y + 1)) {		//�������Ă����Ƃ�
			cout << "�����I" << endl;
			HP_L = HP_L - 1;								//���g��HP��1�������炷
		}


		////////////////////�ߐڒe�̔���/////////////////////
		else if ((Y == ay ||ay == Y+ 1)) {
			if ((ax == X + 1) || (ax == X - 1)) {
				cout << "�߂��ɂ���܂��B" << endl;
			}
			else
				cout << "�߂��ɂ͂���܂���B" << endl;
		}
		else if (X == ax) {
			if ((ay == Y + 2) || (ay == Y - 1)) {
				cout << "�߂��ɂ���܂��B" << endl;
			}
			else
				cout << "�߂��ɂ͂���܂���B" << endl;
		}
		//�ߐڒe���Ȃ������Ƃ�
		else
			cout << "�߂��ɂ͂���܂���B" << endl;
	}
}


int LargeBase::Get_Sharp() {
	return sharp;
}

int LargeBase::Get_HP_L() {
	return HP_L;
}


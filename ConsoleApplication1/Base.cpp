#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Base.h"

using namespace std;

Base::Base() {												//Base�̃R���X�g���N�^�A���W�𗐐��Œ�`
	X = rand() % 25;
	Y = rand() % 25;
}

void Base::NormalDamage(int ax, int ay) {

	////////////////////������///////////////////////////
	if ((X == ax) && (Y == ay)) {							//�������Ă����Ƃ�
		cout << "�����I";
		HP = HP - 1;										//���g��HP��1�������炷
	}


	////////////////////�ߐڒe�̔���/////////////////////
	else if (ay == 0) {										
		if (ax == 0) {
			if (X == ax) {
				if (Y == ay + 1) {
					cout << "�߂��ɂ���܂��B" << endl;
				}
				//�ߐڒe���Ȃ������Ƃ�
				else
					cout << "�߂��ɂ͂���܂���B" << endl;
			}

			else if (Y == ay) {
				if (X == ax + 1) {
					cout << "�߂��ɂ���܂��B" << endl;
				}
				//�ߐڒe���Ȃ������Ƃ�
				else
					cout << "�߂��ɂ͂���܂���B" << endl;
			}
		}
		else if (X == ax) {
			if (Y == ay + 1) {
				cout << "�߂��ɂ���܂��B" << endl;
			}
			//�ߐڒe���Ȃ������Ƃ�
			else
				cout << "�߂��ɂ͂���܂���B" << endl;
		}

		else if (Y == ay) {
			if ((X == ax + 1) || (X == ax - 1)) {
				cout << "�߂��ɂ���܂��B" << endl;
			}
			//�ߐڒe���Ȃ������Ƃ�
			else
				cout << "�߂��ɂ͂���܂���B" << endl;
		}
	}
	else if (ay == 24) {
		if (ax == 24) {
			if (X == ax) {
				if (Y == ay - 1) {
					cout << "�߂��ɂ���܂��B" << endl;
				}
				//�ߐڒe���Ȃ������Ƃ�
				else
					cout << "�߂��ɂ͂���܂���B" << endl;
			}
			else if (Y == ay) {
				if (X == ax - 1) {
					cout << "�߂��ɂ���܂��B" << endl;
				}
				//�ߐڒe���Ȃ������Ƃ�
				else
					cout << "�߂��ɂ͂���܂���B" << endl;
			}
		}
		else if (X == ax) {
			if (Y == ay - 1) {
				cout << "�߂��ɂ���܂��B" << endl;
			}
			//�ߐڒe���Ȃ������Ƃ�
			else
				cout << "�߂��ɂ͂���܂���B" << endl;
		}

		else if (Y == ay) {
			if ((X == ax + 1) || (X == ax - 1)) {
				cout << "�߂��ɂ���܂��B" << endl;
			}
			//�ߐڒe���Ȃ������Ƃ�
			else
				cout << "�߂��ɂ͂���܂���B" << endl;
		}
	}

	/*else if (((X == ax + 1) && (Y == ay )) || ((X == ax - 1) && (Y == ay))||((X == ax) && (Y == ay + 1)) || ((X == ax)||(Y == ay - 1)))
		cout << "�߂��ɂ���܂��B" << endl;*/

	else if (X == ax) {
		if ((Y == ay + 1) || (Y == ay - 1)) {
			cout << "�߂��ɂ���܂��B" << endl;
		}
		//�ߐڒe���Ȃ������Ƃ�
		else
			cout << "�߂��ɂ͂���܂���B" << endl;
	}

	else if (Y == ay) {
		if ((X == ax + 1) || (X == ax - 1)) {
			cout << "�߂��ɂ���܂��B" << endl;
		}
		//�ߐڒe���Ȃ������Ƃ�
		else
			cout << "�߂��ɂ͂���܂���B" << endl;
	}
	///////////////////////////////////////////////////////
	//�ߐڒe���Ȃ������Ƃ�
	else
		cout << "�߂��ɂ͂���܂���B" << endl;
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
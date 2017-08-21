#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "field.h"

using namespace std;


void Field::Set(int tx,int ty) {										//��n�ݒu
	base[ty][tx] = 1;
}

void Field::Reset(int sx, int sy) {										//��n�j��
	base[sy][sx] = 0;
}


void Field::Genarate() {												//�t�B�[���h�\��
	int i = 0;
	int j = 0;
	
	for (i = 0; i < 25; i++) {
		for (j = 0; j < 25; j++) {
			if (base[i][j])
				Trout[i][j] = '��';
			else 
				Trout[i][j] = '��';


			cout<< Trout[i][j];

			if (j == 24) {
				cout << endl;
			}
		}
	}
}


void Field::Attack(int ax ,int ay) {
	if (base[ay][ax]) {
		base[ay][ax] = 0;
		cout << "�����I" << endl;
	}
	else if (ay == 0) {
		if (ax == 0) {
			if (base[ay + 1][ax] || base[ay][ax + 1])
				cout << "�߂��ɂ���܂��B" << endl;
		}
		else if(base[ay + 1][ax]|| base[ay][ax + 1] || base[ay][ax - 1])
			cout << "�߂��ɂ���܂��B" << endl;
	}
	else if (ay == 24) {
		if (ax == 24) {
			if (base[ay - 1][ax] || base[ay][ax - 1]) 
				cout << "�߂��ɂ���܂��B" << endl;
		}
		else if (base[ay - 1][ax] || base[ay][ax + 1] || base[ay][ax - 1])
			cout << "�߂��ɂ���܂��B" << endl;
	}

	else if (base[ay + 1][ax] || base[ay - 1][ax] || base[ay][ax + 1] || base[ay][ax - 1])
		cout << "�߂��ɂ���܂��B" << endl;

}


int Field::Get(int i, int j) {
	return base[j][i];
}
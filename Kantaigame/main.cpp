#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "field.h"
#include "Base.h"
#include "LargeBase.h"

using namespace std;

int main(void) {
	srand((unsigned)time(NULL));

	Field myField, enemyField;					//�t�B�[���h����
	
	Base myBase[5], enemyBase[5];				//1*1�̊�n��5����
	LargeBase myLargeBase, enemyLargeBase;		//�傫����n�𐶐�

	int i, j;									//���[�v�p
	int myx, myy, enex, eney;					//�ꎞ�ۑ��p�i����Ȃ��j
	int myFlag = 0;								//���s����t���O
	int enemyFlag = 0;
	int flag = 0;								//���f�t���O
	int x, y;									//�ꎞ�ۑ��p

												
/////////////////////////�t�B�[���h�Ɋ�n��z�u///////////////////////////
	for (i = 0; i < 5; i++) {										//�����̏�������n��z�u
	//	x = myBase[i].Get_X();
	//	y = myBase[i].Get_Y();					
		myField.Set(myBase[i].Get_X() , myBase[i].Get_Y());
	}

	myField.Set(myLargeBase.Get_X(), myLargeBase.Get_Y());			//�����̑傫����n��z�u
	if (myLargeBase.Get_Sharp()) 
		myField.Set(myLargeBase.Get_X() + 1, myLargeBase.Get_Y());	
	else 
		myField.Set(myLargeBase.Get_X(), myLargeBase.Get_Y() + 1);
	
	for (i = 0; i < 5; i++) {										//�G�̏�������n��z�u
		x = enemyBase[i].Get_X();
		y = enemyBase[i].Get_Y();
		enemyField.Set(x, y);
	}
	
	enemyField.Set(enemyLargeBase.Get_X(), enemyLargeBase.Get_Y());	//�G�̑傫����n��ݒu
	if (enemyLargeBase.Get_Sharp())
		enemyField.Set(enemyLargeBase.Get_X() + 1, enemyLargeBase.Get_Y());
	else
		enemyField.Set(enemyLargeBase.Get_X(), enemyLargeBase.Get_Y() + 1);

////////////////////////////////////////////////////////////////////////////


	cout << "�Q�[���J�n�I" << endl;
	

	while (true) {

		cout << "�����̃t�B�[���h�ł��B" << endl;

		myField.Genarate();							//�����̃t�B�[���h��\��

		//cout << myLargeBase.Get_Sharp() << endl;	//�f�o�b�O�p

		cout << "����̃t�B�[���h�ł��B" << endl;

		enemyField.Genarate();

		cout << enemyLargeBase.Get_Sharp() << endl;


		cout << "���Ȃ��̃^�[���ł��B" << endl;		//�U��������W���w��
		cout << "X���W����͂��Ă��������B:";
		cin >> myx;
		cout << "Y���W����͂��Ă��������B:";
		cin >> myy;


////////////////////////////�����̓����蔻��ƃ_���[�W�t�F�C�Y//////////////////////////
		for (i = 0; i < 5; i++) {
			enemyBase[i].NormalDamage(myx - 1, myy - 1);						//�����蔻�聕�_���[�W
			if (!enemyBase[i].Get_HP()) {										//HP��0�Ȃ�
				enemyField.Reset(enemyBase[i].Get_X(), enemyBase[i].Get_Y());	//���̊�n��j�󂷂�B
				cout << "��n��j�󂵂܂����B" << endl;
			}
		}
		enemyLargeBase.LargeDamage(myx - 1, myy - 1);
		if (!enemyLargeBase.Get_HP_L()) {
			enemyField.Reset(enemyLargeBase.Get_X(), enemyLargeBase.Get_Y());
			if (enemyLargeBase.Get_Sharp()) 
				enemyField.Reset(enemyLargeBase.Get_X() + 1, enemyLargeBase.Get_Y());
			else
				enemyField.Reset(enemyLargeBase.Get_X(), enemyLargeBase.Get_Y() + 1);

			cout << "��n��j�󂵂܂����B" << endl;
		}
////////////////////////////////////////////////////////////////////////////////////////


		cout << "CPU�̃^�[���ł��B" << endl;
		enex = rand() % 25;
		eney = rand() % 25;
		
		cout << "X:" << enex+1 << endl;
		cout << "Y:" << eney+1 << endl;


//////////////////////////////�G�̓����蔻��ƃ_���[�W�t�F�C�Y//////////////////////////
		for (i = 0; i < 5; i++) {
			myBase[i].NormalDamage(enex, eney);						//�����蔻�聕�_���[�W
			if (!myBase[i].Get_HP()) {								//HP��0�Ȃ�
				myField.Reset(myBase[i].Get_X(), myBase[i].Get_Y());//���̊�n��j�󂷂�
				cout << "��n���j�󂳂�܂����B" << endl;
			}
		}

		myLargeBase.LargeDamage(enex, eney);
		if (!myLargeBase.Get_HP_L()) {
			myField.Reset(myLargeBase.Get_X(), myLargeBase.Get_Y());
			if (myLargeBase.Get_Sharp())
				myField.Reset(myLargeBase.Get_X() + 1, myLargeBase.Get_Y());
			else
				myField.Reset(myLargeBase.Get_X(), myLargeBase.Get_Y() + 1); 

			cout << "��n��j�󂵂܂����B" << endl;
		}
////////////////////////////////////////////////////////////////////////////////////////

		cout << "�I���܂����H" << endl;	//���f�p�̃R�}���h
		cout << "�I���F1�@������F0" << endl;
		cin >> flag;

		if (flag) {
			break;
		}

		for (i = 0; i < 25; i++) {
			for (j = 0; j < 25; j++) {
				if (!(myField.Get(i, j)))
					myFlag = 0;
				else if (myField.Get(i, j)) {
					myFlag = 1;
					break;
				}
			}
			if (myFlag)
				break;
		}

		for (i = 0; i < 25; i++) {
			for (j = 0; j < 25; j++) {
				if (!(enemyField.Get(i, j)))
					enemyFlag = 0;
				else if (enemyField.Get(i, j)) {
					enemyFlag = 1;
					break;
				}
			}
			if (enemyFlag)
				break;
		}

		if (!myFlag && !enemyFlag) {
			cout << "���������ł��B" << endl;
			break;
		}
		else if (!myFlag) {
			cout << "���Ȃ��̕����ł��B" << endl;
			break;
		}
		else if (!enemyFlag) {
			cout << "���Ȃ��̏����ł��B" << endl;
			break;
		}
	}
}
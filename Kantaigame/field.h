#pragma once
#ifndef _FIELD_H_
#define _FIELD_H_

class Field {						//�t�B�[���h�N���X
public:
	void Attack(int ax, int ay);	//�U���֐��i�g���ĂȂ��j
	void Genarate();				//�t�B�[���h�����֐�
	void Set(int tx,int ty);		//��n�ݒu�֐�
	void Reset(int sx, int sy);		//��n�j��֐�
	int Get(int i, int j);			//���̍��W�Ɋ�n������̂����ׂ�֐�

private:
	int x = 0;						//���W
	int y = 0;
	char Trout[25][25];				//�t�B�[���h�\���p
	int base[25][25] = {};			//��n�ʒu�Ǘ��p
};
#endif _FIELD_H_
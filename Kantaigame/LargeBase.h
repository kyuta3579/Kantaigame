#pragma once
#ifndef _LARGEBASE_H_
#define _LARGEBASE_H_

#include "Base.h"

class LargeBase : public Base {				//1*2�̊�n�N���X
public:
	LargeBase();
	void LargeDamage(int ax, int ay);		//�����蔻��+�_���[�W
	int Get_Sharp();						//�`�������֐�
	int Get_HP_L();							//HP��Ԃ��֐�
private:
	int HP_L = 3;							//HP��3�Ƃ���
	int sharp;								//�`
};

#endif // _LARGEBASE_H_
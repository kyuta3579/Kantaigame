#pragma once
#ifndef _BASE_H_
#define _BASE_H_

class Base {								//��n�N���X
public:
	Base();
	void NormalDamage(int ax,int ay );		//�����蔻��+�_���[�W
	//�ȉ�protected&private�ϐ���߂��֐�	
	int Get_X();
	int Get_Y();
	int Get_HP();
protected:
	int X, Y;								//���W
private:
	int HP = 1;								//HP

};
#endif // _BASE_H_

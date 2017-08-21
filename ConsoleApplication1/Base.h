#pragma once
#ifndef _BASE_H_
#define _BASE_H_

class Base {								//基地クラス
public:
	Base();
	void NormalDamage(int ax,int ay );		//当たり判定+ダメージ
	//以下protected&private変数を戻す関数	
	int Get_X();
	int Get_Y();
	int Get_HP();
protected:
	int X, Y;								//座標
private:
	int HP = 1;								//HP

};
#endif // _BASE_H_

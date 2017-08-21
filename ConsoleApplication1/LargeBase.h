#pragma once
#ifndef _LARGEBASE_H_
#define _LARGEBASE_H_

#include "Base.h"

class LargeBase : public Base {				//1*2の基地クラス
public:
	LargeBase();
	void LargeDamage(int ax, int ay);		//当たり判定+ダメージ
	int Get_Sharp();						//形を示す関数
	int Get_HP_L();							//HPを返す関数
private:
	int HP_L = 3;							//HPを3とする
	int sharp;								//形
};

#endif // _LARGEBASE_H_
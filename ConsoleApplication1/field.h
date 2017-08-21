#pragma once
#ifndef _FIELD_H_
#define _FIELD_H_

class Field {						//フィールドクラス
public:
	void Attack(int ax, int ay);	//攻撃関数（使ってない）
	void Genarate();				//フィールド生成関数
	void Set(int tx,int ty);		//基地設置関数
	void Reset(int sx, int sy);		//基地破壊関数
	int Get(int i, int j);			//その座標に基地があるのか調べる関数

private:
	int x = 0;						//座標
	int y = 0;
	char Trout[25][25];				//フィールド表示用
	int base[25][25] = {};			//基地位置管理用
};
#endif _FIELD_H_
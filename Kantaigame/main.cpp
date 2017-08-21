#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "field.h"
#include "Base.h"
#include "LargeBase.h"

using namespace std;

int main(void) {
	srand((unsigned)time(NULL));

	Field myField, enemyField;					//フィールド生成
	
	Base myBase[5], enemyBase[5];				//1*1の基地を5つ生成
	LargeBase myLargeBase, enemyLargeBase;		//大きい基地を生成

	int i, j;									//ループ用
	int myx, myy, enex, eney;					//一時保存用（いらない）
	int myFlag = 0;								//勝敗判定フラグ
	int enemyFlag = 0;
	int flag = 0;								//中断フラグ
	int x, y;									//一時保存用

												
/////////////////////////フィールドに基地を配置///////////////////////////
	for (i = 0; i < 5; i++) {										//自分の小さい基地を配置
	//	x = myBase[i].Get_X();
	//	y = myBase[i].Get_Y();					
		myField.Set(myBase[i].Get_X() , myBase[i].Get_Y());
	}

	myField.Set(myLargeBase.Get_X(), myLargeBase.Get_Y());			//自分の大きい基地を配置
	if (myLargeBase.Get_Sharp()) 
		myField.Set(myLargeBase.Get_X() + 1, myLargeBase.Get_Y());	
	else 
		myField.Set(myLargeBase.Get_X(), myLargeBase.Get_Y() + 1);
	
	for (i = 0; i < 5; i++) {										//敵の小さい基地を配置
		x = enemyBase[i].Get_X();
		y = enemyBase[i].Get_Y();
		enemyField.Set(x, y);
	}
	
	enemyField.Set(enemyLargeBase.Get_X(), enemyLargeBase.Get_Y());	//敵の大きい基地を設置
	if (enemyLargeBase.Get_Sharp())
		enemyField.Set(enemyLargeBase.Get_X() + 1, enemyLargeBase.Get_Y());
	else
		enemyField.Set(enemyLargeBase.Get_X(), enemyLargeBase.Get_Y() + 1);

////////////////////////////////////////////////////////////////////////////


	cout << "ゲーム開始！" << endl;
	

	while (true) {

		cout << "自分のフィールドです。" << endl;

		myField.Genarate();							//自分のフィールドを表示

		//cout << myLargeBase.Get_Sharp() << endl;	//デバッグ用

		cout << "相手のフィールドです。" << endl;

		enemyField.Genarate();

		cout << enemyLargeBase.Get_Sharp() << endl;


		cout << "あなたのターンです。" << endl;		//攻撃する座標を指定
		cout << "X座標を入力してください。:";
		cin >> myx;
		cout << "Y座標を入力してください。:";
		cin >> myy;


////////////////////////////自分の当たり判定とダメージフェイズ//////////////////////////
		for (i = 0; i < 5; i++) {
			enemyBase[i].NormalDamage(myx - 1, myy - 1);						//当たり判定＆ダメージ
			if (!enemyBase[i].Get_HP()) {										//HPが0なら
				enemyField.Reset(enemyBase[i].Get_X(), enemyBase[i].Get_Y());	//その基地を破壊する。
				cout << "基地を破壊しました。" << endl;
			}
		}
		enemyLargeBase.LargeDamage(myx - 1, myy - 1);
		if (!enemyLargeBase.Get_HP_L()) {
			enemyField.Reset(enemyLargeBase.Get_X(), enemyLargeBase.Get_Y());
			if (enemyLargeBase.Get_Sharp()) 
				enemyField.Reset(enemyLargeBase.Get_X() + 1, enemyLargeBase.Get_Y());
			else
				enemyField.Reset(enemyLargeBase.Get_X(), enemyLargeBase.Get_Y() + 1);

			cout << "基地を破壊しました。" << endl;
		}
////////////////////////////////////////////////////////////////////////////////////////


		cout << "CPUのターンです。" << endl;
		enex = rand() % 25;
		eney = rand() % 25;
		
		cout << "X:" << enex+1 << endl;
		cout << "Y:" << eney+1 << endl;


//////////////////////////////敵の当たり判定とダメージフェイズ//////////////////////////
		for (i = 0; i < 5; i++) {
			myBase[i].NormalDamage(enex, eney);						//当たり判定＆ダメージ
			if (!myBase[i].Get_HP()) {								//HPが0なら
				myField.Reset(myBase[i].Get_X(), myBase[i].Get_Y());//その基地を破壊する
				cout << "基地が破壊されました。" << endl;
			}
		}

		myLargeBase.LargeDamage(enex, eney);
		if (!myLargeBase.Get_HP_L()) {
			myField.Reset(myLargeBase.Get_X(), myLargeBase.Get_Y());
			if (myLargeBase.Get_Sharp())
				myField.Reset(myLargeBase.Get_X() + 1, myLargeBase.Get_Y());
			else
				myField.Reset(myLargeBase.Get_X(), myLargeBase.Get_Y() + 1); 

			cout << "基地を破壊しました。" << endl;
		}
////////////////////////////////////////////////////////////////////////////////////////

		cout << "終わりますか？" << endl;	//中断用のコマンド
		cout << "終わる：1　続ける：0" << endl;
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
			cout << "引き分けです。" << endl;
			break;
		}
		else if (!myFlag) {
			cout << "あなたの負けです。" << endl;
			break;
		}
		else if (!enemyFlag) {
			cout << "あなたの勝ちです。" << endl;
			break;
		}
	}
}
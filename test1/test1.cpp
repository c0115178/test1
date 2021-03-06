#include "stdafx.h"
#include "kannsuu.cpp"



/*--------------------
main関数
---------------------*/
int main() {
	//勝利条件の初期化
	Goal = false;

	//乱数のSeedの初期化
	initRandom();
	//部屋の初期化
	initRoom();

	//主人公の構造体のポインタ化+初期化
	struct player *player = &initPlayer();
	//化け物の構造体のポインタ化+初期化
	struct monster *monster = &initMonster();
	
	//ゲーム説明
	explain();

	Tutorial(player);

	//勝利条件が達成されない限り探索をする
	while (!Goal) {
		//ターンカウント
		countTurn(player, monster);
		//マップ表示
		//showMap(player, monster);
		printf("%dターン目\nHP:%d   ATK:%d\n", TURN, player->HP, player->ATK);
		Move(player, monster);
	}

	//脱出成功の表示
	printf("おめでとうございます！！\n脱出成功です\n");

	//プレイヤーが何か入力すると終了
	char c = enterSomething();

	return 0;
}

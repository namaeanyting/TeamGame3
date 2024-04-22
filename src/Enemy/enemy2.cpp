#include "DxLib.h"
#include "enemy2.h"

void Enemy2::Init()
{
	phese = 0;
	LoadDivGraph(ENEMY_SUIT, 3, 3, 1, 140, 200, img_suit);
	imgNum = 0;	//画像の添え字設定

	////進行方向の初期化
	//HP = ENEMY_HP_MAX;
}

//通常処理
void Enemy2::Step()
{
	//生きているなら進行
	if (isActive) {
		KnockBack();
		if (HP > 3 && isLeft) {
			x += 3;	//右に行く
			if (x > (1280 / 2) - ENEMY_SIZE_X) {
				x = (1280 / 2) - ENEMY_SIZE_X;
			}
		}
		else if (HP > 3 && !isLeft) {
			x -= 3;	//左に行く
			if (x < (1280 / 2) + ENEMY_SIZE_X) {
				x = (1280 / 2) + ENEMY_SIZE_X;
			}
		}
	}
	//死んでいるなら復活
	else {
		HP = ENEMY2_HP_MAX;//HPを再所持
	}

	//HP制御
	if (HP < 0) {
		HP = 0;
	}
	if (x < 0) {
		isActive = false;
	}
}

//描画
void Enemy2::Draw()
{
	if (isActive) {
		//左に進行
		if (isLeft) {
			DrawRotaGraph(x, y, 1.0f, 0.0f, img_suit[imgNum], true, true);
		}
		//右に侵攻
		else {
			DrawRotaGraph(x, y, 1.0f, 0.0f, img_suit[imgNum], true, false);
		}
	}
}

//ノックバック処理
void Enemy2::KnockBack()
{
	//HPが半分削れたら後ろに下がる
	if (HP == 3) {
		switch (phese)
		{
		case 0:
			//後ろまで下がります
			if (isLeft) {
				x -= 8;
				//次のフェーズへ進
				if (x == 324) {
					phese = 1;
				}
			}
			else {
				x += 8;
				if (x == 956) {
					phese = 1;
				}
			}

			break;
		case 1:
			if (isLeft) {
				x += 3;	//右に行く
				if (x > (1280 / 2) - ENEMY_SIZE_X) {
					x = (1280 / 2) - ENEMY_SIZE_X;
					phese = 0;
				}
			}
			else {
				x -= 3;	//左に行く
				if (x < (1280 / 2) + ENEMY_SIZE_X) {
					x = (1280 / 2) + ENEMY_SIZE_X;
					phese = 0;

				}
			}
			break;
		default:
			break;
		}
	}
}

//ランダム生成
void Enemy2::EnemyGeneration() {
	if (GetRand(1) == 0) {
		x = 0;
		y = 360;
		isLeft = true;
	}
	else {
		x = 1280;
		y = 360;
		isLeft = false;
	}
}

#include "DxLib.h"
#include "player.h"
#include "../Input/Input.h"

void Player::Init()
{
	//画像の読みこみ
	for (int i = 0; i < PLAYER_IMEG_MAX; i++) {
		imgHandl[i] = LoadGraph(PLAYER_IMAGE_PATH[i]);
	}
	//プレイヤーの画像読み込み
	LoadDivGraph(PLAYER_IMG, 3,3,1,140,200,playerImg);
	//基本変数の初期化
	angle = 0.0f;
	posX = 640;
	posY = 360;
	HP = PLAYER_HP_MAX;
	phese = 0;
	for (int i = 0; i < 4; i++) {
		attacDirection[i] = false;
	}

	//その他初期化
	direction[1] = true;	//はじめは右を向く
	isHit = false;			//攻撃されたかをなしに	
	playerImgNum = 0;		//まずは立ちの絵
	attckCount = 0;			//無敵時間
	isDraw = true;
	Yspeed = YSPEED;
}

//通常処理
void Player::Step()
{
	//制御
	if (HP < 0) {
		HP = 0;
	}

	switch (phese)
	{
	case 0:
		//HPがなくなったら回転して場面移動　ちょっと想定と異なる動きしてる
		if (HP == 0) {
			angle += 3;
			if (angle == 120) {
				phese = 1;
			}
		}
		break;
	case 1:
		//終わりの処理へ
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;

	default:
		break;
	}
	
	Jump();//ジャンプ周りの重力

}

//描画
void Player::Draw()
{
	if(isDraw){
		if (direction[1]) {
			DrawRotaGraph(posX, posY, 1.0f, angle, playerImg[playerImgNum], true, true);
		}
		else if (direction[3]) {
			DrawRotaGraph(posX, posY, 1.0f, angle, playerImg[playerImgNum], true, false);
		}
	}
}

//攻撃画像指定
void Player::MoveImage()
{	
	//攻撃絵にする/左向き
	if (attacDirection[3]&& attckCount>0) {
		playerImgNum = 1;
	}
	//攻撃絵にする/右向き
	else if (attacDirection[1] && attckCount > 0) {
		playerImgNum = 1;
	}
	//しゃがみ絵にする
	else if (attacDirection[2] && attckCount > 0) {
		playerImgNum = 2;
	}

	if (attckCount == 0) {
		playerImgNum = 0;//立ち絵
	}
	if (attckCount > 1) {
		attckCount = 0;//戻す,数え直し
	}
}

//プレイヤー操作
void Player::Operation()
{
	//入力した方向にプレイヤーを向ける
	//上にジャンプしたい
	if (Input::IsKeyPush(KEY_INPUT_UP)) {
		Yspeed = YSPEED;
		directionSetting(0);//キー方向設定
	}

	//右向く
	if (Input::IsKeyPush(KEY_INPUT_RIGHT)) {
		directionSetting(1);//キー方向設定
		direction[3] = false;
	}
	
	//しゃがむ
	if (Input::IsKeyPush(KEY_INPUT_DOWN)) {
		directionSetting(2);//キー方向設定
	}

	//左向く
	if (Input::IsKeyPush(KEY_INPUT_LEFT)) {
		directionSetting(3);//キー方向設定
		direction[1] = false;
	}
}

//ボタンの初期化/毎フレーム初期化させる/押すたびに攻撃したいから
void Player::BottunInit()
{
	for (int i = 0; i < 4; i++) {
		attacDirection[i] = false;
	}
}

//方向設定
void Player::directionSetting(int num)
{
	//値セット
	direction[num] = true;
	attacDirection[num] = true;
}

//無敵時間
void Player::InvincibleTime(int count)
{
	isDraw = false; // 一度描画されない

	if (count % 9 < 200) {
		isDraw = true; // 描画されているにする
	}
}

//ジャンプ
void Player::Jump()
{
	//重力を与える
	Yspeed += GRAVITY;
	if (Yspeed > YSPPED_MAX) {
		Yspeed = YSPPED_MAX;
	}
	posY += Yspeed;

	if (posY >= 360) {
		posY = 360;
	}
}

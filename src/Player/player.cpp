#include "DxLib.h"
#include "player.h"
#include "../Input/Input.h"

void Player::Init()
{
	//画像の読みこみ
	for (int i = 0; i < PLAYER_IMEG_MAX; i++) {
		imgHandl[i] = LoadGraph(PLAYER_IMAGE_PATH[i]);
	}
	LoadDivGraph(PLAYER_IMG, 3,3,1,140,200,playerImg);
	directionAngle = 0.0f;
	posX = 640;
	posY = 360;
	HP = PLAYER_HP_MAX;

	direction[1] = true;	//はじめは右を向く
	for (int i = 0; i < 4; i++) {
		attacDirection[i] = false;
	}
	isHit = false;
	playerImgNum = 0;//まずは立ちの絵
	attckCount = 0;
}

//通常処理
void Player::Step()
{
	if (attacDirection[3]&& attckCount>0) {
		playerImgNum = 1;//攻撃絵にする
	}
	if (attckCount == 0) {
		playerImgNum = 0;//立ち絵
	}
	if (attckCount > 1) {
		attckCount = 0;//戻す,数え直し
	}
}

//描画
void Player::Draw()
{
	if(direction[1]){
		DrawRotaGraph(posX, posY, 1.0f, 0.0f, playerImg[playerImgNum], true, true);
	}
	else if (direction[3]) {
		DrawRotaGraph(posX, posY, 1.0f, 0.0f, playerImg[playerImgNum], true, false);
	}
}

//プレイヤー操作
void Player::Operation()
{
	//入力した方向にプレイヤーを向ける
	//上にジャンプしたい
	//if (Input::IsKeyPush(KEY_INPUT_UP)) {
	//	directionSetting(0);//キー方向設定
	//	//directionAngle = 270.0f;
	//}

	//右向く
	if (Input::IsKeyPush(KEY_INPUT_RIGHT)) {
		directionSetting(1);//キー方向設定
		direction[3] = false;
		//directionAngle = 0.0f;
	}
	
	//しゃがむ
	if (Input::IsKeyPush(KEY_INPUT_DOWN)) {
		directionSetting(2);//キー方向設定
		//directionAngle = 90.0f;
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
	//初期化
	/*if (direction[num] == true) {
		direction[num] = false;
	}*/
	/*if (attacDirection[num] == true) {
		attacDirection[num] = false;
	}*/
	//値セット
	direction[num] = true;
	attacDirection[num] = true;
}


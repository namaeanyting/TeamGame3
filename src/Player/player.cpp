#include "DxLib.h"
#include "player.h"
#include "../Input/Input.h"

void Player::Init()
{
	//画像の読みこみ
	for (int i = 0; i < PLAYER_IMEG_MAX; i++) {
		imgHandl[i] = LoadGraph(PLAYER_IMAGE_PATH[i]);
	}
	directionAngle = 0.0f;
	posX = 640;
	posY = 360;
	HP = PLAYER_HP_MAX;
	for (int i = 0; i < 4; i++) {
		direction[i] = false;
		attacDirection[i] = false;
	}
	isHit = false;

}
//通常処理
void Player::Step()
{

}

//描画
void Player::Draw()
{	if (!isHit) {

		DrawRotaGraph(posX, posY, 1.0f, directionAngle / 180 * 3.14, imgHandl[PLAYER_NOMAL], true,true);

	
		//右にパンチ
		//if (!isHit || direction[1]) {
			//DrawRotaGraph(posX, posY, 1.0f, 0.0f, imgHandl[PLAYER_NOMAL], true);
		//}
		//左にパンチ
		/*if (!isHit && direction[3]) {
			DrawRotaGraph(posX, posY, 1.0f, 180.0f, imgHandl[PLAYER_NOMAL], true);
		}*/
	}
}

//終了処理
void Player::Fin()
{

}

//プレイヤー操作
void Player::Operation()
{
	//入力した方向にプレイヤーを向ける
	
	//上にジャンプ
	if (Input::IsKeyPush(KEY_INPUT_UP)) {
		directionSetting(0);//方向設定
		/*if (direction[0] == true) {
			direction[0] = false;
		}
		if (attacDirection[0] == true) {
			attacDirection[0] = false;
		}
		direction[0] = true;
		attacDirection[0] = true;*/

		directionAngle = 270.0f;

	}

	//右向く
	if (Input::IsKeyPush(KEY_INPUT_RIGHT)) {
		directionSetting(1);//方向設定

		/*if (direction[1] == true) {
			direction[1] = false;
		}
		direction[1] = true;*/
		directionAngle = 0.0f;

	}
	
	//しゃがむ
	if (Input::IsKeyPush(KEY_INPUT_DOWN)) {
		directionSetting(2);//方向設定

		/*if (direction[2] == true) {
			direction[2] = false;
		}
		direction[2] = true;*/
		directionAngle = 90.0f;

	}
	//左向く
	if (Input::IsKeyPush(KEY_INPUT_LEFT)) {
		directionSetting(3);//方向設定

		/*if(direction[3] == true){
			direction[3] = false;
		}
		direction[3] = true;*/
		directionAngle = 180.0f;
	}
}

//ボタンの初期化/毎フレーム初期化させる/押すたびに攻撃したいから
void Player::BottunInit()
{
	for (int i = 0; i < 4; i++) {
		direction[i] = false;
	}
}

//方向設定
void Player::directionSetting(int num)
{
	if (direction[num] == true) {
		direction[num] = false;
	}
	if (attacDirection[num] == true) {
		attacDirection[num] = false;
	}
	direction[num] = true;
	attacDirection[num] = true;
}


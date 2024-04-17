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
	}
}
//通常処理
void Player::Step()
{

}

//描画
void Player::Draw()
{
	DrawRotaGraph(posX, posY, 1.0f, directionAngle / 180 * 3.14, imgHandl[PLAYER_PLAYER], true);

}

//終了処理
void Player::Fin()
{

}

//プレイヤー操作
void Player::Operation()
{
	//入力した方向にプレイヤーを向ける
	if (Input::IsKeyPush(KEY_INPUT_LEFT)) {

		if(direction[3] == true){
			direction[3] = false;
		}
		directionAngle = 180.0f;
		direction[3] = true;
	}
	if (Input::IsKeyPush(KEY_INPUT_RIGHT)) {
		if (direction[1] == true) {
			direction[1] = false;
		}
		directionAngle = 0.0f;
		direction[1] = true;

	}
	if (Input::IsKeyPush(KEY_INPUT_UP)) {
		if (direction[0] == true) {
			direction[0] = false;
		}
		directionAngle = 270.0f;
		direction[0] = true;

	}
	if (Input::IsKeyPush(KEY_INPUT_DOWN)) {
		if (direction[2] == true) {
			direction[2] = false;
		}
		directionAngle = 90.0f;
		direction[2] = true;

	}
}


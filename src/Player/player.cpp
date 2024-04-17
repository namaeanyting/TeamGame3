#include "DxLib.h"
#include "player.h"
#include "../Input/Input.h"

void Player::Init()
{
	//�摜�̓ǂ݂���
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
//�ʏ폈��
void Player::Step()
{

}

//�`��
void Player::Draw()
{
	DrawRotaGraph(posX, posY, 1.0f, directionAngle / 180 * 3.14, imgHandl[PLAYER_PLAYER], true);

}

//�I������
void Player::Fin()
{

}

//�v���C���[����
void Player::Operation()
{
	//���͂��������Ƀv���C���[��������
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


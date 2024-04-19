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
		attacDirection[i] = false;
	}
	isHit = false;

}
//�ʏ폈��
void Player::Step()
{

}

//�`��
void Player::Draw()
{	if (!isHit) {

		DrawRotaGraph(posX, posY, 1.0f, directionAngle / 180 * 3.14, imgHandl[PLAYER_NOMAL], true,true);

	
		//�E�Ƀp���`
		//if (!isHit || direction[1]) {
			//DrawRotaGraph(posX, posY, 1.0f, 0.0f, imgHandl[PLAYER_NOMAL], true);
		//}
		//���Ƀp���`
		/*if (!isHit && direction[3]) {
			DrawRotaGraph(posX, posY, 1.0f, 180.0f, imgHandl[PLAYER_NOMAL], true);
		}*/
	}
}

//�I������
void Player::Fin()
{

}

//�v���C���[����
void Player::Operation()
{
	//���͂��������Ƀv���C���[��������
	
	//��ɃW�����v
	if (Input::IsKeyPush(KEY_INPUT_UP)) {
		directionSetting(0);//�����ݒ�
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

	//�E����
	if (Input::IsKeyPush(KEY_INPUT_RIGHT)) {
		directionSetting(1);//�����ݒ�

		/*if (direction[1] == true) {
			direction[1] = false;
		}
		direction[1] = true;*/
		directionAngle = 0.0f;

	}
	
	//���Ⴊ��
	if (Input::IsKeyPush(KEY_INPUT_DOWN)) {
		directionSetting(2);//�����ݒ�

		/*if (direction[2] == true) {
			direction[2] = false;
		}
		direction[2] = true;*/
		directionAngle = 90.0f;

	}
	//������
	if (Input::IsKeyPush(KEY_INPUT_LEFT)) {
		directionSetting(3);//�����ݒ�

		/*if(direction[3] == true){
			direction[3] = false;
		}
		direction[3] = true;*/
		directionAngle = 180.0f;
	}
}

//�{�^���̏�����/���t���[��������������/�������тɍU������������
void Player::BottunInit()
{
	for (int i = 0; i < 4; i++) {
		direction[i] = false;
	}
}

//�����ݒ�
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


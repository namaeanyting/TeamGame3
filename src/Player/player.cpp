#include "DxLib.h"
#include "player.h"
#include "../Input/Input.h"

void Player::Init()
{
	//�摜�̓ǂ݂���
	for (int i = 0; i < PLAYER_IMEG_MAX; i++) {
		imgHandl[i] = LoadGraph(PLAYER_IMAGE_PATH[i]);
	}
	LoadDivGraph(PLAYER_IMG, 3,3,1,140,200,playerImg);
	directionAngle = 0.0f;
	posX = 640;
	posY = 360;
	HP = PLAYER_HP_MAX;

	direction[1] = true;	//�͂��߂͉E������
	for (int i = 0; i < 4; i++) {
		attacDirection[i] = false;
	}
	isHit = false;
	playerImgNum = 0;//�܂��͗����̊G
	attckCount = 0;
}

//�ʏ폈��
void Player::Step()
{
	if (attacDirection[3]&& attckCount>0) {
		playerImgNum = 1;//�U���G�ɂ���
	}
	if (attckCount == 0) {
		playerImgNum = 0;//�����G
	}
	if (attckCount > 1) {
		attckCount = 0;//�߂�,��������
	}
}

//�`��
void Player::Draw()
{
	if(direction[1]){
		DrawRotaGraph(posX, posY, 1.0f, 0.0f, playerImg[playerImgNum], true, true);
	}
	else if (direction[3]) {
		DrawRotaGraph(posX, posY, 1.0f, 0.0f, playerImg[playerImgNum], true, false);
	}
}

//�v���C���[����
void Player::Operation()
{
	//���͂��������Ƀv���C���[��������
	//��ɃW�����v������
	//if (Input::IsKeyPush(KEY_INPUT_UP)) {
	//	directionSetting(0);//�L�[�����ݒ�
	//	//directionAngle = 270.0f;
	//}

	//�E����
	if (Input::IsKeyPush(KEY_INPUT_RIGHT)) {
		directionSetting(1);//�L�[�����ݒ�
		direction[3] = false;
		//directionAngle = 0.0f;
	}
	
	//���Ⴊ��
	if (Input::IsKeyPush(KEY_INPUT_DOWN)) {
		directionSetting(2);//�L�[�����ݒ�
		//directionAngle = 90.0f;
	}

	//������
	if (Input::IsKeyPush(KEY_INPUT_LEFT)) {
		directionSetting(3);//�L�[�����ݒ�
		direction[1] = false;
	}
}

//�{�^���̏�����/���t���[��������������/�������тɍU������������
void Player::BottunInit()
{
	for (int i = 0; i < 4; i++) {
		attacDirection[i] = false;
	}
}

//�����ݒ�
void Player::directionSetting(int num)
{
	//������
	/*if (direction[num] == true) {
		direction[num] = false;
	}*/
	/*if (attacDirection[num] == true) {
		attacDirection[num] = false;
	}*/
	//�l�Z�b�g
	direction[num] = true;
	attacDirection[num] = true;
}


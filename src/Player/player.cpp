#include "DxLib.h"
#include "player.h"
#include "../Input/Input.h"

void Player::Init()
{
	//�摜�̓ǂ݂���
	for (int i = 0; i < PLAYER_IMEG_MAX; i++) {
		imgHandl[i] = LoadGraph(PLAYER_IMAGE_PATH[i]);
	}
	//�v���C���[�̉摜�ǂݍ���
	LoadDivGraph(PLAYER_IMG, 3,3,1,140,200,playerImg);
	//��{�ϐ��̏�����
	angle = 0.0f;
	posX = 640;
	posY = 360;
	HP = PLAYER_HP_MAX;
	phese = 0;
	for (int i = 0; i < 4; i++) {
		attacDirection[i] = false;
	}

	//���̑�������
	direction[1] = true;	//�͂��߂͉E������
	isHit = false;			//�U�����ꂽ�����Ȃ���	
	playerImgNum = 0;		//�܂��͗����̊G
	attckCount = 0;			//���G����
	isDraw = true;
	Yspeed = YSPEED;
}

//�ʏ폈��
void Player::Step()
{
	//����
	if (HP < 0) {
		HP = 0;
	}

	switch (phese)
	{
	case 0:
		//HP���Ȃ��Ȃ������]���ď�ʈړ��@������Ƒz��ƈقȂ铮�����Ă�
		if (HP == 0) {
			angle += 3;
			if (angle == 120) {
				phese = 1;
			}
		}
		break;
	case 1:
		//�I���̏�����
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;

	default:
		break;
	}
	
	Jump();//�W�����v����̏d��

}

//�`��
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

//�U���摜�w��
void Player::MoveImage()
{	
	//�U���G�ɂ���/������
	if (attacDirection[3]&& attckCount>0) {
		playerImgNum = 1;
	}
	//�U���G�ɂ���/�E����
	else if (attacDirection[1] && attckCount > 0) {
		playerImgNum = 1;
	}
	//���Ⴊ�݊G�ɂ���
	else if (attacDirection[2] && attckCount > 0) {
		playerImgNum = 2;
	}

	if (attckCount == 0) {
		playerImgNum = 0;//�����G
	}
	if (attckCount > 1) {
		attckCount = 0;//�߂�,��������
	}
}

//�v���C���[����
void Player::Operation()
{
	//���͂��������Ƀv���C���[��������
	//��ɃW�����v������
	if (Input::IsKeyPush(KEY_INPUT_UP)) {
		Yspeed = YSPEED;
		directionSetting(0);//�L�[�����ݒ�
	}

	//�E����
	if (Input::IsKeyPush(KEY_INPUT_RIGHT)) {
		directionSetting(1);//�L�[�����ݒ�
		direction[3] = false;
	}
	
	//���Ⴊ��
	if (Input::IsKeyPush(KEY_INPUT_DOWN)) {
		directionSetting(2);//�L�[�����ݒ�
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
	//�l�Z�b�g
	direction[num] = true;
	attacDirection[num] = true;
}

//���G����
void Player::InvincibleTime(int count)
{
	isDraw = false; // ��x�`�悳��Ȃ�

	if (count % 9 < 200) {
		isDraw = true; // �`�悳��Ă���ɂ���
	}
}

//�W�����v
void Player::Jump()
{
	//�d�͂�^����
	Yspeed += GRAVITY;
	if (Yspeed > YSPPED_MAX) {
		Yspeed = YSPPED_MAX;
	}
	posY += Yspeed;

	if (posY >= 360) {
		posY = 360;
	}
}

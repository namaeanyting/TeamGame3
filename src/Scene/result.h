#pragma once
#include "../Input/Input.h"

//�摜���g���Ƃ��̖��O
enum RESULT_IMAGE
{
	RESULT_BACK,		//�^�C�g���̔w�i

	RESULT_IMEG_MAX,		//�摜�̖���
};

//�摜�̃p�X
const char RESULT_IMAGE_PATH[RESULT_IMEG_MAX][255] =
{
	"data/result/3.png",			//�^�C�g���w�i�摜
};

class SceneResult
{
private:
	int imgHandl[RESULT_IMEG_MAX];	//�摜�n���h��

public:

	SceneResult();
	~SceneResult();
	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`��
	void Draw();

	//�I������
	void Fin();
};
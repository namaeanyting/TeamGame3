#pragma once

//�摜���g���Ƃ��̖��O
enum TITLE_IMAGE
{
	TITLE_BACK,		//�^�C�g���̔w�i

	TITLE_IMEG_MAX,		//�摜�̖���
};

//�摜�̃p�X
const char TITLE_IMAGE_PATH[TITLE_IMEG_MAX][255] =
{
	"data/title/1.png",			//�^�C�g���w�i�摜
};

class SceneTitle
{
private:
	int imgHandl[TITLE_IMEG_MAX];	//�摜�n���h��
public:

	SceneTitle();
	~SceneTitle();

	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`��
	void Draw();

	//�I������
	void Fin();
};


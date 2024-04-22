#include"DxLib.h"
#include"sound.h"

int Sound::BGM::handle[BGM_MAX];
int Sound::SE::handle[SE_MAX];


//BGM�̃p�X
char BGMPath[BGM_MAX][255] =
{
	"data/sound/title.mp3",
	"data/sound/play.mp3",
	"data/sound/result.mp3",

};


//SE�̃p�X
char SEPath[SE_MAX][255] =
{
	"data/sound/punch.mp3",
	"data/sound/se_monster3.mp3",
};
//������
void Sound::Init()
{
	BGM::Init();
	SE::Init();
}

//������
void Sound::BGM::Init()
{
	for (int i = 0; i < BGM_MAX; i++)
	{
		//�ǂݍ���
		handle[i] = LoadSoundMem(BGMPath[i]);
	}
}
void Sound::SE::Init()
{
	for (int i = 0; i < SE_MAX; i++)
	{
		//�ǂݍ���
		handle[i] = LoadSoundMem(SEPath[i]);
	}
}

//�Đ�������
void Sound::BGM::PlayButton(int nameType)
{
	PlaySoundMem(handle[nameType], DX_PLAYTYPE_LOOP, true);
}
void Sound::SE::PlayButton(int nameType)
{
	PlaySoundMem(handle[nameType], DX_PLAYTYPE_BACK, true);
}

//��~�ƍ폜
void Sound::BGM::StopDelButton(int nameType)
{
	StopSoundMem(handle[nameType]);
	DeleteSoundMem(handle[nameType]);

}
void Sound::SE::StopDelButton(int nameType)
{
	StopSoundMem(handle[nameType]);
	DeleteSoundMem(handle[nameType]);

}

//���ʒ���
void Sound::BGM::Volume(int type, int volume)
{
	ChangeVolumeSoundMem(255 * volume / 100, handle[type]);
}
void Sound::SE::Volume(int type, int volume)
{
	ChangeVolumeSoundMem(255 * volume / 100, handle[type]);
}

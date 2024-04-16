#include"DxLib.h"
#include"sound.h"

int Sound::BGM::handle[BGM_MAX];
int Sound::SE::handle[SE_MAX];


//初期化
void Sound::Init()
{
	BGM::Init();
	SE::Init();
}

//初期化
void Sound::BGM::Init()
{
	for (int i = 0; i < BGM_MAX; i++)
	{
		//読み込み
		handle[i] = LoadSoundMem(BGMPath[i]);
	}
}
void Sound::SE::Init()
{
	for (int i = 0; i < SE_MAX; i++)
	{
		//読み込み
		handle[i] = LoadSoundMem(SEPath[i]);
	}
}

//再生させる
void Sound::BGM::PlayButton(int nameType)
{
	PlaySoundMem(handle[nameType], DX_PLAYTYPE_LOOP, true);
}
void Sound::SE::PlayButton(int nameType)
{
	PlaySoundMem(handle[nameType], DX_PLAYTYPE_LOOP, true);
}

//停止と削除
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
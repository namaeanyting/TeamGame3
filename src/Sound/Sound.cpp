#include"DxLib.h"
#include"sound.h"

int Sound::BGM::handle[BGM_MAX];
int Sound::SE::handle[SE_MAX];


//‰Šú‰»
void Sound::Init()
{
	BGM::Init();
	SE::Init();
}

//‰Šú‰»
void Sound::BGM::Init()
{
	for (int i = 0; i < BGM_MAX; i++)
	{
		//“Ç‚İ‚İ
		handle[i] = LoadSoundMem(BGMPath[i]);
	}
}
void Sound::SE::Init()
{
	for (int i = 0; i < SE_MAX; i++)
	{
		//“Ç‚İ‚İ
		handle[i] = LoadSoundMem(SEPath[i]);
	}
}

//Ä¶‚³‚¹‚é
void Sound::BGM::PlayButton(int nameType)
{
	PlaySoundMem(handle[nameType], DX_PLAYTYPE_LOOP, true);
}
void Sound::SE::PlayButton(int nameType)
{
	PlaySoundMem(handle[nameType], DX_PLAYTYPE_LOOP, true);
}

//’â~‚Æíœ
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
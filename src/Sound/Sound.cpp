#include"DxLib.h"
#include"sound.h"

int Sound::BGM::handle[BGM_MAX];
int Sound::SE::handle[SE_MAX];


//BGMのパス
char BGMPath[BGM_MAX][255] =
{
	"data/sound/title.mp3",
	"data/sound/play.mp3",
	"data/sound/result.mp3",

};


//SEのパス
char SEPath[SE_MAX][255] =
{
	"data/sound/punch.mp3",
	"data/sound/se_monster3.mp3",
};
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
	PlaySoundMem(handle[nameType], DX_PLAYTYPE_BACK, true);
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

//音量調節
void Sound::BGM::Volume(int type, int volume)
{
	ChangeVolumeSoundMem(255 * volume / 100, handle[type]);
}
void Sound::SE::Volume(int type, int volume)
{
	ChangeVolumeSoundMem(255 * volume / 100, handle[type]);
}

#pragma once

enum BGM_TYPE
{
	BGM_TITLE,
	BGM_PLAY,
	BGM_RESULT,
	BGM_MAX,
};
enum SE_TYPE
{
	SE_PUNCH,
	SE_MONSTER,
	/*SE_TITLE,
	SE_PLAY,
	SE_RESULT,*/
	SE_MAX,
};

class Sound
{
public:
	//初期化
	static void Init();

	class BGM
	{
	private:
		//音ハンドル
		static int handle[BGM_MAX];
	public:
		//初期化
		static void Init();	
		//再生させる
		static void PlayButton(int nameType);
		//停止と削除
		static void StopDelButton(int nameType);
		//音量調節
		static void Volume(int type, int volume);
	};

	class SE
	{
	private:
		//音ハンドル
		static int handle[SE_MAX];

	public:
		//初期化
		static void Init();
		//再生させる
		static void PlayButton(int nameType);
		//停止と削除
		static void StopDelButton(int nameType);
		//音量調節
		static void Volume(int type, int volume);

	};
};

/*
宣言	int ChangeVolumeSoundMem( int VolumePal , int SoundHandle ) ;

概略	メモリに読みこんだ音データの再生にボリュームを設定する

引数	int VolumePal 　: 設定する音量( 0 ～ 255 )
        int SoundHandle : 音量を設定する音の識別番号(サウンドハンドル)
戻り値	　０：成功
　		－１：エラー発生

解説	　再生する音の音量を設定します。０は無音、２５５で最大音量です。
　		音を再生中でも音量の変更は可能です。


		 // 音量の設定
	ChangeVolumeSoundMem( 255 * 80 / 100, SHandle ) ;
*/
/*
宣言	int SetVolumeMusic( int Volume ) ;

概略	ＭＩＤＩ又はＭＰ３ファイルの演奏(再生)の音量を設定する

引数	int Volume : 音量( 0～255 )
戻り値	　０：成功
　	－１：エラー発生

解説	　PlayMusic関数 で開始した演奏の音量を設定します０が無音、
		２５５が最大音量(デフォルト)となります。

*/
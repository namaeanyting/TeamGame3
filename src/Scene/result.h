#pragma once
#include "../Input/Input.h"

//画像を使うときの名前
enum RESULT_IMAGE
{
	RESULT_BACK,		//タイトルの背景

	RESULT_IMEG_MAX,		//画像の枚数
};

//画像のパス
const char RESULT_IMAGE_PATH[RESULT_IMEG_MAX][255] =
{
	"data/result/3.png",			//タイトル背景画像
};

class SceneResult
{
private:
	int imgHandl[RESULT_IMEG_MAX];	//画像ハンドル

public:

	SceneResult();
	~SceneResult();
	//初期化
	void Init();

	//通常処理
	void Step();

	//描画
	void Draw();

	//終了処理
	void Fin();
};
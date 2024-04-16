#pragma once

//画像を使うときの名前
enum TITLE_IMAGE
{
	TITLE_BACK,		//タイトルの背景

	TITLE_IMEG_MAX,		//画像の枚数
};

//画像のパス
const char TITLE_IMAGE_PATH[TITLE_IMEG_MAX][255] =
{
	"data/title/1.png",			//タイトル背景画像
};

class SceneTitle
{
private:
	int imgHandl[TITLE_IMEG_MAX];	//画像ハンドル
public:

	SceneTitle();
	~SceneTitle();

	//初期化
	void Init();

	//通常処理
	void Step();

	//描画
	void Draw();

	//終了処理
	void Fin();
};


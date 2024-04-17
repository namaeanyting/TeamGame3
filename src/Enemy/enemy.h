#pragma once
// 敵の画像サイズ
const int ENEMY_SIZE_Y = 200;
const int ENEMY_SIZE_X = 140;
const int ENEMY_KAIND = 3;
//HPの最大値
const int ENEMY_HP_MAX = 6;

//画像を使うときの名前
enum ENEMY_IMAGE
{
	ENEMY_ENEMY,		//敵の姿

	ENEMY_IMEG_MAX,		//画像の最大枚数
};

//画像のパス
const char ENEMY_IMAGE_PATH[ENEMY_IMEG_MAX][255] =
{
	"data/play/kari_enemy.png",			//タイトル背景画像
};

class Enemy
{
private:
	int imgHandl[ENEMY_IMEG_MAX];
	int posX, posY;
	// int HP;
public:
	//初期化
	void Init();

	//通常処理
	void Step();

	//描画
	void Draw();

	//終了処理
	void Fin();
	
	//座標取得
	int GetPosX() { return posX; }
	int GetPosY() { return posY; }

	//HP
	int HP;
};

#pragma once
// プレイヤーの画像サイズ
const int PLAYER_SIZE_Y = 200; 
const int PLAYER_SIZE_X = 140; 

//HPの最大値
const int PLAYER_HP_MAX = 6;

//画像を使うときの名前
enum PLAYER_IMAGE
{
	PLAYER_PLAYER,		//タイトルの背景

	PLAYER_IMEG_MAX,		//画像の枚数
};

//画像のパス
const char PLAYER_IMAGE_PATH[PLAYER_IMEG_MAX][255] =
{
	"data/play/2.png",			//タイトル背景画像
};
class Player
{
private:
	int imgHandl[PLAYER_IMEG_MAX];
	int posX, posY;
	float directionAngle;		//プレイヤーが向いている方向
	
public:
	bool direction[4];			//プレイヤーが向いている・押しているキー
	int HP;
	//初期化
	void Init();

	//通常処理
	void Step();

	//描画
	void Draw();

	//終了処理
	void Fin();

	//プレイヤー操作
	void Operation();

	//座標取得
	int GetPosX() { return posX; }
	int GetPosY() { return posY; }

};
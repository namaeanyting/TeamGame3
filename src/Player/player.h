#pragma once
#include "../Scene/scene.h"

#define GRAVITY			(1.5)	//重力加速度  1.5   0.25
#define YSPEED			(10)	//-27.5  -10
#define YSPPED_MAX		(13)

// プレイヤーの画像サイズ
const int PLAYER_SIZE_Y = 200; 
const int PLAYER_SIZE_X = 140; 

//HPの最大値
const int PLAYER_HP_MAX = 6;
#define PLAYER_IMG "data/player/player.png"

//画像を使うときの名前
enum PLAYER_IMAGE
{
	PLAYER_NOMAL,		//起立
	PLAYER_KICK,		//足蹴り
	PLAYER_PUNCH,		//パンチ

	PLAYER_IMEG_MAX,		//画像の枚数
};

//画像のパス
const char PLAYER_IMAGE_PATH[PLAYER_IMEG_MAX][255] =
{
	"data/player/usagi_normal.png",			
	"data/player/usagi_kick.png",			
	"data/player/usagi_attack.png",			
};
class Player
{
private:
	int imgHandl[PLAYER_IMEG_MAX];
	int posX, posY;
	float angle;		//プレイヤーが向いている方向
	int playerImg[3];
	int phese;			//本編進行
	int Yspeed;			//ジャンプ
public:
	bool direction[4];			//プレイヤーが向いている・押しているキー
	bool attacDirection[4];		//攻撃プレイヤーが向いている・押しているキー
	bool isHit;					//単純に敵に攻撃したか
	int playerImgNum;			//プレイヤーの画像添え字
	int HP;
	int attckCount;				//腕を伸ばした数・最大３

	//初期化
	void Init();

	//通常処理
	void Step();

	//描画
	void Draw();

	//終了処理
	void Fin();

	//攻撃画像指定
	void MoveImage();

	//プレイヤー操作
	void Operation();

	//ボタンの初期化/毎フレーム初期化させる
	void BottunInit();

	//方向設定
	void directionSetting(int num);
	
	//座標取得
	int GetPosX() { return posX; }
	int GetPosY() { return posY; }

};
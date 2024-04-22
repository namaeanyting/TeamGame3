#pragma once
#include "../Scene/scene.h"

#define GRAVITY			(1.5)	
#define YSPEED			(-30)	
#define YSPPED_MAX		(10)

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
	int collsionYspeed;			//ジャンプ

public:
	bool direction[4];			//プレイヤーが向いている・押しているキー
	bool attacDirection[4];		//攻撃プレイヤーが向いている・押しているキー
	bool isHit;					//単純に敵に攻撃したか
	bool isDraw;				//無敵時間　攻撃され中点滅
	int playerImgNum;			//プレイヤーの画像添え字
	int HP;
	int attckCount;				//腕を伸ばした数・最大３
	int collisionPosX;			//当たり判定用の座標
	int collisionPosY;

	void Init();				//初期化
	void Step();				//通常処理
	void Draw();				//描画
	void Fin();					//終了処理
	void MoveImage();			//攻撃画像指定
	void Operation();			//プレイヤー操作
	void Jump();				//ジャンプ
	void BottunInit();			//ボタンの初期化/毎フレーム初期化させる
	void directionSetting(int num);//方向設定
	void InvincibleTime(int count);//無敵時間
	int GetPosX() { return posX; }//座標取得
	int GetPosY() { return posY; }

};
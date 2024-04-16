#pragma once
#define KEY_BUF_LEN (256)

class Input {
private:

	//現在のフレームキー情報
	static char currentKeyBuf[KEY_BUF_LEN];

	//前フレームのキー情報
	static char preKeyBuf[KEY_BUF_LEN];



public:
	//入力制御　初期化
	static void Init();
	//入力制御ステップ
	//他のstepより早く呼ぶ
	static void Step();

	//今押された
	static bool IsKeyPush(int key_code);

	//押し続けられているか
	static bool IsKeyKeep(int key_code);

	//たった今離されたか
	static bool IsKeyRelease(int key_code);

	//単純に押されているか
	static bool IsKeyDown(int key_code);

};

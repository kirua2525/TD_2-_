#include <Novice.h>
#include <math.h>
#include "Vector2.h"
#include "player.h"

const char kWindowTitle[] = "LC1D_21_ナガタ_キルア_(確認課題)";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player player;
    player.Initialize(
        Vector2{100.0f, 600.0f}, // pos
        Vector2{5.0f, 0.0f},     // velocity
        Vector2{50.0f, 50.0f},   // size
        Vector2{25.0f, 25.0f},   // playerRadius
        0.0f,                     // angle
        0xFF0000FF,               // enemyColor
        //textureHandle
        15.0f,                    // jumpSpeed
        true,                     // alive
        true,                     // visible
        false,                    // jumping
        false,                    // moving
        false,                    // onGround
		false,					  // 
		false,
		false,
		Player::weaponType::SWORD
    );

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		//プレイヤーの更新
		player.Update(keys,preKeys);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//プレイヤーの描画
		player.Draw();

		//debug
		player.debugDraw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

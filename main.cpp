#include <Novice.h>
#include <math.h>
#include <time.h>

#include "Vector2.h"
#include "mouse.h"
#include "player.h"
#include "sword.h"
#include "gun.h"
#include "bullet.h"
#include "specialWeapon.h"

const char kWindowTitle[] = "LC1D_21_ナガタ_キルア_(確認課題)";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	srand((unsigned int)time(nullptr));

	Mouse mouse;
	mouse.Initialize(
		Vector2F{ 20.0f,20.0f },
		Vector2F{ 10.0f,10.0f },
		0.0f,
		0x747400FF
	);

	Player player;
    player.Initialize(
        Vector2F{100.0f, 600.0f}, // pos
        Vector2F{5.0f, 0.0f},     // velocity
        Vector2F{50.0f, 50.0f},   // size
        Vector2F{25.0f, 25.0f},   // playerRadius
        0.0f,                     // angle
        0x00000055,               // enemyColor
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
		false,
		false,
		Player::weaponType::SWORD //最初を剣にする
    );

	Sword sword;
	sword.Initialize(
		Vector2F{ player.pos.x, player.pos.y },
		Vector2F{ 50.0f,3.0f },
		Vector2F{ 50.0f,3.0f },
		0.0f,
		0.2f,
		WHITE,
		rand() % ((100 + 50 + 1) + 50),
		10,
		150,
		false
		);

	Gun gun;
	gun.Initialize(
		Vector2F{ player.pos.x, player.pos.y },
		Vector2F{ 10.0f,5.0f },
		Vector2F{ 10.0f,3.0f },
		0.0f,
		RED,
		rand() % ((100 + 50 + 1) + 50),
		10,
		150,
		false
	);

	Bullet bullet;
	bullet.Initialize(
		Vector2F{ player.pos.x, player.pos.y },
		Vector2F{ 10.0f,10.0f },
		Vector2F{ 7.0f,7.0f },
		Vector2F{ 5.0f,5.0f },
		Vector2F{ 0.0f,0.0f },
		gun.angle,
		10.0f,
		RED,
		false
	);

	SpecialWeapon hammer;
	hammer.Initialize(
		Vector2F{ player.pos.x, player.pos.y },
		Vector2F{ 90.0f,9.0f },
		Vector2F{ 90.0f,9.0f },
		0.0f,
		0.2f,
		300.0f,
		GREEN,
		200,
		200,
		200,
		false
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



		mouse.invisible();

		//プレイヤーの更新
		player.Update(keys,preKeys);

		if (player.currentWeapon == Player::weaponType::SWORD) {
			//剣の更新処理
			sword.Update(player,keys);

		}
		else if (player.currentWeapon == Player::weaponType::GUN) {
			//銃の更新処理
			gun.Update(player,mouse);
			mouse.Update(gun);
			bullet.Update(gun, mouse,player);

		}
		else if (player.currentWeapon == Player::weaponType::SPECIAL_ITEM) {
			//特殊アイテムの更新処理
			hammer.Update(player,keys);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//プレイヤーの描画
		player.Draw();

		if (player.currentWeapon == Player::weaponType::SWORD) {
			sword.Draw();

		}
		else if (player.currentWeapon == Player::weaponType::GUN) {
			gun.Draw();
			mouse.Draw();
			bullet.Draw(gun);

		}
		else if (player.currentWeapon == Player::weaponType::SPECIAL_ITEM) {
			hammer.Draw();
		}

		//debug
		player.debugDraw();
		Novice::ScreenPrintf(0,180, "isShot: %s", gun.isShot ? "true" : "false");


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

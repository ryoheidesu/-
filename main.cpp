#include <Novice.h>
#include"player.h"
#include"enemy.h"
#include"bullet.h"
const char kWindowTitle[] = "GC1A_23_ミツイ_リョウヘイ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player player;
	Enemy enemy;

	player.Initialize();
	enemy.Initialize();
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
		player.Update(keys, preKeys);
		float dx = enemy.GetPosX() - player.GetPosX();
		float dy = enemy.GetPosY() - player.GetPosY();
		float d = dx * dx + dy * dy;

		if (d < (player.GetRadius() + enemy.GetRadius()) * (player.GetRadius() + enemy.GetRadius())) {
			player.OnCollision();
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player.Draw();
		enemy.Draw();

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

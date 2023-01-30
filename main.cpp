#include <Novice.h>
#include "SceneManager.h"
#include "Camera.h"
#include "Input.h"
#include "Random.h"
#include "Quad.h"

const char kWindowTitle[] = "学籍番号";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

#include "TextureManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SrandFromTime();
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);
	Quad::GetInstance()->Initalize();

	auto input = Input::GetInstance();

	auto scene = SceneManager::GetInstance();
	scene->Initalize(kWindowWidth, kWindowHeight);

	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		
		scene->Update();
		
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(0, 0, 340, 720, 0.0f, BLACK, kFillModeSolid);
		Novice::DrawBox(0 + 940, 0, 340, 720, 0.0f, BLACK, kFillModeSolid);
		scene->Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (input->TriggerKey(DIK_ESCAPE) == true) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

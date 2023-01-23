#include "MainScene.h"
#include <Novice.h>
#include "Input.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "Camera.h"
#include "Player.h"

MainScene::MainScene()
{
	m_player = std::make_unique<Player>();
}

MainScene::~MainScene()
{
}

void MainScene::Initalize()
{
	m_sharedData->camera.position = { 300,360 };
	m_player->Initalize();
}

void MainScene::ChangeScene()
{
	if (Input::GetInstance()->TriggerKey(DIK_T) == true) {
		SceneManager::GetInstance()->Transition<TitleScene>();
		return;
	}
}

void MainScene::Update()
{
	
	m_player->Update();

}

void MainScene::Draw()
{
	m_player->Draw();

	Novice::ScreenPrintf(0, 0, "MainScene");
}
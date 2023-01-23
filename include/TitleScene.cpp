#include "TitleScene.h"
#include <Novice.h>
#include "Input.h"
#include "SceneManager.h"
#include "MainScene.h"
#include "Camera.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initalize()
{
	m_sharedData->camera.position = { 300,360 };
}

void TitleScene::ChangeScene()
{
	if (Input::GetInstance()->TriggerKey(DIK_T) == true) {
		SceneManager::GetInstance()->Transition<MainScene>();
		return;
	}
}

void TitleScene::Update()
{
	
}

void TitleScene::Draw()
{


	Novice::ScreenPrintf(0, 0, "TitleScene");
}

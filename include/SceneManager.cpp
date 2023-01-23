#include "SceneManager.h"
#include "TitleScene.h"

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;
	return &instance;
}

void SceneManager::Initalize(int windowWidth, int windowHeight)
{
	m_sceneSharedData = std::make_shared<SceneSharedData>();
	m_sceneSharedData->camera.position = { 300,360 };
	m_sceneSharedData->camera.size = { 600,720 };
	m_sceneSharedData->camera.viewPortLeftTop = { 340.0f, 0.0f };
	m_sceneSharedData->camera.viewPortSize = { 600.0f,720.0f };
	m_sceneSharedData->camera.Initalize(windowWidth, windowHeight);

	Transition<TitleScene>();
}

void SceneManager::Update()
{
	m_currentScene->ChangeScene();
	m_currentScene->Update();
}

void SceneManager::Draw()
{
	m_sceneSharedData->camera.UpdateMatrix();
	m_currentScene->Draw();
}

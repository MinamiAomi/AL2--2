#pragma once
#include <memory>
#include "SceneBase.h"


class SceneManager 
{

private:
	std::unique_ptr<SceneBase> m_currentScene;
	std::shared_ptr<SceneSharedData> m_sceneSharedData;

public:
	static SceneManager* GetInstance();

	std::shared_ptr<SceneSharedData> sceneSharedData() const { return m_sceneSharedData; }

	void Initalize(int windowWidth, int windowHeight);
	void Update();
	void Draw();
	
	template<class NextScene>
	void Transition();

private:
	SceneManager() = default;
	~SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	const SceneManager& operator=(const SceneManager&) = delete;
};

template<class NextScene>
inline void SceneManager::Transition()
{
	m_currentScene.reset(new NextScene);
	m_currentScene->Initalize();
}

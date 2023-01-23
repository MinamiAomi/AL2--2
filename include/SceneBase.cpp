#include "SceneBase.h"
#include "SceneManager.h"

SceneBase::SceneBase() {
	m_sharedData = std::move(SceneManager::GetInstance()->sceneSharedData());
}

#pragma once
#include "SceneBase.h"
#include <memory>

class MainScene :
	public SceneBase
{
private:
	std::unique_ptr<class Player> m_player;

public:
	MainScene();
	~MainScene();

	void Initalize() override;
	void ChangeScene() override;
	void Update() override;
	void Draw() override;
};



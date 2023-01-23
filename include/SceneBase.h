#pragma once
#include <memory>
#include "Camera.h"

struct SceneSharedData
{
	Camera camera;
};

class SceneBase 
{
protected:
	std::shared_ptr<SceneSharedData> m_sharedData = {};

public:
	SceneBase();
	virtual ~SceneBase() {}

	virtual void Initalize() = 0;
	virtual void ChangeScene() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};
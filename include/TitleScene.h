#pragma once
#include "SceneBase.h"


class TitleScene :
    public SceneBase
{
private:


public:
	TitleScene();
	~TitleScene();

	void Initalize() override;
	void ChangeScene() override;
	void Update() override;
	void Draw() override;
};


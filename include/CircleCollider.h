#pragma once
#include "ColliderBase.h"
#include "MyMath.h"

class CircleCollider :
    public ColliderBase
{

public:
	Vector2  center = {};
	float radius = {};

public:
	CircleCollider(class GameObject* owner);
	~CircleCollider();

	virtual bool CheckCollision(ColliderBase* other) override;
	virtual bool CheckCollision(ColliderBase* other, CollisionData& data) override;
};


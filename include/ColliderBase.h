#pragma once

class ColliderBase;
class GameObject;

struct CollisionData
{
	// 衝突したコライダー
	ColliderBase* other = nullptr;
};

class ColliderBase
{
private:
	GameObject* m_owner;

public:
	ColliderBase(GameObject* owner) : m_owner(owner) {}
	virtual ~ColliderBase() {}

	GameObject* owner() { return m_owner; }
	
	virtual bool CheckCollision(ColliderBase* other) = 0;
	virtual bool CheckCollision(ColliderBase* other, CollisionData& data) = 0;
};


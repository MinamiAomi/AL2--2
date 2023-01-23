#pragma once

enum ObjectTag 
{
	kObjectTagPlayer,
	kObjectTagEnemy,
	kObjectTagBullet,
	kObjectTagItem,
	
	kObjectTagNone,

	kObjectTagCount
};

class GameObject
{

private:
	ObjectTag m_tag;


public:
	GameObject(ObjectTag tag = kObjectTagNone) : m_tag(tag) {}
	virtual ~GameObject() {}

	ObjectTag tag() const { return m_tag; }
	
	virtual void OnCollision(class GameObject* other) = 0;
	virtual void Initalize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};


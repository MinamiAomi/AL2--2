#pragma once
#include "BulletBase.h"
#include "MyMath.h"
#include <memory>
#include "Transform.h"

class PlayerBullet :
    public BulletBase
{
protected:
    Transform m_transform;
    Vector2 m_velocity;
    
    std::unique_ptr<class RectCollider> m_collider;

public:
    PlayerBullet();
    virtual ~PlayerBullet();

    virtual void Initalize();
    virtual void Update();
    virtual void Draw();

    virtual void OnCollision(class GameObject* other);
};


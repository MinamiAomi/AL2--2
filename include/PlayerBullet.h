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
    std::unique_ptr<class CircleCollider> m_collider;

    unsigned int m_color = 0x000000FF;

public:
    PlayerBullet();
    virtual ~PlayerBullet();

    void position(const Vector2& pos) { m_transform.position = pos; }
    void rotate(float rot) { m_transform.rotate = rot; }
    void scale(const Vector2& scale) { m_transform.scale = scale; }
    void velocity(const Vector2& vel) { m_velocity = vel; }
    void color(unsigned int color) { color = color; }

    virtual void Initalize();
    virtual void Update();
    virtual void Draw();

    virtual void OnCollision(class GameObject* other);
};


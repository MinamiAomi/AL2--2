#pragma once
#include "GameObject.h"
#include "MyMath.h"
#include <memory>
#include "Transform.h"

class EnemyBase :
    public GameObject
{
protected:
    bool m_isActive = false;
    Transform m_transform;
    std::unique_ptr<class RectCollider> m_collider;

public:
    EnemyBase();
    virtual ~EnemyBase();

    void isActive(bool isActive) { m_isActive = isActive; }
    bool isActive() const { return m_isActive; }
    void position(const Vector2& pos) { m_transform.position = pos; }
    void rotate(float rot) { m_transform.rotate = rot; }
    void scale(const Vector2& scale) { m_transform.scale = scale; }

    void ColliderUpdate();

    virtual void Initalize() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void OnCollision(GameObject* other) = 0;
};


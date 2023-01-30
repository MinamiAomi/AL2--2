#pragma once
#include "GameObject.h"
#include "MyMath.h"
#include <memory>
#include "Transform.h"

class Player :
    public GameObject
{
public:
    static const int kBulletMaxCount = 15;

private:
    Transform m_transform;
    std::unique_ptr<class RectCollider> m_collider;
    Vector2 m_velocity;
    float m_moveSpeed = {};

    std::unique_ptr<class PlayerBullet> m_bullets[kBulletMaxCount] = {};
    int m_bulletCoolTime = 0;

public:
    Player();
    ~Player();

    void Initalize();
    void Update();
    void Draw();

    void OnCollision(GameObject* other);
};


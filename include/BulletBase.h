#pragma once
#include "GameObject.h"
#include "MyMath.h"

class BulletBase :
    public GameObject
{
protected:
    bool m_isActive = false;
    float m_power = 0.0f;

public:
    BulletBase();
    virtual ~BulletBase();

    void isActive(bool isActive) { m_isActive = isActive; }
    bool isActive() const { return m_isActive; }
    void power(float power) { m_power = power; }
    float power() const { return m_power; }

    virtual void Initalize() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

    virtual void OnCollision(class GameObject* other) = 0;
};


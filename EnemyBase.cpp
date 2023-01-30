#include "EnemyBase.h"
#include "RectCollider.h"

EnemyBase::EnemyBase() :
	GameObject(kObjectTagEnemy)
{
	m_collider = std::make_unique<RectCollider>(this);
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::ColliderUpdate()
{
	m_collider->center(m_transform.position);
	m_collider->size = m_transform.scale;
}


#include "PlayerBullet.h"
#include "RectCollider.h"
#include "Quad.h"
#include "Camera.h"
#include "SceneManager.h"

PlayerBullet::PlayerBullet()
{
	m_collider = std::make_unique<RectCollider>(this);
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Initalize()
{
}

void PlayerBullet::Update()
{
	auto& camera = SceneManager::GetInstance()->sceneSharedData()->camera;

	if (m_transform.position.y > camera.ScreenTop() + m_transform.scale.y) {
		m_isActive = false;
	}

	m_transform.position += m_velocity;

	m_collider->center(m_transform.position);
	m_collider->size = m_transform.scale;
}

void PlayerBullet::Draw()
{
	auto& camera = SceneManager::GetInstance()->sceneSharedData()->camera;

	m_transform.UpdateMatrix();
	Quad::GetInstance()->DrawBoxQ(m_transform.world * camera.vpVpMatrix());
}

void PlayerBullet::OnCollision(GameObject* other)
{
	m_isActive = false;
}

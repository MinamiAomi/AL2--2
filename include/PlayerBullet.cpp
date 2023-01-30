#include "PlayerBullet.h"
#include "CircleCollider.h"
#include "Quad.h"
#include "Camera.h"
#include "SceneManager.h"
#include <Novice.h>

PlayerBullet::PlayerBullet()
{
	m_collider = std::make_unique<CircleCollider>(this);
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

	m_collider->center = m_transform.position;
	m_collider->radius = Math::Max(m_transform.scale.x, m_transform.scale.y);
}

void PlayerBullet::Draw()
{
	auto& camera = SceneManager::GetInstance()->sceneSharedData()->camera;

	m_transform.UpdateMatrix();
	Vector2 src = m_transform.position * camera.vpVpMatrix();
	int r = Math::Max(m_transform.scale.x, m_transform.scale.y);
	Novice::DrawEllipse((int)src.x, (int)src.y, r, r, m_transform.rotate, m_color, kFillModeSolid);
	//Quad::GetInstance()->DrawBoxQ(m_transform.world * camera.vpVpMatrix());
}

void PlayerBullet::OnCollision(GameObject* other)
{
	m_isActive = false;
}

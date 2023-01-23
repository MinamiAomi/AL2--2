#include "Player.h"
#include "RectCollider.h"
#include "Quad.h"
#include "Camera.h"
#include "Input.h"
#include "SceneManager.h"

Player::Player() :
	GameObject(kObjectTagPlayer)
{
	m_collider = std::make_unique<RectCollider>(this);
}

Player::~Player() 
{
}

void Player::Initalize()
{
	m_transform.position = { 300,150 };
	m_transform.scale = { 100.0f,100.0f };
	m_moveSpeed = 5.0f;
}

void Player::Update()
{
	auto input = Input::GetInstance();
	auto& camera = SceneManager::GetInstance()->sceneSharedData()->camera;

	m_velocity = Vec2Zero;
	if (input->PushKey(DIK_W) == true) {
		m_velocity.y += 1.0f;
	}
	if (input->PushKey(DIK_S) == true) {
		m_velocity.y -= 1.0f;
	}
	if (input->PushKey(DIK_D) == true) {
		m_velocity.x += 1.0f;
	}
	if (input->PushKey(DIK_A) == true) {
		m_velocity.x -= 1.0f;
	}

	if (IsZero(m_velocity) != true) {
		m_transform.position += Normalized(m_velocity) * m_moveSpeed;
	}



	if (m_transform.position.x <= m_transform.scale.x * 0.5f) {
		m_transform.position.x = m_transform.scale.x * 0.5f;
	}
	if (m_transform.position.x >= camera.size.x - m_transform.scale.x * 0.5f) {
		m_transform.position.x = camera.size.x - m_transform.scale.x * 0.5f;
	}

	m_collider->center(m_transform.position);
	m_collider->size = m_transform.scale;
}

void Player::Draw()
{
	auto& camera = SceneManager::GetInstance()->sceneSharedData()->camera;

	m_transform.UpdateMatrix();
	Quad::GetInstance()->DrawBoxQ(m_transform.world * camera.vpVpMatrix());

}

void Player::OnCollision(GameObject* other)
{
}

#include "Player.h"
#include "RectCollider.h"
#include "Quad.h"
#include "Camera.h"
#include "Input.h"
#include "SceneManager.h"
#include "PlayerBullet.h"
#include <Novice.h>

Player::Player() :
	GameObject(kObjectTagPlayer)
{
	m_collider = std::make_unique<RectCollider>(this);
	for (auto& it : m_bullets) {
		it = std::make_unique<PlayerBullet>();
	}
}

Player::~Player() 
{
}

void Player::Initalize()
{
	m_transform.position = { 300,150 };
	m_transform.scale = { 30.0f,30.0f };
	m_moveSpeed = 5.0f;
	for (auto& it : m_bullets) {
		it->Initalize();
	}
	m_bulletCoolTime = 0;
}

void Player::Update()
{
	auto input = Input::GetInstance();
	auto& camera = SceneManager::GetInstance()->sceneSharedData()->camera;

	if (m_bulletCoolTime > 0) {
		m_bulletCoolTime--;
	}

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

	if (m_transform.position.y <= m_transform.scale.y * 0.5f) {
		m_transform.position.y = m_transform.scale.y * 0.5f;
	}
	if (m_transform.position.y >= camera.size.y - m_transform.scale.y * 0.5f) {
		m_transform.position.y = camera.size.y - m_transform.scale.y * 0.5f;
	}


	
	if (m_bulletCoolTime == 0 && input->PushKey(DIK_SPACE) == true) {
		int i = 1;
		for (auto& it : m_bullets) {
			if (it->isActive() == false) {
				it->position(m_transform.position + Vector2(0, m_transform.scale.y * 0.5f));
				it->rotate(0.0f);
				it->scale({ 5,5 });
				it->power(5);
				it->isActive(true);
				m_bulletCoolTime = 10;
				static const Vector2 tmpvel = Vec2UnitY * 15.0f;
				static const float diffAngle = Math::ToRadians(10.0f);
				static const int kFireBulletCount = 3;
				int j = (i >> 1) * ((i & 1) ? 1 : -1);
				it->velocity(Rotated(tmpvel, diffAngle * j));
				if (i == kFireBulletCount) {
					break;
				}
				i++;
			}
		}
	}

	for (auto& it : m_bullets) {
		if (it->isActive() == true) {
			it->Update();
		}
	}


	m_collider->center(m_transform.position);
	m_collider->size = m_transform.scale;
}

void Player::Draw()
{
	auto& camera = SceneManager::GetInstance()->sceneSharedData()->camera;
	m_transform.UpdateMatrix();

	int i = 0;
	for (auto& it : m_bullets) {
		if (it->isActive() == true) {
			it->Draw();
			i++;
		}
	}
	Novice::ScreenPrintf(0, 20, "%d", i);
	
	Quad::GetInstance()->DrawBoxQ(m_transform.world * camera.vpVpMatrix(),0x000000FF);

}

void Player::OnCollision(GameObject* other)
{
}

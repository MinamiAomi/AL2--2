#pragma once
#include "ColliderBase.h"
#include "MyMath.h"

class RectCollider :
	public ColliderBase
{

public:
	// ç∂è„ç¿ïW
	Vector2 position = {};
	// ëÂÇ´Ç≥
	Vector2 size = {};

public:
	RectCollider(class GameObject* owner);
	virtual ~RectCollider();

	inline void center(const Vector2& center) {
		position.x = center.x - size.x * 0.5f; 
		position.y = center.y + size.y * 0.5f;
	}
	inline Vector2 center() const {
		return { position.x + size.x * 0.5f, position.y - size.y * 0.5f };
	}

	inline void left(float left) { position.x = left; }
	inline float left() const { return position.x; }
	inline void top(float top) { position.y = top; }
	inline float top() const { return position.y; }
	inline void right(float right) { position.x = right - size.x; }
	inline float right() const { return position.x + size.x; }
	inline void bottom(float bottom) { position.y = bottom + size.y; }
	inline float bottom() const { return position.y - size.y; }

	inline void leftTop(const Vector2& lefttop) { position = lefttop; }
	inline const Vector2& leftTop() const { return position; }
	inline void rightTop(const Vector2& righttop) { right(righttop.x), top(righttop.y); }
	inline Vector2 rightTop() const { return { right(),top() }; }
	inline void leftBottom(const Vector2& leftbottom) { left(leftbottom.x), bottom(leftbottom.y); }
	inline Vector2 leftBottom() const { return { left(),bottom() }; }
	inline void rightBottom(const Vector2& rightbottom) { right(rightbottom.x), bottom(rightbottom.y); }
	inline Vector2 rightBottom() const { return { right(),bottom() }; }

	virtual bool CheckCollision(ColliderBase* other) override;
	virtual bool CheckCollision(ColliderBase* other, CollisionData& data) override;
};


#include "RectCollider.h"
#include "CircleCollider.h"
#include "PrimitiveCollision.h"

RectCollider::RectCollider(GameObject* owner) :
	ColliderBase(owner)
{
}

RectCollider::~RectCollider()
{
}

bool RectCollider::CheckCollision(ColliderBase* other)
{
	if (RectCollider* o = dynamic_cast<RectCollider*>(other)) {
		return PrimitiveCollision::RectToRect(position, size, o->position, o->size);
	}
	else if (CircleCollider* o = dynamic_cast<CircleCollider*>(other)) {
		return PrimitiveCollision::RectToCircle(position, size, o->center, o->radius);
	}

	return false;
}

bool RectCollider::CheckCollision(ColliderBase* other, CollisionData& data)
{
	return false;
}

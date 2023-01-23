#include "CircleCollider.h"
#include "RectCollider.h"
#include "PrimitiveCollision.h"

CircleCollider::CircleCollider(GameObject* owner) : 
	ColliderBase(owner) 
{
}

CircleCollider::~CircleCollider()
{
}

bool CircleCollider::CheckCollision(ColliderBase* other)
{
	if (CircleCollider* o = dynamic_cast<CircleCollider*>(other)) {
		return PrimitiveCollision::CircleToCircle(center, radius, o->center, o->radius);
	}
	else if (RectCollider* o = dynamic_cast<RectCollider*>(other)) {
		return PrimitiveCollision::RectToCircle(o->position, o->size, center, radius);
	}

	return false;
}

bool CircleCollider::CheckCollision(ColliderBase* other, CollisionData& data)
{
	return false;
}

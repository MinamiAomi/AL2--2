#include "PrimitiveCollision.h"

bool PrimitiveCollision::CircleToCircle(const Vector2& c1, float r1, const Vector2& c2, float r2) {
	float dist = LengthSquare(c1 - c2);
	float rad = r1 + r2;
	return dist < rad* rad;
}
bool PrimitiveCollision::RectToRect(const Vector2& lt1, const Vector2& s1, const Vector2& lt2, const Vector2& s2) {
	return lt1.x < lt2.x + s2.x &&
		lt1.x + s1.x > lt2.x &&
		lt1.y > lt2.y - s2.y &&
		lt1.y - s1.y < lt2.y;
}
bool PrimitiveCollision::RectToCircle(const Vector2& lt, const Vector2& s, const Vector2& c1, float r1) {
	Vector2 closestPoint;
	closestPoint.x = Math::Max(Math::Min(c1.x, lt.x + s.x), lt.x);
	closestPoint.y = Math::Min(Math::Max(c1.y, lt.y - s.y), lt.y);
	float dist = LengthSquare(c1 - closestPoint);
	return dist < r1* r1;
}
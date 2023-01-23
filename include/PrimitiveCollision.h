#pragma once
#include "MyMath.h"

/// <summary>
/// 図形の当たり判定
/// </summary>
namespace PrimitiveCollision{
	/// <summary>
	/// 円と円の当たり判定
	/// </summary>
	/// <param name="c1">円１の中心点</param>
	/// <param name="r1">円１の半径</param>
	/// <param name="c2">円２の中心点</param>
	/// <param name="r2">円２の半径</param>
	/// <returns></returns>
	bool CircleToCircle(const Vector2& c1, float r1, const Vector2& c2, float r2);
	/// <summary>
	/// 矩形と矩形の当たり判定判定
	/// </summary>
	/// <param name="lt1">矩形１の左上座標</param>
	/// <param name="s1">矩形１の大きさ</param>
	/// <param name="lt2">矩形２の左側</param>
	/// <param name="s2">矩形２の大きさ</param>
	/// <returns></returns>
	bool RectToRect(const Vector2& lt1, const Vector2& s1, const Vector2& lt2, const Vector2& s2);
	/// <summary>
	/// 矩形と円の当たり判定
	/// </summary>
	/// <param name="lt">矩形の左上座標</param>
	/// <param name="s">矩形の大きさ</param>
	/// <param name="c1">円の中心点</param>
	/// <param name="r1">円の半径</param>
	/// <returns></returns>
	bool RectToCircle(const Vector2& lt, const Vector2& s, const Vector2& c1, float r1);

};
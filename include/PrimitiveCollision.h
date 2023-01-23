#pragma once
#include "MyMath.h"

/// <summary>
/// �}�`�̓����蔻��
/// </summary>
namespace PrimitiveCollision{
	/// <summary>
	/// �~�Ɖ~�̓����蔻��
	/// </summary>
	/// <param name="c1">�~�P�̒��S�_</param>
	/// <param name="r1">�~�P�̔��a</param>
	/// <param name="c2">�~�Q�̒��S�_</param>
	/// <param name="r2">�~�Q�̔��a</param>
	/// <returns></returns>
	bool CircleToCircle(const Vector2& c1, float r1, const Vector2& c2, float r2);
	/// <summary>
	/// ��`�Ƌ�`�̓����蔻�蔻��
	/// </summary>
	/// <param name="lt1">��`�P�̍�����W</param>
	/// <param name="s1">��`�P�̑傫��</param>
	/// <param name="lt2">��`�Q�̍���</param>
	/// <param name="s2">��`�Q�̑傫��</param>
	/// <returns></returns>
	bool RectToRect(const Vector2& lt1, const Vector2& s1, const Vector2& lt2, const Vector2& s2);
	/// <summary>
	/// ��`�Ɖ~�̓����蔻��
	/// </summary>
	/// <param name="lt">��`�̍�����W</param>
	/// <param name="s">��`�̑傫��</param>
	/// <param name="c1">�~�̒��S�_</param>
	/// <param name="r1">�~�̔��a</param>
	/// <returns></returns>
	bool RectToCircle(const Vector2& lt, const Vector2& s, const Vector2& c1, float r1);

};
#pragma once
#include "MyMath.h"
#include <array>

class Quad 
{
public:
	static constexpr int kVertexCount = 4;
private:
	std::array<Vector2, kVertexCount> m_vertices;


public:
	static Quad* GetInstance();

	void Initalize();
	
	const std::array<Vector2, kVertexCount>& vertices() const { return m_vertices; }
	std::array<Vector2, kVertexCount> vertices(const Matrix33& mat);

	Vector2 LeftTop(const Matrix33& mat) const { return m_vertices[0] * mat; }
	Vector2 RightTop(const Matrix33& mat) const { return m_vertices[1] * mat; }
	Vector2 LeftBottom(const Matrix33& mat) const { return m_vertices[2] * mat; }
	Vector2 RightBottom(const Matrix33& mat) const { return m_vertices[3] * mat; }

	void DrawBoxT(const Matrix33& mat, unsigned int color = 0xFFFFFFFF);
	void DrawBoxQ(const Matrix33& mat, unsigned int color = 0xFFFFFFFF);
	void DrawTexture(const Matrix33& mat, int x, int y, int w, int h, int handle, unsigned int color = 0xFFFFFFFF);
};

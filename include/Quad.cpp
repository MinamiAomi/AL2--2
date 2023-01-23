#include "Quad.h"
#include "Novice.h"

Quad* Quad::GetInstance() {
	static Quad instance;
	return &instance;
}

void Quad::Initalize()
{
	m_vertices[0] = { -0.5f,  0.5f };
	m_vertices[1] = {  0.5f,  0.5f };
	m_vertices[2] = { -0.5f, -0.5f };
	m_vertices[3] = {  0.5f, -0.5f };
}

std::array<Vector2, Quad::kVertexCount> Quad::vertices(const Matrix33& mat)
{
	std::array<Vector2, kVertexCount> result;
	for (int i = 0; i < kVertexCount; i++) {
		result[i] = m_vertices[i] * mat;
	}
	return result;
}

void Quad::DrawBoxT(const Matrix33& mat, unsigned int color)
{
	std::array<Vector2, kVertexCount> result;
	for (int i = 0; i < kVertexCount; i++) {
		result[i] = m_vertices[i] * mat;
	}
	Novice::DrawTriangle(
		(int)result[0].x, (int)result[0].y, (int)result[1].x, (int)result[1].y,
		(int)result[2].x, (int)result[2].y, color, kFillModeSolid);
	Novice::DrawTriangle(
		(int)result[1].x, (int)result[1].y, (int)result[2].x, (int)result[2].y,
		(int)result[3].x, (int)result[3].y, color, kFillModeSolid);
}

void Quad::DrawBoxQ(const Matrix33& mat, unsigned int color)
{
	std::array<Vector2, kVertexCount> result;
	for (int i = 0; i < kVertexCount; i++) {
		result[i] = m_vertices[i] * mat;
	}
	Novice::DrawQuad(
		(int)result[0].x, (int)result[0].y, (int)result[1].x, (int)result[1].y,
		(int)result[2].x, (int)result[2].y, (int)result[3].x, (int)result[3].y,
		0, 0, 256, 256, 0, color);
}

void Quad::DrawTexture(const Matrix33& mat, int x, int y, int w, int h, int handle, unsigned int color)
{
	std::array<Vector2, kVertexCount> result;
	for (int i = 0; i < kVertexCount; i++) {
		result[i] = m_vertices[i] * mat;
	}
	Novice::DrawQuad(
		(int)result[0].x, (int)result[0].y, (int)result[1].x, (int)result[1].y,
		(int)result[2].x, (int)result[2].y,	(int)result[3].x, (int)result[3].y,
		x, y, w, h, handle, color);
}

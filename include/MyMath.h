#pragma once
#include "Vector2Math.h"
#include "Matrix33.h"
#include <math.h>
#include <array>

namespace Math
{

	constexpr float Pi = 3.14159265359f;
	constexpr float TwoPi = 2.0f * Pi;


	/// <summary>
	/// 弧度法変換
	/// </summary>
	/// <param name="degrees">度数法</param>
	/// <returns>弧度法</returns>
	constexpr inline float ToRadians(float degrees) {
		return degrees * Pi / 180.0f;
	}
	/// <summary>
	/// 度数法変換
	/// </summary>
	/// <param name="radians">弧度法</param>
	/// <returns>度数法</returns>
	constexpr inline float ToDegrees(float radians) {
		return radians * 180.0f / Pi;
	}
	/// <summary>
	/// 符号を判断
	/// </summary>
	/// <typeparam name="TYPE">型</typeparam>
	/// <param name="v">値</param>
	/// <returns> 0は0 </returns>
	template <typename TYPE>
	int GetSign(TYPE v) {
		return (v > 0) - (v < 0);
	}
	/// <summary>
	/// 大きいほうを求める
	/// </summary>
	/// <typeparam name="TYPE">型</typeparam>
	/// <param name="v1">値１</param>
	/// <param name="v2">値２</param>
	/// <returns>値１　or　値２</returns>
	template <typename TYPE>
	TYPE Max(const TYPE& v1, const TYPE& v2) {
		return v1 < v2 ? v2 : v1;
	}
	/// <summary>
	/// 小さいほうを求める
	/// </summary>
	/// <typeparam name="TYPE">型</typeparam>
	/// <param name="v1">値１</param>
	/// <param name="v2">値２</param>
	/// <returns>値１　or　値２</returns>
	template <typename TYPE>
	TYPE Min(const TYPE& v1, const TYPE& v2) {
		return v1 < v2 ? v1 : v2;
	}
	/// <summary>
	/// 値を収める
	/// </summary>
	/// <typeparam name="TYPE">型</typeparam>
	/// <param name="value">値</param>
	/// <param name="lower">下限</param>
	/// <param name="upper">上限</param>
	/// <returns></returns>
	template <typename TYPE>
	TYPE Clamp(const TYPE& value, const TYPE& lower, const TYPE& upper) {
		return Min(upper, Max(lower, value));
	}
	/// <summary>
	/// 値をループさせる
	/// </summary>
	/// <param name="value">値</param>
	/// <param name="range">範囲</param>
	/// <param name="min">最小</param>
	/// <returns></returns>
	inline float Loop(float value, float range, float min = 0.0f) {
		if (min < value && value < min + range) return value;
		float x = fmodf(value - min, range);
		if (x < 0) {
			x += range;
		}
		return x + min;
	}
	/// <summary>
	/// 絶対値
	/// </summary>
	/// <param name="value">値</param>
	/// <returns></returns>
	inline float Abs(float value) {
		return fabsf(value);
	}
	/// <summary>
	///	サイン
	/// </summary>
	/// <param name="angle">ラジアン</param>
	/// <returns></returns>
	inline float Sin(float angle) {
		return sinf(angle);
	}
	/// <summary>
	/// コサイン
	/// </summary>
	/// <param name="angle">ラジアン</param>
	/// <returns></returns>
	inline float Cos(float angle) {
		return cosf(angle);
	}
	/// <summary>
	/// タンジェント
	/// </summary>
	/// <param name="angle">ラジアン</param>
	/// <returns></returns>
	inline float Tan(float angle) {
		return tanf(angle);
	}
	/// <summary>
	/// アークサイン
	/// </summary>
	/// <param name="angle">ラジアン</param>
	/// <returns></returns>
	inline float Asin(float angle) {
		return asinf(angle);
	}
	/// <summary>
	/// アークコサイン
	/// </summary>
	/// <param name="angle">ラジアン</param>
	/// <returns></returns>
	inline float Acos(float angle) {
		return acosf(angle);
	}
	/// <summary>
	/// アークタンジェント
	/// </summary>
	/// <param name="y">y成分</param>
	/// <param name="x">x成分</param>
	/// <returns>ラジアン</returns>
	inline float Atan2(float y, float x) {
		return atan2f(y, x);
	}
	/// <summary>
	/// 線形補間
	/// </summary>
	/// <param name="t">変化量</param>
	/// <param name="start">スタート</param>
	/// <param name="end">エンド</param>
	/// <returns></returns>
	inline float Lerp(float t, float start, float end) {
		return start + t * (end - start);
	}
	/// <summary>
	/// 現在範囲から別の範囲に変換
	/// </summary>
	/// <param name="value">値</param>
	/// <param name="start1">現在範囲の最小</param>
	/// <param name="end1">現在範囲の最大</param>
	/// <param name="start2">変換範囲の最小</param>
	/// <param name="end2">変換範囲の最大</param>
	/// <returns></returns>
	inline float Map(float value, float s1, float e1, float s2, float e2) {
		return (value - s1) / (e1 - s1) * (e2 - s2) + s2;
	}
	//inline float Map(float value, float start1, float end1, float start2, float end2) {
	//	return start2 + (end1 - start2) * ((value - start1) / (end2 - start1));
	//}

	inline float InvLerp(float value, float start, float end) {
		return (value - start) / (end - start);
	}

	/// <summary>
	/// 平方根
	/// </summary>
	/// <param name="value">値</param>
	/// <returns></returns>
	inline float Sqrt(float value) {
		return sqrtf(value);
	}
	/// <summary>
	/// float剰余演算
	/// </summary>
	/// <param name="number">割られる数</param>
	/// <param name="denom">割る数</param>
	/// <returns>余り</returns>
	inline float Fmod(float number, float denom) {
		return fmodf(number, denom);
	}
	/// <summary>
	/// 冪乗
	/// </summary>
	/// <param name="base">底</param>
	/// <param name="exponent">指数</param>
	/// <returns></returns>
	inline float Pow(float base, float exponent) {
		return powf(base, exponent);
	}

}

namespace Color {

	static const unsigned int kByteMax = 0xFF;

	inline unsigned int Create(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
		return r << 24 | g << 16 | b << 8 | a;
	}

	unsigned int HsvaToRgba(float h, float s, float v, unsigned int a);

	unsigned int Lerp(float t, unsigned int start, unsigned int end);

	inline std::array<unsigned char, 4> Detach(unsigned int rgba) {
		std::array<unsigned char, 4> result = {
			static_cast<unsigned char>(rgba >> 24),
			static_cast<unsigned char>(rgba >> 16),
			static_cast<unsigned char>(rgba >> 8),
			static_cast<unsigned char>(rgba) };
		return result;
	}


	inline unsigned int Connect(const std::array<unsigned char, 4>& colors) {
		return Create(colors[0], colors[1], colors[2], colors[3]);
	};
}
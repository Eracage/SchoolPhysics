#pragma once
#ifndef VECTOR2_H_EGE2D
#define VECTOR2_H_EGE2D

namespace Ege2d
{
	class Vector2
	{
	public:
		Vector2();
		Vector2(float X, float Y);
		~Vector2();
		
		float getLenght() const;

		float getLenghtPow2() const;

		float getRadians() const;

		float getDegrees() const;


		float x,y;
	};
	
	Vector2 operator -(const Vector2& RightVal);

	Vector2 operator +(const Vector2& LeftVal,const Vector2& RightVal);
	Vector2 operator -(const Vector2& LeftVal,const Vector2& RightVal);

	const Vector2& operator +=(Vector2& LeftVal,const Vector2& RightVal);
	const Vector2& operator -=(Vector2& LeftVal,const Vector2& RightVal);

	Vector2 operator /(const Vector2& LeftVal,const float& RightVal);
	const Vector2& operator /=(Vector2& LeftVal,const float& RightVal);

	bool operator ==(const Vector2& LeftVal,const Vector2& RightVal);
	bool operator !=(const Vector2& LeftVal,const Vector2& RightVal);

	Vector2 operator *(const Vector2& LeftVal, const float& RightVal);
	Vector2 operator *(const float& LeftVal, const Vector2& RightVal);

	const Vector2& operator *=(Vector2& LeftVal, const float& RightVal);
}

#endif
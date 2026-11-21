#pragma once

namespace NovaE {
    struct Vec2 {
		//variables
		float x;
		float y;
		//constructor
		Vec2(float x = 0.0f, float y = 0.0f) : x(x), y(y)
		{
		}
		//operations
		Vec2 operator+(const Vec2& other) const;
		Vec2 operator-(const Vec2& other) const;
		Vec2 operator*(const float scalar) const;
		Vec2 operator/(float scalar) const;
		//usefull functions
		float Length() const;
		float LengthSquared() const;
		//returns what the vector would look like if normalized
		Vec2 Normalized() const;
		//changes the actual vector
		void Normalize();
		float Distance(const Vec2& v) const;

		//holy dot product
		float Dot(const Vec2& other) const;
	};
}
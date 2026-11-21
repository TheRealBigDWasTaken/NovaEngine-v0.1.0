#pragma once

#include "NovaEngine/Math/Vec2.h"

namespace NovaE {
    struct Vec3 {
		//variables
		float x;
		float y;
		float z;
		//constructor
		Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z)
		{ }
		Vec3(const Vec2& xy, float z) :x(xy.x), y(xy.y), z(z)
		{ }
		//operations
		Vec3 operator+(const Vec3& other) const;
		Vec3 operator-(const Vec3& other) const;
		Vec3 operator*(float scalar) const;
		Vec3 operator/(float scalar) const;
		//usefull functions
		float Length() const;
		float LengthSquared() const;

		//returns what the vector would look like if normalized
		Vec3 Normalized() const;
		//changes the actual vector
		void Normalize();

		float Distance(const Vec3& v) const;

		//holy dot product
		float Dot(const Vec3& other) const;

		//Cross product
		Vec3 Cross(const Vec3& other) const;

		//Vec3 Presets

		static const Vec3 Zero;
		static const Vec3 One;

		static const Vec3 Up;
		static const Vec3 Down;

		static const Vec3 Left;
		static const Vec3 Right;

		static const Vec3 Forward;
		static const Vec3 Back;
	};
}
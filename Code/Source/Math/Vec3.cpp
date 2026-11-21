#include "NovaEngine/Math/Vec3.h"
#include <cmath>

namespace NovaE {
    //Vector3
    Vec3 Vec3::operator+(const Vec3& other) const
    {
        return
        {
            x + other.x,
            y + other.y,
            z + other.z
        };
    }
    Vec3 Vec3::operator-(const Vec3& other) const
    {
        return
        {
            x - other.x,
            y - other.y,
            z - other.z
        };
    }
    Vec3 Vec3::operator*(float scalar) const
    {
        return
        {
            x * scalar,
            y * scalar,
            z * scalar
        };
    }
    Vec3 Vec3::operator/(float scalar) const {
        return
        {
            x / scalar,
            y / scalar,
            z / scalar
        };
    };
    float Vec3::Length() const {
        return std::sqrt(x*x + y*y + z*z);
    };
    float Vec3::LengthSquared() const {
        return x * x + y * y + z * z;
    };
    Vec3 Vec3::Normalized() const {
        float l = Length();
        if (l == 0.0f) {
            return Vec3();
        }
        return {
            x / l,
            y / l,
            z / l
        };
    };
    void Vec3::Normalize() {
        float l = Length();
        if (l == 0)
            return;
        this->x /= l;
        this->y /= l;
        this->z /= l;
    }

    float Vec3::Distance(const Vec3& v) const {
        return (*this - v).Length();
    };

    float Vec3::Dot(const Vec3& other) const {
        //x1 * x2 + y1 * y2 + z1 * z2
        return (x * other.x) + (y * other.y) + (z * other.z);
    };

    Vec3 Vec3::Cross(const Vec3& other) const{
        return{
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        };
    }

    //presets

    const Vec3 Vec3::Zero = { 0.0f,  0.0f,  0.0f };
    const Vec3 Vec3::One = { 1.0f,  1.0f,  1.0f };

    const Vec3 Vec3::Up = { 0.0f,  1.0f,  0.0f };
    const Vec3 Vec3::Down = { 0.0f, -1.0f,  0.0f };

    const Vec3 Vec3::Right = { 1.0f,  0.0f,  0.0f };
    const Vec3 Vec3::Left = { -1.0f, 0.0f,  0.0f };

    const Vec3 Vec3::Forward = { 0.0f,  0.0f,  1.0f };
    const Vec3 Vec3::Back = { 0.0f,  0.0f, -1.0f };
}
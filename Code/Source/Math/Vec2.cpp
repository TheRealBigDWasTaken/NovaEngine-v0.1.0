#include "NovaEngine/Math/Vec2.h"
#include <cmath>

namespace NovaE {
    //Vector2
    Vec2 Vec2::operator+(const Vec2& other) const
    {
        return
        {
            x + other.x,
            y + other.y
        };
    }
    Vec2 Vec2::operator-(const Vec2& other) const
    {
        return
        {
            x - other.x,
            y - other.y
        };
    }
    Vec2 Vec2::operator*(float scalar) const
    {
        return
        {
            x * scalar,
            y * scalar
        };
    }
    Vec2 Vec2::operator/(float scalar) const {
        return
        {
            x / scalar,
            y / scalar
        };
    };
    float Vec2::Length() const {
        return sqrt(x*x + y*y);
    };
    float Vec2::LengthSquared() const {
        return x * x + y * y;
    };
    Vec2 Vec2::Normalized() const {
        float l = Length();
        if (l == 0.0f) {
            return Vec2();
        }
        return {
            x / l,
            y / l
        };
    };
    void Vec2::Normalize() {
        float l = Length();
        if (l == 0.0f) {
            return;
        }
        this->x /= l;
        this->y /= l;
    }

    float Vec2::Distance(const Vec2& v) const {
        return (*this - v).Length();
    };

    float Vec2::Dot(const Vec2& other) const {
        //x1 * x2 + y1 * y2
        return (x * other.x) + (y * other.y);
    };
}
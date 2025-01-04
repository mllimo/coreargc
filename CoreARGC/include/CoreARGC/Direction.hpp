#pragma once

#include <raymath.h>

namespace CoreARGC {
    enum class Direction {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    constexpr const Vector2 UP_VECTOR = { 0, -1 };
    constexpr const Vector2 RIGHT_VECTOR = { 1, 0};
    constexpr const Vector2 DOWN_VECTOR = { 0, 1 };
    constexpr const Vector2 LEFT_VECTOR = { -1, 0 };

    Vector2 DirectionToVector(Direction direction);
}
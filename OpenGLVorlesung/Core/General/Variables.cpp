#include "Variables.h"
const float F_ZERO = 0.0f;
const float F_ONE = 1.0f;

void Vertex::Position::operator+=(Position a_pos)
{
    x += a_pos.x;
    y += a_pos.y;
    z += a_pos.z;
}

Vertex::Position Vertex::Position::Zero()
{
    return Position{ F_ZERO, F_ZERO, F_ZERO };
}

Vertex::Position Vertex::Position::Forward()
{
    return Position{ F_ZERO, F_ZERO, F_ONE };
}

Vertex::Color Vertex::Color::Black(void)
{
    return Color{ F_ZERO, F_ZERO, F_ZERO };
}

Vertex::Color Vertex::Color::White(void)
{
    return Color{ F_ONE, F_ONE, F_ONE };
}

Vertex::Color Vertex::Color::Red(void)
{
    return Color{ F_ONE, F_ZERO, F_ZERO };
}

Vertex::Color Vertex::Color::Green(void)
{
    return Color{ F_ZERO, F_ONE, F_ZERO };
}

Vertex::Color Vertex::Color::Blue(void)
{
    return Color{ F_ZERO, F_ZERO, F_ONE };
}

Transform::Position Transform::Position::Zero()
{
    return Position{ F_ZERO, F_ZERO, F_ZERO };
}

Transform::Position Transform::Position::Forward()
{
    return Position{ F_ZERO, F_ZERO, F_ONE };
}

void Transform::Position::operator+=(Position a_pos)
{
    x += a_pos.x;
    y += a_pos.y;
    z += a_pos.z;
}

Transform::Rotation Transform::Rotation::Zero(void)
{
    return Rotation{ F_ZERO, F_ZERO, F_ZERO };
}

Transform::Scale Transform::Scale::One(void)
{
    return Scale{ F_ONE, F_ONE, F_ONE };
}

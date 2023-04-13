#include "Variables.h"

const float F_ZERO = 0.0f;
const float F_ONE = 0.0f;


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

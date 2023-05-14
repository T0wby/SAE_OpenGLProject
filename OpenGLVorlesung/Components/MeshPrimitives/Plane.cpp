#include "Plane.h"

CPlane::CPlane()
{
	SetVertices();
	SetIndices();
}

void CPlane::SetVertices(void)
{
	m_vertices =
	{
		// Top
		Vertex{Vertex::Position{1.0f, 0.0f, 1.0f}, Vertex::Color::Red(),   Vertex::UVCoord{0.0f, 0.0f}}, // 0
		Vertex{Vertex::Position{-1.0f, 0.0f, 1.0f},  Vertex::Color::Green(), Vertex::UVCoord{0.0f, 1.0f}}, // 1
		Vertex{Vertex::Position{1.0f, 0.0f, -1.0f},  Vertex::Color::Blue(),  Vertex::UVCoord{1.0f, 0.0f}}, // 2
		Vertex{Vertex::Position{-1.0f, 0.0f, -1.0f},   Vertex::Color::White(), Vertex::UVCoord{1.0f, 1.0f}}, // 3
	};
}

void CPlane::SetIndices(void)
{
	m_indices =
	{
		// Top
		0, 1, 2,
		2, 1, 3
	};
}

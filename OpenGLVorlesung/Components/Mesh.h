#ifndef MESH_H
#define MESH_H

#include "Component.h"
#include <vector>
#include "../Core/General/Variables.h"

class CMesh : public IComponent
{
public:
	inline CMesh(Transform a_transform) : m_transform(a_transform)
	{
		for (auto&& vertex : m_vertices)
		{
			Vertex vert = Vertex();
			vert.position.x = m_transform.position.x;
			vert.position.y = m_transform.position.y;
			vert.position.z = m_transform.position.z;
			vertex.position += vert.position;
		}
	}

	inline void SetPosition(float a_x, float a_y, float a_z)
	{
		m_transform.position.x = a_x;
		m_transform.position.y = a_y;
		m_transform.position.z = a_z;
	}

	// Engine Loop
	virtual const int Initialize(void) const override;
	virtual const int Update(void) const override;
	virtual void Draw(void) override;
	virtual void Finalize(void) override;

protected: 
	std::vector<Vertex> m_vertices =
	{
		// Front
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Red(),   Vertex::UVCoord{0.0f, 0.0f}}, // 0
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::Green(), Vertex::UVCoord{0.0f, 1.0f}}, // 1
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::Blue(),  Vertex::UVCoord{1.0f, 0.0f}}, // 2
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::White(), Vertex::UVCoord{1.0f, 1.0f}}, // 3
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red(),   Vertex::UVCoord{1.0f, 1.0f}}, // 4

		// Right
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::Red(),   Vertex::UVCoord{0.0f, 0.0f}}, // 5
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Green(), Vertex::UVCoord{0.0f, 1.0f}}, // 6
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::Blue(),  Vertex::UVCoord{1.0f, 0.0f}}, // 7
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::White(), Vertex::UVCoord{1.0f, 1.0f}}, // 8
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red(),   Vertex::UVCoord{1.0f, 1.0f}}, // 9

		// Left
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Red(),   Vertex::UVCoord{0.0f, 0.0f}}, // 10
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Green(), Vertex::UVCoord{0.0f, 1.0f}}, // 11
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::Blue(),  Vertex::UVCoord{1.0f, 0.0f}}, // 12
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::White(), Vertex::UVCoord{1.0f, 1.0f}}, // 13
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red(),   Vertex::UVCoord{1.0f, 1.0f}}, // 14

		// Back
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Red(),   Vertex::UVCoord{0.0f, 0.0f}}, // 15
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Green(), Vertex::UVCoord{0.0f, 1.0f}}, // 16
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::Blue(),  Vertex::UVCoord{1.0f, 0.0f}}, // 17
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::White(), Vertex::UVCoord{1.0f, 1.0f}}, // 18
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red(),   Vertex::UVCoord{1.0f, 1.0f}}, // 19

		// Bottom
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Red(),   Vertex::UVCoord{0.0f, 0.0f}}, // 20
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Green(), Vertex::UVCoord{0.0f, 1.0f}}, // 21
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Blue(),  Vertex::UVCoord{1.0f, 0.0f}}, // 22
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::White(), Vertex::UVCoord{1.0f, 1.0f}}, // 23
	};

	std::vector<unsigned int> m_indices =
	{
		// Front
		0, 1, 2,
		2, 1, 3,
		2, 3, 4,
		// Right
		5, 6, 7,
		7, 6, 8,
		7, 8, 9,
		// Left
		10, 11, 12,
		12, 11, 13,
		12, 13, 14,
		// Back
		15, 16, 17,
		17, 16, 18,
		17, 18, 19,
		// Bottom
		20, 21, 22,
		22, 21, 23
	};

	Transform m_transform{};
};
#endif // !MESH_H




#ifndef MESH_H
#define MESH_H

#include "Component.h"
#include <vector>
#include "../Core/General/Variables.h"

class CMesh : public IComponent
{
public:

	// Engine Loop
	virtual const int Initialize(void) const override;
	virtual const int Update(void) const override;
	virtual void Draw(void) override;
	virtual void Finalize(void) override;

private: 
	std::vector<Vertex> m_vertices =
	{
		// Front
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Red()}, // 0
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::Green()}, // 1
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::Blue()}, // 2
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::White()}, // 3
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red()}, // 4

		// Right
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f}, Vertex::Color::Red()}, // 5
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f},  Vertex::Color::Green()}, // 6
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},  Vertex::Color::Blue()}, // 7
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},   Vertex::Color::White()}, // 8
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red()}, // 9

		// Left
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f}, Vertex::Color::Red()}, // 10
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f},  Vertex::Color::Green()}, // 11
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f},  Vertex::Color::Blue()}, // 12
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},   Vertex::Color::White()}, // 13
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red()}, // 14
		
		// Back
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Red()}, // 15
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},  Vertex::Color::Green()}, // 16
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::Blue()}, // 17
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f},   Vertex::Color::White()}, // 18
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red()}, // 19

		// Bottom
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f}, Vertex::Color::Red()}, // 20
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f},  Vertex::Color::Green()}, // 21
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f},  Vertex::Color::Blue()}, // 22
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},   Vertex::Color::White()}, // 23
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
};
#endif // !MESH_H




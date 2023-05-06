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
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.0f}, Vertex::Color::Red()}, // links-unten
		Vertex{Vertex::Position{0.5f, -0.5f, 0.0f},  Vertex::Color::Green()}, // rechts-unten
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.0f},  Vertex::Color::Blue()}, // oben-links
		Vertex{Vertex::Position{0.5f, 0.5f, 0.0f},   Vertex::Color::White()},
	};

	std::vector<unsigned int> m_indices = 
	{
		0, 1, 2,
		2, 1, 3
	};
};
#endif // !MESH_H




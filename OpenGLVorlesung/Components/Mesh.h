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

protected: 
	std::vector<Vertex> m_vertices{};

	std::vector<unsigned int> m_indices{};
};
#endif // !MESH_H




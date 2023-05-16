#ifndef MESH_H
#define MESH_H

#include "Component.h"
#include "PrimitiveMeshes.h"
#include <vector>
#include "../Core/General/Variables.h"

//TODO: vertices etc shouldn't be set in here but taken on construction instead

class CMesh : public IComponent
{
public:

	inline CMesh(CPrimitiveMeshes* a_meshStruct) 
	{
		m_vertices = a_meshStruct->GetVertices();
		m_indices = a_meshStruct->GetIndices();
	}

	// Engine Loop
	virtual const int Initialize(void) const override;
	virtual int Update(void) override;
	virtual void Draw(void) override;
	virtual void Finalize(void) override;


protected: 
	std::vector<Vertex> m_vertices{	};

	std::vector<unsigned int> m_indices{};
};
#endif // !MESH_H




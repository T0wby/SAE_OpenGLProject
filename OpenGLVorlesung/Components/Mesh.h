#ifndef MESH_H
#define MESH_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Component.h"
#include "PrimitiveMeshes.h"
#include <vector>
#include "../Core/General/Variables.h"


class CMesh : public IComponent
{
public:

	inline CMesh(CPrimitiveMeshes* a_meshStruct) 
	{
		m_vertices = a_meshStruct->GetVertices();
		m_indices = a_meshStruct->GetIndices();
	}

	CMesh(const CMesh&) = default;
	CMesh(CMesh&&) = default;
	CMesh& operator= (const CMesh&) = default;
	CMesh& operator= (CMesh&&) = default;
	virtual ~CMesh() = default;

	// Engine Loop
	virtual int Initialize(void) override;
	virtual int Update(void) override;
	virtual void Draw(void) override;
	virtual void Finalize(void) override;

	unsigned int GetVAO();

protected: 
	std::vector<Vertex> m_vertices{};

	std::vector<unsigned int> m_indices{};

	GLuint m_iVBO {0};
	GLuint m_iVAO {0};
	GLuint m_iEBO {0};
};
#endif // !MESH_H




#ifndef MESH_H
#define MESH_H

#include "Component.h"
#include <vector>

class CMesh : public IComponent
{
public:

	// Engine Loop
	virtual const int Initialize(void) const override;
	virtual const int Update(void) const override;
	virtual void Draw(void) override;
	virtual void Finalize(void) override;

private:
	float m_fVertices[18] =
	{
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.0f,  0.0f, 0.0f, 1.0f,
		 //0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,
		 //0.0f, 1.0f, 0.0f,  1.0f, 0.0f, 1.0f
	};
};
#endif // !MESH_H




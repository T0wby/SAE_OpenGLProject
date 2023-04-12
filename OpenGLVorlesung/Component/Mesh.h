#pragma once
#include "Component.h"
class CMesh : IComponent
{
public:
	// Engine Loop
	virtual const int Intialize(void) const override;
	virtual const int Update(void) const override;
	virtual void Draw(void) const override;
	virtual void Finalize(void) override;
private:
	float m_fVertices[18] =
	{
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // links-unten rot
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // rechts-unten grün
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // mitte-oben blau
	};
};


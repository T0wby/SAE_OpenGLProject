#pragma once
#include "../Mesh.h"
class CPlane : public CMesh
{
public:
	CPlane();
private:
	void SetVertices(void);
	void SetIndices(void);
};


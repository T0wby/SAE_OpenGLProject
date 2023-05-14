#ifndef HOUSE_H
#include "../Mesh.h"
class CHouse : public CMesh
{
public:
	CHouse();
private:
	void SetVertices(void);
	void SetIndices(void);
};
#endif // !HOUSE_H




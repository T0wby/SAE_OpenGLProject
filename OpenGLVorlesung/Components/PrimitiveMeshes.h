#ifndef PRIMITIVEMESHES_H
#define PRIMITIVEMESHES_H
#include <vector>
#include "../Core/General/Variables.h"

class CPrimitiveMeshes
{
public:
	static CPrimitiveMeshes GetPlane();
	static CPrimitiveMeshes GetCube();
	static CPrimitiveMeshes GetHouse();

	auto GetVertices(void) const -> const std::vector<Vertex>;
	auto GetIndices(void) const -> const std::vector<unsigned int>;

	void SetVertices(const std::vector<Vertex>& a_vertices);
	void SetIndices(const std::vector<unsigned int>& a_indices);

private:
	std::vector<Vertex> m_vertices{};
	std::vector<unsigned int> m_indices{};
};

#endif // !PRIMITIVEMESHES_H




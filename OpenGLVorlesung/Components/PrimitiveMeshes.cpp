#include "PrimitiveMeshes.h"
#include <glm/glm.hpp>

//TODO: Calculate all Normals :)

glm::vec3 CalculateFaceNormal(const glm::vec3& v1, const glm::vec3& v2, const glm::vec3& v3)
{
	glm::vec3 edge1 = v2 - v1;
	glm::vec3 edge2 = v3 - v1;

	// Calculate the cross product of the edges to get the face normal
	glm::vec3 normal = glm::cross(edge1, edge2);
	normal = glm::normalize(normal);

	return normal;
}


CPrimitiveMeshes CPrimitiveMeshes::GetPlane()
{
	CPrimitiveMeshes PlaneMesh = CPrimitiveMeshes();

	PlaneMesh.SetVertices({
		// Bottom
		Vertex{Vertex::Position{-0.5f, 0.0f, -0.5f},Vertex::Color::Red(),   Vertex::Normal{0.0f, 0.0f, 1.0f},Vertex::UVCoord{0.0f, 0.0f}}, // 1
		Vertex{Vertex::Position{0.5f, 0.0f, -0.5f}, Vertex::Color::Green(), Vertex::Normal{0.0f, 0.0f, 1.0f},Vertex::UVCoord{0.0f, 1.0f}}, // 2
		Vertex{Vertex::Position{-0.5f, 0.0f, 0.5f}, Vertex::Color::Blue(),  Vertex::Normal{0.0f, 0.0f, 1.0f},Vertex::UVCoord{1.0f, 0.0f}}, // 3
		Vertex{Vertex::Position{0.5f, 0.0f, 0.5f},  Vertex::Color::White(), Vertex::Normal{0.0f, 0.0f, 1.0f},Vertex::UVCoord{1.0f, 1.0f}} // 4
		});

	PlaneMesh.SetIndices({
		// Bottom
		0, 1, 2,
		2, 1, 3
		});

	return PlaneMesh;
}

CPrimitiveMeshes CPrimitiveMeshes::GetCube()
{
	CPrimitiveMeshes CubeMesh = CPrimitiveMeshes();

	CubeMesh.SetVertices({
		// Front
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Red(),  Vertex::Normal{0.0f, 0.0f, 1.0f}, Vertex::UVCoord{0.0f, 0.0f}}, // 0
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::Red(),  Vertex::Normal{0.0f, 0.0f, 1.0f}, Vertex::UVCoord{0.0f, 1.0f}}, // 1
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::Red(),  Vertex::Normal{0.0f, 0.0f, 1.0f}, Vertex::UVCoord{1.0f, 0.0f}}, // 2
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::Red(),  Vertex::Normal{0.0f, 0.0f, 1.0f}, Vertex::UVCoord{1.0f, 1.0f}}, // 3

		// Right
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::Red(), Vertex::Normal{1.0f, 0.0f, 0.0f}, Vertex::UVCoord{0.0f, 0.0f}}, // 4
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Red(), Vertex::Normal{1.0f, 0.0f, 0.0f}, Vertex::UVCoord{0.0f, 1.0f}}, // 5
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::Red(), Vertex::Normal{1.0f, 0.0f, 0.0f}, Vertex::UVCoord{1.0f, 0.0f}}, // 6
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::Red(), Vertex::Normal{1.0f, 0.0f, 0.0f}, Vertex::UVCoord{1.0f, 1.0f}}, // 7

		// Left
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Red(), Vertex::Normal{-1.0f, 0.0f, 0.0f}, Vertex::UVCoord{0.0f, 0.0f}}, // 8
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Red(), Vertex::Normal{-1.0f, 0.0f, 0.0f}, Vertex::UVCoord{0.0f, 1.0f}}, // 9
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::Red(), Vertex::Normal{-1.0f, 0.0f, 0.0f}, Vertex::UVCoord{1.0f, 0.0f}}, // 10
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::Red(), Vertex::Normal{-1.0f, 0.0f, 0.0f}, Vertex::UVCoord{1.0f, 1.0f}}, // 11

		// Back
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Red(), Vertex::Normal{0.0f, 0.0f, -1.0f}, Vertex::UVCoord{0.0f, 0.0f}}, // 12
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Red(), Vertex::Normal{0.0f, 0.0f, -1.0f}, Vertex::UVCoord{0.0f, 1.0f}}, // 13
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::Red(), Vertex::Normal{0.0f, 0.0f, -1.0f}, Vertex::UVCoord{1.0f, 0.0f}}, // 14
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::Red(), Vertex::Normal{0.0f, 0.0f, -1.0f}, Vertex::UVCoord{1.0f, 1.0f}}, // 15

		// Bottom
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Red(), Vertex::Normal{0.0f, -1.0f, 0.0f}, Vertex::UVCoord{0.0f, 0.0f}}, // 16
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Red(), Vertex::Normal{0.0f, -1.0f, 0.0f}, Vertex::UVCoord{0.0f, 1.0f}}, // 17
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Red(), Vertex::Normal{0.0f, -1.0f, 0.0f}, Vertex::UVCoord{1.0f, 0.0f}}, // 18
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::Red(), Vertex::Normal{0.0f, -1.0f, 0.0f}, Vertex::UVCoord{1.0f, 1.0f}}, // 19

		// Top
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::Red(), Vertex::Normal{0.0f, 1.0f, 0.0f},Vertex::UVCoord{0.0f, 0.0f}}, // 20
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::Red(), Vertex::Normal{0.0f, 1.0f, 0.0f},Vertex::UVCoord{0.0f, 1.0f}}, // 21
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::Red(), Vertex::Normal{0.0f, 1.0f, 0.0f},Vertex::UVCoord{1.0f, 0.0f}}, // 22
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::Red(), Vertex::Normal{0.0f, 1.0f, 0.0f},Vertex::UVCoord{1.0f, 1.0f}}  // 23
		});

	CubeMesh.SetIndices({
		// Front
		0, 1, 2,
		2, 1, 3,
		// Right
		4, 5, 6,
		6, 5, 7,
		// Left
		8, 9, 10,
		10, 9, 11,
		// Back
		12, 13, 14,
		14, 13, 15,
		// Bottom
		16, 17, 18,
		18, 17, 19,
		// Top
		20, 21, 22,
		22, 21, 23
		});

	return CubeMesh;
}

CPrimitiveMeshes CPrimitiveMeshes::GetLightCube()
{
	CPrimitiveMeshes CubeMesh = CPrimitiveMeshes();

	CubeMesh.SetVertices({
		// Front
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::White(), Vertex::Normal::Zero(),   Vertex::UVCoord{0.0f, 0.0f}}, // 0
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 1
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(),  Vertex::UVCoord{0.0f, 0.0f}}, // 2
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 3

		// Right
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(),   Vertex::UVCoord{0.0f, 0.0f}}, // 4
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::White(), Vertex::Normal::Zero(),   Vertex::UVCoord{0.0f, 0.0f}}, // 5
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::White(), Vertex::Normal::Zero(),   Vertex::UVCoord{0.0f, 0.0f}}, // 6
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(),   Vertex::UVCoord{0.0f, 0.0f}}, // 7

		// Left
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::White(), Vertex::Normal::Zero(),   Vertex::UVCoord{0.0f, 0.0f}}, // 8
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 9
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::White(), Vertex::Normal::Zero(),  Vertex::UVCoord{0.0f, 0.0f}}, // 10
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 11

		// Back
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::White(), Vertex::Normal::Zero(),   Vertex::UVCoord{0.0f, 0.0f}}, // 12
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 13
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(),  Vertex::UVCoord{0.0f, 0.0f}}, // 14
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 15

		// Bottom
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::White(), Vertex::Normal::Zero(),   Vertex::UVCoord{0.0f, 0.0f}}, // 16
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 17
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::White(), Vertex::Normal::Zero(),  Vertex::UVCoord{0.0f, 0.0f}}, // 18
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 19

		// Top
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(),   Vertex::UVCoord{0.0f, 0.0f}}, // 20
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 21
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::White(), Vertex::Normal::Zero(),  Vertex::UVCoord{0.0f, 0.0f}}, // 22
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}  // 23
		});

	CubeMesh.SetIndices({
		// Front
		0, 1, 2,
		2, 1, 3,
		// Right
		4, 5, 6,
		6, 5, 7,
		// Left
		8, 9, 10,
		10, 9, 11,
		// Back
		12, 13, 14,
		14, 13, 15,
		// Bottom
		16, 17, 18,
		18, 17, 19,
		// Top
		20, 21, 22,
		22, 21, 23
		});

	return CubeMesh;
}

CPrimitiveMeshes CPrimitiveMeshes::GetHouse()
{
	CPrimitiveMeshes HouseMesh = CPrimitiveMeshes();

	HouseMesh.SetVertices({
		// Front
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Red(),   Vertex::Normal{0.0f, 0.0f, 1.0f}, Vertex::UVCoord{0.0f, 0.0f}}, // 0 lu
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::Green(), Vertex::Normal{0.0f, 0.0f, 1.0f}, Vertex::UVCoord{0.0f, 1.0f}}, // 1 ru
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::Blue(),  Vertex::Normal{0.0f, 0.0f, 1.0f}, Vertex::UVCoord{1.0f, 0.0f}}, // 2 lo
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::White(), Vertex::Normal{0.0f, 0.0f, 1.0f}, Vertex::UVCoord{1.0f, 1.0f}}, // 3 ro

		// Right
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::Red(),   Vertex::Normal{1.0f, 0.0f, 0.0f}, Vertex::UVCoord{0.0f, 0.0f}}, // 4
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Green(), Vertex::Normal{1.0f, 0.0f, 0.0f}, Vertex::UVCoord{0.0f, 1.0f}}, // 5
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::Blue(),  Vertex::Normal{1.0f, 0.0f, 0.0f}, Vertex::UVCoord{1.0f, 0.0f}}, // 6
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::White(), Vertex::Normal{1.0f, 0.0f, 0.0f}, Vertex::UVCoord{1.0f, 1.0f}}, // 7

		// Left
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Red(),   Vertex::Normal{-1.0f, 0.0f, 0.0f}, Vertex::UVCoord{0.0f, 0.0f}}, // 8
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Green(), Vertex::Normal{-1.0f, 0.0f, 0.0f}, Vertex::UVCoord{0.0f, 1.0f}}, // 9
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::Blue(),  Vertex::Normal{-1.0f, 0.0f, 0.0f}, Vertex::UVCoord{1.0f, 0.0f}}, // 10
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::White(), Vertex::Normal{-1.0f, 0.0f, 0.0f}, Vertex::UVCoord{1.0f, 1.0f}}, // 11

		// Back
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Red(),   Vertex::Normal{0.0f, 0.0f, -1.0f}, Vertex::UVCoord{0.0f, 0.0f}}, // 12
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Green(), Vertex::Normal{0.0f, 0.0f, -1.0f}, Vertex::UVCoord{0.0f, 1.0f}}, // 13
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::Blue(),  Vertex::Normal{0.0f, 0.0f, -1.0f}, Vertex::UVCoord{1.0f, 0.0f}}, // 14
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::White(), Vertex::Normal{0.0f, 0.0f, -1.0f}, Vertex::UVCoord{1.0f, 1.0f}}, // 15

		// Bottom
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Red(),   Vertex::Normal{0.0f, -1.0f, 0.0f}, Vertex::UVCoord{0.0f, 0.0f}}, // 16
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Green(), Vertex::Normal{0.0f, -1.0f, 0.0f}, Vertex::UVCoord{0.0f, 1.0f}}, // 17
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Blue(),  Vertex::Normal{0.0f, -1.0f, 0.0f}, Vertex::UVCoord{1.0f, 0.0f}}, // 18
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::White(), Vertex::Normal{0.0f, -1.0f, 0.0f}, Vertex::UVCoord{1.0f, 1.0f}}, // 19

		//TriangleFront
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 20 lu
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 21 ru
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 22 mi

		//TriangleRight
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 23 lu
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 24 ru
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 25 mi

		//TriangleLeft
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 26 lu
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 27 ru
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 28 mi

		//TriangleBack
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 29 lu
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 30 ru
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 31 mi

		});

	HouseMesh.SetIndices({
		// Front
		0, 1, 2,
		2, 1, 3,
		// Right
		4, 5, 6,
		6, 5, 7,
		// Left
		8, 9, 10,
		10, 9, 11,
		// Back
		12, 13, 14,
		14, 13, 15,
		// Bottom
		16, 17, 18,
		18, 17, 19,
		// TriFront
		20, 21, 22,
		// TriRight
		23, 24, 25,
		// TriLeft
		26, 27, 28,
		// TriBottom
		29, 30, 31
		});

    return HouseMesh;
}

auto CPrimitiveMeshes::GetVertices(void) const -> const std::vector<Vertex>
{
	return m_vertices;
}

auto CPrimitiveMeshes::GetIndices(void) const -> const std::vector<unsigned int>
{
	return m_indices;
}

void CPrimitiveMeshes::SetVertices(const std::vector<Vertex>& a_vertices)
{
	m_vertices = a_vertices;
}

void CPrimitiveMeshes::SetIndices(const std::vector<unsigned int>& a_indices)
{
	m_indices = a_indices;
}

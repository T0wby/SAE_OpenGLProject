#include "PrimitiveMeshes.h"

CPrimitiveMeshes CPrimitiveMeshes::GetPlane()
{
	CPrimitiveMeshes PlaneMesh = CPrimitiveMeshes();

	PlaneMesh.SetVertices({
		// Bottom
		Vertex{Vertex::Position{-0.5f, 0.0f, -0.5f},Vertex::Color::Red(),   Vertex::Normal::Zero(),Vertex::UVCoord{0.0f, 0.0f}}, // 1
		Vertex{Vertex::Position{0.5f, 0.0f, -0.5f}, Vertex::Color::Green(), Vertex::Normal::Zero(),Vertex::UVCoord{0.0f, 1.0f}}, // 2
		Vertex{Vertex::Position{-0.5f, 0.0f, 0.5f}, Vertex::Color::Blue(),  Vertex::Normal::Zero(),Vertex::UVCoord{1.0f, 0.0f}}, // 3
		Vertex{Vertex::Position{0.5f, 0.0f, 0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(),Vertex::UVCoord{1.0f, 1.0f}} // 4
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
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Red(),   Vertex::Normal::Zero(),   Vertex::UVCoord{0.0f, 0.0f}}, // 0
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::Green(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 1.0f}}, // 1
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::Blue(),  Vertex::Normal::Zero(),  Vertex::UVCoord{1.0f, 0.0f}}, // 2
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 3

		// Right
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::Red(),   Vertex::Normal::Zero(),   Vertex::UVCoord{0.0f, 0.0f}}, // 4
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Green(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 1.0f}}, // 5
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::Blue(),  Vertex::Normal::Zero(),  Vertex::UVCoord{1.0f, 0.0f}}, // 6
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 7

		// Left
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 8
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Green(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 1.0f}}, // 9
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::Blue(),  Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 0.0f}}, // 10
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 11

		// Back
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 12
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Green(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 1.0f}}, // 13
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::Blue(),  Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 0.0f}}, // 14
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 15

		// Bottom
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 16
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Green(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 1.0f}}, // 17
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Blue(),  Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 0.0f}}, // 18
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 19

		// Top
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},Vertex::Color::Red(),     Vertex::Normal::Zero(),Vertex::UVCoord{0.0f, 0.0f}}, // 20
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f}, Vertex::Color::Green(),   Vertex::Normal::Zero(),Vertex::UVCoord{0.0f, 1.0f}}, // 21
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::Blue(),  Vertex::Normal::Zero(),  Vertex::UVCoord{1.0f, 0.0f}}, // 22
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(),Vertex::UVCoord{1.0f, 1.0f}}  // 23
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
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 0
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::Green(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 1.0f}}, // 1
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::Blue(),  Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 0.0f}}, // 2
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 3
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 4

		// Right
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 5
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Green(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 1.0f}}, // 6
		Vertex{Vertex::Position{0.5f, 0.5f, 0.5f},   Vertex::Color::Blue(),  Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 0.0f}}, // 7
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 8
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 9

		// Left
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 10
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Green(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 1.0f}}, // 11
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::Blue(),  Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 0.0f}}, // 12
		Vertex{Vertex::Position{-0.5f, 0.5f, 0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 13
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 14

		// Back
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 15
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Green(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 1.0f}}, // 16
		Vertex{Vertex::Position{0.5f, 0.5f, -0.5f},  Vertex::Color::Blue(),  Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 0.0f}}, // 17
		Vertex{Vertex::Position{-0.5f, 0.5f, -0.5f}, Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 18
		Vertex{Vertex::Position{0.0f, 1.0f, 0.0f},   Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 19

		// Bottom
		Vertex{Vertex::Position{-0.5f, -0.5f, -0.5f},Vertex::Color::Red(),   Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 0.0f}}, // 20
		Vertex{Vertex::Position{0.5f, -0.5f, -0.5f}, Vertex::Color::Green(), Vertex::Normal::Zero(), Vertex::UVCoord{0.0f, 1.0f}}, // 21
		Vertex{Vertex::Position{-0.5f, -0.5f, 0.5f}, Vertex::Color::Blue(),  Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 0.0f}}, // 22
		Vertex{Vertex::Position{0.5f, -0.5f, 0.5f},  Vertex::Color::White(), Vertex::Normal::Zero(), Vertex::UVCoord{1.0f, 1.0f}}, // 23
		});

	HouseMesh.SetIndices({
		// Front
		0, 1, 2,
		2, 1, 3,
		2, 3, 4,
		// Right
		5, 6, 7,
		7, 6, 8,
		7, 8, 9,
		// Left
		10, 11, 12,
		12, 11, 13,
		12, 13, 14,
		// Back
		15, 16, 17,
		17, 16, 18,
		17, 18, 19,
		// Bottom
		20, 21, 22,
		22, 21, 23
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

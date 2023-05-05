#include "Mesh.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

constexpr GLsizei I_VERTEX_SIZE = 6 * sizeof(float);
constexpr GLsizei I_VERT_ELEM_SIZE = 3 * sizeof(float);
const int I_DEFAULT = 0;
const GLsizei I_BUF_NUMB = 1;
const GLint I_FIRST_IDX = 0;
const GLint I_SECOND_IDX = 1;
const GLint I_VERTEX_COUNT = 3;

unsigned int I_VERTEX_BUFFER = 0; // Iterator

const int CMesh::Initialize(void) const
{
	// Generating VertexArray
	glGenVertexArrays(I_BUF_NUMB, &I_VERTEX_BUFFER);
	// Bind VertexArray to system
	glBindVertexArray(I_VERTEX_BUFFER);

	// Generate Buffer and define it
	glGenBuffers(I_BUF_NUMB, &I_VERTEX_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, I_VERTEX_BUFFER);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_fVertices), m_fVertices, GL_STATIC_DRAW);
	// Defining how we go through the Data(Start at 0, got 4 Vertices, Data in Float, not normalized, One data set contains 6 floats in Pos and Color, void pointer)
	glVertexAttribPointer(I_FIRST_IDX, I_VERTEX_COUNT, GL_FLOAT, GL_FALSE, I_VERTEX_SIZE, (void*)I_DEFAULT);
	glEnableVertexAttribArray(I_FIRST_IDX);
	glVertexAttribPointer(I_SECOND_IDX, I_VERTEX_COUNT, GL_FLOAT, GL_FALSE, I_VERTEX_SIZE, (void*)I_VERT_ELEM_SIZE);
	glEnableVertexAttribArray(I_SECOND_IDX);

	return 0;
}

const int CMesh::Update(void) const
{
	return 0;
}

void CMesh::Draw(void)
{
	glBindVertexArray(I_VERTEX_BUFFER); // Data from Buffer to OpenGL
	glDrawArrays(GL_TRIANGLES, I_FIRST_IDX, I_VERTEX_COUNT); // Updating Viewport
}

void CMesh::Finalize(void)
{
}

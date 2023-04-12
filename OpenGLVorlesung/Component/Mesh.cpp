#include "Mesh.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

constexpr GLsizei I_VERTEX_SIZE = 6 * sizeof(float); // Variablen pro Vertex
constexpr GLsizei I_VERT_ELEM_SIZE = 3 * sizeof(float);
const int I_DEFAULT = 0;
const GLsizei I_BUF_NUMB = 1;
const GLint I_FIRST_IDX = 0;
const GLint I_SECOND_IDX = 1;
const GLint I_VERT_NUMB = 3; // Anzahl der Vertices

unsigned I_VERTEX_BUFFER = 0;

const int CMesh::Intialize(void) const
{
	glGenVertexArrays(I_BUF_NUMB, &I_VERTEX_BUFFER);
	glBindVertexArray(I_VERTEX_BUFFER);

	glGenBuffers(I_BUF_NUMB, &I_VERTEX_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, I_VERTEX_BUFFER);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_fVertices), m_fVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(I_FIRST_IDX, I_VERT_NUMB, GL_FLOAT, GL_FALSE, I_VERTEX_SIZE, (void*)I_DEFAULT);
	glEnableVertexAttribArray(I_FIRST_IDX);
	glVertexAttribPointer(I_SECOND_IDX, I_VERT_NUMB, GL_FLOAT, GL_FALSE, I_VERTEX_SIZE, (void*)I_VERT_ELEM_SIZE);
	glEnableVertexAttribArray(I_SECOND_IDX);


	return 0;
}

const int CMesh::Update(void) const
{
	return 0;
}

void CMesh::Draw(void) const
{
	glBindVertexArray(I_VERTEX_BUFFER); // Daten von Buffer an OpenGL
	glDrawArrays(GL_TRIANGLES, I_FIRST_IDX, I_VERT_NUMB); // Update auf Viewport zeichnen
}

void CMesh::Finalize(void)
{
}


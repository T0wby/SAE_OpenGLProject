#include "Mesh.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const int I_DEFAULT = 0;
const GLsizei I_BUF_NUMB = 1;
const GLint I_FIRST_IDX = 0;
const GLint I_SECOND_IDX = 1;
const GLint I_VERTEX_COUNT = 3;

GLuint I_VERTEX_BUFFER = 0; // Iterator
GLuint I_ELEM_BUFFER = 0; // Index Buffer

const int CMesh::Initialize(void) const
{
	// Generating VertexArray
	glGenVertexArrays(I_BUF_NUMB, &I_VERTEX_BUFFER);
	glBindVertexArray(I_VERTEX_BUFFER);

	// Generate VertexBuffer and define it
	glGenBuffers(I_BUF_NUMB, &I_VERTEX_BUFFER); // buf = new Buffer()
	glBindBuffer(GL_ARRAY_BUFFER, I_VERTEX_BUFFER); // _openGL.SetBuffer(buf);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices.front(), GL_STATIC_DRAW); //buf.Initialize(IsArray, _size, ref _vertices, IsStaticDraw);

	// Generate IndexBuffer and define it
	glGenBuffers(I_BUF_NUMB, &I_ELEM_BUFFER);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, I_ELEM_BUFFER);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices[0], GL_STATIC_DRAW);

	// Defining how we go through the Data(Start at 0, got number of Vertices, Data in Float, not normalized, One data set contains 6 floats in Pos and Color, void pointer)
	glVertexAttribPointer(I_FIRST_IDX, I_VERTEX_COUNT, GL_FLOAT, GL_FALSE, Vertex::GetSize(), (void*)I_DEFAULT);
	glEnableVertexAttribArray(I_FIRST_IDX);
	glVertexAttribPointer(I_SECOND_IDX, I_VERTEX_COUNT, GL_FLOAT, GL_FALSE, Vertex::GetSize(), (void*)(Vertex::GetElemSize()));
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, I_ELEM_BUFFER);

	glDrawArrays(GL_TRIANGLES, I_FIRST_IDX, I_VERTEX_COUNT); // Updating Viewport
	glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, (void*)0);
}

void CMesh::Finalize(void)
{
}

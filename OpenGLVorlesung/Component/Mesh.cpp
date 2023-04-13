#include "Mesh.h"
#include <../glad/glad.h>
#include <../GLFW/glfw3.h>

//constexpr GLsizei I_VERTEX_SIZE = 6 * sizeof(float); // Variablen pro Vertex
//constexpr GLsizei I_VERT_ELEM_SIZE = 3 * sizeof(float);
const int I_DEFAULT = 0;
const GLsizei I_BUF_NUMB = 1;
const GLint I_FIRST_IDX = 0;
const GLint I_SECOND_IDX = 1;
const GLint I_VERT_NUMB = 3; // Anzahl der Vertices

GLuint I_VERTEX_BUFFER = 0;
GLuint I_ELEM_BUFFER = 0;

const int CMesh::Intialize(void) const
{
	glGenVertexArrays(I_BUF_NUMB, &I_VERTEX_BUFFER);
	glBindVertexArray(I_VERTEX_BUFFER);

	// Vertex-Buffer definieren
	glGenBuffers(I_BUF_NUMB, &I_VERTEX_BUFFER); //Initalize aka buf = new Buffer()
	glBindBuffer(GL_ARRAY_BUFFER, I_VERTEX_BUFFER); // openGL.SetBuffer(buf)
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices.front(), GL_STATIC_DRAW); //buf.Initialize

	// Index-Buffer definieren
	glGenBuffers(I_BUF_NUMB, &I_ELEM_BUFFER);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, I_ELEM_BUFFER);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices.front(), GL_STATIC_DRAW);

	// Iterier-Kopf für jeden Wert
	glVertexAttribPointer(I_FIRST_IDX, I_VERT_NUMB, GL_FLOAT, GL_FALSE, Vertex::GetSize(), (void*)I_DEFAULT);
	glEnableVertexAttribArray(I_FIRST_IDX);

	// Iterier-Kopf für jeden logischen Bereich(Position, Farbe)
	glVertexAttribPointer(I_SECOND_IDX, I_VERT_NUMB, GL_FLOAT, GL_FALSE, Vertex::GetSize(), (void*)(Vertex::GetElemSize()));
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, I_ELEM_BUFFER);

	glDrawArrays(GL_TRIANGLES, I_FIRST_IDX, I_VERT_NUMB); // Update auf Viewport zeichnen
	glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, (void*)0);
}

void CMesh::Finalize(void)
{
}


#include "Mesh.h"


const int I_DEFAULT = 0;
const GLsizei I_BUF_NUMB = 1;
const GLint I_FIRST_IDX = 0; //  position; layout (location = 0) in vertex shade
const GLint I_SECOND_IDX = 1; // color; layout (location = 1) in vertex shade
const GLint I_THIRD_IDX = 2; //  normal; layout (location = 2) in vertex shade
const GLint I_FOURTH_IDX = 3; // uv; layout (location = 3) in vertex shade
const GLint I_VARIABLE_SIZE = 3; // The position/color values have a size of 3 floats and we do not normalize the values.


int CMesh::Initialize(void)
{
	// Generating VertexArray
	glGenVertexArrays(I_BUF_NUMB, &m_iVAO);
	glBindVertexArray(m_iVAO);

	// Generate VertexBuffer and define it
	glGenBuffers(I_BUF_NUMB, &m_iVBO); // buf = new Buffer()
	glBindBuffer(GL_ARRAY_BUFFER, m_iVBO); // _openGL.SetBuffer(buf);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices.front(), GL_STATIC_DRAW); //buf.Initialize(IsArray, _size, ref _vertices, IsStaticDraw);

	// Generate IndexBuffer and define it
	glGenBuffers(I_BUF_NUMB, &m_iEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices[0], GL_STATIC_DRAW);

	// Defining how we go through the Data(Start at 0, size of the variable, Data in Float, not normalized, One data set contains 6 floats in Pos and Color(stride size), Start pos for the stride; 0 for pos 3 for Color)
	glVertexAttribPointer(I_FIRST_IDX, I_VARIABLE_SIZE, GL_FLOAT, GL_FALSE, Vertex::GetSize(), (void*)I_DEFAULT);
	glEnableVertexAttribArray(I_FIRST_IDX);
	glVertexAttribPointer(I_SECOND_IDX, I_VARIABLE_SIZE, GL_FLOAT, GL_FALSE, Vertex::GetSize(), reinterpret_cast<void*>(Vertex::GetElemSize()));
	glEnableVertexAttribArray(I_SECOND_IDX);
	glVertexAttribPointer(I_THIRD_IDX, I_VARIABLE_SIZE, GL_FLOAT, GL_FALSE, Vertex::GetSize(), reinterpret_cast<void*>(Vertex::GetElemSize()));
	glEnableVertexAttribArray(I_THIRD_IDX);
	glVertexAttribPointer(I_FOURTH_IDX, 2, GL_FLOAT, GL_FALSE, Vertex::GetSize(), reinterpret_cast<void*>(Vertex::GetElemSize() * 3));
	glEnableVertexAttribArray(I_FOURTH_IDX);

	return 0;
}

int CMesh::Update(void)
{
	return 0;
}

void CMesh::Draw(void)
{
	//glBindVertexArray(m_iVAO); // Data from Buffer to OpenGL
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iEBO);

	glDrawArrays(GL_TRIANGLES, I_FIRST_IDX, I_VARIABLE_SIZE); // Updating Viewport
	glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, static_cast<void*>(0));
}

void CMesh::Finalize(void)
{
}

unsigned int CMesh::GetVAO()
{
	return m_iVAO;
}

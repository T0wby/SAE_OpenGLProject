#ifndef MATERIAL_H
#define MATERIAL_H

#include "Component.h"

class CMaterial : public IComponent
{
public:
	// Engine Loop
	virtual const int Initialize(void) const override;
	virtual const int Update(void) const override;
	virtual void Draw(void) override;
	virtual void Finalize(void) override;

private:
	const char* m_sVertexShader =
		"#version 330 core\n"
		"layout(location = 0) in vec3 position;\n"
		"layout(location = 1) in vec3 color;\n"
		"out vec3 vertexColor;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(position, 1.0);\n"
		"	vertexColor = color;\n"
		"}\n";
	const char* m_sFragmentShader =
		"#version 330 core\n"
		"out vec4 fragColor;\n"
		"in vec3 vertexColor;\n"
		"void main()\n"
		"{\n"
		"fragColor = vec4(vertexColor, 1.0f);\n"
		"}\n";
};
#endif // !MATERIAL_H




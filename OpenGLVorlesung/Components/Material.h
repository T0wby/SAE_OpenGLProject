#ifndef MATERIAL_H
#define MATERIAL_H

#include "Component.h"
#include <string>

class CMaterial : public IComponent
{
public:
	inline CMaterial(std::string a_sVertexShader, std::string a_sFragmentShader, std::string a_sTextureOne)
		: m_sVertexShader(a_sVertexShader), m_sFragmentShader(a_sFragmentShader), m_sTextureOne(a_sTextureOne) {}
	
	inline CMaterial(std::string a_sVertexShader, std::string a_sFragmentShader, std::string a_sTextureOne, std::string a_sTextureTwo)
		: m_sVertexShader(a_sVertexShader), m_sFragmentShader(a_sFragmentShader), m_sTextureOne(a_sTextureOne), m_sTextureTwo(a_sTextureTwo) {}

	auto GetShaderID(void) const -> const int;
	auto GetShaderProgram(void) const -> const unsigned int;

	// Engine Loop
	virtual const int Initialize(void) const override;
	virtual int Update(void) override;
	virtual void Draw(void) override;
	virtual void Finalize(void) override;

private:
	std::string m_sVertexShader{ "" };
	std::string m_sFragmentShader{ "" };
	std::string m_sTextureOne{ "" };
	std::string m_sTextureTwo{ "" };

	std::string m_sTestVertexShader =
		"#version 330 core\n"
		"layout(location = 0) in vec3 position;\n"
		"layout(location = 1) in vec3 color;\n"
		"out vec3 vertexColor;\n"
		"uniform mat4 camMatrix;\n"
		"void main()\n"
		"{"
		"gl_Position = camMatrix * vec4(position, 1.0);\n"
		"vertexColor = color;\n"
		"}\n";
	std::string m_sTestFragmentShader =
		"#version 330 core\n"
		"out vec4 fragColor;\n"
		"in vec3 vertexColor;\n"
		"void main()"
		"{"
		"fragColor = vec4(vertexColor, 1.0f);\n"
		"}\n";
};
#endif // !MATERIAL_H




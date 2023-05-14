#ifndef SHADER_H
#define SHADER_H

#include <string>

class CShader
{
public:
	inline CShader(std::string a_sVertexShader, std::string a_sFragmentShader)
		: m_sVertexShader(a_sVertexShader), m_sFragmentShader(a_sFragmentShader) {}

	auto GetShaderID(void) const -> const int;
	auto GetShaderProgram(void) const -> const unsigned int;

	void Initialize(void);
	void Draw(void);

private:
	std::string m_sVertexShader{ "" };
	std::string m_sFragmentShader{ "" };
};

#endif // !SHADER_H




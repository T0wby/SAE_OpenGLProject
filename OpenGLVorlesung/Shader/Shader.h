#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>

class CShader
{
public:
	inline CShader(const std::string& a_sVertexShader, const std::string& a_sFragmentShader)
		: m_sVertexShader(a_sVertexShader), m_sFragmentShader(a_sFragmentShader) {}

	auto GetShaderID(void) const -> const int;
	auto GetShaderProgram(void) const -> const unsigned int;
	void SendMat4ToShader(const std::string& a_sName, const glm::mat4& a_mat) const;
	void SendVec3ToShader(const std::string& a_sName, const glm::vec3& a_vec) const;
	void SendFloatToShader(const std::string& a_sName, const float& a_float) const;

	void Initialize(void);
	void Draw(void);

private:
	std::string m_sVertexShader{};
	std::string m_sFragmentShader{};

	GLsizei m_iShaderID{1};
	unsigned int m_iShaderProgram{0};
};

#endif // !SHADER_H




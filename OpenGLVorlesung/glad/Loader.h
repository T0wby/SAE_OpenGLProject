#ifndef LOADER_H
#define LOADER_H
#include <glad/glad.h>

class CLoader
{
public:
	inline CLoader(GLuint a_iWidth, GLuint a_iHeight)
		: m_iWidth(a_iWidth), m_iHeight(a_iHeight) {}

	auto Initialize(void) const->const int;
	auto Finalize(void) const->const int;

private:
	GLuint m_iWidth{ 0 };
	GLuint m_iHeight{ 0 };
};
#endif // !LOADER_H




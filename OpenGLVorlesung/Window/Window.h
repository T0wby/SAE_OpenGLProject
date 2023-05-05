#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <string>
class CWindow
{
public:
	inline CWindow(GLuint a_iWidth, GLuint a_iHeight, std::string a_sTitle)
		: m_iWidth(a_iWidth), m_iHeight(a_iHeight), m_sTitle(a_sTitle) {}

	auto Initialize(void) const->const int;
	auto Update(void) const->const int;
	void Finalize(void);

	auto GetWindowShouldClose(void) const->const bool;
	void UpdateSwapBuffers(void);


private:
	GLuint m_iWidth{ 0 };
	GLuint m_iHeight{ 0 };
	std::string m_sTitle{ "" };
};

#endif // !WINDOW_H

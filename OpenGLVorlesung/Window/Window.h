#ifndef WINDOW_H
#define WINDOW_H

#include <../GLFW/glfw3.h>
#include "../Component/Camera.h"
#include <string>
#include <memory>

class CWindow
{
public:
	inline CWindow(GLuint a_iWidth,GLuint a_iHeight, std::string a_sTitle)
		: m_iWidth(a_iWidth), m_iHeight(a_iHeight), m_sTitle(a_sTitle){}

	void UpdateSwapBuffer(void);
	//void HandleKeys(GLFWwindow* a_pWindow, int a_iKey, int a_iScancode, int a_iAction, int a_iMode);
	auto GetWindowShouldClose(void) const->const bool;

	auto Initialize(void) const->const int;
	auto Update(void) const->const int;
	auto Finalize(void) const->const int;

private:
	GLuint m_iWidth{ 0 };
	GLuint m_iHeight{ 0 };
	std::string m_sTitle{""};

	std::shared_ptr<CCamera> m_pCamera;
};

#endif // !WINDOW_H

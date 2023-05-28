#ifndef WINDOW_H
#define WINDOW_H

#include "../Components/Camera.h"
#include <GLFW/glfw3.h>
#include <string>
#include <memory>

class CWindow
{
public:
	inline CWindow(GLuint a_iWidth, GLuint a_iHeight, std::string a_sTitle, std::shared_ptr<CCamera> a_pCamera)
		: m_iWidth(a_iWidth), m_iHeight(a_iHeight), m_sTitle(a_sTitle) 
	{
		SetCamera(a_pCamera);
	}

	auto Initialize(void) const->const int;
	auto Update(void) const->const int;
	void Finalize(void);

	auto GetWindowShouldClose(void) const->const bool;
	void UpdateSwapBuffers(void);
	void SetWindowShouldClose(bool a_bShouldClose);

	GLFWwindow* GetWindow(void);

private:
	GLuint m_iWidth{ 0 };
	GLuint m_iHeight{ 0 };
	std::string m_sTitle{ "" };

	void SetCamera(const std::shared_ptr<CCamera>& a_pCamera);
};

#endif // !WINDOW_H

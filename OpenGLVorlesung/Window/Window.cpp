#include "Window.h"

const int I_SUCCESS = 0;
const int I_ERR_GLFW_INIT_FAILED = -1;
const int I_ERR_WIN_INIT_FAILED = -2;

GLFWwindow* pWindow = nullptr;

std::shared_ptr<CCamera> pCurrCamera = nullptr;

auto CWindow::Initialize(void) const -> const int
{
	if (!glfwInit()) return I_ERR_GLFW_INIT_FAILED;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	if (pWindow == nullptr) pWindow = glfwCreateWindow(m_iWidth, m_iHeight, m_sTitle.c_str(), nullptr, nullptr);

	if (!pWindow)
	{
		glfwTerminate();
		return I_ERR_WIN_INIT_FAILED;
	}

	glfwMakeContextCurrent(pWindow);

	//glfwSetKeyCallback(pWindow, HandleKeys);
	return I_SUCCESS;
}

auto CWindow::Update(void) const -> const int
{
	glfwPollEvents();
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	return I_SUCCESS;
}

void CWindow::Finalize(void)
{
	glfwTerminate();
}

auto CWindow::GetWindowShouldClose(void) const -> const bool
{
	return glfwWindowShouldClose(pWindow);
}

void CWindow::UpdateSwapBuffers(void)
{
	glfwSwapBuffers(pWindow);
}

void CWindow::SetWindowShouldClose(bool a_bShouldClose)
{
	if (a_bShouldClose)
	{
		glfwSetWindowShouldClose(pWindow, GLFW_TRUE);
	}
	else
	{
		glfwSetWindowShouldClose(pWindow, GLFW_FALSE);
	}
}

GLFWwindow* CWindow::GetWindow(void)
{
	if (pWindow == nullptr) return nullptr;

	return pWindow;
}

void CWindow::SetCamera(std::shared_ptr<CCamera> a_pCamera)
{
	pCurrCamera = a_pCamera;
}


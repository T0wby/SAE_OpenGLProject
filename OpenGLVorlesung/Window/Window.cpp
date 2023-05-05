#include "Window.h"

const int I_SUCCESS = 0;
const int I_ERR_GLFW_INIT_FAILED = -1;
const int I_ERR_WIN_INIT_FAILED = -2;

GLFWwindow* pWindow = nullptr;


void HandleKeys(GLFWwindow* a_pWindow, int a_iKey, int a_iScancode, int a_iAction, int a_iModus)
{
	if (a_iKey == GLFW_KEY_ESCAPE && a_iAction == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(pWindow, GLFW_TRUE);
	}
}

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

	glfwSetKeyCallback(pWindow, HandleKeys);
	return I_SUCCESS;
}

auto CWindow::Update(void) const -> const int
{
	glfwPollEvents();
	glClearColor(1, 0.5, 0.5, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	return I_SUCCESS;
}

auto CWindow::Finalize(void) const -> const int
{
	glfwTerminate();
	return I_SUCCESS;
}

auto CWindow::GetWindowShouldClose(void) const -> const bool
{
	return glfwWindowShouldClose(pWindow);
}

void CWindow::UpdateSwapBuffers(void)
{
	glfwSwapBuffers(pWindow);
}


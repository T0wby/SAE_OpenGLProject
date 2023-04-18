#include "Window.h"

const int I_SUCCESS = 0;
const int I_ERR_GLFW_INIT_FAILED = -1;
const int I_ERR_WIN_INIT_FAILED = -2;

GLFWwindow* pWindow = nullptr;

void CWindow::UpdateSwapBuffer(void)
{
	glfwSwapBuffers(pWindow);
}

void HandleKeys(GLFWwindow* a_pWindow, int a_iKey, int a_iScancode, int a_iAction, int a_iMode)
{
	if (a_iKey == GLFW_KEY_ESCAPE && a_iAction == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(a_pWindow, GLFW_TRUE);
	}
}

auto CWindow::GetWindowShouldClose(void) const -> const bool
{
	return glfwWindowShouldClose(pWindow);
}

auto CWindow::Initialize(void) const -> const int
{
	if (!glfwInit()) return I_ERR_GLFW_INIT_FAILED;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	if (pWindow == nullptr) pWindow = glfwCreateWindow(640, 480, "Real Engine", nullptr, nullptr);

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

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);

	return I_SUCCESS;
}

auto CWindow::Finalize(void) const -> const int
{
	glfwTerminate();
	return I_SUCCESS;
}

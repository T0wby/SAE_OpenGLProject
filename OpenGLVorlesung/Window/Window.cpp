#include "Window.h"

const int I_SUCCESS = 0;
const int I_ERR_GLFW_INIT_FAILED = -1;
const int I_ERR_WIN_INIT_FAILED = -2;

GLFWwindow* pWindow = nullptr;

auto CWindow::Initialize(void) const -> const int
{
	if (!glfwInit()) return I_ERR_GLFW_INIT_FAILED;

	if (pWindow == nullptr) pWindow = glfwCreateWindow(640, 480, "Real Engine", nullptr, nullptr);

	if (!pWindow)
	{
		glfwTerminate();
		return I_ERR_WIN_INIT_FAILED;
	}

	glfwMakeContextCurrent(pWindow);
	return I_SUCCESS;
}

auto CWindow::Run(void) const -> const int
{
	while (!glfwWindowShouldClose(pWindow))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(pWindow);
	}
	return I_SUCCESS;
}

auto CWindow::Finalize(void) const -> const int
{
	glfwTerminate();
	return I_SUCCESS;
}

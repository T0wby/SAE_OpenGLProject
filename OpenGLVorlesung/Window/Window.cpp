#include "Window.h"

const int I_SUCCESS = 0;
const int I_ERR_GLFW_INIT_FAILED = -1;
const int I_ERR_WIN_INIT_FAILED = -2;

GLFWwindow* pWindow = nullptr;

std::shared_ptr<CCamera> pCurrCamera = nullptr;

void HandleKeys(GLFWwindow* a_pWindow, int a_iKey, int a_iScancode, int a_iAction, int a_iModus)
{
	if (a_iAction == GLFW_PRESS || a_iAction == GLFW_REPEAT)
	{
		if (a_iAction == GLFW_PRESS && a_iKey == GLFW_KEY_ESCAPE)
		{
			glfwSetWindowShouldClose(pWindow, GLFW_TRUE);
		}
		if (a_iKey == GLFW_KEY_W || a_iKey == GLFW_KEY_UP)
		{
			pCurrCamera->SetPosition(glm::vec3(0.0f, 0.0f, 1.0f));
		}
		if (a_iKey == GLFW_KEY_A || a_iKey == GLFW_KEY_LEFT)
		{
			pCurrCamera->SetPosition(glm::vec3(1.0f, 0.0f, 0.0f));
		}
		if (a_iKey == GLFW_KEY_S || a_iKey == GLFW_KEY_DOWN)
		{
			pCurrCamera->SetPosition(glm::vec3(0.0f, 0.0f, -1.0f));
		}
		if (a_iKey == GLFW_KEY_D || a_iKey == GLFW_KEY_RIGHT)
		{
			pCurrCamera->SetPosition(glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		if (a_iKey == GLFW_KEY_Q)
		{
			pCurrCamera->SetPosition(glm::vec3(0.0f, -1.0f, 0.0f));
		}
		if (a_iKey == GLFW_KEY_E)
		{
			pCurrCamera->SetPosition(glm::vec3(0.0f, 1.0f, 0.0f));
		}
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
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);
	
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

void CWindow::SetCamera(std::shared_ptr<CCamera> a_pCamera)
{
	pCurrCamera = a_pCamera;
}


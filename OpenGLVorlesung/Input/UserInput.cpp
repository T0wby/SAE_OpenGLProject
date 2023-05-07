#include "UserInput.h"
#include <iostream>

const int I_SUCCESS = 0;
const int I_USERINPUT_INIT_FAILED = -5;

std::shared_ptr<CWindow> pCurrWindow = nullptr;
std::shared_ptr<CCamera> pCCamera = nullptr;

std::function<void(void)> pExitInput = nullptr;
std::function<void(void)> pForwardInput = nullptr;
std::function<void(void)> pBackwardInput = nullptr;
std::function<void(void)> pRightInput = nullptr;
std::function<void(void)> pLeftInput = nullptr;
std::function<void(void)> pUpInput = nullptr;
std::function<void(void)> pDownInput = nullptr;

void HandleKeys(GLFWwindow* a_pWindow, int a_iKey, int a_iScancode, int a_iAction, int a_iMode)
{
	if (a_iAction == GLFW_PRESS || a_iAction == GLFW_REPEAT)
	{
		switch (a_iKey)
		{
		case GLFW_KEY_ESCAPE: pExitInput(); break;

		case GLFW_KEY_W: //nobreak
		case GLFW_KEY_UP: pForwardInput(); break;

		case GLFW_KEY_S: //nobreak
		case GLFW_KEY_DOWN: pBackwardInput(); break;

		case GLFW_KEY_A: //nobreak
		case GLFW_KEY_LEFT: pLeftInput(); break;

		case GLFW_KEY_D: //nobreak
		case GLFW_KEY_RIGHT: pRightInput(); break;

		case GLFW_KEY_Q: //nobreak
		case GLFW_KEY_SPACE: pUpInput(); break;

		case GLFW_KEY_E: //nobreak
		case GLFW_KEY_LEFT_CONTROL: pDownInput(); break;

		default:
			break;
		}
	}
}



auto CUserInput::Initialize(std::shared_ptr<CWindow> a_pWindow, std::shared_ptr<CCamera> a_pCamera) const -> const int
{
	pCCamera = a_pCamera;

	/*if (a_pWindow == nullptr || a_pWindow->GetWindow() == nullptr)
	{
		std::cout << "ERR: UserInput window is nullptr!" << std::endl;
		return I_USERINPUT_INIT_FAILED;
	}*/

	pCurrWindow = a_pWindow;

	SetDefaultInput();

	glfwSetKeyCallback(pCurrWindow->GetWindow(), HandleKeys);
	return I_SUCCESS;
}

auto CUserInput::Update(void) const -> const int
{
	return I_SUCCESS;
}

void CUserInput::Finalize(void)
{
}

#pragma region SetInputMethods

void CUserInput::SetExitInput(std::function<void(void)> a_pExitInput)
{
	pExitInput = a_pExitInput;
}

void CUserInput::SetForwardInput(std::function<void(void)> a_pForwardInput)
{
	pForwardInput = a_pForwardInput;
}

void CUserInput::SetBackwardInput(std::function<void(void)> a_pBackwardInput)
{
	pBackwardInput = a_pBackwardInput;
}

void CUserInput::SetRightInput(std::function<void(void)> a_pRightInput)
{
	pRightInput = a_pRightInput;
}

void CUserInput::SetLeftInput(std::function<void(void)> a_pLeftInput)
{
	pLeftInput = a_pLeftInput;
}

void CUserInput::SetUpInput(std::function<void(void)> a_pUpInput)
{
	pUpInput = a_pUpInput;
}

void CUserInput::SetDownInput(std::function<void(void)> a_pDownInput)
{
	pDownInput = a_pDownInput;
}

void CUserInput::SetDefaultInput(void) const
{
	pExitInput = ([]() { pCurrWindow->SetWindowShouldClose(true); });
	pForwardInput = ([]() { pCCamera->SetPosition(glm::vec3(pCCamera->GetSpeed() * pCCamera->GetOrientation())); });
	pBackwardInput = ([]() { pCCamera->SetPosition(glm::vec3(pCCamera->GetSpeed() * -pCCamera->GetOrientation())); });
	pRightInput = ([]() { pCCamera->SetPosition(glm::vec3(pCCamera->GetSpeed()* glm::normalize(glm::cross(pCCamera->GetOrientation(), pCCamera->GetUp())))); });
	pLeftInput = ([]() { pCCamera->SetPosition(glm::vec3(pCCamera->GetSpeed() * -glm::normalize(glm::cross(pCCamera->GetOrientation(), pCCamera->GetUp())))); });
	pUpInput = ([]() { pCCamera->SetPosition(glm::vec3(pCCamera->GetSpeed() * pCCamera->GetUp())); });
	pDownInput = ([]() { pCCamera->SetPosition(glm::vec3(pCCamera->GetSpeed() * -pCCamera->GetUp())); });
}


#pragma endregion

#include "UserInput.h"
#include <iostream>

const int I_SUCCESS = 0;
const int I_USERINPUT_INIT_FAILED = -5;

std::shared_ptr<CWindow> pCurrWindow = nullptr;
std::shared_ptr<CCamera> pCCamera = nullptr;

// Key Input
std::function<void(void)> pExitInput = nullptr;
std::function<void(void)> pForwardInput = nullptr;
std::function<void(void)> pBackwardInput = nullptr;
std::function<void(void)> pRightInput = nullptr;
std::function<void(void)> pLeftInput = nullptr;
std::function<void(void)> pUpInput = nullptr;
std::function<void(void)> pDownInput = nullptr;

// Mouse Input
float fPitch { 0.0f };
float fYaw { -90.0f };
float fLastPosX { 400.0f };
float fLastPosY { 400.0f };
float fOffsetX { 0.0f };
float fOffsetY { 0.0f };
const float F_SENSE { 0.01f };

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

		case GLFW_KEY_E: //nobreak
		case GLFW_KEY_SPACE: pUpInput(); break;

		case GLFW_KEY_Q: //nobreak
		case GLFW_KEY_LEFT_CONTROL: pDownInput(); break;

		default:
			break;
		}
	}
}

void MouseInput(GLFWwindow* a_pWindow, double a_dXPos, double a_dYPos)
{
	fOffsetX = static_cast<float>(a_dXPos)- fLastPosX;
	fOffsetY = fLastPosY - static_cast<float>(a_dYPos); // reversed since y-coordinates range from bottom to top
	fLastPosX = static_cast<float>(a_dXPos);
	fLastPosY = static_cast<float>(a_dYPos);

	fOffsetX *= F_SENSE;
	fOffsetY *= F_SENSE;

	fYaw += fOffsetX;
	fPitch += fOffsetY;

	if (fPitch > 89.0f)
		fPitch = 89.0f;
	if (fPitch < -89.0f)
		fPitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(fYaw)) * cos(glm::radians(fPitch));
	direction.y = sin(glm::radians(fPitch));
	direction.z = sin(glm::radians(fYaw)) * cos(glm::radians(fPitch));
	pCCamera->CalcOrientation(direction);
}

int CUserInput::Initialize(std::shared_ptr<CWindow> a_pWindow, std::shared_ptr<CCamera> a_pCamera, float& a_fDeltaTime)
{
	m_fDeltaTime = a_fDeltaTime;
	pCCamera = a_pCamera;

	pCurrWindow = a_pWindow;

	SetDefaultInput();

	glfwSetKeyCallback(pCurrWindow->GetWindow(), HandleKeys);
	glfwSetCursorPosCallback(pCurrWindow->GetWindow(), MouseInput);
	return I_SUCCESS;
}

int CUserInput::Update(float& a_fDeltaTime)
{
	m_fDeltaTime = a_fDeltaTime;

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
	pForwardInput = ([this]() { pCCamera->SetPosition(glm::vec3(pCCamera->GetSpeed() * m_fDeltaTime * pCCamera->GetOrientation())); });
	pBackwardInput = ([this]() { pCCamera->SetPosition(glm::vec3(pCCamera->GetSpeed() * m_fDeltaTime * -pCCamera->GetOrientation())); });
	pRightInput = ([this]() { pCCamera->SetPosition(glm::vec3(pCCamera->GetSpeed() * m_fDeltaTime * glm::normalize(glm::cross(pCCamera->GetOrientation(), pCCamera->GetUp())))); });
	pLeftInput = ([this]() { pCCamera->SetPosition(glm::vec3(pCCamera->GetSpeed() * m_fDeltaTime * -glm::normalize(glm::cross(pCCamera->GetOrientation(), pCCamera->GetUp())))); });
	pUpInput = ([this]() { pCCamera->SetPosition(glm::vec3(pCCamera->GetSpeed() * m_fDeltaTime * pCCamera->GetUp())); });
	pDownInput = ([this]() { pCCamera->SetPosition(glm::vec3(pCCamera->GetSpeed() * m_fDeltaTime * -pCCamera->GetUp())); });
}


#pragma endregion

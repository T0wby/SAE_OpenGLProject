#ifndef USERINPUT_H
#define USERINPUT_H

#include "../Window/Window.h"
#include <GLFW/glfw3.h>
#include <functional>
#include "../Components/Camera.h"

class CUserInput
{
public:
	CUserInput() = default;
	CUserInput(const CUserInput&) = default;
	CUserInput(CUserInput&&) = default;
	CUserInput& operator= (const CUserInput&) = default;
	CUserInput& operator= (CUserInput&&) = default;
	~CUserInput() = default;
	
	int Initialize(std::shared_ptr<CWindow> a_pWindow, std::shared_ptr<CCamera> a_pCamera, float& a_fDeltaTime);
	int Update(float& a_fDeltaTime);
	void Finalize(void);

	void SetExitInput(std::function<void(void)> a_pExitInput);
	void SetForwardInput(std::function<void(void)> a_pForwardInput);
	void SetBackwardInput(std::function<void(void)> a_pBackwardInput);
	void SetRightInput(std::function<void(void)> a_pRightInput);
	void SetLeftInput(std::function<void(void)> a_pLeftInput);
	void SetUpInput(std::function<void(void)> a_pUpInput);
	void SetDownInput(std::function<void(void)> a_pDownInput);
	void SetMouseMode(std::function<void(void)> a_pMouseMode);

	void ChangeMouseMode();
private:
	void SetDefaultInput(void);
	void CheckKeys(void);
	float m_fDeltaTime{ 0.0f };
	bool m_bMouseOn {false};

};
#endif // !USERINPUT_H




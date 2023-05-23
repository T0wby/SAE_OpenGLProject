#ifndef USERINPUT_H
#define USERINPUT_H

#include "../Window/Window.h"
#include <GLFW/glfw3.h>
#include <functional>
#include "../Components/Camera.h"

class CUserInput
{
public:
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


private:
	void SetDefaultInput(void) const;
	void CheckKeys(void);
	float m_fDeltaTime{ 0.0f };

};
#endif // !USERINPUT_H




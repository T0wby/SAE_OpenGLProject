#include "Time.h"
#include <GLFW/glfw3.h>


CTime::CTime()
{
	m_fLastFrame = glfwGetTime();
}

void CTime::Update()
{
	m_fCurrentFrame = glfwGetTime();
	m_fDeltaTime = m_fCurrentFrame - m_fLastFrame;
	m_fLastFrame = m_fCurrentFrame;
}
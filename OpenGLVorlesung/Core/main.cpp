#include "../Window/Window.h"
#include <memory>

const int I_SUCCESS = 0;

CWindow* pWindow = nullptr;

int Initialize()
{
	
	return I_SUCCESS;
}

int Run()
{
	
	return I_SUCCESS;
}

void Finalize()
{
	
}

int main(void)
{
	GLFWwindow* pWindow = nullptr;
	auto iErrorMsg = static_cast<int>(0);

	iErrorMsg = Initialize();
	if (iErrorMsg != 0) return iErrorMsg;

	iErrorMsg = Run();
	if (iErrorMsg != 0) return iErrorMsg;

	Finalize();
	
	return I_SUCCESS;
}
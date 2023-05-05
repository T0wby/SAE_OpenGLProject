#include "../Window/Window.h"
#include <memory>

const int I_SUCCESS = 0;

std::unique_ptr<CWindow> pWindow;

int Initialize()
{
	return pWindow->Initialize();
}

int Run()
{
	return pWindow->Run();
}

void Finalize()
{
	pWindow->Finalize();
}

int main(void)
{
	pWindow = std::make_unique<CWindow>();
	auto iErrorMsg = static_cast<int>(0);

	iErrorMsg = Initialize();
	if (iErrorMsg != 0) return iErrorMsg;

	iErrorMsg = Run();
	if (iErrorMsg != 0) return iErrorMsg;

	Finalize();
	
	return I_SUCCESS;
}
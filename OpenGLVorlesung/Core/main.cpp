#include "../glad/Loader.h"
#include "../Window/Window.h"
#include <memory>

const int I_SUCCESS = 0;

std::unique_ptr<CWindow> pWindow = nullptr;
std::unique_ptr<CLoader> pGladLoader = nullptr;

int Initialize()
{
	auto iErrorMsg = static_cast<int>(0);
	pWindow = std::make_unique<CWindow>(640, 480, "SAE_Tobi_Engine");
	pGladLoader = std::make_unique<CLoader>(640, 480);

	iErrorMsg = pWindow->Initialize();
	if (iErrorMsg != 0) return iErrorMsg;

	iErrorMsg = pGladLoader->Initialize();

	return iErrorMsg;
}

int Run()
{
	while (!pWindow->GetWindowShouldClose())
	{
		pWindow->Update();

		pWindow->UpdateSwapBuffers();
	}
	return I_SUCCESS;
}

void Finalize()
{
	pWindow->Finalize();
}

int main(void)
{
	auto iErrorMsg = static_cast<int>(0);

	iErrorMsg = Initialize();
	if (iErrorMsg != 0) return iErrorMsg;

	iErrorMsg = Run();
	if (iErrorMsg != 0) return iErrorMsg;

	Finalize();
	
	return I_SUCCESS;
}
#include "../glad/Loader.h"
#include "System/DataManager.h"
#include "../Window/Window.h"
#include "../Components/Mesh.h"
#include "../Components/Material.h"
#include <memory>

const int I_SUCCESS = 0;

std::unique_ptr<CWindow> pWindow = nullptr;
std::unique_ptr<CLoader> pGladLoader = nullptr;
std::unique_ptr<IComponent> pMaterial = nullptr;
std::unique_ptr<IComponent> pMesh = nullptr;

int Initialize()
{
	auto fileVertex = CDataManager::ReadFile("../../Shader/DefaultVertex.glsl");
	auto fileFragment = CDataManager::ReadFile("../../Shader/DefaultFragment.glsl");

	auto iErrorMsg = static_cast<int>(0);
	pWindow = std::make_unique<CWindow>(640, 480, "SAE_Tobi_Engine");
	pGladLoader = std::make_unique<CLoader>(640, 480);
	pMaterial = std::make_unique<CMaterial>(fileVertex, fileFragment);
	pMesh = std::make_unique<CMesh>();

	iErrorMsg = pWindow->Initialize();
	if (iErrorMsg != 0) return iErrorMsg;

	iErrorMsg = pGladLoader->Initialize();
	if (iErrorMsg != 0) return iErrorMsg;

	iErrorMsg = pMaterial->Initialize();
	if (iErrorMsg != 0) return iErrorMsg;
	
	iErrorMsg = pMesh->Initialize();
	if (iErrorMsg != 0) return iErrorMsg;

	return iErrorMsg;
}

int Run()
{
	while (!pWindow->GetWindowShouldClose())
	{
		pWindow->Update();

		pMaterial->Draw();
		pMesh->Draw();

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
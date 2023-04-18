#include "System/DataManager.h"
#include "../Window/Window.h"
#include "../glad/Loader.h"
#include "../Component/Mesh.h"
#include "../Component/Material.h"
#include "../Component/Camera.h"
#include <memory>
#include <glm.hpp>

const int I_SUCCESS = 0;

std::unique_ptr<CWindow> pWindow = nullptr;
std::unique_ptr<CLoader> pLoader = nullptr;

std::unique_ptr<CCamera> pCamera = nullptr;

std::unique_ptr<CMaterial> pMaterial = nullptr;
std::unique_ptr<CMesh> pMesh = nullptr;

int Initialize()
{
	auto vertexShader = CDataManager::ReadFile("../Resource Files/Shader/DefaultVertex.glsl");
	auto fragmentShader = CDataManager::ReadFile("../Resource Files/Shader/DefaultFragment.glsl");
	pWindow = std::make_unique<CWindow>(640, 480, "Real Engine");
	//pLoader = std::make_unique<CLoader>(640, 480);

	pCamera = std::make_unique<CCamera>(640, 480, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f));
	pMaterial = std::make_unique<CMaterial>(vertexShader, fragmentShader);
	pMesh = std::make_unique<CMesh>();

	return I_SUCCESS;
}

int Run()
{
	
	while (!pWindow->GetWindowShouldClose())
	{
		pWindow->Update();

		pWindow->UpdateSwapBuffer();
	}

	return I_SUCCESS;
}

void Finalize()
{
	if (pWindow != nullptr)
	{
		pWindow->Finalize();
	}
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
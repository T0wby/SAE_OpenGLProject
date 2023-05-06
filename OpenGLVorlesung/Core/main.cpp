#include "../glad/Loader.h"
#include "System/DataManager.h"
#include "../Window/Window.h"
#include "../Components/Camera.h"
#include "../Components/Mesh.h"
#include "../Components/Material.h"
#include <glm/glm.hpp>
#include <memory>

const int I_SUCCESS = 0;
const int I_WIDTH = 640;
const int I_HEIGHT = 640;


// System
std::unique_ptr<CWindow> pWindow = nullptr;
std::unique_ptr<CLoader> pGladLoader = nullptr;

// Components
std::shared_ptr<CCamera> pCamera = nullptr;
std::unique_ptr<CMaterial> pMaterial = nullptr;
std::unique_ptr<IComponent> pMesh = nullptr;

int Initialize()
{
	auto vertexShader = CDataManager::ReadFile("Resource Files/Shader/DefaultVertexShader.glsl");
	auto fragmentShader = CDataManager::ReadFile("Resource Files/Shader/DefaultFragmentShader.glsl");

	auto iErrorMsg = static_cast<int>(0);

	pCamera = std::make_shared<CCamera>(I_WIDTH, I_HEIGHT, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f));

	// System
	pWindow = std::make_unique<CWindow>(I_WIDTH, I_HEIGHT, "SAE_Tobi_Engine", pCamera);
	pGladLoader = std::make_unique<CLoader>(I_WIDTH, I_HEIGHT);

	// Components
	pMaterial = std::make_unique<CMaterial>(vertexShader, fragmentShader);
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

		pCamera->SetCameraData(60.0f, 0.1f, 1000.0f, pMaterial->GetShaderID(), "camMatrix");
		pCamera->Update();

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
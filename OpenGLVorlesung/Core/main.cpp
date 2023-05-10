#include "../glad/Loader.h"
#include "System/DataManager.h"
#include "General/Time.h"
#include "../Window/Window.h"
#include "../Components/Camera.h"
#include "../Input/UserInput.h"
#include "../Components/Mesh.h"
#include "../Components/Material.h"
#include <glm/glm.hpp>
#include <memory>

const int I_SUCCESS = 0;
const int I_WIDTH = 640;
const int I_HEIGHT = 640;


// System
std::shared_ptr<CWindow> pWindow = nullptr;
std::unique_ptr<CLoader> pGladLoader = nullptr;
std::unique_ptr<CTime> pTime = nullptr;

// Components
std::shared_ptr<CCamera> pCamera = nullptr;
std::unique_ptr<CUserInput> pUserInput = nullptr;
std::unique_ptr<CMaterial> pMaterial = nullptr;
std::unique_ptr<CMesh> pMesh = nullptr;

int Initialize()
{
	auto vertexShader = CDataManager::ReadFile("Resource Files/Shader/DefaultVertex.glsl");
	auto fragmentShader = CDataManager::ReadFile("Resource Files/Shader/DefaultFragment.glsl");

	pCamera = std::make_shared<CCamera>(I_WIDTH, I_HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f));

	// System
	pWindow = std::make_shared<CWindow>(I_WIDTH, I_HEIGHT, "SAE_Tobi_Engine", pCamera);
	pGladLoader = std::make_unique<CLoader>(I_WIDTH, I_HEIGHT);
	pUserInput = std::make_unique<CUserInput>();
	pTime = std::make_unique<CTime>();

	// Components
	pMaterial = std::make_unique<CMaterial>(vertexShader, fragmentShader, "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
	pMesh = std::make_unique<CMesh>();

	auto iErrorMsg = pWindow->Initialize();

	iErrorMsg = pGladLoader->Initialize();

	auto deltaTime = pTime->GetDeltaTime();
	iErrorMsg = pUserInput->Initialize(pWindow, pCamera, deltaTime);

	iErrorMsg = pMaterial->Initialize();
	
	iErrorMsg = pMesh->Initialize();

	glEnable(GL_DEPTH_TEST);
	return iErrorMsg;
}

int Run()
{
	float deltaTime{ 0.0f };
	while (!pWindow->GetWindowShouldClose())
	{
		pWindow->Update();
		pTime->Update();
		deltaTime = pTime->GetDeltaTime();

		pUserInput->Update(deltaTime);

		pCamera->SetCameraData(45.0f, 0.1f, 1000.0f, pMaterial->GetShaderProgram(), "camMatrix");
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
	//if (iErrorMsg != 0) return iErrorMsg;

	iErrorMsg = Run();
	//if (iErrorMsg != 0) return iErrorMsg;

	Finalize();
	
	return iErrorMsg;
}
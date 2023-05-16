#include "../glad/Loader.h"
#include "System/DataManager.h"
#include "General/Time.h"
#include "../Window/Window.h"
#include "../Components/Camera.h"
#include "../Input/UserInput.h"
#include "../Components/Mesh.h"
#include "../Shader/Shader.h"
#include "../Shader/Texture.h"
#include "../GameObject/GameObject.h"
#include "../Core/General/DrawData.h"
#include <glm/glm.hpp>
#include <memory>
#include <glm/gtc/type_ptr.hpp>

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

std::shared_ptr<CShader> pDefaultShader = nullptr;
std::unique_ptr<CGameObject> pGameObject = nullptr;
std::unique_ptr<CGameObject> pGameObject2 = nullptr;

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

	auto iErrorMsg = pWindow->Initialize();

	// Components
	pDefaultShader = std::make_shared<CShader>(vertexShader, fragmentShader);
	//pMaterial = std::make_unique<CMaterial>(vertexShader, fragmentShader, "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
	//pMesh = std::make_unique<CMesh>(Transform{ 0.0f, 0.0f, 0.0f });
	//pAmbientMaterial = std::make_unique<CMaterial>(vertexShader, fragmentShader, "Resource Files/Image/DEU_Voerde_COA.svg.png");
	//pAmbientMesh = std::make_unique<CMesh>(Transform{ 0.0f, 1.0f, 0.0f });



	iErrorMsg = pGladLoader->Initialize();

	pGameObject = std::make_unique<CGameObject>(pDefaultShader);
	pGameObject->GetTransform()->m_position = glm::vec3(1.0f, 0.0f, -3.0f);

	pGameObject2 = std::make_unique<CGameObject>(pDefaultShader);

	auto deltaTime = pTime->GetDeltaTime();
	iErrorMsg = pUserInput->Initialize(pWindow, pCamera, deltaTime);


	pDefaultShader->Initialize();
	pGameObject->Initialize();

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

		pCamera->SetCameraData(45.0f, 0.1f, 1000.0f, pDefaultShader->GetShaderProgram(), "camMatrix");
		pCamera->Update();


		pGameObject->Update();
		pGameObject2->GetTransform()->m_rotation = glm::vec3(1.0f + static_cast<float>(glfwGetTime()), static_cast<float>(glfwGetTime()), 0.0f);
		pGameObject2->Update();

		DrawData drawData
		{
			pCamera->GetCamMatrix(),
			pCamera->GetPos()
		};

		pGameObject->Draw(drawData);
		pGameObject2->Draw(drawData);


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
#include "../glad/Loader.h"
#include "System/DataManager.h"
#include "General/Time.h"
#include "../Window/Window.h"
#include "../Components/Camera.h"
#include "../Input/UserInput.h"
#include "../Components/Mesh.h"
#include "../Components/Material.h"
#include "../Shader/Shader.h"
#include "../GameObject/GameObject.h"
#include "../Core/General/DrawData.h"
#include <glm/glm.hpp>
#include <memory>
#include <glm/gtc/type_ptr.hpp>

constexpr int I_SUCCESS = 0;
constexpr int I_WIDTH = 640;
constexpr int I_HEIGHT = 640;

// Light properties
constexpr glm::vec3 V3_LIGHT_AMBIENT = glm::vec3(0.2f, 0.2f, 0.2f);
constexpr glm::vec3 V3_LIGHT_DIFFUSE = glm::vec3(1.0f, 1.0f, 1.0f);
constexpr glm::vec3 V3_LIGHT_SPECULAR = glm::vec3(1.0f, 1.0f, 1.0f);

// System
std::shared_ptr<CWindow> pWindow = nullptr;
std::unique_ptr<CLoader> pGladLoader = nullptr;
std::unique_ptr<CTime> pTime = nullptr;

// Components
std::shared_ptr<CCamera> pCamera = nullptr;
std::unique_ptr<CUserInput> pUserInput = nullptr;

std::shared_ptr<CShader> pDefaultShader = nullptr;
std::shared_ptr<CShader> pPhongShader = nullptr;
std::shared_ptr<CShader> pPhongShader2 = nullptr;
std::shared_ptr<CShader> pLightShader = nullptr;
std::shared_ptr<CMesh> pMesh = nullptr;
std::shared_ptr<CMesh> pMesh2 = nullptr;
std::shared_ptr<CMesh> pMesh3 = nullptr;
std::shared_ptr<CMaterial> pMat = nullptr;
std::shared_ptr<CMaterial> pMatGO2 = nullptr;
std::shared_ptr<CMaterial> pMatLight = nullptr;
std::shared_ptr<CMaterial> pMatDefault = nullptr;
std::unique_ptr<CGameObject> pGameObject = nullptr;
std::unique_ptr<CGameObject> pGameObject2 = nullptr;
std::unique_ptr<CGameObject> pGameObject3 = nullptr;
std::unique_ptr<CGameObject> pLightObject = nullptr;

int Initialize()
{
	// Shader Files
	auto vertexShader = CDataManager::ReadFile("Resource Files/Shader/DefaultVertex.glsl");
	auto fragmentShader = CDataManager::ReadFile("Resource Files/Shader/DefaultFragment.glsl");
	auto vertexPhongShader = CDataManager::ReadFile("Resource Files/Shader/PhongVertex.glsl");
	auto fragmentPhongShader = CDataManager::ReadFile("Resource Files/Shader/PhongFragment.glsl");
	auto vertexLightShader = CDataManager::ReadFile("Resource Files/Shader/LightVertex.glsl");
	auto fragmentLightShader = CDataManager::ReadFile("Resource Files/Shader/LightFragment.glsl");
	pCamera = std::make_shared<CCamera>(I_WIDTH, I_HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f));

	// System
	pWindow = std::make_shared<CWindow>(I_WIDTH, I_HEIGHT, "SAE_Tobi_Engine", pCamera);
	pGladLoader = std::make_unique<CLoader>(I_WIDTH, I_HEIGHT);
	pUserInput = std::make_unique<CUserInput>();
	pTime = std::make_unique<CTime>();

	auto iErrorMsg = pWindow->Initialize();

	// Components
	pDefaultShader = std::make_shared<CShader>(vertexShader, fragmentShader);
	pPhongShader = std::make_shared<CShader>(vertexPhongShader, fragmentPhongShader);
	pPhongShader2 = std::make_shared<CShader>(vertexPhongShader, fragmentPhongShader);
	pLightShader = std::make_shared<CShader>(vertexLightShader, fragmentLightShader);
	pMatDefault = std::make_shared<CMaterial>();
	pMatLight = std::make_shared<CMaterial>();
	*pMatLight = {
		V3_LIGHT_AMBIENT,
		V3_LIGHT_DIFFUSE
	};
	pMat = std::make_shared<CMaterial>();
	*pMat = {
		glm::vec3(1.0f, 0.3f, 0.3f),
		glm::vec3(1.0f, 0.3f, 0.3f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		64.0f
	};
	pMatGO2 = std::make_shared<CMaterial>();
	*pMatGO2 = {
		glm::vec3(0.0f, 1.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.3f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		32.0f
	};

	iErrorMsg = pGladLoader->Initialize();

	// VerticesInformation
	CPrimitiveMeshes house = CPrimitiveMeshes::GetHouse();
	CPrimitiveMeshes cube = CPrimitiveMeshes::GetCube();
	CPrimitiveMeshes plane = CPrimitiveMeshes::GetPlane();
	CPrimitiveMeshes lightCube = CPrimitiveMeshes::GetLightCube();

	// Create Scene Objects
	pGameObject = std::make_unique<CGameObject>(pDefaultShader, &house, pMatDefault, "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
	pGameObject->GetTransform()->m_position = glm::vec3(2.5f, 0.0f, -3.0f);

	pGameObject2 = std::make_unique<CGameObject>(pPhongShader, &cube, pMat, "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
	pGameObject2->GetTransform()->m_position = glm::vec3(0.0f, -1.0f, -4.0f);
	pGameObject3 = std::make_unique<CGameObject>(pPhongShader2, &cube, pMatGO2, "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
	pGameObject3->GetTransform()->m_position = glm::vec3(-2.0f, 0.0f, -7.0f);

	pLightObject = std::make_unique<CGameObject>(pLightShader, &lightCube, pMatLight);
	pLightObject->GetTransform()->m_position = glm::vec3(-0.0f, -1.0f, -4.0f);
	pLightObject->GetTransform()->m_scale = glm::vec3(0.5f, 0.5f, 0.5f);

	auto deltaTime = pTime->GetDeltaTime();
	iErrorMsg = pUserInput->Initialize(pWindow, pCamera, deltaTime);


	pDefaultShader->Initialize();
	pPhongShader->Initialize();
	pPhongShader2->Initialize();
	pLightShader->Initialize();
	pGameObject->Initialize();
	pGameObject2->Initialize();
	pGameObject3->Initialize();
	pLightObject->Initialize();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
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
		pGameObject2->Update();
		pGameObject2->GetTransform()->m_position = glm::vec3(sin(glfwGetTime()) * 0.5f,cos(glfwGetTime()) * 0.5f,  -4.0f);
		pGameObject2->GetTransform()->m_rotation = glm::vec3(1.0f + static_cast<float>(glfwGetTime()), static_cast<float>(glfwGetTime()), 0.0f);
		pGameObject3->Update();
		pLightObject->Update();
		pLightObject->GetTransform()->m_position = pGameObject2->GetTransform()->m_position + glm::vec3(cos(glfwGetTime()) * 2.0f,sin(glfwGetTime()) * 1.5f,  sin(glfwGetTime()) * 1.5f);

		DrawData drawData
		{
			pCamera->GetCamMatrix(),
			pCamera->GetPos(),
			pLightObject->GetTransform()->m_position,
			V3_LIGHT_AMBIENT,
			//V3_LIGHT_DIFFUSE,
			//V3_LIGHT_AMBIENT * glm::vec3(sin(glfwGetTime() * 2.0f), sin(glfwGetTime() * 0.7f), sin(glfwGetTime() * 1.3f)),
			V3_LIGHT_DIFFUSE * glm::vec3(sin(glfwGetTime() * 1.0f), sin(glfwGetTime() * 0.3f), sin(glfwGetTime() * 0.6f)),
			V3_LIGHT_SPECULAR
		};

		pGameObject2->Draw(drawData);
		pGameObject3->Draw(drawData);
		pGameObject->Draw(drawData);
		pLightObject->Draw(drawData);


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
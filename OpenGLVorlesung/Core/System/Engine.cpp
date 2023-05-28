#include "Engine.h"
#include "../../glad/Loader.h"
#include "DataManager.h"
#include "Scene.h"
#include "../General/Time.h"
#include "../../Window/Window.h"
#include "../../Components/Camera.h"
#include "../../Input/UserInput.h"
#include "../../Components/Mesh.h"
#include "../../Components/Material.h"
#include "../../Shader/Shader.h"
#include "../../GameObject/GameObject.h"
#include "../../Core/General/DrawData.h"
#include <glm/glm.hpp>
#include <memory>
#include <glm/gtc/type_ptr.hpp>

constexpr int I_SUCCESS = 0;

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

std::shared_ptr<CShader> pPhongShaderHouse = nullptr;
std::shared_ptr<CShader> pPhongShaderCube = nullptr;
std::shared_ptr<CShader> pPhongShaderCube2 = nullptr;
std::shared_ptr<CShader> pPhongShaderCube3 = nullptr;
std::shared_ptr<CShader> pLightShader = nullptr;

std::shared_ptr<CMaterial> pMatCube = nullptr;
std::shared_ptr<CMaterial> pMatCube2 = nullptr;
std::shared_ptr<CMaterial> pMatCube3 = nullptr;
std::shared_ptr<CMaterial> pMatLight = nullptr;
std::shared_ptr<CMaterial> pMatHouse = nullptr;

std::shared_ptr<CGameObject> pHouseObject = nullptr;
std::shared_ptr<CGameObject> pCubeObject = nullptr;
std::shared_ptr<CGameObject> pCubeObject2 = nullptr;
std::shared_ptr<CGameObject> pCubeObject3 = nullptr;
std::shared_ptr<CGameObject> pLightObject = nullptr;

void CEngine::AddScene(std::shared_ptr<CScene> a_scene)
{
	if (a_scene == nullptr) return;

	m_scenes.push_back(a_scene);
}

void CEngine::RemoveScene(std::shared_ptr<CScene> a_scene)
{
	if (a_scene == nullptr) return;


	for (int i = 0; i < m_scenes.size(); i++)
	{
		if (a_scene == m_scenes[i])
		{
			m_scenes.erase(m_scenes.begin() + i);
			break;
		}
	}
}

int CEngine::Initialize()
{
	CreateScenes();
	CreateSystemPointer();

	auto iErrorMsg = pWindow->Initialize();

	// Create Components that are later used for the game objects
	CreateComponents();

	iErrorMsg = pGladLoader->Initialize();

	// Create and Add all game objects to a scene
	CreateGameObjects();

	auto deltaTime = pTime->GetDeltaTime();
	iErrorMsg = pUserInput->Initialize(pWindow, pCamera, deltaTime);


	pPhongShaderHouse->Initialize();
	pPhongShaderCube->Initialize();
	pPhongShaderCube2->Initialize();
	pPhongShaderCube3->Initialize();
	pLightShader->Initialize();

	InitializeScenes();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
	return iErrorMsg;
}

int CEngine::Run()
{
	float deltaTime{ 0.0f };
	while (!pWindow->GetWindowShouldClose())
	{
		pWindow->Update();
		pTime->Update();
		deltaTime = pTime->GetDeltaTime();

		pUserInput->Update(deltaTime);

		pCamera->SetCameraData(45.0f, 0.1f, 1000.0f, pPhongShaderHouse->GetShaderProgram(), "camMatrix");
		pCamera->Update();


		DrawData drawData
		{
			pCamera->GetCamMatrix(),
			pCamera->GetPos(),
			pLightObject->GetTransform()->m_position,
			V3_LIGHT_AMBIENT,
			//V3_LIGHT_DIFFUSE,
			//V3_LIGHT_AMBIENT * glm::vec3(sin(glfwGetTime() * 2.0f), sin(glfwGetTime() * 0.7f), sin(glfwGetTime() * 1.3f)),
			V3_LIGHT_DIFFUSE * glm::vec3(static_cast<float>(sin(glfwGetTime())), static_cast<float>(sin(glfwGetTime()))* 0.3f, static_cast<float>(sin(glfwGetTime())) * 0.6f),
			V3_LIGHT_SPECULAR
		};

		UpdateScenes(drawData);
		pCubeObject->GetTransform()->m_position = glm::vec3(static_cast<float>(sin(glfwGetTime())) * 0.5f,static_cast<float>(cos(glfwGetTime())) * 0.5f,  -4.0f);
		pCubeObject->GetTransform()->m_rotation = glm::vec3(1.0f + static_cast<float>(glfwGetTime()), static_cast<float>(glfwGetTime()), 0.0f);
		pLightObject->GetTransform()->m_position = pCubeObject->GetTransform()->m_position + glm::vec3(static_cast<float>(cos(glfwGetTime())) * 2.0f,static_cast<float>(sin(glfwGetTime())) * 1.5f,  static_cast<float>(sin(glfwGetTime())) * 1.5f);


		pWindow->UpdateSwapBuffers();
	}
	return I_SUCCESS;
}

void CEngine::Finalize()
{
	pWindow->Finalize();
}

/**
 * \brief Initializes all scenes in the Engine
 */
void CEngine::InitializeScenes()
{
	// for (std::shared_ptr<CScene> scene : m_scenes)
	// {
	// 	scene->Initialize();
	// }
	m_activeScene->Initialize();
}

/**
 * \brief Calls the Update and then the Draw function of all scenes in the Engine.
 * \param a_drawData Data used in the draw of GameObjects
 */
void CEngine::UpdateScenes(const DrawData& a_drawData)
{
	// for (std::shared_ptr<CScene> scene : m_scenes)
	// {
	// 	scene->Update();
	// 	scene->Draw(a_drawData);
	// }
	m_activeScene->Update();
	m_activeScene->Draw(a_drawData);
}

void CEngine::CreateSystemPointer()
{
	pCamera = std::make_shared<CCamera>(m_iWidth, m_iHeight, glm::vec3(0.0f, 3.0f, 7.0f), glm::vec3(0.0f, 0.0f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f));

	// System
	pWindow = std::make_shared<CWindow>(m_iWidth, m_iHeight, "SAE_Tobi_Engine", pCamera);
	pGladLoader = std::make_unique<CLoader>(m_iWidth, m_iHeight);
	pUserInput = std::make_unique<CUserInput>();
	pTime = std::make_unique<CTime>();
}

/**
 * \brief Create a scene and add it to the Engine
 */
void CEngine::CreateScenes()
{
	std::shared_ptr<CScene> pScene = std::make_shared<CScene>();
	m_scenes.push_back(pScene);
	m_activeScene = pScene;
}

/**
 * \brief Create Shader and Components that are later used on GameObjects
 */
void CEngine::CreateComponents()
{
	// Shader
	const auto vertexShader = CDataManager::ReadFile("Resource Files/Shader/DefaultVertex.glsl");
	const auto fragmentShader = CDataManager::ReadFile("Resource Files/Shader/DefaultFragment.glsl");
	const auto vertexPhongShader = CDataManager::ReadFile("Resource Files/Shader/PhongVertex.glsl");
	const auto fragmentPhongShader = CDataManager::ReadFile("Resource Files/Shader/PhongFragment.glsl");
	const auto vertexLightShader = CDataManager::ReadFile("Resource Files/Shader/LightVertex.glsl");
	const auto fragmentLightShader = CDataManager::ReadFile("Resource Files/Shader/LightFragment.glsl");
	
	// Components
	pPhongShaderHouse = std::make_shared<CShader>(vertexPhongShader, fragmentPhongShader);
	pPhongShaderCube = std::make_shared<CShader>(vertexPhongShader, fragmentPhongShader);
	pPhongShaderCube2 = std::make_shared<CShader>(vertexPhongShader, fragmentPhongShader);
	pPhongShaderCube3 = std::make_shared<CShader>(vertexPhongShader, fragmentPhongShader);
	pLightShader = std::make_shared<CShader>(vertexLightShader, fragmentLightShader);

	CreateMaterials();
	
}

/**
 * \brief Create Materials that are later used on GameObjects
 */
void CEngine::CreateMaterials()
{
	pMatHouse = std::make_shared<CMaterial>();
	*pMatHouse = {
		glm::vec3(0.5f, 0.7f, 0.7f),
		glm::vec3(0.5f, 0.7f, 0.7f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		128.0f
	};
	
	pMatLight = std::make_shared<CMaterial>();
	*pMatLight = {
		V3_LIGHT_AMBIENT,
		V3_LIGHT_DIFFUSE
	};
	
	pMatCube = std::make_shared<CMaterial>();
	*pMatCube = {
		glm::vec3(1.0f, 0.3f, 0.3f),
		glm::vec3(1.0f, 0.3f, 0.3f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		64.0f
	};
	
	pMatCube2 = std::make_shared<CMaterial>();
	*pMatCube2 = {
		glm::vec3(0.0f, 1.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.3f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		32.0f
	};
	
	pMatCube3 = std::make_shared<CMaterial>();
	*pMatCube3 = {
		glm::vec3(0.5f, 1.0f, 0.3f),
		glm::vec3(0.5f, 1.0f, 0.3f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		64.0f
	};
}

/**
 * \brief Create Game Objects and add them to the scene.
 */
void CEngine::CreateGameObjects()
{
	// VerticesInformation
	CPrimitiveMeshes house = CPrimitiveMeshes::GetHouse();
	CPrimitiveMeshes cube = CPrimitiveMeshes::GetCube();
	CPrimitiveMeshes plane = CPrimitiveMeshes::GetPlane();
	CPrimitiveMeshes lightCube = CPrimitiveMeshes::GetLightCube();

	// Create Scene Objects
	pHouseObject = std::make_shared<CGameObject>(pPhongShaderHouse, &house, pMatHouse, "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
	pHouseObject->GetTransform()->m_position = glm::vec3(0.0f, 0.0f, 0.0f);

	pCubeObject = std::make_shared<CGameObject>(pPhongShaderCube, &cube, pMatCube, "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
	pCubeObject->GetTransform()->m_position = glm::vec3(0.0f, -1.0f, -4.0f);
	pCubeObject2 = std::make_shared<CGameObject>(pPhongShaderCube2, &cube, pMatCube2, "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
	pCubeObject2->GetTransform()->m_position = glm::vec3(-2.0f, 0.0f, -7.0f);
	pCubeObject3 = std::make_shared<CGameObject>(pPhongShaderCube3, &cube, pMatCube3, "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
	pCubeObject3->GetTransform()->m_position = glm::vec3(0.0f, -3.0f, 0.0f);
	pCubeObject3->GetTransform()->m_scale = glm::vec3(20.0f, 0.01f, 20.0f);

	
	pLightObject = std::make_shared<CGameObject>(pLightShader, &lightCube, pMatLight);
	pLightObject->GetTransform()->m_position = glm::vec3(-0.0f, -1.0f, -4.0f);
	pLightObject->GetTransform()->m_scale = glm::vec3(0.5f, 0.5f, 0.5f);

	m_activeScene->AddGameObject(pHouseObject);
	m_activeScene->AddGameObject(pCubeObject);
	m_activeScene->AddGameObject(pCubeObject2);
	m_activeScene->AddGameObject(pCubeObject3);
	m_activeScene->AddGameObject(pLightObject);
}

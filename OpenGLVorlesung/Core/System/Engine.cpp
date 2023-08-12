#include "Engine.h"
#include "../../glad/Loader.h"
#include "Scene.h"
#include "Scenes/PhongScene.h"
#include "../General/Time.h"
#include "../../Window/Window.h"
#include "../../Input/UserInput.h"
#include "../../Components/Mesh.h"
#include "../../Core/General/DrawData.h"
#include <memory>

// System
std::shared_ptr<CWindow> pWindow = nullptr;
std::shared_ptr<CLoader> pGladLoader = nullptr;
std::shared_ptr<CTime> pTime = nullptr;
std::shared_ptr<CUserInput> pUserInput = nullptr;

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
	CreateSystemPointer();
	CreateScenes();

	auto iErrorMsg = pWindow->Initialize();

	iErrorMsg = pGladLoader->Initialize();

	auto deltaTime = pTime->GetDeltaTime();
	iErrorMsg = pUserInput->Initialize(pWindow, m_pCamera, deltaTime);

	InitializeScenes();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
	return iErrorMsg;
}

int CEngine::Run()
{
	auto iErrorMsg{0};
	float deltaTime{ 0.0f };
	while (!pWindow->GetWindowShouldClose())
	{
		iErrorMsg = pWindow->Update();
		pTime->Update();
		deltaTime = pTime->GetDeltaTime();

		pUserInput->Update(deltaTime);

		DrawData drawData
		{
			
		};

		UpdateScenes(drawData);


		pWindow->UpdateSwapBuffers();
	}
	return iErrorMsg;
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
	// System
	pWindow = std::make_shared<CWindow>(m_iWidth, m_iHeight, "SAE_Tobi_Engine", m_pCamera);
	pGladLoader = std::make_shared<CLoader>(m_iWidth, m_iHeight);
	pUserInput = std::make_shared<CUserInput>();
	pTime = std::make_shared<CTime>();
}

/**
 * \brief Create a scene and add it to the Engine
 */
void CEngine::CreateScenes()
{
	//std::shared_ptr<CScene> pScene = std::make_shared<CScene>();
	const std::shared_ptr<CPhongScene> phong_scene = std::make_shared<CPhongScene>(pWindow, pGladLoader, pUserInput, pTime);
	m_pCamera = phong_scene->GetCamera();
	m_scenes.push_back(phong_scene);
	m_activeScene = phong_scene;
}
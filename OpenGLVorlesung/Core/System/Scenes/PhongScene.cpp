#include "PhongScene.h"
#include "../DataManager.h"

constexpr int I_SUCCESS = 0;
constexpr int I_WIDTH = 1920;
constexpr int I_HEIGHT = 1080;

void CPhongScene::Initialize()
{
    CreateComponents();
    CreateGameObjects();
    InitializeComponents();

    // Initialize all GO's
    CScene::Initialize();
}

void CPhongScene::Update()
{
    m_pCamera->SetCameraData(45.0f, 0.1f, 1000.0f, m_pPhongShaderHouse->GetShaderProgram(), "camMatrix");
    m_pCamera->Update();

    m_pCubeObject->GetTransform()->m_position = glm::vec3(static_cast<float>(sin(glfwGetTime())) * 0.5f,
                                                          static_cast<float>(cos(glfwGetTime())) * 0.5f, -4.0f);
    m_pCubeObject->GetTransform()->m_rotation = glm::vec3(1.0f + static_cast<float>(glfwGetTime()),
                                                          static_cast<float>(glfwGetTime()), 0.0f);
    m_pLightObject->GetTransform()->m_position = m_pCubeObject->GetTransform()->m_position + glm::vec3(
        static_cast<float>(cos(glfwGetTime())) * 4.0f, static_cast<float>(sin(glfwGetTime())) * 3.5f,
        static_cast<float>(sin(glfwGetTime())) * 3.5f);

    // Update all GO's
    CScene::Update();
}

void CPhongScene::Draw(const DrawData& a_drawData)
{
    const DrawData drawData
    {
        m_pCamera->GetCamMatrix(),
        m_pCamera->GetPos(),
        m_pLightObject->GetTransform()->m_position,
        V3_LIGHT_AMBIENT,
        V3_LIGHT_DIFFUSE,
        V3_LIGHT_SPECULAR
    };

    // Draw all GO's
    CScene::Draw(drawData);
}

void CPhongScene::Finalize()
{
    CScene::Finalize();
}

auto CPhongScene::GetCamera() -> const std::shared_ptr<CCamera>
{
    if (m_pCamera == nullptr)
    {
        CreateSystems();
    }
    return m_pCamera;
}

void CPhongScene::CreateSystems()
{
    if (m_pCamera != nullptr) return;
    m_pCamera = std::make_shared<CCamera>(I_WIDTH, I_HEIGHT, glm::vec3(0.0f, 3.0f, 7.0f), glm::vec3(0.0f, 0.0f, -0.5f),
                                          glm::vec3(0.0f, 1.0f, 0.0f));
}

void CPhongScene::CreateComponents()
{
    // Shader
    const auto vertexPhongShader = CDataManager::ReadFile("Resource Files/Shader/PhongVertex.glsl");
    const auto fragmentPhongShader = CDataManager::ReadFile("Resource Files/Shader/PhongFragment.glsl");
    const auto vertexLightShader = CDataManager::ReadFile("Resource Files/Shader/LightVertex.glsl");
    const auto fragmentLightShader = CDataManager::ReadFile("Resource Files/Shader/LightFragment.glsl");

    // Components
    m_pPhongShaderHouse = std::make_shared<CShader>(vertexPhongShader, fragmentPhongShader);
    m_pPhongShaderCube = std::make_shared<CShader>(vertexPhongShader, fragmentPhongShader);
    m_pPhongShaderCube2 = std::make_shared<CShader>(vertexPhongShader, fragmentPhongShader);
    m_pPhongShaderCube3 = std::make_shared<CShader>(vertexPhongShader, fragmentPhongShader);
    m_pLightShader = std::make_shared<CShader>(vertexLightShader, fragmentLightShader);

    CreateMaterials();
}

void CPhongScene::CreateMaterials()
{
    m_pMatHouse = std::make_shared<CMaterial>();
    *m_pMatHouse = {
        glm::vec3(0.1745f, 0.01175f, 0.01175f),
        glm::vec3(0.61424f, 0.04136f, 0.04136f),
        glm::vec3(0.727811f, 0.626959f, 0.626959f),
        32.0f
    };

    m_pMatLight = std::make_shared<CMaterial>();
    *m_pMatLight = {
        V3_LIGHT_AMBIENT,
        V3_LIGHT_DIFFUSE
    };

    m_pMatCube = std::make_shared<CMaterial>();
    *m_pMatCube = {
        glm::vec3(0.24725f, 0.1995f, 0.0745f),
        glm::vec3(0.75164f, 0.60648f, 0.22648f),
        glm::vec3(0.628281f, 0.555802f, 0.366065f),
        64.0f
    };

    m_pMatCube2 = std::make_shared<CMaterial>();
    *m_pMatCube2 = {
        glm::vec3(0.0215f, 0.1745f, 0.0215f),
        glm::vec3(0.07568f, 0.61424f, 0.07568f),
        glm::vec3(0.633f, 0.727811f, 0.633f),
        32.0f
    };

    m_pMatCube3 = std::make_shared<CMaterial>();
    *m_pMatCube3 = {
        glm::vec3(0.5f, 1.0f, 0.3f),
        glm::vec3(0.5f, 1.0f, 0.3f),
        glm::vec3(1.0f, 1.0f, 1.0f),
        1024.0f
    };
}

void CPhongScene::CreateGameObjects()
{
    // VerticesInformation
    CPrimitiveMeshes house = CPrimitiveMeshes::GetHouse();
    CPrimitiveMeshes cube = CPrimitiveMeshes::GetCube();
    CPrimitiveMeshes plane = CPrimitiveMeshes::GetPlane();
    CPrimitiveMeshes lightCube = CPrimitiveMeshes::GetLightCube();

    // Create Scene Objects
    m_pHouseObject = std::make_shared<CGameObject>(m_pPhongShaderHouse, &house, m_pMatHouse,
                                                   "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
    m_pHouseObject->GetTransform()->m_position = glm::vec3(0.0f, 0.0f, 0.0f);

    m_pCubeObject = std::make_shared<CGameObject>(m_pPhongShaderCube, &cube, m_pMatCube,
                                                  "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
    m_pCubeObject->GetTransform()->m_position = glm::vec3(0.0f, -1.0f, 0.0f);
    m_pCubeObject2 = std::make_shared<CGameObject>(m_pPhongShaderCube2, &cube, m_pMatCube2,
                                                   "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
    m_pCubeObject2->GetTransform()->m_position = glm::vec3(-2.0f, 0.0f, 0.0f);
    m_pCubeObject3 = std::make_shared<CGameObject>(m_pPhongShaderCube3, &cube, m_pMatCube3,
                                                   "Resource Files/Image/SAE_Institute_Black_Logo.jpg");
    m_pCubeObject3->GetTransform()->m_position = glm::vec3(0.0f, -5.0f, 0.0f);
    m_pCubeObject3->GetTransform()->m_scale = glm::vec3(20.0f, 0.01f, 20.0f);


    m_pLightObject = std::make_shared<CGameObject>(m_pLightShader, &lightCube, m_pMatLight);
    m_pLightObject->GetTransform()->m_position = glm::vec3(-0.0f, -1.0f, -4.0f);
    m_pLightObject->GetTransform()->m_scale = glm::vec3(0.5f, 0.5f, 0.5f);

    AddGameObject(m_pHouseObject);
    AddGameObject(m_pCubeObject);
    AddGameObject(m_pCubeObject2);
    AddGameObject(m_pCubeObject3);
    AddGameObject(m_pLightObject);
}

void CPhongScene::InitializeComponents()
{
    m_pPhongShaderHouse->Initialize();
    m_pPhongShaderCube->Initialize();
    m_pPhongShaderCube2->Initialize();
    m_pPhongShaderCube3->Initialize();
    m_pLightShader->Initialize();
}

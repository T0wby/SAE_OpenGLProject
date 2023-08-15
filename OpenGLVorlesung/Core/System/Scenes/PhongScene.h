#ifndef PHONGSCENE_H
#define PHONGSCENE_H
#include "../Scene.h"

#include "../../General/Time.h"
#include "../../../Window/Window.h"
#include "../../../Components/Camera.h"
#include "../../../Input/UserInput.h"
#include "../../../glad/Loader.h"

class CPhongScene : public CScene
{
public:
    inline CPhongScene(const std::shared_ptr<CWindow>& a_pWindow, const std::shared_ptr<CLoader>& a_pGladLoader,
        const std::shared_ptr<CUserInput>& a_pUserInput,const std::shared_ptr<CTime>& a_pTime)
    : m_pWindow(a_pWindow), m_pGladLoader(a_pGladLoader), m_pTime(a_pTime), m_pUserInput(a_pUserInput) {}

    CPhongScene(const CPhongScene&) = default;
    CPhongScene(CPhongScene&&) = default;
    CPhongScene& operator= (const CPhongScene&) = default;
    CPhongScene& operator= (CPhongScene&&) = default;
    ~CPhongScene() override = default;
    
    void Initialize() override;
    void Update(void) override;
    void Draw(const DrawData& a_drawData) override;
    void Finalize(void) override;

    auto GetCamera() -> const std::shared_ptr<CCamera>;

private:
    void CreateSystems();
    void CreateComponents();
    void CreateMaterials();
    void CreateGameObjects();

    void InitializeComponents();

    
private:
    // System
    std::shared_ptr<CWindow> m_pWindow = nullptr;
    std::shared_ptr<CLoader> m_pGladLoader = nullptr;
    std::shared_ptr<CTime> m_pTime = nullptr;
    std::shared_ptr<CCamera> m_pCamera = nullptr;
    std::shared_ptr<CUserInput> m_pUserInput = nullptr;

    // Shader
    std::shared_ptr<CShader> m_pPhongShaderHouse = nullptr;
    std::shared_ptr<CShader> m_pPhongShaderCube = nullptr;
    std::shared_ptr<CShader> m_pPhongShaderCube2 = nullptr;
    std::shared_ptr<CShader> m_pPhongShaderCube3 = nullptr;
    std::shared_ptr<CShader> m_pLightShader = nullptr;
    
    // Materials
    std::shared_ptr<CMaterial> m_pMatCube = nullptr;
    std::shared_ptr<CMaterial> m_pMatCube2 = nullptr;
    std::shared_ptr<CMaterial> m_pMatCube3 = nullptr;
    std::shared_ptr<CMaterial> m_pMatLight = nullptr;
    std::shared_ptr<CMaterial> m_pMatHouse = nullptr;
    
    // GameObjects
    std::shared_ptr<CGameObject> m_pHouseObject = nullptr;
    std::shared_ptr<CGameObject> m_pCubeObject = nullptr;
    std::shared_ptr<CGameObject> m_pCubeObject2 = nullptr;
    std::shared_ptr<CGameObject> m_pCubeObject3 = nullptr;
    std::shared_ptr<CGameObject> m_pLightObject = nullptr;

    // Light properties
    const glm::vec3 V3_LIGHT_AMBIENT = glm::vec3(1.0f, 1.0f, 1.0f);
    const glm::vec3 V3_LIGHT_DIFFUSE = glm::vec3(1.0f, 1.0f, 1.0f);
    const glm::vec3 V3_LIGHT_SPECULAR = glm::vec3(1.0f, 1.0f, 1.0f);
};
#endif
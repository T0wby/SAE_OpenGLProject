#include "Scene.h"

void CScene::AddGameObject(std::shared_ptr<CGameObject> a_gameObject)
{
    if (a_gameObject == nullptr) return;

    m_gameObjects.push_back(a_gameObject);
}

void CScene::AddGameObject(const std::shared_ptr<CShader>& a_pShader, CPrimitiveMeshes* a_meshStruct,
    const std::shared_ptr<CMaterial>& a_pMaterial, const std::string& a_sTextureLocation)
{
    m_gameObjects.push_back(std::make_shared<CGameObject>(a_pShader, a_meshStruct, a_pMaterial, a_sTextureLocation));
}

void CScene::RemoveGameObject(std::shared_ptr<CGameObject> a_gameObject)
{
    if (a_gameObject == nullptr) return;


    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        if (a_gameObject == m_gameObjects[i])
        {
            m_gameObjects.erase(m_gameObjects.begin() + i);
            break;
        }
    }
}

std::shared_ptr<CGameObject> CScene::GetGameObject(const int& a_iIndex)
{
    if (m_gameObjects.size() < a_iIndex) return nullptr;
    
    return m_gameObjects[a_iIndex];
}

void CScene::Initialize()
{
    for (std::shared_ptr<CGameObject> go : m_gameObjects)
    {
        go->Initialize();
    }
}

void CScene::Update()
{
    for (std::shared_ptr<CGameObject> go : m_gameObjects)
    {
        go->Update();
    }
}

void CScene::Draw(const DrawData& a_drawData)
{
    for (std::shared_ptr<CGameObject> go : m_gameObjects)
    {
        go->Draw(a_drawData);
    }
}

void CScene::Finalize()
{
}

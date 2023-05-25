#include "Scene.h"

void CScene::AddGameObject(std::shared_ptr<CGameObject> a_gameObject)
{
    if (a_gameObject == nullptr) return;

    m_gameObjects.push_back(a_gameObject);
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

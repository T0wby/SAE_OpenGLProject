#ifndef SCENE_H
#define SCENE_H
#include "../../GameObject/GameObject.h"

class CScene
{
public:
    virtual ~CScene() = default;
    void AddGameObject(std::shared_ptr<CGameObject> a_gameObject);
    void AddGameObject(const std::shared_ptr<CShader>& a_pShader, CPrimitiveMeshes* a_meshStruct, const std::shared_ptr<CMaterial>& a_pMaterial , const std::string& a_sTextureLocation = "");
    void RemoveGameObject(std::shared_ptr<CGameObject> a_gameObject);

    std::shared_ptr<CGameObject> GetGameObject(const int& a_iIndex);
    
    virtual void Initialize(void);
    virtual void Update(void);
    virtual void Draw(const DrawData& a_drawData);
    virtual void Finalize(void);

protected:
    std::vector<std::shared_ptr<CGameObject>> m_gameObjects{};

};
#endif

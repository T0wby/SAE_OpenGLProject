#ifndef SCENE_H
#define SCENE_H
#include "../../GameObject/GameObject.h"

class CScene
{
public:
    void AddGameObject(std::shared_ptr<CGameObject> a_gameObject);
    void AddGameObject(const std::shared_ptr<CShader>& a_pShader, CPrimitiveMeshes* a_meshStruct, const std::shared_ptr<CMaterial>& a_pMaterial , const std::string& a_sTextureLocation = "");
    void RemoveGameObject(std::shared_ptr<CGameObject> a_gameObject);

    std::shared_ptr<CGameObject> GetGameObject(const int& a_iIndex);
    
    void Initialize(void);
    void Update(void);
    void Draw(const DrawData& a_drawData);
    void Finalize(void);

private:
    std::vector<std::shared_ptr<CGameObject>> m_gameObjects{};

};
#endif

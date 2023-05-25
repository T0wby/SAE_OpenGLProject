#ifndef SCENE_H
#define SCENE_H
#include "../../GameObject/GameObject.h"

class CScene
{
public:
    void AddGameObject(std::shared_ptr<CGameObject> a_gameObject);
    void RemoveGameObject(std::shared_ptr<CGameObject> a_gameObject);

    void Initialize(void);
    void Update(void);
    void Draw(const DrawData& a_drawData);
    void Finalize(void);

private:
    std::vector<std::shared_ptr<CGameObject>> m_gameObjects{};

};
#endif

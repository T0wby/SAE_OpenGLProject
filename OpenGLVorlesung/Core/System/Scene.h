#ifndef SCENE_H
#define SCENE_H
#include "../../GameObject/GameObject.h"

class CScene
{
public:
    void AddScene(std::shared_ptr<CGameObject> a_gameObject);
    void RemoveScene(std::shared_ptr<CGameObject> a_gameObject);

    void Initialize(void);
    void Run(void);
    void Finalize(void);

private:
    std::vector<std::shared_ptr<CGameObject>> a_gameObjects{};

};
#endif

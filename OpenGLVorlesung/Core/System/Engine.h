#ifndef ENGINE_H
#define ENGINE_H
#include <memory>
#include "Scene.h"

class CEngine
{
public:
    void AddScene(std::shared_ptr<CScene> a_scene);
    void RemoveScene(std::shared_ptr<CScene> a_scene);

    int Initialize(void);
    int Run(void);
    void Finalize(void);

private:
    std::vector<std::shared_ptr<CScene>> m_scenes{};
    int m_iWidth{1280};
    int m_iHeight{1280};

    void InitializeScenes(void);
    void UpdateScenes(const DrawData& a_drawData);

    void CreateSystemPointer(void);
    void CreateScenes(void);
    void CreateComponents(void);
    void CreateMaterials(void);
    void CreateGameObjects(void);
    
};
#endif
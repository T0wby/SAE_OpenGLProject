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
    std::vector<std::shared_ptr<CScene>> a_scenes{};
    int m_iWidth{640};
    int m_iHeight{640};
};
#endif
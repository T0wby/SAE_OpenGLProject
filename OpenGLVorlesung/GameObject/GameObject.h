#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <memory>
#include <vector>
#include "../Components/Component.h"

class CGameObject
{
public:

	void AddComponent(std::shared_ptr<IComponent> a_component);
	void RemoveComponent(std::shared_ptr<IComponent> a_component);

	void Initialize(void);
	void Update(void);
	void Draw(void);

private:
	std::vector<std::shared_ptr<IComponent>> m_components{};

};

#endif // !GAMEOBJECT_H




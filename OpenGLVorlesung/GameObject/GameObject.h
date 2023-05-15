#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <memory>
#include <vector>
#include "../Components/Component.h"
#include "../Shader/Shader.h"
#include "../Core/General/DrawData.h"
#include "../Core/General/Variables.h"

class CGameObject
{
public:
	inline CGameObject(std::shared_ptr<CShader> a_pShader)
		: m_pShader(a_pShader) {}

	void AddComponent(std::shared_ptr<IComponent> a_component);
	void RemoveComponent(std::shared_ptr<IComponent> a_component);

	void Initialize(void);
	void Update(void);
	void Draw(DrawData);

private:
	std::vector<std::shared_ptr<IComponent>> m_components{};
	std::shared_ptr<CShader> m_pShader{ nullptr };
	Transform m_transform{};
};

#endif // !GAMEOBJECT_H




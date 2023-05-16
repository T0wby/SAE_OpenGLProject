#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <memory>
#include <vector>
#include "../Components/Component.h"
#include "../Shader/Shader.h"
#include "../Components/Transform.h"
#include "../Components/Mesh.h"
#include "../Core/General/DrawData.h"

class CGameObject
{
public:
	inline CGameObject(std::shared_ptr<CShader> a_pShader, CPrimitiveMeshes& a_meshStruct)
		: m_pShader(a_pShader) 
	{
		m_pTransform = std::make_shared<CTransform>();
		m_pMesh = std::make_shared<CMesh>(a_meshStruct);
		m_pMesh->Initialize();
		m_components.push_back(m_pTransform);
		m_components.push_back(m_pMesh);
	}

	//TODO: GetComponent
	void AddComponent(std::shared_ptr<IComponent> a_component);
	void RemoveComponent(std::shared_ptr<IComponent> a_component);

	std::shared_ptr<CTransform> GetTransform(void);
	std::shared_ptr<CMesh> GetMesh(void);
	std::shared_ptr<CShader> GetShader(void);

	void Initialize(void);
	void Update(void);
	void Draw(DrawData);

private:
	std::vector<std::shared_ptr<IComponent>> m_components{};
	std::shared_ptr<CShader> m_pShader{ nullptr };
	std::shared_ptr<CMesh> m_pMesh{ nullptr };
	std::shared_ptr<CTransform> m_pTransform{ nullptr };
};

#endif // !GAMEOBJECT_H




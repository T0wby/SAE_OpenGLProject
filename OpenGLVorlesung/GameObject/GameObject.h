#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <memory>
#include <vector>
#include <string>
#include "../Components/Component.h"
#include "../Shader/Shader.h"
#include "../Shader/Texture.h"
#include "../Components/Transform.h"
#include "../Components/Mesh.h"
#include "../Components/Material.h"
#include "../Core/General/DrawData.h"

class CGameObject
{
public:
	inline CGameObject(const std::shared_ptr<CShader>& a_pShader, CPrimitiveMeshes* a_meshStruct, const std::shared_ptr<CMaterial>& a_pMaterial , const std::string& a_sTextureLocation = "")
		: m_pShader(a_pShader), m_pMaterial(a_pMaterial)
	{
		m_pTransform = std::make_shared<CTransform>();
		m_pMesh = std::make_shared<CMesh>(a_meshStruct);

		if (!a_sTextureLocation.empty())
		{
			m_pTexture = std::make_shared<CTexture>(a_sTextureLocation);
			m_pTexture->Initialize();
		}

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
	std::shared_ptr<CTexture> m_pTexture{ nullptr };
	std::shared_ptr<CMesh> m_pMesh{ nullptr };
	std::shared_ptr<CMaterial> m_pMaterial{ nullptr };
	std::shared_ptr<CTransform> m_pTransform{ nullptr };
};

#endif // !GAMEOBJECT_H




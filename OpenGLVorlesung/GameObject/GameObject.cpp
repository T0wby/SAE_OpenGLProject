#include "GameObject.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>


//TODO: Create own transform class/Component
glm::mat4x4 TransformMatrix{};
glm::mat4x4 PositionMatrix{};
glm::mat4x4 RotationMatrix{};
glm::mat4x4 ScaleMatrix{};

void CGameObject::AddComponent(std::shared_ptr<IComponent> a_component)
{
	if (a_component == nullptr) return;

	m_components.push_back(a_component);
}


void CGameObject::RemoveComponent(std::shared_ptr<IComponent> a_component)
{
	if (a_component == nullptr) return;


	for (int i = 0; i < m_components.size(); i++)
	{
		if (a_component == m_components[i])
		{
			m_components.erase(m_components.begin() + i);
			break;
		}
	}
}

std::shared_ptr<CTransform> CGameObject::GetTransform(void)
{
	return m_pTransform;
}

std::shared_ptr<CMesh> CGameObject::GetMesh(void)
{
	return m_pMesh;
}

std::shared_ptr<CShader> CGameObject::GetShader(void)
{
	return m_pShader;
}

void CGameObject::Initialize(void)
{
	for (std::shared_ptr<IComponent> component : m_components)
	{
		component->Initialize(); // calls the Initialize function of each component
	}
}

void CGameObject::Update(void)
{
	//m_pTransform->Update();

	for (std::shared_ptr<IComponent> component : m_components)
	{
		component->Update(); // calls the update function of each component
	}
}

void CGameObject::Draw(const DrawData& a_drawData)
{
	//glUseProgram(m_pShader->GetShaderProgram()); // same as m_pShader->Draw();
	m_pShader->Draw();
	m_pShader->SendMat4ToShader("camMatrix", a_drawData.m_projectionViewMatrix);
	m_pShader->SendVec3ToShader("camPosition", a_drawData.m_cameraPosition);
	m_pShader->SendMat4ToShader("transform", m_pTransform->m_transformMatrix);

	// Send Struct Material
	m_pShader->SendVec3ToShader("material.ambient", m_pMaterial->m_vAmbient);
	m_pShader->SendVec3ToShader("material.diffuse", m_pMaterial->m_vDiffuse);
	m_pShader->SendVec3ToShader("material.specular", m_pMaterial->m_vSpecular);
	m_pShader->SendFloatToShader("material.shininess", m_pMaterial->m_fShininess);
	// Send Struct Light
	m_pShader->SendVec3ToShader("light.position", a_drawData.m_lightPosition);
	m_pShader->SendVec3ToShader("light.ambient", a_drawData.m_lightAmbient);
	m_pShader->SendVec3ToShader("light.diffuse", a_drawData.m_lightDiffuse);
	m_pShader->SendVec3ToShader("light.specular", a_drawData.m_lightSpecular);
	
	glBindVertexArray(m_pMesh->GetVAO());
	//m_pMesh->Draw(); // done in for loop

	for (std::shared_ptr<IComponent> component : m_components)
	{
		component->Draw(); // calls the draw function of each component
	}
}

#include "System/DataManager.h"
#include "../Window/Window.h"
#include "../Component/Mesh.h"
#include "../Component/Material.h"
#include <memory>

const int I_SUCCESS = 0;

std::unique_ptr<CWindow> pWindow = nullptr;
std::unique_ptr<CMaterial> pMaterial = nullptr;
std::unique_ptr<CMesh> pMesh = nullptr;

int Initialize()
{
	auto vertexShader = CDataManager::ReadFile("../../Shader/DefaultVertex.glsl");
	auto fragmentShader = CDataManager::ReadFile("../../Shader/DefaultFragment.glsl");
	pWindow = std::make_unique<CWindow>(640, 480, "Real Engine");
	pMaterial = std::make_unique<CMaterial>(vertexShader, fragmentShader);
	pMesh = std::make_unique<CMesh>();

	return I_SUCCESS;
}

int Run()
{
	
	return I_SUCCESS;
}

void Finalize()
{
	
}

int main(void)
{
	GLFWwindow* pWindow = nullptr;
	auto iErrorMsg = static_cast<int>(0);

	iErrorMsg = Initialize();
	if (iErrorMsg != 0) return iErrorMsg;

	iErrorMsg = Run();
	if (iErrorMsg != 0) return iErrorMsg;

	Finalize();
	
	return I_SUCCESS;
}
#include "Loader.h"

const int I_SUCCESS = 0;
const int I_GLAD_INIT_FAILED = 3;

const int CLoader::Intialize(void) const
{
	auto iVersion = gladLoadGl();
	if (iVersion == 0)
	{
		std::cout << "Err: Failed to open glad!" << std::endl;
		return I_GLAD_INIT_FAILED;
	}

	glViewport(0, 0, m_iWidth, m_iHeight);

	return I_SUCCESS;
}

const int CLoader::Update(void) const
{
	return I_SUCCESS;
}

void CLoader::Draw(void) const
{
}

void CLoader::Finalize(void)
{
}

#include "Loader.h"
#include <iostream>

const int I_SUCCESS = 0;
const int I_ERR_GLAD_INIT_FAILED = -3;

auto CLoader::Initialize(void) const -> const int
{
	auto iVersion = gladLoadGL();
	if (iVersion == 0)
	{
		std::cout << "Err: Failed to load glad!" << std::endl;
		return I_ERR_GLAD_INIT_FAILED;
	}

	glViewport(0, 0, m_iWidth, m_iHeight);

	return I_SUCCESS;
}

auto CLoader::Finalize(void) const -> const int
{
	return I_SUCCESS;
}

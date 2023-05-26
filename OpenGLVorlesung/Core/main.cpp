#include "System/Engine.h"

std::unique_ptr<CEngine> pEngine{nullptr};

int main(void)
{
	pEngine = std::make_unique<CEngine>();
	auto iErrorMsg = static_cast<int>(0);

	iErrorMsg = pEngine->Initialize();

	iErrorMsg = pEngine->Run();

	pEngine->Finalize();
	
	return iErrorMsg;
}
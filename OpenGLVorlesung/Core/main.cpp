#include "../glad/Loader.h"
#include "System/Engine.h"


std::unique_ptr<CEngine> pEngine{nullptr};

int main(void)
{
	pEngine = std::make_unique<CEngine>();
	auto iErrorMsg = static_cast<int>(0);

	iErrorMsg = pEngine->Initialize();
	//if (iErrorMsg != 0) return iErrorMsg;

	iErrorMsg = pEngine->Run();
	//if (iErrorMsg != 0) return iErrorMsg;

	pEngine->Finalize();
	
	return iErrorMsg;
}
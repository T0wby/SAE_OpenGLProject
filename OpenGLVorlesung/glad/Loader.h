#pragma once
#include "../Component/Component.h"
#include <iostream>
class CLoader : public IComponent
{
private:

public:
	// Inherited via IComponent
	virtual const int Intialize(void) const override;
	virtual const int Update(void) const override;
	virtual void Draw(void) const override;
	virtual void Finalize(void) override;
};


#pragma once
class IComponent
{
	virtual const int Intialize(void) const = 0;
	virtual const int Update(void) const = 0;
	virtual void Draw(void) const = 0;
	virtual void Finalize(void) = 0;
};


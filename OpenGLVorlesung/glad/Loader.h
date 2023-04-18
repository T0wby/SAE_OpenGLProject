#ifndef LOADER_H
#define LOADER_H

#include "../Component/Component.h"
#include <iostream>
#include <../glad/glad.h>

class CLoader : public IComponent
{
private:
	GLuint m_iWidth{ 0 };
	GLuint m_iHeight{ 0 };

public:
	inline CLoader(GLuint a_iWidth, GLuint a_iHeight)
		: m_iWidth(a_iWidth), m_iHeight(a_iHeight){}

	// Inherited via IComponent
	virtual const int Intialize(void) const override;
	virtual const int Update(void) const override;
	virtual void Draw(void) const override;
	virtual void Finalize(void) override;
};

#endif // !LOADER_H

#ifndef MATERIAL_H
#define MATERIAL_H

#include "Component.h"
#include <string>

class CMaterial : public IComponent
{
public:
	inline CMaterial(std::string a_sVertexShader, std::string a_sFragmentShader)
		: m_sVertexShader(a_sVertexShader), m_sFragmentShader(a_sFragmentShader) {}

	// Engine Loop
	virtual const int Initialize(void) const override;
	virtual const int Update(void) const override;
	virtual void Draw(void) override;
	virtual void Finalize(void) override;

private:
	std::string m_sVertexShader{ "" };
	std::string m_sFragmentShader{ "" };
};
#endif // !MATERIAL_H




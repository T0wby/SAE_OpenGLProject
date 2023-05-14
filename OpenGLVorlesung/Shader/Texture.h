#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>

class CTexture
{
public:
	inline CTexture(std::string a_sTexture)
		: m_sTexture(a_sTexture) {}

	void Initialize(void);

private:
	std::string m_sTexture{ "" };
};

#endif // !TEXTURE_H

#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>

class CTexture
{
public:
	inline CTexture(const std::string& a_sTexture)
		: m_sTexture(a_sTexture) {}
	CTexture(const CTexture&) = default;
	CTexture(CTexture&&) = default;
	CTexture& operator= (const CTexture&) = default;
	CTexture& operator= (CTexture&&) = default;
	~CTexture() = default;
	
	void Initialize(void);

private:
	std::string m_sTexture{};
};

#endif // !TEXTURE_H

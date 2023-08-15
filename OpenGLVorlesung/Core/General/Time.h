#ifndef TIME_H
#define TIME_H

class CTime
{
public:
	CTime();
	CTime(const CTime&) = default;
	CTime(CTime&&) = default;
	CTime& operator= (const CTime&) = default;
	CTime& operator= (CTime&&) = default;
	~CTime() = default;

	
	void Update();

	inline float GetDeltaTime() const
	{
		return m_fDeltaTime;
	}

private:
	float m_fDeltaTime{0};
	float m_fLastFrame{0};
	float m_fCurrentFrame{0};
};
#endif // !TIME_H





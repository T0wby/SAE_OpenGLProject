#ifndef TIME_H
#define TIME_H

class CTime
{
public:
	CTime();
	void Update();

	inline float GetDeltaTime()
	{
		return m_fDeltaTime;
	}

private:
	float m_fDeltaTime{0};
	float m_fLastFrame{0};
	float m_fCurrentFrame{0};
};
#endif // !TIME_H





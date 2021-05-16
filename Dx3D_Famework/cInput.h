#pragma once
class cInput
{
public:
	static cInput* s_This;

	float m_nMouseX, m_nMouseY;
	float m_nBeforeMouseX, m_nBeforeMouseY;
	float m_nDistanceX, m_nDistanceY;
	int m_nMouseWheel;

	cInput();
	~cInput();
public:
	static cInput* GetInputSingleTone();

	void Update();
	void Release();
};


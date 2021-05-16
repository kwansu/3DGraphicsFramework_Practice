#pragma once

class cInput
{
private:
	static cInput* s_this;

public:
	float m_fMouseX;
	float m_fMouseY;
	float m_fBeforeX;
	float m_fBeforeY;
	float m_fDistanceX;
	float m_fDistanceY;

	float m_fDragX;
	float m_fDragY;

	short m_nMouseWheel;

public:
	static cInput* GetInput();
	cInput();
	~cInput();
	void Update();
};


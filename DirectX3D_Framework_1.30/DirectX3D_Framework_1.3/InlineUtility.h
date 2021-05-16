#pragma once

// ��ũ�θ� ��ü�� ���ø� �ζ��� �Լ��� :

template <typename T>
inline void SafeDelete(T ptr)
{
	if (ptr)
	{
		delete ptr;
		ptr = NULL;
	}
}


template <typename T>
inline void SafeRelease(T ptr)
{
	if (ptr)
	{
		ptr->Release();
		ptr = NULL;
	}
}


#define SINGLETONE(class_name) private:\
	class_name(void);\
public:\
	~class_name(void);\
	static class_name* GetInstance()\
{\
	static class_name instance;\
	return &instance;\
}


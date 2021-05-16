#include "stdafx.h"
#include "MyFunction.h"

bool CommandCheck(char* str, char* command)
{
	int i = 0;
	int j = 0;

	while (str[i])
	{

		if (str[i] == command[j])
		{
			++j;
		}
		++i;

		if (!command[j])
			return true;
	}

	return false;
}


bool GetIntFromString(char* str, int* pResult)
{
	int i = 0;
	bool bPositive = true;
	*pResult = 0;

	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			str[i] == '-' ? bPositive = false : *pResult = str[i] - '0';
			++i;

			while (str[i] >= '0' && str[i] <= '9')
			{
				*pResult *= 10;
				*pResult += str[i++] - '0';
			}

			if (!bPositive)
			{
				*pResult *= -1;
				if (!(*pResult))
					return false;
			}

			return true;
		}
		++i;
	}
	return false;
}
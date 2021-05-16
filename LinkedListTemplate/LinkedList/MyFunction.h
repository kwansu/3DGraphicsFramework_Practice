#pragma once
#include <iostream>

void UppercaseToLowercase(char* str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 'a' - 'A';
		}
		++i;
	}
}


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


bool GetTemplateFromString(char* str, int* pResult)
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


bool GetTemplateFromString(char* str, float* pResult)
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

			if (str[i++] == '.')
			{
				while (str[i] >= '0' && str[i] <= '9')
				{
					*pResult += (str[i++] - '0') / 10;
				}
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


bool GetTemplateFromString(char* str, char** pResult)
{
	int i = 0;
	bool bTwo = false;

	while (str[i])
	{
		if (str[i++] == '"')
		{
			if (bTwo)
				return true;

			*pResult = &(str[i]);
			bTwo = true;
		}
	}

	return false;
}
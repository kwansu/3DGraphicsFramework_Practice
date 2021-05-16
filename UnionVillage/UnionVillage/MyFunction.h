#pragma once

template <typename T>
inline bool IsBetween(T val, T min, T max)
{
	return (val >= min && val <= max) ? true : false;
}

int GetNextInt(char*& str)
{
	int i = 0;
	bool bPositive = true;

	while (str[i])
	{
		if (str[i] == '-')
		{
			++i;
			if (str[i] >= '0' && str[i] <= '9')
				bPositive = false;

			continue;
		}

		if (str[i] >= '0' && str[i] <= '9')
		{
			int nResult = str[i++] - '0';

			while (str[i] >= '0' && str[i] <= '9')
			{
				nResult *= 10;
				nResult += str[i++] - '0';
			}

			if (!bPositive)
				nResult *= -1;

			str = &str[i];
			return nResult;
		}
		++i;
	}

	return 0;
}
#include "StdAfx.h"
#include "cMatrix.h"


cMatrix::cMatrix(const cMatrix& copy)
	: cMatrix(copy.m_nDimension)
{
	for (int i = 0; i < m_nDimension; ++i)
	{
		for (int j = 0; j < m_nDimension; ++j)
			m_arr[i][j] = copy.m_arr[i][j];
	}
}


cMatrix::cMatrix(int nDimension)
	: m_nDimension(nDimension)
{
	m_arr = new float*[nDimension];

	for (int i = 0; i < nDimension; ++i)
	{
		m_arr[i] = new float[nDimension];
		for (int j = 0; j < nDimension; ++j)
			m_arr[i][j] = 0;
	}
}


cMatrix::~cMatrix()
{
	if (m_arr)
	{
		for (int i = 0; i < m_nDimension; ++i)
			delete[] m_arr[i];

		delete[] m_arr;
	}
}


bool cMatrix::operator==(const cMatrix& matrix)
{
	for (int i = 0; i < m_nDimension; ++i)
	{
		for (int j = 0; j < m_nDimension; ++j)
			if (!EqualFloat(m_arr[i][j], matrix.m_arr[i][j]))
				return false;
	}

	return true;
}


bool cMatrix::operator!=(const cMatrix& matrix)
{
	return !(this->operator==(matrix));
}


cMatrix cMatrix::operator+(const cMatrix& matrix)
{
	cMatrix resultM(m_nDimension);

	for (int i = 0; i < m_nDimension; ++i)
	{
		for (int j = 0; j < m_nDimension; ++j)
			resultM.m_arr[i][j] = m_arr[i][j] + matrix.m_arr[i][j];
	}

	return resultM;
}


cMatrix cMatrix::operator-(const cMatrix& matrix)
{
	cMatrix resultM(m_nDimension);

	for (int i = 0; i< m_nDimension; ++i)
	{
		for (int j = 0; j < m_nDimension; ++j)
			resultM.m_arr[i][j] = m_arr[i][j] - matrix.m_arr[i][j];
	}

	return resultM;
}


cMatrix cMatrix::operator*(const cMatrix& matrix)
{
	cMatrix resultM(m_nDimension);

	for (int i = 0; i < m_nDimension; ++i)
	{
		for (int j = 0; j < m_nDimension; ++j)
			for (int n = 0; n < m_nDimension; ++n)
				resultM.m_arr[i][j] += m_arr[i][n] * matrix.m_arr[n][j];
	}

	return resultM;
}


cMatrix cMatrix::operator*(float scalar)
{
	cMatrix resultM(m_nDimension);

	for (int i = 0; i < m_nDimension; ++i)
	{
		for (int j = 0; j < m_nDimension; ++j)
			resultM.m_arr[i][j] = m_arr[i][j] * scalar;
	}

	return resultM;
}


cMatrix cMatrix::operator/(float scalar)
{
	return this->operator*(1/scalar);
}


cMatrix cMatrix::operator=(const cMatrix& matrix)
{
	for (int i = 0; i < m_nDimension; ++i)
	{
		for (int j = 0; j < m_nDimension; ++j)
			m_arr[i][j] = matrix.m_arr[i][j];
	}
	return *this;
}


cMatrix cMatrix::Identity(int nDimension)
{
	cMatrix resultM(nDimension);

	for (int i = 0; i < nDimension; ++i)
	{
		for (int j = 0; j < nDimension; ++j)
			if (i == j)
				resultM.m_arr[i][j] = 1;
	}

	return resultM;
}


cMatrix cMatrix::Transpose()
{
	cMatrix resultM(m_nDimension);

	for (int i = 0; i < m_nDimension; ++i)
	{
		for (int j = 0; j < m_nDimension; ++j)
			resultM.m_arr[i][j] = m_arr[j][i];
	}

	return resultM;
}


cMatrix cMatrix::Inverse(float& fDet)
{
	cMatrix copy = *this;
	return copy.Inverse();
}


cMatrix cMatrix::Inverse()
{
	cMatrix inverseM = Identity(m_nDimension);
	float tem;
	
	for (int j = 0; j < m_nDimension; ++j)
	{
		for (int i = 0; i < m_nDimension; ++i)
		{
			if (i == j && !EqualFloat(m_arr[i][j], 1))
			{
				if (EqualFloat(m_arr[i][j], 0))
				{
					for (int r = j; r < m_nDimension; ++r)
					{
						if (r != i && !EqualFloat(m_arr[r][j], 0))
						{
							tem = 1 / m_arr[r][j];
							AddRow(m_arr[i], m_arr[r], tem);
							AddRow(inverseM.m_arr[i], inverseM.m_arr[r], tem);
							break;
						}
						if (r + 1 == m_nDimension)
							return inverseM;
					}
				}
				else
				{
					tem = 1 / m_arr[i][j];
					MultiplyRow(tem, m_arr[i]);
					MultiplyRow(tem, inverseM.m_arr[i]);
				}
			}
			else if (i != j && !EqualFloat(m_arr[i][j], 0))
			{
				for (int r = j; r < m_nDimension; ++r)
				{
					if (r != i && !EqualFloat(m_arr[r][j], 0))
					{
						tem = -m_arr[i][j] / m_arr[r][j];
						AddRow(m_arr[i], m_arr[r], tem);
						AddRow(inverseM.m_arr[i], inverseM.m_arr[r], tem);
						break;
					}
					if (r + 1 == m_nDimension)
						return inverseM;
				}
			}
		}
	}

	return inverseM;
}


void cMatrix::MultiplyRow(float val, float*& row)
{
	for (int i = 0; i < m_nDimension; ++i)
		row[i] *= val;
}


void cMatrix::AddRow(float*& rowPur,float*& row, float fMul)
{
	for (int i = 0; i < m_nDimension; ++i)
		rowPur[i] += row[i] * fMul;
}


cMatrix cMatrix::Random(int nDimension)
{
	cMatrix resultM(nDimension);

	for (int i = 0; i < nDimension; ++i)
	{
		for (int j = 0; j < nDimension; ++j)
			resultM.m_arr[i][j] = rand() % 20 - 10;
	}

	return resultM;
}

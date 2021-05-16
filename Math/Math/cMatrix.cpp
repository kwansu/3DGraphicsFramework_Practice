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
			if (!IsInEpsilon(m_arr[i][j], matrix.m_arr[i][j], EPSILON))
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


cMatrix cMatrix::Inverse2(float& fDet)
{
	cMatrix inverseM(m_nDimension);

	for (int i = 0; i < m_nDimension; ++i)
	{
		for (int j = 0; j < m_nDimension; ++j)
			inverseM.m_arr[i][j] = GetC(j, i);
	}

	float fDef = 0;

	for (int n = 0; n < m_nDimension; ++n)
		fDef += m_arr[0][n] * inverseM.m_arr[0][n];

	return (inverseM * (1.f / fDef));
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
			if (i == j && !IsInEpsilon(m_arr[i][j], 1))
			{
				if (IsInEpsilon(m_arr[i][j], 0))
				{
					for (int r = j; r < m_nDimension; ++r)
					{
						if (r != i && !IsInEpsilon(m_arr[r][j], 0))
						{
							tem = 1 / m_arr[r][j];
							AddRow(m_arr[i], m_arr[r], tem);
							AddRow(inverseM.m_arr[i], inverseM.m_arr[r], tem);
							break;
						}
						if (r + 1 == m_nDimension)
							cout << "역행렬이 존재하지 않습니다." << endl;
					}
				}
				else
				{
					tem = 1 / m_arr[i][j];
					MultiplyRow(tem, m_arr[i]);
					MultiplyRow(tem, inverseM.m_arr[i]);
				}
			}
			else if (i != j && !IsInEpsilon(m_arr[i][j], 0))
			{
				for (int r = j; r < m_nDimension; ++r)
				{
					if (r != i && !IsInEpsilon(m_arr[r][j], 0))
					{
						tem = -m_arr[i][j] / m_arr[r][j];
						AddRow(m_arr[i], m_arr[r], tem);
						AddRow(inverseM.m_arr[i], inverseM.m_arr[r], tem);
						break;
					}
					if (r + 1 == m_nDimension)
						cout << "역행렬이 존재하지 않습니다." << endl;
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


void cMatrix::Print()
{
	cout << endl;

	for (int i = 0; i < m_nDimension; ++i)
	{
		for (int j = 0; j < m_nDimension; ++j)
			cout << SetZeroEpsilon(m_arr[i][j]) << "\t";

		cout << endl;
	}
}



// i, j는 삭제할 행과 열.
cMatrix cMatrix::GetSmallMatrix(int _i, int _j)
{
	cMatrix resultM(m_nDimension - 1);
	int i2 = 0;
	int j2 = 0;

	for (int i = 0; i < m_nDimension - 1; ++i, ++i2)
	{
		if (i2 == _i) ++i2;
		for (int j = 0; j < m_nDimension - 1; ++j, ++j2)
		{
			if (j2 == _j) ++j2;
			resultM.m_arr[i][j] = m_arr[i2][j2];
		}
		j2 = 0;
	}

	return resultM;
}


float cMatrix::GetMatrixValue()
{
	if (m_nDimension == 2)
		return m_arr[0][0] * m_arr[1][1] - m_arr[0][1] * m_arr[1][0];

	float fResult = 0;

	for (int n = 0; n < m_nDimension; ++n)
		fResult += m_arr[0][n] * GetC(0, n);

	return fResult;
}


float cMatrix::GetC(int i, int j)
{
	return ((i + j) % 2 == 0 ? 1.f : -1.f) * GetSmallMatrix(i, j).GetMatrixValue();
}

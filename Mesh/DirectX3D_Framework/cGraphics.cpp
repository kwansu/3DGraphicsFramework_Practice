#include "stdafx.h"
#include "cGraphics.h"


cGraphics::cGraphics()
	: m_pMeshEdit(NULL), m_pMtlEdit(NULL), m_pTexture(NULL)
{
}


cGraphics::~cGraphics()
{
}


bool cGraphics::LoadObjFile(char* strFileName)
{
	char strLine[100];

	ifstream ifObj(strFileName);

	if (!ifObj.is_open())
		return false;

	char* token = NULL;
	char* context = NULL;

	while (!ifObj.eof())
	{
		ifObj.getline(strLine, 100);
		token = strtok_s(strLine, " ", &context);

		if (!token)
			continue;

		if (!strcmp(token, "#"))
			continue;

		if (!strcmp(token, "mtllib"))
		{
			token = strtok_s(NULL, " ", &context);
			assert(token && "mtllib");

			if (!LoadMtlFile(token))
				return false;

			continue;
		}

		if (!strcmp(token, "g"))
		{
			token = strtok_s(strLine, " ", &context);

			if (token)
			{
				pair<map<string, cMesh>::iterator, bool> result;
				result = m_mapMeshData.insert(pair<string, cMesh>
					(string(token), cMesh()));
				
				m_pMeshEdit = &result.first->second;
			}
			continue;
		}

		if (!strcmp(token, "v"))
		{
			cVec3 vec;

			token = strtok_s(NULL, " ", &context);
			assert(token && "v");
			vec.x = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "v");
			vec.y = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "v");
			vec.z = atof(token);

			m_pMeshEdit->PushPosition(&vec);
			continue;
		}

		if (!strcmp(token, "vn"))
		{
			cVec3 vec;

			token = strtok_s(NULL, " ", &context);
			assert(token && "vn");
			vec.x = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "vn");
			vec.y = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "vn");
			vec.z = atof(token);

			m_pMeshEdit->PushNormal(&vec);
			continue;
		}

		if (!strcmp(token, "vt"))
		{
			cVec2 vec;

			token = strtok_s(NULL, " ", &context);
			assert(token && "vt");
			vec.x = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "vt");
			vec.y = atof(token);

			m_pMeshEdit->PushTexturePos(&vec);
			continue;
		}

		if (!strcmp(token, "usemtl"))
		{
			token = strtok_s(NULL, " ", &context);
			assert(token && "usemtl");

			m_pMeshEdit->SetMaterial(
				&m_mapMtlData.find(token)->second);
		}

		if (!strcmp(token, "f"))
		{
			int aPNT[3];
			for (int i = 0; i < 3; ++i)
			{
				token = strtok_s(NULL, "/", &context);
				assert(token && "f");
				aPNT[0] = atoi(token) - 1;

				token = strtok_s(NULL, "/", &context);
				assert(token && "f");
				aPNT[1] = atoi(token) - 1;

				token = strtok_s(NULL, " ", &context);
				assert(token && "f");
				aPNT[2] = atoi(token) - 1;

				m_pMeshEdit->PushVertexPNT(aPNT);
			}
		}
	}

	return true;
}


bool cGraphics::LoadMtlFile(char* strFileName)
{
	char strLine[100];

	ifstream ifMtl(strFileName);

	if (!ifMtl.is_open())
		return false;

	char* token = NULL;
	char* context = NULL;

	while (!ifMtl.eof())
	{
		ifMtl.getline(strLine, 100);
		token = strtok_s(strLine, " ", &context);

		if (!token)
			continue;

		if (!strcmp(token, "#"))
			continue;

		if (!strcmp(token, "map_Kd"))
		{
			token = strtok_s(NULL, " ", &context);
			assert(token && "newmtl");

			//char* -> LPCWSTR변환 방법 확인후 token이름으로 파일열기
			if (!strcmp(token, "seafloor.dds"))
			{
				D3DXCreateTextureFromFile(g_pDevice, TEXT("seafloor.dds")
					, &m_pTexture);
			}
			else if (!strcmp(token, "NMP_Ripples2_512.dds"))
			{
				D3DXCreateTextureFromFile(g_pDevice, TEXT("NMP_Ripples2_512.dds")
					, &m_pTexture);
			}
			else
			{
				D3DXCreateTextureFromFile(g_pDevice, TEXT("box.jpg")
					, &m_pTexture);
			}
		}

		if (!strcmp(token, "newmtl"))
		{
			token = strtok_s(NULL, " ", &context);
			assert(token && "newmtl");

			pair<map<string, stMaterial>::iterator, bool> result;
			result = m_mapMtlData.insert(pair<string, stMaterial>
				(string(token), stMaterial()));

			m_pMtlEdit = &result.first->second;
			ZeroMemory(m_pMtlEdit, sizeof(stMaterial));
			continue;
		}

		if (!strcmp(token, "Ka"))
		{
			xColor color;
			color.a = 1.0f;

			token = strtok_s(NULL, " ", &context);
			assert(token && "Ka");
			color.r = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "Ka");
			color.g = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "Ka");
			color.b = atof(token);

			m_pMtlEdit->Ambient = color;
			continue;
		}

		if (!strcmp(token, "Kd"))
		{
			xColor color;
			color.a = 1.0f;

			token = strtok_s(NULL, " ", &context);
			assert(token && "Kd");
			color.r = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "Kd");
			color.g = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "Kd");
			color.b = atof(token);

			m_pMtlEdit->Diffuse = color;
			continue;
		}

		if (!strcmp(token, "Ks"))
		{
			xColor color;
			color.a = 1.0f;

			token = strtok_s(NULL, " ", &context);
			assert(token && "Ks");
			color.r = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "Ks");
			color.g = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "Ks");
			color.b = atof(token);

			m_pMtlEdit->Specular = color;
			continue;
		}
	}

	return true;
}


void cGraphics::Release()
{
	SAFE_RELEASE(m_pTexture);
}


void cGraphics::Render()
{
	g_pDevice->SetTexture(0, m_pTexture);

	map<string, cMesh>::iterator iter;
	for (iter = m_mapMeshData.begin(); iter != m_mapMeshData.end(); ++iter)
	{
		iter->second.Render();
	}
}


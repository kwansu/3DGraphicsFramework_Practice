#include "stdafx.h"
#include "cGraphics.h"


cGraphics::cGraphics()
{
}


cGraphics::~cGraphics()
{
}


bool cGraphics::LoadObjFile(char* strFileName)
{
	vector<cVec3>			m_aPosition;
	vector<cVec3>			m_aNormal;
	vector<cVec2>			m_aTexturePos;
	cMesh*					m_pMeshEdit;

	char strLine[100];

	ifstream ifObj(strFileName);

	if (!ifObj.is_open())
		return false;

	char* token;
	char* context;

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

			if (LoadMtlFile(token))
				assert("mtllib");

			continue;
		}

		if (!strcmp(token, "g"))
		{
			token = strtok_s(NULL, " ", &context);

			if (token)
			{
				pair<map<string, cMesh>::iterator, bool> result;
				result = m_mapMeshData.insert(
					pair< string, cMesh >(token, cMesh()));

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

			m_aPosition.push_back(vec);
			continue;
		}
		if (!strcmp(token, "vn"))
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

			m_aNormal.push_back(vec);
			continue;
		}
		if (!strcmp(token, "vt"))
		{
			cVec2 vec;
			token = strtok_s(NULL, " ", &context);
			assert(token && "v");
			vec.x = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "v");
			vec.y = atof(token);

			m_aTexturePos.push_back(vec);
			continue;

		}

		if (!strcmp(token, "usemtl"))
		{
			token = strtok_s(NULL, " ", &context);
			assert(token && "usemtl");

			m_pMeshEdit->SetMaterial(&m_mapMtlData.find(token)->second);
			continue;
		}

		if (!strcmp(token, "f"))
		{
			int aPNT[3];

			for (int i = 0; i < 3; ++i)
			{
				token = strtok_s(NULL, "/", &context);
				assert(token && "f");
				aPNT[0] = atoi(token);

				token = strtok_s(NULL, "/", &context);
				assert(token && "f");
				aPNT[2] = atoi(token);

				token = strtok_s(NULL, " ", &context);
				assert(token && "f");
				aPNT[1] = atoi(token);

				m_pMeshEdit->PushVertex(&Vertex_PNT(m_aPosition[aPNT[0] - 1]
					, m_aNormal[aPNT[1] - 1], m_aTexturePos[aPNT[2] - 1]));
			}
			continue;
		}
	}

	return true;
}


bool cGraphics::LoadMtlFile(char* strFileName)
{
	cMaterial*				m_pMtlEdit;

	char strLine[100];

	ifstream ifMtl(strFileName);

	if (!ifMtl.is_open())
		return false;

	char* token;
	char* context;

	while (!ifMtl.eof())
	{
		ifMtl.getline(strLine, 100);
		token = strtok_s(strLine, " ", &context);

		if (!token)
			continue;

		if (!strcmp(token, "#"))
			continue;

		if (!strcmp(token, "newmtl"))
		{
			token = strtok_s(NULL, " ", &context);
			assert(token && "newmtl");

			pair<map<string, cMaterial>::iterator, bool> result;
			result = m_mapMtlData.insert(
				pair< string, cMaterial >(token, cMaterial()));

			m_pMtlEdit = &result.first->second;
			ZeroMemory(m_pMtlEdit, sizeof(D3DMATERIAL9));
			continue;
		}

		if (token[0] == 'K')
		{
			char c = token[1];
			xColor color;
			color.a = 0;

			token = strtok_s(NULL, " ", &context);
			assert(token && "k");
			color.r = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "k");
			color.g = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "k");
			color.b = atof(token);

			switch (c)
			{
			case 'a':
				m_pMtlEdit->GetMaterial()->Ambient = color;
			case 'd':
				m_pMtlEdit->GetMaterial()->Diffuse = color;
			case 's':
				m_pMtlEdit->GetMaterial()->Specular = color;
			}
			continue;
		}

		if (!strcmp(token, "map_Kd"))
		{
			token = strtok_s(NULL, " ", &context);
			assert(token && "map_Kd");

			pair<map<string, pTexture>::iterator, bool> result;
			result = m_mapTexture.insert(
				pair< string, pTexture >(token, pTexture()));

			if (result.second)
			{
				D3DXCreateTextureFromFile(g_pDevice, token
					, &result.first->second);
			}

			m_pMtlEdit->SetTexture(result.first->second);
			continue;
		}
	}
	return true;
}


void cGraphics::Release()
{
	map<string, pTexture>::iterator texIter;
	for (texIter = m_mapTexture.begin(); texIter != m_mapTexture.end(); ++texIter)
	{
		SAFE_RELEASE(texIter->second);
	}
}


void cGraphics::Render()
{
	map<string, cMesh>::iterator iter;
	for (iter = m_mapMeshData.begin(); iter != m_mapMeshData.end(); ++iter)
	{
		iter->second.Render();
	}
}


bool cGraphics::IsPicked(const cVec3* pvDir, const cVec3* pvPos)
{
	map<string, cMesh>::iterator iter;
	for (iter = m_mapMeshData.begin(); iter != m_mapMeshData.end(); ++iter)
	{
		if (iter->second.IsPicked(pvDir, pvPos))
			return true;
	}
	return false;
}

#include "stdafx.h"
#include "cObject_Collider_Bottom.h"


cObject_Collider_Bottom::cObject_Collider_Bottom()
{
	m_aVertex.clear();

	vector<cVec3>			m_aPosition;

	char strLine[100];

	ifstream ifObj("map_surface.obj");

	if (!ifObj.is_open())
		assert("바닥파일 열기실패.");

	char* token;
	char* context;

	while (!ifObj.eof())
	{
		ifObj.getline(strLine, 100);
		token = strtok_s(strLine, " ", &context);

		if (!token)
			continue;

		if (!strcmp(token, "v"))
		{
			cVec3 vec;
			token = strtok_s(NULL, " ", &context);
			assert(token && "v");
			vec.x = atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "v");
			vec.z = -atof(token);

			token = strtok_s(NULL, " ", &context);
			assert(token && "v");
			vec.y = atof(token);

			vec *= 0.1f;

			m_aPosition.push_back(vec);
			continue;
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
				token = strtok_s(NULL, " ", &context);
				assert(token && "f");

				m_aVertex.push_back(Vertex_PC(m_aPosition[aPNT[0]]));
			}
			continue;
		}
	}

	ifObj.close();

	//SetScale(0.1f, 0.1f, 0.1f);
	//m_fAngleX = -90;
	//UpdateWorld();
}


cObject_Collider_Bottom::~cObject_Collider_Bottom()
{
}

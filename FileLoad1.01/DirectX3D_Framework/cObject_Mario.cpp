#include "stdafx.h"
#include "cObject_Mario.h"


cObject_Mario::cObject_Mario()
	: m_fLookSpeed(0), m_fUpSpeed(0)
	, m_bBottom(false), m_paObject(NULL)
	, m_pChildHead(NULL), m_pChildLArm(NULL)
	, m_pChildRArm(NULL), m_pChildLLeg(NULL)
	, m_pChildRLeg(NULL)
{
}


cObject_Mario::~cObject_Mario()
{
	SAFE_DELETE(m_pChildHead);
	SAFE_DELETE(m_pChildLArm);
	SAFE_DELETE(m_pChildRArm);
	SAFE_DELETE(m_pChildLLeg);
	SAFE_DELETE(m_pChildRLeg);
}


void cObject_Mario::Setup(cObject_Collider* paObject)
{
	m_paObject = paObject;

	SetLocalSize(2.1f, 3.1f, 1);

	m_pCollider = new cObject_Collider(&m_matWolrd);
	m_pCollider->Setup();

	m_pChildHead = new cObject_Mario_Head;
	m_pChildHead->SetLocalSize(2.1f, 2.f, 2.f);
	m_pChildHead->Setup(&m_matWolrd, 0, 7.1f, 0);

	m_pChildLArm = new cObject_Limbs(false);
	m_pChildLArm->SetLocalSize(1, 3.2f, 1);
	m_pChildLArm->Setup(&m_matWolrd, 3.2f, 3.1f, 0);

	m_pChildRArm = new cObject_Limbs(true);
	m_pChildRArm->SetLocalSize(1, 3.2f, 1);
	m_pChildRArm->Setup(&m_matWolrd,-3.2f, 3.1f, 0);

	m_pChildLLeg = new cObject_Limbs(false);
	m_pChildLLeg->SetLocalSize(1, 3.2f, 1);
	m_pChildLLeg->Setup(&m_matWolrd, 1.1f,-3.2f, 0);
			
	m_pChildRLeg = new cObject_Limbs(true);
	m_pChildRLeg->SetLocalSize(1, 3.2f, 1);
	m_pChildRLeg->Setup(&m_matWolrd,-1.1f,-3.2f, 0);

	m_pChildRArm->SetRotation(-70, 0, 0);
	m_vPos.y = 50;
	m_vPos.x = -30;
	UpdateWorld();


	ZeroMemory(&m_pLight, sizeof(D3DLIGHT9));
	m_pLight.Type = D3DLIGHT_SPOT;
	m_pLight.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//m_pLight.Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);
	m_pLight.Direction = cVec3(0, 0, 1);
	m_pLight.Range = 200.f;
	m_pLight.Falloff = 1.0f;
	m_pLight.Phi = D3DXToRadian(60);
	m_pLight.Theta = D3DXToRadian(30);

	ZeroMemory(&m_pLight2, sizeof(D3DLIGHT9));
	m_pLight2.Type = D3DLIGHT_POINT;
	m_pLight2.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_pLight2.Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);
	//m_pLight2.Direction = cVec3(0, 0, 1);
	m_pLight2.Range = 45.f;
	m_pLight2.Position = cVec3(0, 0, 0);
	//m_pLight2.Falloff = 0.1f;
	//m_pLight2.Phi = D3DXToRadian(80);
	//m_pLight2.Theta = D3DXToRadian(40);

	g_pDevice->SetLight(1, &m_pLight2);
	g_pDevice->LightEnable(1, true);
	g_pDevice->SetLight(0, &m_pLight);
	g_pDevice->LightEnable(0, true);
}


void cObject_Mario::Update()
{
	UpdateDirection();

	if (g_pInput->IsKeyPress('W'))
	{
		m_fLookSpeed += MARIO_ACCELERATION;
		m_pChildLArm->Walking();
		m_pChildRArm->Walking();
		m_pChildLLeg->Walking();
		m_pChildRLeg->Walking();
	}
	else if (g_pInput->IsKeyPress('S'))
	{
		m_fLookSpeed -= MARIO_ACCELERATION;
		m_pChildLArm->Walking();
		m_pChildRArm->Walking();
		m_pChildLLeg->Walking();
		m_pChildRLeg->Walking();
	}
	else if (m_fLookSpeed)
		m_fLookSpeed += m_fLookSpeed > 0 ? -MARIO_ACCELERATION : MARIO_ACCELERATION;

	if (g_pInput->IsKeyPress('A'))
		m_fAngleY -= MARIO_ROTATE_SPEED;

	if (g_pInput->IsKeyPress('D'))
		m_fAngleY += MARIO_ROTATE_SPEED;

	if (m_fLookSpeed > 1.5f)	m_fLookSpeed = 1.5f;
	if (m_fLookSpeed < -1.5f)		m_fLookSpeed = -1.5f;
	if (fabs(m_fLookSpeed) < MARIO_ACCELERATION)
		m_fLookSpeed = 0;

	if (m_bBottom)
	{
		if (g_pInput->IsKeyPress(VK_SPACE))
		{
			m_fUpSpeed = MARIO_JUMP_POWER;
		}
	}
	else
	{
		m_fUpSpeed -= GRVITY_ACCELERATION;
		if (m_fUpSpeed > 3)
			m_fUpSpeed = 3;
	}

	UpdateWorld();

	float dist;
	cVec3 tmp = m_vPos + m_vLook * (m_fLookSpeed + 1)
		+ cVec3(0, 1, 0) * m_fUpSpeed;
	tmp.y -= 9.5f;

	if (m_paObject->CollisionCheck(tmp, &dist))
	{
//a		tmp.y += 9.5f;

		if (dist > -2)
		{
			m_vPos += m_vLook *m_fLookSpeed + cVec3(0, 1, 0) * m_fUpSpeed;
			if (dist < 0)
			{
				m_vPos.y -= dist;
				m_fUpSpeed = 0;
				m_bBottom = true;
			}
			else
			{
				m_bBottom = false;
			}
		}
	}

	//if (m_vPos.y < -80)
	//	m_vPos = cVec3(0, 3, 0);

	UpdateWorld();

	m_pCollider->Update();
	m_pChildHead->Update();
	m_pChildLArm->Update();
	m_pChildLLeg->Update();
	m_pChildRArm->Update();
	m_pChildRLeg->Update();



	UpdateWorld();

	m_pLight.Direction = m_vLook;
	m_pLight.Position = m_vPos + m_vUp * 6;
	m_pLight2.Position = m_vPos + m_vLook * 40;

	g_pDevice->SetLight(1, &m_pLight2);
	g_pDevice->SetLight(0, &m_pLight);
}


void cObject_Mario::Render()
{
	m_pChildHead->Render();
	m_pChildLArm->Render();
	m_pChildLLeg->Render();
	m_pChildRArm->Render();
	m_pChildRLeg->Render();

	cObject_Cube::Render();
}


void cObject_Mario::CollisionHandling()
{
	
}

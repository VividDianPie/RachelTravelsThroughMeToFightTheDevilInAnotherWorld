using namespace std;
#include "Hakumen.h"
#include "Action.h"
#include "BOSSIdle.h"
#include "Animation.h"
#include "matrix3.h"
#include"GameOutput.h"
#include"OBJManager.h"
#include"KJ.h"
#include"scene.h"
#include"Obstacle.h"
#include"HakumenWalk.h"
#include"HakumenAtk.h"
#include"HakumenBig.h"
#include"HakumenDie.h"
#include"Hakumenshou.h"
void CHakumen::Init()
{
	CAction* act = nullptr;
	act = new CHakumenWalk;
	act->Init();
	act->SetEnemy(this);
	SetAction(白面走, act);
	m_curAct = act;

	act = new CHakumenAtk;
	act->Init();
	act->SetEnemy(this);
	SetAction(白面砍, act);

	act = new CHakumenBig;
	act->Init();
	act->SetEnemy(this);
	SetAction(白面大, act);

	act = new CHakumenDie;
	act->Init();
	act->SetEnemy(this);
	SetAction(白面死, act);
	act = new CHakumenShou;
	act->Init();
	act->SetEnemy(this);
	SetAction(BOSS受, act);
	m_JudgePos.x = 500;
	m_JudgePos.y = 600;
	m_Property.Hp = 99;
	m_Property.MaxHp = 100;
	m_Property.Speed = 5;
	m_Property.m_RunSpeed = 20;
	m_Property.m_RunOFFindex = 0;
	m_NextState = -1;
	m_NextAct = -1;
	m_pos.x = m_JudgePos.x;
	m_pos.y = m_JudgePos.y;
	m_Active = true;
	m_curAct->Reset();
	m_level = 5;
	m_NDir = 4;
	m_r.SetTag(&m_JudgePos.x, &m_JudgePos.y);
	m_r.SetWH(150, 30);
	m_Property.FaceDir = 4;
	m_State = BOSS走;
	CKJ::GetKJ()->GetcurScene()->GetEnemyManager()->Push_back(this);
}
void CHakumen::Run()
{
	m_curAct->Run();

	CGO* go = CGO::GetGO();
	float JudgePosX = this->GetJudgePos().x;
	float JudgePosY = this->GetJudgePos().y;
	go->DrawRect(JudgePosX, JudgePosY, m_r.GetW(), m_r.GetH(), 2, RGB(0, 0, 0));
	go->DrawRect(m_pos.x, m_pos.y, 2, 2, 3, RGB(255, 0, 0));
	CMyRect ARect, DRect;
	BMP* bmp = this->GetCurPic();
	for (int i = 0; i < bmp->alen; ++i)
	{
		ARect = bmp->aRect[i];
		if (m_Property.FaceDir != m_NDir)
			ARect.Setoff(-ARect.GetOffx() + m_pos.x, ARect.GetOffy() + m_pos.y);
		else
			ARect.Setoff(ARect.GetOffx() + m_pos.x, ARect.GetOffy() + m_pos.y);
		go->DrawRect(ARect.GetOffx(), ARect.GetOffy(), ARect.GetW(), ARect.GetH(), 2, RGB(255, 0, 0));
	}
	for (int i = 0; i < bmp->dlen; ++i)
	{
		DRect = bmp->dRect[i];
		if (m_Property.FaceDir != m_NDir)
			DRect.Setoff(-DRect.GetOffx() + m_pos.x, DRect.GetOffy() + m_pos.y);
		else
			DRect.Setoff(DRect.GetOffx() + m_pos.x, DRect.GetOffy() + m_pos.y);
		go->DrawRect(DRect.GetOffx(), DRect.GetOffy(), DRect.GetW(), DRect.GetH(), 2, RGB(0, 0, 255));
	}
	if (m_NextState > -1)
	{
		map<int, CAction*>::iterator it;
		it = m_Acts.find(m_NextState);
		if (it == m_Acts.end())
			return;
		m_curAct = it->second;
		m_curAct->Reset();
		m_State = m_NextState;
		m_NextState = -1;
	}
	else if (m_NextAct > -1)
	{
		map<int, CAction*>::iterator it;
		it = m_Acts.find(m_NextAct);
		if (it == m_Acts.end())
			return;
		m_curAct = it->second;
		m_curAct->Reset();
		m_State = m_NextAct;
		m_NextAct = -1;
	}
}

void CHakumen::End()
{
}

void CHakumen::SetState(int st)
{
	m_NextState = st;
}

void CHakumen::SetCurAct(int index)
{
	if (index < 0 || index >= m_Acts.size())
		return;
	m_curAct = m_Acts.find(index)->second;
}

bool CHakumen::Peng(int dir)
{
	COBJM* wall = CKJ::GetKJ()->GetcurScene()->GetObstacleManager();
	int len = wall->GetSize();
	for (int i = 0; i < len; ++i)
	{
		CObstacle* w = (CObstacle*)wall->GetOBJ(i);
		if (this->GetMyRect()->Peng(w->GetMyRect()))
		{
			w->Peng(dir, this, 1);
			return true;
		}
	}
	return false;
}

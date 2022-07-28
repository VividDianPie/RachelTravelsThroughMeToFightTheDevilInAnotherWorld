#pragma once
#include "Action.h"
class CBOSSRun : public CAction
{
	CAnimation* m_Animation;
	int m_NextAct;
public:
	~CBOSSRun();
	void Init();
	void Run();
	void End();
	CAnimation* GetAnimation();
	void Reset();
	bool Peng();
};
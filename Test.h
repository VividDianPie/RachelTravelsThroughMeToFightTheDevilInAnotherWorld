#pragma once
#include<vector>
using namespace std;
#include "scene.h"
#include "Animation.h"
class CTest : public CScene
{
	int x1;
	int y1;
	BMP a1[12];
	BMP a2[12];
	BMP a3[9];
	BMP a4[6];
	BMP a5[13];
	BMP a6[5];
	BMP a7[15];
	BMP a8[16];
	BMP a9[14];
	BMP a10[10];
	BMP a11[3];
	BMP a12[11];
	BMP a13[16];
	BMP a14[17];
	BMP a15[6];
	BMP a16[5];
	BMP a17[10];
	BMP a18[20];
	BMP a19[13];
	BMP a20[12];
	BMP a21[5];
	BMP a22[18];
	BMP a23[19];
	BMP a24[19];
	BMP a25[21];
	BMP a26[16];
	BMP a27[4];
	BMP a28[19];
	BMP a29[13];
	BMP a30[15];
	BMP a31[17];
	BMP a32[10];
	BMP a33[18];
	BMP a34[7];
	BMP a35[9];
	BMP a36[26];
	BMP a37[43];
	BMP a38[15];
	BMP a39[5];

	int piclen;
	int m_piclen0;
	int m_piclen1;
	int m_piclen2;
	int m_piclen3;
	int m_piclen4;
	int m_piclen5;
	int m_piclen6;
	int m_piclen7;
	int m_piclen8;
	int m_piclen9;
	int m_piclen10;
	int m_piclen11;
	int m_piclen12;
	int m_piclen13;
	int m_piclen14;
	int m_piclen15;
	int m_piclen16;
	int m_piclen17;
	int m_piclen18;
	int m_piclen19;
	int m_piclen20;
	int m_piclen21;
	int m_piclen22;
	int m_piclen23;
	int m_piclen24;
	int m_piclen25;
	int m_piclen26;
	int m_piclen27;
	int m_piclen28;
	int m_piclen29;
	int m_piclen30;
	int m_piclen31;
	int m_piclen32;
	int m_piclen33;
	int m_piclen34;
	int m_piclen35;
	int m_piclen36;
	int m_piclen37;
	int m_piclen38;
	int curA;
	int curf;
	int curf2;
	int curcf;
	bool Move;
	int m_CurMousePosX;
	int m_CurMousePosY;
	int m_OldPicPosX;
	int m_OldPicPosY;
	bool m_PicLen0Or1;
	char buf[30];
	FILE* pf;
	vector<char* >m_AnchorPosDataVector;
public:
	CTest();
	~CTest();
	void Init();
	void Run();
	void End();
	COBJM* GetHeroManager();
	COBJM* GetEnemyManager();
	virtual COBJM* GetObstacleManager();
	CAudioManager* GetAudio();
	virtual CTXManager* GetTX();
	virtual int TrueOrFalse() ;

};
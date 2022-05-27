#pragma once

#include "GameDefine.h"
#include "Enemy.h"

// スクロール速度
#define		SCROLL_SPEED	(1.0f)

//敵の出現構造体
typedef struct tag_ENEMYSTART {
	int		Count;
	float* PosX;
	float* Scroll;
}ENEMYSTART;

class CStage{
private:
	ENEMYSTART*		m_pEnemyStart;
	CMeshContainer	m_EnemyMesh;
	int				m_EnemyNo;
	CSprite3D			m_BG;
	float				m_Scroll;
public:
	CStage();
	~CStage();
	bool Load();
	void Initialize(ENEMYSTART* pSt);
	void Update(CEnemy* ene, int ecnt);
	void Render();
	void RenderDebugText();
	void Release();
};
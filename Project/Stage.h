#pragma once

#include "GameDefine.h"
#include "Enemy.h"

// �X�N���[�����x
#define		SCROLL_SPEED	(1.0f)

//�G�̏o���\����
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
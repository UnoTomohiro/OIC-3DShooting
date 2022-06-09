#pragma once
#include "GameDefine.h"
#include "Mof.h"
#include "PlayerShot.h"
#include "Enemy.h"

// à⁄ìÆë¨ìx
#define PLAYER_SPEED		(0.1f)

//ã ÇÃî≠éÀå¿äEêî
#define	PLAYER_SHOT_COUNT	(40)

//íeÇÃî≠éÀä‘äu
#define	PLAYERSHOT_WAIT		(5)

class CPlayer {
private:
	CMeshContainer	m_Mesh;
	CVector3		m_Pos;
	float			m_RotZ;

	CMeshContainer m_ShotMesh;
	CPlayerShot		m_ShotArray[PLAYER_SHOT_COUNT];
	int				m_ShotWait;

	bool			m_bDead;

public:
	CPlayer();
	~CPlayer();
	bool Load();
	void Initialize();
	void Update();
	void Render();
	void RenderDebugText();
	const CVector3 GetPosition() { return m_Pos; }
	void Release();
	void RenderDebug();
	CSphere GetSphere() { return CSphere(m_Pos, 0.4f); }
	void CollisionEnemy(CEnemy& ene);
	bool IsDead() { return m_bDead; }
};
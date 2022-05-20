#pragma once
#include "GameDefine.h"
#include "Mof.h"
#include "PlayerShot.h"

// ˆÚ“®‘¬“x
#define PLAYER_SPEED		(0.1f)

//‹Ê‚Ì”­ËŒÀŠE”
#define	PLAYER_SHOT_COUNT	(40)

//’e‚Ì”­ËŠÔŠu
#define	PLAYERSHOT_WAIT		(5)

class CPlayer{
private:
	CMeshContainer	m_Mesh;
	CVector3		m_Pos;
	float			m_RotZ;

	CMeshContainer m_ShotMesh;
	CPlayerShot		m_ShotArray[PLAYER_SHOT_COUNT];
	int				m_ShotWait;
public:
	CPlayer();
	~CPlayer();
	bool Load();
	void Initialize();
	void Update();
	void Render();
	void RenderDebugText();
	const CVector3 GetPosition(){ return m_Pos; }
	void Release();
};
#include "Enemy.h"

/**
 * コンストラクタ
 *
 */
CEnemy::CEnemy():
m_pMesh(NULL),
m_Pos(0,0,0),
m_Rot(0,0,0),
m_bShow(false),
m_AnimTime(0){
}

/**
 * デストラクタ
 *
 */
CEnemy::~CEnemy(){
}

/**
 * 初期化
 *
 */
void CEnemy::Initialize(){

}

/**
 * 開始
 *
 */
void CEnemy::Start(const Vector3& p){

}

/**
 * 更新
 *
 */
void CEnemy::Update(){

}

/**
 * 描画
 *
 */
void CEnemy::Render(){
	if(!GetShow())
	{
		return;
	}
	


}

/**
 * デバッグ文字描画
 *
 */
void CEnemy::RenderDebugText(int i){
	//位置の描画
	CGraphicsUtilities::RenderString(10,70 + i * 24,MOF_XRGB(0,0,0),
		"敵[%d] %s , 位置 X : %.1f , Y : %.1f , Z : %.1f",i + 1,
		(GetShow() ? "表示" : "非表示"),m_Pos.x,m_Pos.y,m_Pos.z);
}

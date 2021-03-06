#include "Enemy.h"

//敵の移動
ANIM_DATA g_EnemyAnimPosY[2] = {
	{1.0f,-10.0f,EASE_LINEAR},
	{3.0f,0.0f,EASE_INOUT_SINE},
};

ANIM_DATA g_EnemyAnimPosZ[5] = {
		{0.0f,-FIELD_HALF_Z,EASE_LINEAR},
		{1.0f,FIELD_HALF_Z - 10.0f ,EASE_LINEAR},
		{2.0f,FIELD_HALF_Z,EASE_OUT_SINE},
		{3.0f,FIELD_HALF_Z - 10.0f ,EASE_IN_SINE},
		{5.0f,-FIELD_HALF_Z,EASE_LINEAR},
};
/**
 * コンストラクタ
 *
 */
CEnemy::CEnemy():
m_pMesh(NULL),
m_Pos(0,0,0),
m_Rot(0,0,0),
m_bShow(false),
m_HP(5),
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
	m_Pos = Vector3(0,0,0);
	m_Rot = Vector3(0, 0, 0);
	m_bShow = false;
	m_AnimTime = 0;

}

/**
 * 開始
 *
 */
void CEnemy::Start(const Vector3& p){
	m_Pos = p;
	m_Rot = Vector3(0, 0, 0);
	m_bShow = true;
	m_HP = 5;
	m_AnimTime = 0;
	
}

/**
 * 更新
 *
 */
void CEnemy::Update(){
	//非表示
	if (!GetShow())
	{
		return;
	}
	//時間を進める
	m_AnimTime += CUtilities::GetFrameSecond();
	//アニメーション
	m_Pos.y = InterpolationAnim(m_AnimTime, g_EnemyAnimPosY, 2);
	m_Pos.z = InterpolationAnim(m_AnimTime, g_EnemyAnimPosZ, 5);
	//アニメーション終了で消去
	if (g_EnemyAnimPosZ[4].Time < m_AnimTime)
	{
		m_bShow = false;
	}

	
	
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
	CMatrix44		matWorid;
	matWorid.RotationZXY(m_Rot);
	matWorid.SetTranslation(m_Pos);
	m_pMesh->Render(matWorid);


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

//デバッグ描画
void CEnemy::RenderDebug() {
	//非表示
	if (!GetShow()) {
		return;
	}
	//当たり判定の表示
	CGraphicsUtilities::RenderSphere(GetSphere(), Vector4(1, 0, 0, 0.3f));
}

/**
*ダメージ処理
*引数分のHPを減らしHPが０以下になれば敵を消去する
*
*引数
*[in]		dmg		ダメージ
*/

void CEnemy::Damage(int dmg) {
	m_HP -= dmg;
	if (m_HP <= 0)
	{
		m_bShow = false;
	}
}

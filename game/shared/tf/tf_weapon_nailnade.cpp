//====== Copyright � 1996-2005, Valve Corporation, All rights reserved. =======
//
// Purpose: 
//
//=============================================================================

#include "cbase.h"
#include "tf_weapon_nailnade.h"
#include "decals.h"
#include "in_buttons.h"
#include "basecombatweapon_shared.h"
// Client specific.
#ifdef CLIENT_DLL
#include "c_tf_player.h"
// Server specific.
#else
#include "tf_player.h"
#endif

//=============================================================================
//
// Weapon Nail tables.
//
IMPLEMENT_NETWORKCLASS_ALIASED(TFNailnade, DT_TFNailnade)

BEGIN_NETWORK_TABLE(CTFNailnade, DT_TFNailnade)
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA(CTFNailnade)
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS(tf_weapon_nailnade, CTFNailnade);
PRECACHE_WEAPON_REGISTER(tf_weapon_nailnade);

//=============================================================================
//
// Weapon Bottle functions.
//

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
CTFNailnade::CTFNailnade()
{
}
void CTFNailnade::WeaponReset(void)
{
	BaseClass::WeaponReset();
}

bool CTFNailnade::DefaultDeploy(char* szViewModel, char* szWeaponModel, int iActivity, char* szAnimExt)
{
	m_bCancharge = false;
	bool bRet = BaseClass::DefaultDeploy(szViewModel, szWeaponModel, iActivity, szAnimExt);
	if (bRet)
	{
	}
	/*	if (random->RandomInt(0,3) == 1) {
			if (pPlayer->IsPlayerDead == true)
				pPlayer->SetHealth(pPlayer->GetHealth() - 15);
	}*/	
		return bRet;
	
}
void CTFNailnade::ItemPostFrame() {

	CTFPlayer* pPlayer = ToTFPlayer(GetOwner());
	if (!pPlayer)
		return;
	if (pPlayer->m_afButtonPressed & IN_ATTACK) {
	// Grenades dun dont cook in source games!!! :(((((
	//	b_cancharge = true;
	}
	if (pPlayer->m_afButtonReleased & IN_ATTACK) {
		//b_cancharge = false;
		PrimaryAttack();
	}
	if (pPlayer->m_afButtonPressed & IN_ATTACK2) {
		// Grenades dun dont cook in source games!!! :(((((
		//b_cancharge = true;
	}
	if (pPlayer->m_afButtonReleased & IN_ATTACK2) {
		PrimaryAttack2();
	}
}
void CTFNailnade::PrimaryAttack() {
	CTFPlayer* pTFPlayer = ToTFPlayer(GetOwner());
	if (!pTFPlayer)
		return;

	FireProjectile(pTFPlayer);
}
void CTFNailnade::PrimaryAttack2() {
	CTFPlayer* pTFPlayer = ToTFPlayer(GetOwner());
	if (!pTFPlayer)
		return;
	FireProjectile(pTFPlayer);
}

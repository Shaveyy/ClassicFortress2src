//====== Copyright © 1996-2005, Valve Corporation, All rights reserved. =======
//
// Purpose: 
//
//=============================================================================

#include "cbase.h"
#include "tf_weapon_pipenade.h"
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
IMPLEMENT_NETWORKCLASS_ALIASED(TFPipenade, DT_TFWeaponBottle)

BEGIN_NETWORK_TABLE(CTFPipenade, DT_TFWeaponPipenade)
#if defined( CLIENT_DLL )
RecvPropBool(RECVINFO(firetwo))
#else
SendPropBool(SENDINFO(firetwo))
#endif
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA(CTFPipenade)
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS(tf_weapon_pipenade, CTFPipenade);
PRECACHE_WEAPON_REGISTER(tf_weapon_pipenade);

//=============================================================================
//
// Weapon Bottle functions.
//

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
CTFPipenade::CTFPipenade()
{
}
void CTFPipenade::WeaponReset(void)
{
	BaseClass::WeaponReset();
	firetwo = false;
	m_bBroken = false;
}

bool CTFPipenade::DefaultDeploy(char* szViewModel, char* szWeaponModel, int iActivity, char* szAnimExt)
{
	firetwo = false;
	bool bRet = BaseClass::DefaultDeploy(szViewModel, szWeaponModel, iActivity, szAnimExt);

	if (bRet)
	{
	}

	return bRet;
}
void CTFPipenade::ItemPostFrame() {

	CTFPlayer* pPlayer = ToTFPlayer(GetOwner());
	if (!pPlayer)
		return;
	if (pPlayer->m_afButtonPressed & IN_ATTACK) {
	// Grenades dun dont cook in source games!!! :(((((
	}
	if (pPlayer->m_afButtonReleased & IN_ATTACK) {
		PrimaryAttack();
	}
	if (pPlayer->m_afButtonPressed & IN_ATTACK2) {
		// Grenades dun dont cook in source games!!! :(((((
	}
	if (pPlayer->m_afButtonReleased & IN_ATTACK2) {
		PrimaryAttack();
	}
}
void CTFPipenade::PrimaryAttack() {
	CTFPlayer* pTFPlayer = ToTFPlayer(GetOwner());
	if (!pTFPlayer)
		return;
		FireProjectile(pTFPlayer);
}
void CTFPipenade::PrimaryAttack2() {
	CTFPlayer* pTFPlayer = ToTFPlayer(GetOwner());
	if (!pTFPlayer)
		return;
	FireProjectile(pTFPlayer); // replace this later to fire a grenade with less velocity.
}

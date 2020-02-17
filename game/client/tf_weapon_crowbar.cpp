//====== Copyright © 1996-2005, Valve Corporation, All rights reserved. =======
//
// Purpose: 
//
//=============================================================================

#include "cbase.h"
#include "tf_weapon_crowbar.h"
#include "decals.h"

// Client specific.
#ifdef CLIENT_DLL
#include "c_tf_player.h"
// Server specific.
#else
#include "tf_player.h"
#endif

//=============================================================================
//
// Weapon Bottle tables.
//
IMPLEMENT_NETWORKCLASS_ALIASED(TFCrowbar, DT_TFWeaponCrowbar)

BEGIN_NETWORK_TABLE(CTFCrowbar, DT_TFWeaponCrowbar)
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA(CTFCrowbar)
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS(tf_weapon_crowbar, CTFCrowbar);
PRECACHE_WEAPON_REGISTER(tf_weapon_crowbar);

#define TF_BOTTLE_SWITCHGROUP 1

//=============================================================================
//
// Weapon Crowbar functions.
//

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
CTFCrowbar::CTFCrowbar()
{
}

void CTFCrowbar::WeaponReset(void)
{
	BaseClass::WeaponReset();
}

bool CTFCrowbar::DefaultDeploy(char* szViewModel, char* szWeaponModel, int iActivity, char* szAnimExt)
{
	bool bRet = BaseClass::DefaultDeploy(szViewModel, szWeaponModel, iActivity, szAnimExt);

	if (bRet)
	{
		SwitchBodyGroups();
	}

	return bRet;
}

void CTFCrowbar::SwitchBodyGroups(void)
{
	int iState = 0;

	SetBodygroup(TF_BOTTLE_SWITCHGROUP, iState);

	CTFPlayer* pTFPlayer = ToTFPlayer(GetOwner());

	if (pTFPlayer && pTFPlayer->GetActiveWeapon() == this)
	{
		if (pTFPlayer->GetViewModel())
		{
			pTFPlayer->GetViewModel()->SetBodygroup(TF_BOTTLE_SWITCHGROUP, iState);
		}
	}
}

void CTFCrowbar::Smack(void)
{
	BaseClass::Smack();

	if (ConnectedHit() && IsCurrentAttackACritical())
	{
		SwitchBodyGroups();
	}
}

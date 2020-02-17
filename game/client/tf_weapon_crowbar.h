//====== Copyright © 1996-2005, Valve Corporation, All rights reserved. =======
//
// Purpose: 
//
//=============================================================================

#ifndef TF_WEAPON_CROWBAR_H
#define TF_WEAPON_CROWBAR_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_melee.h"

#ifdef CLIENT_DLL
#define CTFCrowbar C_TFCrowbar
#endif

//=============================================================================
//
// Crowbar class.
//
class CTFCrowbar : public CTFWeaponBaseMelee
{
public:

	DECLARE_CLASS(CTFCrowbar, CTFWeaponBaseMelee);
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	CTFCrowbar();
	virtual int			GetWeaponID(void) const { return TF_WEAPON_CROWBAR; }
	virtual void		Smack(void);
	virtual void		WeaponReset(void);
	virtual bool		DefaultDeploy(char* szViewModel, char* szWeaponModel, int iActivity, char* szAnimExt);

	void				SwitchBodyGroups(void);

private:

	CTFCrowbar(const CTFCrowbar&) {}
	CNetworkVar(bool, m_bBroken);
};

#endif // TF_WEAPON_CROWBAR_H

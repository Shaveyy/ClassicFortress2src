//====== Copyright � 1996-2005, Valve Corporation, All rights reserved. =======
//
// Purpose: 
//
//=============================================================================

#ifndef TF_WEAPON_NAIL_H
#define TF_WEAPON_NAIL_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_melee.h"

#ifdef CLIENT_DLL
#define CTFNailnade C_TFNailnade
#endif

//=============================================================================
//
// Bottle class.
//
class CTFNailnade : public CTFWeaponBaseMelee
{
public:

	DECLARE_CLASS(CTFNailnade, CTFWeaponBaseMelee);
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	CTFNailnade();
	virtual int			GetWeaponID(void) const { return TF_WEAPON_NAILNADE; }

	virtual void		WeaponReset(void);
	virtual bool		DefaultDeploy(char* szViewModel, char* szWeaponModel, int iActivity, char* szAnimExt);
	virtual void		ItemPostFrame(void);
	virtual void		PrimaryAttack(void);
	virtual void		PrimaryAttack2(void);
	void				SwitchBodyGroups(void);
	CBaseEntity *FirePipebomb( CTFPlayer *pPlayer, int iSpecificNail );


private:

	CTFNailnade(const CTFNailnade&) {}
	CNetworkVar(bool, m_bBroken);
	CNetworkVar(bool, m_bCancharge);
};

#endif // TF_WEAPON_BOTTLE_H

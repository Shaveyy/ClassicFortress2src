//====== Copyright © 1996-2005, Valve Corporation, All rights reserved. =======
//
// Purpose: 
//
//=============================================================================

#ifndef TF_WEAPON_PIPE_H
#define TF_WEAPON_PIPE_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_weaponbase_melee.h"

#ifdef CLIENT_DLL
#define CTFPipenade C_TFPipenade
#endif

//=============================================================================
//
// Bottle class.
//
class CTFPipenade : public CTFWeaponBaseMelee
{
public:

	DECLARE_CLASS(CTFPipenade, CTFWeaponBaseMelee);
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	CTFPipenade();
	virtual int			GetWeaponID(void) const { return TF_WEAPON_PIPENADE; }

	virtual void		WeaponReset(void);
	virtual bool		DefaultDeploy(char* szViewModel, char* szWeaponModel, int iActivity, char* szAnimExt);
	virtual void		ItemPostFrame(void);
	virtual void		PrimaryAttack(void);
	virtual void		PrimaryAttack2(void);
	void				SwitchBodyGroups(void);
private:

	CTFPipenade(const CTFPipenade&) {}
	CNetworkVar(bool, m_bBroken);
	CNetworkVar(bool, firetwo);
};

#endif // TF_WEAPON_BOTTLE_H

//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
#include "cbase.h"
#include "func_no_jump.h"
#ifdef CLIENT_DLL
#else
#include "tf_team.h"
#include "ndebugoverlay.h"
#include "tf_obj.h"
#include "triggers.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "func_nogrenades.h"
#include "tf_player.h"
#endif
#include "in_buttons.h"
#include "tier0/memdbgon.h"

//-----------------------------------------------------------------------------
// Purpose: Defines an area where objects cannot be built
//-----------------------------------------------------------------------------
#ifndef CLIENT_DLL
class CFuncNoJump : public CBaseTrigger
{
	DECLARE_CLASS(CFuncNoJump, CBaseTrigger);
public:
	CFuncNoJump();

	DECLARE_DATADESC();

	virtual void Spawn(void);
	virtual void Precache(void);
	virtual void Activate(void);
	// Player Touch

private:
	bool	m_bActive;
};

LINK_ENTITY_TO_CLASS(func_nojump, CFuncNoJump);

BEGIN_DATADESC(CFuncNoJump)

END_DATADESC()


PRECACHE_REGISTER(func_nojump);

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
CFuncNoJump::CFuncNoJump()
{
}

//-----------------------------------------------------------------------------
// Purpose: Initializes the resource zone
//-----------------------------------------------------------------------------
void CFuncNoJump::Spawn(void)
{
	BaseClass::Spawn();
	InitTrigger();

	m_bActive = true;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CFuncNoJump::Precache(void)
{
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CFuncNoJump::Activate(void)
{
	BaseClass::Activate();
}


//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
#endif
bool InNoJumpZone(CBaseEntity* pOther)
{
#ifndef CLIENT_DLL
	CBaseEntity* pEntity = NULL;
	while ((pEntity = gEntList.FindEntityByClassname(pEntity, "func_nojump")) != NULL)
	{
		CFuncNoJump* pNoJump = (CFuncNoJump*)pEntity;
		// Are we within this no build?
		if (pNoJump->PointIsWithin(pOther->GetAbsOrigin()))
		{
			return true;	// prevent jumping.
		}
	}
#endif
		return false;
}


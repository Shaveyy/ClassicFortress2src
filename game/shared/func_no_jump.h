//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: Place where we can't build things.
//
// $NoKeywords: $
//=============================================================================//

#ifndef TF_FUNC_NO_JUMP_H
#define TF_FUNC_NO_JUMP_H

#ifdef _WIN32
#pragma once
#endif
#ifdef CLIENT_DLL
#else
#include "triggers.h"
#endif
//-----------------------------------------------------------------------------
// Is a given point contained within any construction yard?
//-----------------------------------------------------------------------------
	bool InNoJumpZone(CBaseEntity* pOther);

#endif // TF_FUNC_NO_BUILD_H

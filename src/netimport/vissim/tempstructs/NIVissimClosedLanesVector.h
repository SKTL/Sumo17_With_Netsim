/****************************************************************************/
/// @file    NIVissimClosedLanesVector.h
/// @author  Daniel Krajzewicz
/// @date    Sept 2002
/// @version $Id: NIVissimClosedLanesVector.h 13811 2013-05-01 20:31:43Z behrisch $
///
// -------------------
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.sourceforge.net/
// Copyright (C) 2001-2013 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
#ifndef NIVissimClosedLanesVector_h
#define NIVissimClosedLanesVector_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif


#include <vector>
#include "NIVissimClosedLaneDef.h"

typedef std::vector<NIVissimClosedLaneDef*> NIVissimClosedLanesVector;


#endif

/****************************************************************************/


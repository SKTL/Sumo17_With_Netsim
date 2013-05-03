/****************************************************************************/
/// @file    NIVissimClosedLaneDef.cpp
/// @author  Daniel Krajzewicz
/// @date    Sept 2002
/// @version $Id: NIVissimClosedLaneDef.cpp 13811 2013-05-01 20:31:43Z behrisch $
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


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <utils/common/VectorHelper.h>
#include "NIVissimClosedLaneDef.h"

#ifdef CHECK_MEMORY_LEAKS
#include <foreign/nvwa/debug_new.h>
#endif // CHECK_MEMORY_LEAKS


NIVissimClosedLaneDef::NIVissimClosedLaneDef(int lane,
        const std::vector<int>& assignedVehicles)
    : myLaneNo(lane), myAssignedVehicles(assignedVehicles) {}


NIVissimClosedLaneDef::~NIVissimClosedLaneDef() {}



/****************************************************************************/


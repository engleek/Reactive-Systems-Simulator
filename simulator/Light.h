/*******************************************************************************************
 **
 **    Copyright 2008 Simon & Humphries
 **
 **    This file is part of the Reactive Systems Simulator.
 **
 **    The Reactive Systems Simulator is free software: you can redistribute it and/or modify
 **    it under the terms of the GNU General Public License as published by
 **    the Free Software Foundation, either version 3 of the License, or
 **    (at your option) any later version.
 **
 **    The Reactive Systems Simulator is distributed in the hope that it will be useful,
 **    but WITHOUT ANY WARRANTY; without even the implied warranty of
 **    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **    GNU General Public License for more details.
 **
 **    You should have received a copy of the GNU General Public License
 **    along with the Reactive Systems Simulator .  If not, see <http://www.gnu.org/licenses/>.
 **
 ********************************************************************************************/

#ifndef LIGHT_H
#define LIGHT_H

#include "Entity.h"

using namespace qglviewer;

class Light : public Entity {
    public:
        Light();
        Light(Vec position, Vec angle);
        Light(lua_State* L) { } // Surdéfinition du constructeur obligatoire pour Lunar
        ~Light() { }

        void setPosition(lua_State* L);
        int setAngle(lua_State* L);

    private:
        friend class Lunar<Light>;
        static const char className[];
        static Lunar<Light>::RegType methods[];
};

#endif

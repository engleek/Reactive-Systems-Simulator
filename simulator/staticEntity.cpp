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

#include "staticEntity.h"

// Pour que Lunar comprenne quelque chose à ma classe :
const char StaticEntity::className[] = "StaticEntity";

#define method(class, name) {#name, &class::name}
Lunar<StaticEntity>::RegType StaticEntity::methods[] = {
	method(StaticEntity, setPosition),
	method(StaticEntity, setAngle),
	{0,0}
};

// Constructeur
StaticEntity::StaticEntity(void)
{
	new Entity();
}

StaticEntity::StaticEntity(Vec pos, Vec ang)
{
	new Entity(pos, ang);
}

// setPosition
// avec Lua
int StaticEntity::setPosition(lua_State* L)
{
	int nbArgs = lua_gettop(L);
	
	if (nbArgs == 3 && lua_isnumber(L,1) &&
		lua_isnumber(L,2) && lua_isnumber(L,3))
	{
		position->setValue(lua_tonumber(L,1), lua_tonumber(L,2), lua_tonumber(L,3));
	}
	else if (nbArgs == 0)
	{
		position->setValue(0, 0, 0);
	}
	else
	{
		std::cout << "StaticEntity:setPosition() : mauvais parametres" << std::endl;
	}
	
	return 0;
}

// setAngle
//avec Lua
int StaticEntity::setAngle(lua_State* L)
{
	int nbArgs = lua_gettop(L);
	
	if (nbArgs == 3 && lua_isnumber(L,1) &&
		lua_isnumber(L,2) && lua_isnumber(L,3))
	{
		angle->setValue(lua_tonumber(L,1), lua_tonumber(L,2), lua_tonumber(L,3));
	}
	else if (nbArgs == 0)
	{
		angle->setValue(0, 0, 0);
	}
	else
	{
		std::cout << "StaticEntity:setAngle() : mauvais parametres" << std::endl;
	}
	
	return 0;
}
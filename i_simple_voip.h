/*

Simple VOIP interface.

Copyright (C) 2016 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 5373 $ $Date:: 2016-12-28 #$ $Author: serge $

#ifndef SIMPLE_VOIP_I_SIMPLE_VOIP_H
#define SIMPLE_VOIP_I_SIMPLE_VOIP_H

namespace simple_voip
{

class ForwardObject;

class ISimpleVoip
{
public:
    virtual ~ISimpleVoip() {};

    virtual void consume( const ForwardObject * req )   = 0;
};

} // namespace simple_voip

#endif  // SIMPLE_VOIP_I_SIMPLE_VOIP_H

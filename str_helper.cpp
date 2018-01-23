/*

String Helper. Provides to_string() function.

Copyright (C) 2018 Sergey Kolevatov

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

// $Revision: 8603 $ $Date:: 2018-01-23 #$ $Author: serge $

#include "str_helper.h"             // self

#include <map>

namespace simple_voip
{

#define TUPLE_VAL_STR(_x_)  _x_,#_x_
#define TUPLE_STR_VAL(_x_)  #_x_,_x_

const std::string & StrHelper::to_string( Failed::type_e l )
{
    typedef Failed::type_e Type;
    typedef std::map< Type, std::string > Map;
    static Map m =
    {
        { Type:: TUPLE_VAL_STR( LOGGED_OUT ) },
        { Type:: TUPLE_VAL_STR( VOIP_ERROR ) },
        { Type:: TUPLE_VAL_STR( FAILED ) },
        { Type:: TUPLE_VAL_STR( REFUSED ) },
        { Type:: TUPLE_VAL_STR( BUSY ) },
        { Type:: TUPLE_VAL_STR( NOANSWER ) },
    };

    auto it = m.find( l );

    static const std::string undef( "undef" );

    if( it == m.end() )
        return undef;

    return it->second;
}

} // namespace simple_voip

/*

Simple VOIP config.

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

#ifndef SIMPLE_VOIP_CONFIG_H
#define SIMPLE_VOIP_CONFIG_H

#include <string>                   // std::string
#include <cstdint>                  // uint32_t

namespace simple_voip
{

struct Config
{
    std::string     called_id;
    std::string     username;
    std::string     password;
    std::string     host;
    uint32_t        port;
    uint32_t        relogin_pause; // pause in seconds before the next login attempt
    uint32_t        connection_lost_timeout_sec;
    uint32_t        ringing_timeout_sec;
    std::string     agent_name;
};

} // namespace simple_voip

#endif  // SIMPLE_VOIP_CONFIG_H

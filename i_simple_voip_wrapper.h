/*

Simple VOIP wrapper interface.

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

// $Revision: 5388 $ $Date:: 2016-12-29 #$ $Author: serge $

#ifndef SIMPLE_VOIP_I_SIMPLE_VOIP_WRAPPER_H
#define SIMPLE_VOIP_I_SIMPLE_VOIP_WRAPPER_H

#include "config.h"                 // Config
#include "i_simple_voip.h"          // ISimpleVoip
#include "i_simple_voip_callback.h" // ISimpleVoipCallback

namespace simple_voip
{

class ISimpleVoipWrapper: public ISimpleVoip
{
public:
    virtual ~ISimpleVoipWrapper() {};

    virtual bool init(
            const Config        & config,
            ISimpleVoipCallback * callback,
            std::string         & error_msg )           = 0;

    virtual void shutdown()                             = 0;
};

} // namespace simple_voip

#endif  // SIMPLE_VOIP_I_SIMPLE_VOIP_WRAPPER_H

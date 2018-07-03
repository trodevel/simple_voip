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

// $Revision: 9495 $ $Date:: 2018-07-03 #$ $Author: serge $

#include "str_helper.h"             // self

#include <map>
#include <typeinfo>

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

std::ostream & StrHelper::write( std::ostream & os, const simple_voip::IObject & o )
{
    os << typeid( o ).name();

    if( typeid( o ) == typeid( simple_voip::InitiateCallRequest ) )
    {
        auto & m = dynamic_cast<const simple_voip::InitiateCallRequest&>( o );

        os << " " << m.req_id << " " << m.party;
    }
    else if( typeid( o ) == typeid( simple_voip::ErrorResponse ) )
    {
        auto & m = dynamic_cast<const simple_voip::ErrorResponse&>( o );

        os << " " << m.req_id << " " << m.errorcode << " " << m.descr;
    }
    else if( typeid( o ) == typeid( simple_voip::RejectResponse ) )
    {
        auto & m = dynamic_cast<const simple_voip::RejectResponse&>( o );

        os << " " << m.req_id << " " << m.errorcode << " " << m.descr;
    }
    else if( typeid( o ) == typeid( simple_voip::InitiateCallRequest ) )
    {
        auto & m = dynamic_cast<const simple_voip::InitiateCallRequest&>( o );

        os << " " << m.req_id << " " << m.party;
    }
    else if( typeid( o ) == typeid( simple_voip::InitiateCallResponse ) )
    {
        auto & m = dynamic_cast<const simple_voip::InitiateCallResponse&>( o );

        os << " " << m.req_id << " " << m.call_id;
    }
    else if( typeid( o ) == typeid( simple_voip::DropRequest ) )
    {
        auto & m = dynamic_cast<const simple_voip::DropRequest&>( o );

        os << " " << m.req_id << " " << m.call_id;
    }
    else if( typeid( o ) == typeid( simple_voip::DropResponse ) )
    {
        auto & m = dynamic_cast<const simple_voip::DropResponse&>( o );

        os << " " << m.req_id;
    }
    else if( typeid( o ) == typeid( simple_voip::PlayFileRequest ) )
    {
        auto & m = dynamic_cast<const simple_voip::PlayFileRequest&>( o );

        os << " " << m.req_id << " " << m.call_id << " " << m.filename;
    }
    else if( typeid( o ) == typeid( simple_voip::PlayFileResponse ) )
    {
        auto & m = dynamic_cast<const simple_voip::PlayFileResponse&>( o );

        os << " " << m.req_id;
    }
    else if( typeid( o ) == typeid( simple_voip::PlayFileStopRequest ) )
    {
        auto & m = dynamic_cast<const simple_voip::PlayFileStopRequest&>( o );

        os << " " << m.req_id << " " << m.call_id;
    }
    else if( typeid( o ) == typeid( simple_voip::PlayFileStopResponse ) )
    {
        auto & m = dynamic_cast<const simple_voip::PlayFileStopResponse&>( o );

        os << " " << m.req_id;
    }
    else if( typeid( o ) == typeid( simple_voip::RecordFileRequest ) )
    {
        auto & m = dynamic_cast<const simple_voip::RecordFileRequest&>( o );

        os << " " << m.req_id << " " << m.call_id << " " << m.filename;
    }
    else if( typeid( o ) == typeid( simple_voip::RecordFileResponse ) )
    {
        auto & m = dynamic_cast<const simple_voip::RecordFileResponse&>( o );

        os << " " << m.req_id;
    }
    else if( typeid( o ) == typeid( simple_voip::RecordFileStopRequest ) )
    {
        auto & m = dynamic_cast<const simple_voip::RecordFileStopRequest&>( o );

        os << " " << m.req_id << " " << m.call_id;
    }
    else if( typeid( o ) == typeid( simple_voip::RecordFileStopResponse ) )
    {
        auto & m = dynamic_cast<const simple_voip::RecordFileStopResponse&>( o );

        os << " " << m.req_id;
    }
    else if( typeid( o ) == typeid( simple_voip::Failed ) )
    {
        auto & m = dynamic_cast<const simple_voip::Failed&>( o );

        os << " " << m.call_id << " " << to_string( m.type ) << " " << m.descr;
    }
    else if( typeid( o ) == typeid( simple_voip::Dialing ) )
    {
        auto & m = dynamic_cast<const simple_voip::Dialing&>( o );

        os << " " << m.call_id;
    }
    else if( typeid( o ) == typeid( simple_voip::Ringing ) )
    {
        auto & m = dynamic_cast<const simple_voip::Ringing&>( o );

        os << " " << m.call_id;
    }
    else if( typeid( o ) == typeid( simple_voip::Connected ) )
    {
        auto & m = dynamic_cast<const simple_voip::Connected&>( o );

        os << " " << m.call_id;
    }
    else if( typeid( o ) == typeid( simple_voip::ConnectionLost ) )
    {
        auto & m = dynamic_cast<const simple_voip::ConnectionLost&>( o );

        os << " " << m.call_id << " " << m.descr;
    }
    else if( typeid( o ) == typeid( simple_voip::CallDuration ) )
    {
        auto & m = dynamic_cast<const simple_voip::CallDuration&>( o );

        os << " " << m.call_id << " " << m.t;
    }
    else if( typeid( o ) == typeid( simple_voip::DtmfTone ) )
    {
        auto & m = dynamic_cast<const simple_voip::DtmfTone&>( o );

        os << " " << m.call_id << " " << int( m.tone );
    }

    return os;
}

const std::string StrHelper::to_string( const simple_voip::IObject & o )
{
    std::stringstream os;

    write( os, o );

    return os.str();
}

} // namespace simple_voip

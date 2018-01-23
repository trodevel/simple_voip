/*

Simple VOIP objects.

Copyright (C) 2017 Sergey Kolevatov

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


// $Revision: 6031 $ $Date:: 2017-03-15 #$ $Author: serge $

#ifndef SIMPLE_VOIP_OBJECT_FACTORY_H
#define SIMPLE_VOIP_OBJECT_FACTORY_H

#include "objects.h"    // Object...

namespace simple_voip
{

template <class T>
void init_req_id( T * obj, uint32_t req_id )
{
    obj->req_id = req_id;
}

template <class T>
void init_call_id( T * obj, uint32_t call_id )
{
    obj->call_id = call_id;
}

template <class T>
T *create_message_t( uint32_t call_id )
{
    T *res = new T;

    init_call_id( res, call_id );

    return res;
}

inline InitiateCallRequest *create_initiate_call_request( uint32_t req_id, const std::string & party )
{
    auto * res = new InitiateCallRequest;

    init_req_id( res, req_id );

    res->party      = party;

    return res;
}

inline InitiateCallResponse *create_initiate_call_response( uint32_t req_id, uint32_t call_id )
{
    auto * res = new InitiateCallResponse;

    init_req_id( res, req_id );

    res->call_id    = call_id;

    return res;
}

inline DropRequest *create_drop_request( uint32_t req_id, uint32_t call_id )
{
    auto * res = new DropRequest;

    init_req_id( res, req_id );

    res->call_id    = call_id;

    return res;
}

inline DropResponse *create_drop_response( uint32_t req_id )
{
    auto * res = new DropResponse;

    init_req_id( res, req_id );

    return res;
}

inline PlayFileRequest *create_play_file_request( uint32_t req_id, uint32_t call_id, const std::string & filename )
{
    auto * res = new PlayFileRequest;

    init_req_id( res, req_id );

    res->call_id    = call_id;
    res->filename   = filename;

    return res;
}

inline PlayFileResponse *create_play_file_response( uint32_t req_id )
{
    auto * res = new PlayFileResponse;

    init_req_id( res, req_id );

    return res;
}

inline PlayFileStopRequest *create_play_file_stop_request( uint32_t req_id, uint32_t call_id )
{
    auto * res = new PlayFileStopRequest;

    init_req_id( res, req_id );

    res->call_id    = call_id;

    return res;
}

inline PlayFileStopResponse *create_play_file_stop_response( uint32_t req_id )
{
    auto * res = new PlayFileStopResponse;

    init_req_id( res, req_id );

    return res;
}

inline RecordFileRequest *create_record_file_request( uint32_t req_id, uint32_t call_id, const std::string & filename )
{
    auto * res = new RecordFileRequest;

    init_req_id( res, req_id );

    res->call_id    = call_id;
    res->filename   = filename;

    return res;
}

inline RecordFileResponse *create_record_file_response( uint32_t req_id )
{
    auto * res = new RecordFileResponse;

    init_req_id( res, req_id );

    return res;
}

inline ErrorResponse *create_error_response( uint32_t req_id, uint32_t errorcode, const std::string & descr )
{
    auto * res = new ErrorResponse;

    init_req_id( res, req_id );

    res->errorcode  = errorcode;
    res->descr      = descr;

    return res;
}

inline RejectResponse *create_reject_response( uint32_t req_id, uint32_t errorcode, const std::string & descr )
{
    auto * res = new RejectResponse;

    init_req_id( res, req_id );

    res->errorcode  = errorcode;
    res->descr      = descr;

    return res;
}

inline Failed *create_failed( uint32_t call_id, Failed::type_e type, const std::string & descr )
{
    auto * res = create_message_t<Failed>( call_id );

    res->type       = type;
    res->descr      = descr;

    return res;
}

inline ConnectionLost *create_connection_lost( uint32_t call_id, const std::string & descr )
{
    auto * res = create_message_t<ConnectionLost>( call_id );

    res->descr      = descr;

    return res;
}

inline DtmfTone *create_dtmf_tone( uint32_t call_id, DtmfTone::tone_e tone )
{
    auto * res = create_message_t<DtmfTone>( call_id );

    res->tone       = tone;

    return res;
}

} // namespace simple_voip

#endif  // SIMPLE_VOIP_OBJECT_FACTORY_H

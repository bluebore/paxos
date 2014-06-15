// Copyright (c) 2014, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: yanshiguang02@baidu.com

#ifndef  PAXOS_PAXOS_SERVER_IMPL_H_
#define  PAXOS_PAXOS_SERVER_IMPL_H_

#include <paxos.pb.h>

namespace paxos {

class PaxosServerImpl : public PaxosServer{
public:
    inline PaxosServerImpl() {};
    virtual ~PaxosServerImpl();

    virtual void Prepare(::google::protobuf::RpcController* controller,
            const ::paxos::PrepareRequest* request,
            ::paxos::PrepareResponse* response,
            ::google::protobuf::Closure* done);
    virtual void Accept(::google::protobuf::RpcController* controller,
            const ::paxos::AcceptRequest* request,
            ::paxos::AcceptResponse* response,
            ::google::protobuf::Closure* done);
};

} // namespace paxos

#endif  //__PAXOS_IMPL_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

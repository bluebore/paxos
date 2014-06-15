// Copyright (c) 2014, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: yanshiguang02@baidu.com

void PaxosServerImpl::Prepare(::google::protobuf::RpcController* controller,
        const ::paxos::PrepareRequest* request,
        ::paxos::PrepareResponse* response,
        ::google::protobuf::Closure* done) {
    done->Run();
}

void PaxosServerImpl::Accept(::google::protobuf::RpcController* controller,
        const ::paxos::AcceptRequest* request,
        ::paxos::AcceptResponse* response,
        ::google::protobuf::Closure* done) {
    done->Run();
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

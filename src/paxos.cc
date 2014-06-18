// Copyright (c) 2014, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: yanshiguang02@baidu.com

#include <stdio.h>
#include <sofa/pbrpc/pbrpc.h>
#include "paxos_server_impl.h"

namespace paxos {

class PaxosImpl : public Paxos {
public:
    PaxosImpl() {}
    ~PaxosImpl() {}
    bool Start(int port);
    bool Stop();
    std::string Commit(const std::string& value);
private:
    sofa::pbrpc::RpcServer* rpc_server_;
    PaxosServerImple* paxos_server_;
}

PaxosImpl::PaxosImpl() 
    : rpc_server(NULL), paxos_server_(NULL) {
}

PaxosImpl::~PaxosImpl() {
    rpc_server_->Stop();
    delete rpc_server_;
}

bool PaxosImpl::Start(int port) {
    sofa::pbrpc::RpcServerOptions options;
    rpc_server_ = new sofa::pbrpc::RpcServer(options);
    char addr[16];
    snprintf(addr, 16, "0.0.0.0:%d", port);
    if (!rpc_server.Start(addr)) {
        fprintf(stderr, "Bind to %d failed!\n", port);
        return false;
    }

    paxos_server_ = new PaxosServerImpl();
    if (!rpc_server.RegisterService(paxos_server_)) {
        fprintf(stderr, "Register service failed");
        return false;
    }
    rpc_server->Run();

    return true;
}

bool PaxosImpl::Stop() {
    rpc_server->Stop();
    return true;
}

bool Paxos::Commit(const std::string& value) {
    sofa::pbrpc::RpcClientOptions client_options;
    sofa::pbrpc::RpcClient rpc_client(client_options);
    sofa::pbrpc::RpcChannelOptions channel_options;
    sofa::pbrpc::RpcChannel rpc_channel(&rpc_client, "127.0.0.1:10000", channel_options);

    PaxosServer_Stub stub(&rpc_channel);

    PrepareRequest request;
    request.set_id(0);
    request.set_value(value);
    return true;
}

}  // namespace paxos

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

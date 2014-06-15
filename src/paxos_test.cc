// Copyright (c) 2014, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: yanshiguang02@baidu.com


#include "paxos.h"


int main(int argc, char* argv[]) {
    Paxos::Paxos paxos;
    paxos.Start();
    paxos.Vote();
    paxos.Stop();

    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

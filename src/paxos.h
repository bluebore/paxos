// Copyright (c) 2014, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: yanshiguang02@baidu.com

#ifndef  PAXOS_PAXOS_H_
#define  PAXOS_PAXOS_H_

#include <string>

namespace paxos {

class Paxos {
public:
    bool Start(int port);
    bool Stop();
    std::string Vote();
};

}

#endif  //PAXOS_PAXOS_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

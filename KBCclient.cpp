//
//  KBCclient.cpp
//  screenshot
//
//  Created by 张瑶林 on 2020/7/16.
//  Copyright © 2020 mian. All rights reserved.
//

#include "KBCclient.hpp"
#include <sys/unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

#include <string>

using namespace std;

void
client() {
    int socketFd = socket(AF_INET, SOCK_STREAM, 0);
    //要连接的服务器的 ip 和 端口
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = 0x00000000;
    serverAddress.sin_port = 0xBEAF;
    
    //客户端直接连接服务器，无需其他设置
    connect(socketFd, (struct sockaddr *)&serverAddress,
            sizeof(serverAddress));
    string data = "shi wo da ge";
    send(socketFd, data.c_str(), data.length(), 0);
}

int
main() {
    client();
    return 0;
}

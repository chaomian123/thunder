//
//  KBCserver.cpp
//  screenshot
//
//  Created by 张瑶林 on 2020/7/16.
//  Copyright © 2020 mian. All rights reserved.
//

#include "KBCserver.hpp"

#include <sys/unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

void
server() {
    int socketFd = socket(AF_INET, SOCK_STREAM, 0);
    //ip 和 端口
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = 0x00000000;
    serverAddress.sin_port = 0xBEAF;
    
    //向os申请端口
    bind(socketFd, (struct sockaddr *)&serverAddress,
         sizeof(serverAddress));
//    第二个参数无脑写6
    listen(socketFd, 6);
    
    struct sockaddr_in clientAddress;
    socklen_t len = sizeof(clientAddress);
    int connection = accept(socketFd, (struct sockaddr*)&clientAddress, &len);
    
    //执行到这， 说明已经创建了连接， 可以直接读取客户端发送来的数据
    const int size = 100;
    char data[100];
    recv(connection, data, size, 0);
    printf("recv: (%s)\n", data);
}

int
main() {
    server();
    return 0;
}

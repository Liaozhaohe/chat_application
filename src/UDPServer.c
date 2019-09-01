/*
 * @Copyright: CS Department, BIT
 * @Author: Liao Zhaohe
 * @FileName: 
 * @Version: 
 * @Date: 2019-08-30 00:38:55
 * @LastEditors: 
 * @LastEditTime: 2019-08-30 01:19:59
 * @Description: 
 */

#include "head.h"

int main()
{
    socketfd sock;
    if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
        ERR_EXIT("Socket Error");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
}

/*
 * @Copyright: School of Computer Science & Technology, BIT
 * @Author: Liao Zhaohe
 * @FileName: 
 * @Version: 
 * @Date: 2019-09-01 20:14:09
 * @LastEditors: 
 * @LastEditTime: 2019-09-02 01:29:55
 * @Description: 
 */
#include "head.h"

int main()
{
    socketfd client_fd;
    struct sockaddr_in server_addr_in;
    server_addr_in.sin_addr.s_addr = inet_addr("0.0.0.0");
    server_addr_in.sin_family = AF_INET;
    server_addr_in.sin_port = htons(PORT);

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        printf("Socket Error!\n%s(errno: %d)\n", strerror(errno), errno);
    printf("**********Socket Opened***********\n");

    if (connect(client_fd, (struct sockaddr *)&server_addr_in, sizeof(server_addr_in)) != 0)
        printf("Connect Error!\n%s(errno: %d)\n", strerror(errno), errno);
    printf("**********Connection Established***********\n");

    char buf[512];
    memset(buf, 0, sizeof(buf));
    while (1)
    {
        printf("Message: ");
        scanf("%s", buf);
        send(client_fd, buf, sizeof(char) * 512, 0);
    }

    close(client_fd);
}

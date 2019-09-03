/*
 * @Copyright: School of Computer Science & Technology, BIT
 * @Author: Liao Zhaohe
 * @FileName: 
 * @Version: 
 * @Date: 2019-08-31 23:27:12
 * @LastEditors: 
 * @LastEditTime: 2019-09-02 05:57:34
 * @Description: 
 */

#include <head.h>

INT16 main()
{
    socketfd server_sock_fd;
    if ((server_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        printf("Socket Error!\n%s(errno: %d)\n", strerror(errno), errno);

    struct sockaddr_in server_addr;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Reuse the port
    INT16 optval = 1;
    size_t optlen = sizeof(optval);
    setsockopt(server_sock_fd, SOL_SOCKET, SO_REUSEPORT, &optval, optlen);

    if (bind(server_sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        printf("Bind Error!\n%s(errno: %d)\n", strerror(errno), errno);

    if (listen(server_sock_fd, MAX_FD) == -1)
        printf("Listen Error!\n%s(errno: %d)\n", strerror(errno), errno);

    printf("\n***********Listening**********\n");

    socketfd connected_fd[MAX_FD];
    memset(connected_fd, 0, sizeof(connected_fd));
    INT16 connect_num = 0;

    fd_set read_fdset, write_fdset;
    FD_ZERO(&read_fdset);
    FD_ZERO(&write_fdset);
    FD_SET(server_sock_fd, &read_fdset);

    printf("Into Loop...\n");
    while (1)
    {
        FD_ZERO(&read_fdset);
        FD_SET(server_sock_fd, &read_fdset);
        for (int ii = 0; ii < connect_num; ii++)
        {
            FD_SET(connected_fd[ii], &read_fdset);
        }

        int t = select(FD_SETSIZE, &read_fdset, NULL, NULL, NULL);
        printf("Select Returns: %d\n", t);

        if (FD_ISSET(server_sock_fd, &read_fdset)) // A new connection request
        {
            if (connect_num < MAX_FD)
            {
                struct sockaddr_in client_addr_in;
                INT16 client_size = sizeof(client_addr_in);
                socketfd client_fd = accept(server_sock_fd, &client_addr_in, &client_size);
                printf("\n**********New Client Accepted**********\n");

                connected_fd[connect_num] = client_fd;
                connect_num++;
            }
            else
            {
                printf("Accept Error: User Limit Exceeded!");
            }
        }
        //else
        {
            int ii = 0; // Iteration Variable
            for (ii = 0; ii < connect_num; ii++)
            {
                if (FD_ISSET(connected_fd[ii], &read_fdset))
                {
                    INT8 msg[512];
                    bzero(msg, sizeof(msg));
                    recv(connected_fd[ii], msg, sizeof(msg), 0);
                    printf("Recieved Message: %s\n", msg);
                    printf("ii = %d\n", ii);
                }
            }
        }
    }

    close(server_sock_fd);

    return 0;
}

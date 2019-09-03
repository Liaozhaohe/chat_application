/*
 * @Copyright: CS of BIT
 * @Author: 王占坤
 * @File name: 
 * @Version: 
 * @Date: 2019-08-30 15:08:30 +0800
 * @LastEditTime: 2019-09-02 20:07:09
 * @LastEditors: 
 * @Description: 这里是主头文件，包含了所有的库文件，全局变量声明，结构体声明等
 */
#ifndef __HEAD_H__
#define __HEAD_H__
///////////////include库文件区/////////////
#include "config.h" //这里为了防止遗忘，确保把config文件链接到所有文件中
#include <stdio.h>
#include <stdlib.h>
//#include <gtk/gtk.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <cJSON.h>

/////////////define区////////////////////
#define PORT 54323
#define MAX_FD 20 // max number of client communicating with server
//////////////typedef区/////////////////

/**
 * @Author: Liao Zhaohe
 * @Description: Define data type by their lenth.
 */
typedef int socketfd;

typedef signed char INT8;
typedef unsigned char UINT8;
typedef int INT16;
typedef unsigned int UINT16;
typedef long int INT32;
typedef unsigned long int UINT32;
typedef long long int INT64;
typedef unsigned long long int UINT64;

typedef float FLOAT32;
typedef double FLOAT64;

typedef unsigned char BOOLEAN;
typedef unsigned char boolean;

/////////////全局结构体定义区//////////

/**
 * @Author: Liao Zhaohe
 * @Description: Define information exchange code.
 *               See details in "数据封装规范要求与信息列表.xml"
 */
enum INFO_CODE
{
    /*********** Client Info Code ************/
    CL_INTERNET_WRONG = 101,
    CL_ACCOUNT_NOTEXIST = 102,
    CL_ACCOUNT_ONLINE = 103,
    CL_FILE_SEND = 104,
    CL_FILE_RECEIVE = 105,
    CL_FILE_LARGE = 106,
    CL_NO_RESPOUND = 107,
    CL_FILE_OVERDUE = 108,

    /******** Communication Info Code ********/
    CM_NO_CONNECTION_TO_SERVER = 201,
    CM_NO_CONNECTION_TO_CLIENT = 202,

    /********** Data Base info Code **********/
    DB_PASSWD_WRONG = 301,
    DB_USER_NOT_EXIST = 302,
    DB_USER_HAS_BEEN_ONLINE = 303,
    DB_LOGIN_ACC = 304,
    DB_PASSWD_CHANGE_ACC = 305,
    DB_PASSWD_CHANGE_REJ = 306,
    DB_FILE_SAVED = 307,
    DB_USER_LOG_OUT = 308,
    DB_CJSON_PARSE_ERR = 309,
    DB_FIRST_LOGIN = 310,
    DB_DATABASE_ERROR = 311
};

///////////////全局变量声明区/////////////

#endif
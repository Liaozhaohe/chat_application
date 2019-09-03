#ifndef __DBINFORMATION_H__
#define __DBINFORMATION_H__

/*
 * @Copyright: School of Computer Science & Technology, BIT
 * @Author: Liao Zhaohe
 * @FileName: 
 * @Version: 
 * @Date: 2019-09-02 18:21:23
 * @LastEditors: 
 * @LastEditTime: 2019-09-02 23:29:44
 * @Description: 
 */
#include "head.h"

INFO_CODE parse_login_info(cJSON *login_info, char *user_name, char *user_ip, char *password);

#endif //!__DBINFORMATION_H__
/*
 * @Copyright: School of Computer Science & Technology, BIT
 * @Author: Liao Zhaohe
 * @FileName: 
 * @Version: 
 * @Date: 2019-09-02 23:26:29
 * @LastEditors: 
 * @LastEditTime: 2019-09-03 01:02:57
 * @Description: 
 */
#include "DBInformation.h"

INFO_CODE parseToString(cJSON *json, char *string, const char *name)
{
    cJSON *j_str = NULL;
    if ((j_str = cJSON_GetObjectItem(json, name)) == NULL)
        return DB_CJSON_PARSE_ERR;
    strcpy(string, j_str->valuestring);
    return ACCEPTED;
}

/**
 * @Author: Liao Zhaohe
 * @Description: 
 *      Parse the log in information (cJSON formate) to char* that the database uses.
 * @Parameters: 
 *      cJSON* login_info: a pointer to a cJson struct, which is passed to database by the 
 *          socket server.
 *      char* user_name: Provided by DB, stores username parsed fron cJSON.
 *      char* user_ip: Provided by DB, stores user_ip parsed fron cJSON.
 *      char* password: Provided by DB, stores password parsed fron cJSON.
 * @Return: 
 *      Return 0 for parsing info successfully, info code for other condition. (See in Throw)
 * @Throw: 
 *      DB_CJSON_PARSE_ERR : when passed cJSON has the error structure.
 */
INFO_CODE parseLoginInfo(cJSON *login_info, char *user_name, char *user_ip, char *password)
{
    INFO_CODE info;
    if ((info = parseToString(login_info, user_name, "user_name")) != ACCEPTED)
        return info;
    if ((info = parseToString(login_info, user_ip, "user_ip")) != ACCEPTED)
        return info;
    if ((info = parseToString(login_info, password, "password")) != ACCEPTED)
        return info;

    return ACCEPTED;
}

/**
 * @Author: Liao Zhaohe
 * @Description: Parse the username information fron cJSON to char*.
 * @Parameters: 
 *      cJSON* login_info: a pointer to a cJson struct, which is passed to database by the 
 *              socket server.
 *      char* user_name: Provided by DB, stores username parsed fron cJSON.
 * @Return: 
 *      Return 0 for parsing info successfully, info code for other condition. (See in Throw)
 * @Throw: 
 *      DB_CJSON_PARSE_ERR : when passed cJSON has the error structure.
 */
INFO_CODE parseUserName(cJSON *username_json, char *username)
{
    return parseToString(username_json, username, "username");
}

/**
 * @Author: Liao Zhaohe
 * @Description: Parse the information fron cJSON to char*. This information is used to change
 *               password question.
 * @Parameters: 
 *     cJSON* change_passwd_ques_info: a pointer to a cJson struct, which is passed to database by the 
 *            socket server.
 *     char* user_ip : Provided by DB, stores user ip parsed fron cJSON.
 *     char* user_name : Provided by DB, stores user name parsed fron cJSON.
 *     char* question : Provided by DB, stores question parsed fron cJSON
 *     char* answer : Provided by DB, stores answer parsed fron cJSON
 * @Return: 
 *      Return 0 for parsing info successfully, info code for other condition. (See in Throw)
 * @Throw: 
 *      DB_CJSON_PARSE_ERR : when passed cJSON has the error structure.
 */
INFO_CODE parseChangePasswdQuestionInfo(
    cJSON *change_passwd_ques_info,
    char *user_ip,
    char *user_name,
    char *question,
    char *answer)
{
    INFO_CODE info;
    if ((info = parseToString(change_passwd_ques_info, user_ip, "user_ip")) != ACCEPTED)
        return info;
    if ((info = parseToString(change_passwd_ques_info, user_name, "user_name")) != ACCEPTED)
        return info;
    if ((info = parseToString(change_passwd_ques_info, question, "question")) != ACCEPTED)
        return info;
    if ((info = parseToString(change_passwd_ques_info, answer, "answer")) != ACCEPTED)
        return info;

    return ACCEPTED;
}

/**
 * @Author: Liao Zhaohe
 * @Description: Parse the information fron cJSON to char*. This information is used to get
 *               password question.
 * @Parameters: 
 *     cJSON* get_passwd_ques_info: a pointer to a cJson struct, which is passed to database by the 
 *            socket server.
 *     char* user_name : Provided by DB, stores username parsed fron cJSON
 * @Return: 
 *      Return 0 for parsing info successfully, info code for other condition. (See in Throw)
 * @Throw: 
 *      DB_CJSON_PARSE_ERR : when passed cJSON has the error structure.
 */
INFO_CODE parseGetPasswdQuestionInfo(
    cJSON *get_passwd_ques_info,
    char *user_name)
{
    return parseToString(get_passwd_ques_info, user_name, "user_name");
}

/**
 * @Author: Liao Zhaohe
 * @Description: Parse the information fron cJSON to char*. This information is used to change
 *               password question.
 * @Parameters: 
 *     cJSON* change_passwd_ques_info: a pointer to a cJson struct, which is passed to database by the 
 *              socket server.
 *     char* user_name: Provided by DB, stores username parsed fron cJSON
 *     char* answer: Provided by DB, stores answer parsed fron cJSON
 *     cher* passwd: Provided by DB, stores passwd parsed fron cJSON
 * @Return: 
 *      Return 0 for parsing info successfully, info code for other condition. (See in Throw)
 * @Throw: 
 *      DB_CJSON_PARSE_ERR : when passed cJSON has the error structure.
 */
INFO_CODE parseChangePasswdInfo(
    cJSON *change_passwd_info,
    char *user_name,
    char *answer,
    char *passwd)
{
    INFO_CODE info;
    if ((info = parseToString(change_passwd_info, user_name, "user_name")) != ACCEPTED)
        return info;
    if ((info = parseToString(change_passwd_info, answer, "answer")) != ACCEPTED)
        return info;
    if ((info = parseToString(change_passwd_info, passwd, "passwd")) != ACCEPTED)
        return info;

    return ACCEPTED;
}

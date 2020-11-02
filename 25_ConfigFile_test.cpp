/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/16 上午 08:12
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
#include"ConfigFile.h"

using namespace std;

int main25() {

    char * filePath = "D:\\Program_Files\\JetBrains\\CLionProjects\\c_base_pro\\config.ini";
    char ** fileData = NULL;
    struct ConfigInfo *info = NULL;
    int lines =0;
    //加载配置文件
    loadFile_ConfigFile(filePath,&fileData,&lines);
    //解析配置文件
    parseFile_ConfigFile(fileData,lines,&info);

    printf("IP:%s \n", getInfo_ConfigFile("ip",info,lines));
    printf("ppp:%s \n", getInfo_ConfigFile("ppp",info,lines));
    printf("TTT:%s \n", getInfo_ConfigFile("TTT",info,lines));

    //释放配置信息内存
    destroInfo_ConfigFile(info);
    return 0;
}

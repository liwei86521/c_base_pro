/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/15 上午 10:26
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

//查找子串第一次出现的位置
char* myStrStr(const char *str, const char *substr){

    const char *mystr = str;
    const char *mysub = substr;

    while (*mystr != '\0')
    {
        if (*mystr != *mysub)
        {
            ++mystr;
            continue;
        }


        //临时指针变量
        const char *temp_mystr = mystr;
        const char *temp_mysub = mysub;

        while (*temp_mysub != '\0')
        {

            if (*temp_mystr != *temp_mysub)
            {
                ++mystr;
                break;
            }

            temp_mysub++;
            temp_mystr++;

        }

        //说明匹配成功
        if (*temp_mysub == '\0')
        {
            return (char *)mystr;
        }

    }

    return NULL;
}

void test20()
{
    char *str = "abcdefg";
    char *sub = "def";
    char *pos = myStrStr(str, sub);
    printf("pos = %s\n", pos);

}

int main20() {

    test20();

    return 0;
}

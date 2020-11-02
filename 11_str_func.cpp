#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test_strlen();

void test_strcpy();

void test_strcat();

void test_strcmp();

void test_strstr();

void test_strtok();
void copyString01(char *dst, const char *source);
void copyString02(char *dst, const char *source);
void reverseString11(char *str);

void test01() {
    char str1[] = {'h', 'e', 'l', 'l', 'o'}; //字数数组不是字符串， 因为后面没有 '\0'
    printf("%s\n", str1);
}

void test02_str()
{
    char *source = "hello world!";
    char buf[1024] = {0};
    //copyString01(buf, source);
    copyString02(buf, source);
    printf("%s\n",buf);

}
void test03_str()
{
    char p[] = "abc";
    //char *p = "hello world!"; // 这个不能让这样传
    reverseString11(p);
    printf("p = %s", p);
}
void test04_str()
{
    //1. 格式化字符串
    char buf[1024] = { 0 };
    // sprintf 最常见的应用之一莫过于把结构打印到字符串中 如buf
    sprintf(buf, "Hello %s!", "Obama");
    printf("buf:%s\n",buf);

}

void reversPrint(char *p){
    //1. 首先要退出递归退出条件
    if (*p == '\0'){
        return;
    }

    reversPrint(p + 1);
    printf("%c",*p);
}

void test11_12(){
    char *s = "abcdefg";
    reversPrint(s);
}

int main11_67(){
    test11_12();
    //test03_str();
    //test04_str();

    return 0;

}

void copyString01(char *dst, const char *source)
{
    int len = strlen(source);

    for (int i = 0; i < len; ++i)
    {
        dst[i] = source[i];
    }

    dst[len] = '\0';
}

void copyString02(char *dst, const char *source)
{
    while (*source != '\0')
    {
        *dst = *source;
        ++dst;
        ++source;
    }

    *dst = '\0';
}

void reverseString11(char *str){
     if (NULL == str)
    {
        return;
    }

    int len = strlen(str);

    int start = 0;
	int end = len - 1;
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		++start;
		--end;
	}

// method 2
//    char *pStart = str;
//    char *pEnd = str + len - 1;
//
//    while (pStart < pEnd)
//    {
//        char temp = *pStart;
//        *pStart = *pEnd;
//        *pEnd = temp;
//
//        ++pStart;
//        --pEnd;
//    }

}

void test_strtok() {
    char a[100] = "adc*fvcv*ebcy*hghbdfg*casdert";
    char *s = strtok(a, "*");//将"*"分割的子串取出
    //printf("s ---> %s\n", s); // 获取第一个子字符串  s ---> adc

    while (s != NULL){ // 继续获取其他的子字符串
        printf("%s\n", s);
        s = strtok(NULL, "*");
    }
}

void test_strstr() {
    char src[] = "dddfabcd123abcd333abcd";
    char *p = strstr(src, "fa");// 在字符串src中查找字符串needle出现的位置
    printf("p = %s\n", p); // p = fabcd123abcd333abcd

}

void test_strcmp() {
    char *str1 = "hello world";
    char *str2 = "hello mike";
    if (strcmp(str1, str2) == 0){
        printf("str1==str2\n");
    }
    else if (strcmp(str1, str2) > 0){
        printf("str1>str2\n");
    }else{
        printf("str1<str2\n");
    }
}

void test_strcat() {
    char str[20] = "123";
    char *src = "hello world";
    printf("%s\n", strcat(str, src));
}

void test_strcpy() {
    char arr1[] = "hello word";
    char arr2[100];
    char arr3[100];
    //参数：目标字符串 源字符串
// 功能：把src所指向的字符串复制到dest所指向的空间中，'\0'也会拷贝过去
    if (strcpy(arr2, arr1) != NULL){
    	printf("拷贝成功！ \n");
    }
    printf("%s\n", arr2);

    //参数：目标字符串 源字符串 字符长度   注:有限拷贝不会将\0拷贝到目标字符串中
    strncpy(arr3, arr1, 5); //把前5个字符copy过去
    arr3[5] = '\0';//48 0   加上'\0'  不然会乱码
    printf("%s\n", arr3);

}

void test_strlen() {
    char arr[] = "hello";
    int len = strlen(arr);
    printf("字符串的有效长度：%d\n", len); // 5
    printf("字符串的长度：%d \n", sizeof(arr)); // 6

    int index = 0;
    while (arr[index] != '\0'){
        index++;
    }
    printf("%d\n", index);
}

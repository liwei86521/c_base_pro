#include <iostream>
using namespace std;

#define LAG >
#define SMA <
#define EQ ==
#define TRUE 1
#define FALSE 0
#define swap(a,b) { int t;t=*a;*a=*b;*b=t;}//注意放在一行里 参数a,b不要写数据类型
#define swap2(a,b) { a=a^b; b=a^b; a=a^b;}//注意放在一行里 参数a,b不要写数据类型
int maxNum(int a, int b);
#define MAXIMUM(x,y)(x>y)?x:y
#define MINIMUM(x,y) (x>y)?y:x
void reverse(char* s);
int length(char *s);  // 求字符串长度

void print_arr_str(); // 打印字符串数组
void oct2ten(); // 8进制数转化为十进制

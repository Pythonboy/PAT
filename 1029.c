/*
时间：2018/6/23 16点20分
作者：楼浩然
题目：
1029 旧键盘(20)（20 分）
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：

输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过80个字符的串，由字母A-Z（包括大、小写）、数字0-9、以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。

输出格式：

按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。

输入样例：

7_This_is_a_test
_hs_s_a_es
输出样例：

7TI
*/

//思路：解题关键在于使用strchr函数判断字符是否在某个字符串中出现过

#include <stdio.h>
#include <string.h>
#define SIZE 81

int main(void)
{
    char a[SIZE],b[SIZE],c[SIZE];
    scanf("%s",a);
    scanf("%s",b);
    int length = strlen(a);
    int i;//循环计数
    int z=0;
    for(i=0 ; i<length ; i++)
    {
        if((strchr(b,a[i])== 0) && (strchr(c,a[i])==0))
        {
            if(a[i]>='a'&a[i]<='z')
            {
                a[i] = a[i]-32;
            }
            if(strchr(c,a[i])==0)
            {
                c[z] = a[i];
                z++;
            }
        }
    }
    for(i=0 ; i<z ; i++)
        printf("%c",c[i]);
    return 0;
}

/*
反省：
要熟悉掌握字符串的各种内置函数
*/

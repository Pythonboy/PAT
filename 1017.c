/*
ʱ��;2018/6/19 15��22��
���ߣ�¥��Ȼ
��Ŀ��
1017 A����B (20)��20 �֣�
����Ҫ�����A/B������A�ǲ�����1000λ����������B��1λ������������Ҫ�������Q������R��ʹ��A = B * Q + R������
�����ʽ��
������1�������θ���A��B���м���1�ո�ָ���
�����ʽ��
��1�����������Q��R���м���1�ո�ָ���
����������
123456789050987654321 7
���������
17636684150141093474 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
char a[MAX];
char res[MAX];

int main(void)
{
    char c;
    int num;
    int i = 0;
    int Re,j,mid = 0;
    while (scanf("%c",&c) && c != ' ')
    {
        a[i] = c;
        i++;
    }
    scanf("%d",&num);
    for (j=0 ; j<i ; j++)
    {
        int temp = ((a[j]-'0')+mid*10)/num;
        mid = ((a[j]-'0')+mid*10)%num;
        res[j] = temp + '0';
    }
    Re = mid;
    int len = strlen(res);
    if(res[0] != '0'&& len > 1)
        printf("%c",res[0]);
    else if(res[0] == '0' && len == 1)
        printf("%c",res[0]);
    for ( j=1 ; j<len ; j++)
        printf("%c",res[j]);
    printf(" %d\n",Re);
    return 0;
}

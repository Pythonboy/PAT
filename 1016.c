/*
ʱ�䣺2018/6/19 15��45��
���ߣ�¥��Ȼ
��Ŀ��
1016 ����A+B (15)��15 �֣�
������A�ġ�D~A~��Ϊ1λ���������֡�����Ϊ��A������D~A~��ɵ�������P~A~�����磺����A = 3862767��D~A~ = 6����A�ġ�6���֡�P~A~��66����ΪA����2��6��
�ָ���A��D~A~��B��D~B~�����д�������P~A~ + P~B~��
�����ʽ��
������һ�������θ���A��D~A~��B��D~B~���м��Կո�ָ�������0 < A, B < 10^10^��
�����ʽ��
��һ�������P~A~ + P~B~��ֵ��
��������1��
3862767 6 13530293 3
�������1��
399
��������2��
3862767 1 13530293 8
�������2��
0
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
char shuru_1[MAX];
char shuru_2[MAX];

int part(char * p , int num)
{
    int i = 0;
    int total = 0;
    int res = num;
    while ( p[i] != '\0')
    {
        if ( (p[i] - '0') == num)
            total += 1;
        i++;
    }
    if (total == 0)
        return 0;
    else
    {
        for ( i=1 ; i<total ; i++)
        {
            res = res*10 + num;
        }
        return res;
    }
}

int main(void)
{
    int num_1,num_2;
    scanf("%s %d %s %d",shuru_1,&num_1,shuru_2,&num_2);
    int a[2]={0,0};
    a[0] = part(shuru_1,num_1);
    a[1] = part(shuru_2,num_2);
    printf("%d\n",a[0]+a[1]);
    return 0;
}

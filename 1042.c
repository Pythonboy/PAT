/*
ʱ�䣺2018/6/24 19��16��
���ߣ�¥��Ȼ
��Ŀ��
1042 �ַ�ͳ��(20)��20 �֣�
���д�����ҳ�һ�θ��������г�����Ƶ�����Ǹ�Ӣ����ĸ��

�����ʽ��

������һ���и���һ�����Ȳ�����1000���ַ������ַ�����ASCII���������ɼ��ַ����ո���ɣ����ٰ���1��Ӣ����ĸ���Իس��������س��������ڣ���

�����ʽ��

��һ�����������Ƶ����ߵ��Ǹ�Ӣ����ĸ������ִ���������Կո�ָ�������в��У����������ĸ����С���Ǹ���ĸ��ͳ��ʱ�����ִ�Сд�����Сд��ĸ��

����������

This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
���������

e 7
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1001

int cmp(const void * a, const void * b)
{
    return (*(char *)a - *(char *)b);
}

int main(void)
{
    char N[SIZE];
    gets(N);
    int len = strlen(N);
    char shuru[SIZE];
    int i,j=0;
    for(i=0 ; i<len ; i++)
    {
        if((N[i]>='A'&&N[i]<='Z')||(N[i]>='a'&&N[i]<='z'))
        {
            if(N[i]>='A'&&N[i]<='Z')
            {
                shuru[j] = tolower(N[i]);
                j++;
            }
            else
            {
                shuru[j] = N[i];
                j++;
            }
        }
    }
    shuru[j] = '\0';
    char ch;
    qsort(shuru,j,sizeof(char),cmp);
    int total = 1;  //��¼�����ַ������ַ������ֵĴ���
    char c;  //��¼���������ַ�
    int zs=0; //��¼ÿ���ַ����ֵĸ���
    for(i=1 ; i<j ; i++)
    {
        if(shuru[i]==shuru[i-1])
        {
            if(i==1)
                zs+=2;
            else
                zs+=1;
            if(zs>total)
            {
                total = zs;
                c = shuru[i];
            }
        }
        else
        {
            zs=1;
            if(zs>total)
            {
                total = zs;
                c = shuru[i];
            }
        }
    }
    if(total==1)
        printf("%c %d",shuru[0],total);
    else
        printf("%c %d",c,total);
    return 0;


}

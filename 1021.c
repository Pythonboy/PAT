/*
ʱ�䣺2018/6/19 14��37��
���ߣ�¥��Ȼ
1021 ��λ��ͳ�� (15)��15 �֣�
����һ��kλ����N = d~k-1~*10^k-1^ + ... + d~1~*10^1^ + d~0~ (0<=d~i~<=9, i=0,...,k-1, d~k-1~>0)�����д����ͳ��ÿ�ֲ�ͬ�ĸ�λ���ֳ��ֵĴ��������磺����N = 100311������2��0��3��1����1��3��
�����ʽ��
ÿ���������1��������������һ��������1000λ��������N��
�����ʽ��
��N��ÿһ�ֲ�ͬ�ĸ�λ���֣���D:M�ĸ�ʽ��һ���������λ����D������N�г��ֵĴ���M��Ҫ��D�����������
����������
100311
���������
0:2
1:3
3:1
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1001
char array[MAX];

int main(void)
{
    int i = 0;
    char c;
    int j;
    int res[10] = {0,0,0,0,0,0,0,0,0,0};
//    while (scanf("%c",&c) && c != '\n')  //������һ��д�����ܹ�ͨ�����Ե�
    while (scanf("%c",&c)!= EOF)
    {
        array[i] = c;
        i++;
    }
    for ( j=0 ; j<i; j++)
    {
        int temp = array[j] - '0';    //�����õ�һ�ֽ��ַ�����ת��Ϊ���ֵķ���
        res[temp] += 1;
    }
    for ( j=0 ; j<10 ; j++)
    {
        if (res[j] != 0)
            printf("%d:%d\n",j,res[j]);
    }
    return 0;
}


/*   �������ͣ�������̫��ʱ���޷�����
void did(int * p, long int n);  //ͳ�Ƹ�λ��
void print(int * p);

int main(void)
{
    long int num;
    int a[10]={0,0,0,0,0,0,0,0,0,0};
    int i;
    scanf("%ld",&num);
    did(a,num);
    print(a);
    return 0;
}

void did(int * p, long int n)
{
    int i;
    while(n!=0)
    {
        i = n%10;
        p[i] += 1;
        n = n/10;
    }
}

void print(int * p)
{
    int i;
    for( i=0 ; i<=9 ; i++)
    {
        if ( p[i] != 0)
            printf("%d:%d\n",i,p[i]);
    }
}
*/

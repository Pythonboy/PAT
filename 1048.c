/*
ʱ�䣺2018/6/21 09��06��
���ߣ�¥��Ȼ
��Ŀ��
1048 ���ּ���(20)��20 �֣�
����Ҫ��ʵ��һ�����ּ��ܷ��������ȹ̶�һ��������������A������һ������B������ÿ1λ������A�Ķ�Ӧλ���ϵ����ֽ����������㣺������λ����Ӧλ��������Ӻ��13ȡ�ࡪ��������J����10��Q����11��K����12����ż��λ����B�����ּ�ȥA�����֣������Ϊ���������ټ�10���������λΪ��1λ��

�����ʽ��

������һ�������θ���A��B����Ϊ������100λ��������������Կո�ָ���

�����ʽ��

��һ����������ܺ�Ľ����

����������

1234567 368782971
���������

3695Q8118
*/

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char A[101], B[101];
    char encrypt[] = "0123456789JQK";

    scanf("%s %s", A, B);
    int lenA = strlen(A);
    int lenB = strlen(B);
    int maxlen = lenA > lenB ? lenA : lenB;
    int a, b;
    int i;

    for(i = 0; i < maxlen; i++)
    {
        a = lenA + i - maxlen < 0 ? 0 : A[lenA + i - maxlen] - '0';
        b = lenB + i - maxlen < 0 ? 0 : B[lenB + i - maxlen] - '0';
        if((maxlen - i) % 2)    putchar(encrypt[(a + b) % 13]);
        else                    putchar('0' + (b - a < 0 ? b - a + 10 : b - a));
    }

    return 0;
}
*/

//���ˣ����Ǻ÷���
#include <stdio.h>
#include <string.h>
#define MAX 101
char A[MAX]; //���A�ַ���
char B[MAX];//���B�ַ���

void coding(char * a, char * b,int la ,int lb); //��B�ַ�������

int main(void)
{
    scanf("%s %s",A,B);
    int len_A = strlen(A); //A�ַ����ĳ���
    int len_B = strlen(B);  //B�ַ����ĳ���
    if(len_A > len_B)
    {
        int le = len_A - len_B ;  //ȷ����Ҫ��B�ַ���ǰ����Ӽ���0
        int i;  //ѭ������
        for(i=len_B ; i>=0 ; i--)
            B[i+le] = B[i];
        for(i=0 ; i<le ; i++)
            B[i] = '0';
        len_B = len_A;
    }
    coding(A,B,len_A,len_B);
    printf("%s",B);
    return 0;
}

char yu_shu(int n)
{
    if(n==11)
        return 'Q';
    else if(n==10)
        return 'J';
    else if(n==12)
        return 'K';
    else
        return n+'0';
}

void coding(char * a, char * b,int la ,int lb)
{
    int i;//ѭ������
    int length = la > lb? lb:la;
    int tem;
    for(i=1 ; i<=length ; i++)
    {
        if(i%2)
        {
            tem = (b[lb-1]-'0'+a[la-1]-'0')%13;
  //          printf("%d\n",tem);
            b[lb-1] = yu_shu(tem);
            lb--;
            la--;
        }
        else
        {
            tem = b[lb-1] - a[la-1];
            if(tem<0)
                tem+=10;
//            printf("%d\n",tem);
            b[lb-1] = tem+'0';
            lb--;
            la--;
        }
    }
}


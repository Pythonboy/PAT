/*
ʱ�䣺2018/6/20 19��56��
���ߣ�¥��Ȼ
��Ŀ��
1027 ��ӡɳ©(20)��20 �֣�
����Ҫ����д������Ѹ����ķ��Ŵ�ӡ��ɳ©����״���������17����*����Ҫ�����и�ʽ��ӡ

*****
 ***
  *
 ***
*****
��ν��ɳ©��״������ָÿ��������������ţ����з������Ķ��룻�������з�������2���������ȴӴ�С˳��ݼ���1���ٴ�С����˳���������β��������ȡ�

��������N�����ţ���һ�����������һ��ɳ©��Ҫ���ӡ����ɳ©���õ������ܶ�ķ��š�

�����ʽ��

������һ�и���1��������N��<=1000����һ�����ţ��м��Կո�ָ���

�����ʽ��

���ȴ�ӡ���ɸ���������ɵ�����ɳ©��״�������һ�������ʣ��û�õ��ķ�������

����������

19 *
���������

*****
 ***
  *
 ***
*****
2
*/

#include <stdio.h>

int length(int N, int * n);  //�����һ�е���Ŀ
void Paint(int M ,char ch);  //M�����һ�еķ��������ú������ڻ�©��

int main(void)
{
    int N,n; //N������ķ�������n����ʣ�µķ�����
    char ch; //©��ʹ�õķ���
    scanf("%d %c",&N,&ch);
    int max_length;  //©�������з���������Ŀ
    max_length = length(N,&n);
    Paint(max_length,ch);
    printf("%d\n",n);
    return 0;
}

int length(int N, int * n)
{
    if(N==1)
    {
        *n = 0;
        return 1;
    }
    int max_length;
    int sum = -1; //©���еķ�����
    for(max_length = 1 ; sum < N ; max_length += 2)
    {
        sum+=max_length*2;
    }

    sum -= (max_length-2)*2;
    *n = N - sum;        //ʣ�µķ�����
    max_length -=4;
    return max_length;
}

void Paint(int M,char ch)
{
    int i,j,z; //����ѭ������
    for (i=M ; i>=1 ; i-=2)
    {
        for(j=0;j<(M-i)/2;j++)putchar(' ');
        for(z=0;z<i;z++)putchar(ch);
        putchar('\n');
    }
    for (i=3 ; i<=M ; i+=2)
    {
        for(j=0;j<(M-i)/2;j++)putchar(' ');
        for(z=0;z<i;z++)putchar(ch);
        putchar('\n');
    }
}

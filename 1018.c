/*
ʱ�䣺2018/6/19 16��27��
���ߣ�¥��Ȼ
��Ŀ��
1018 ���Ӽ����� (20)��20 �֣�
���Ӧ�ö����桰���Ӽ�����������Ϸ������ͬʱ�������ƣ�ʤ��������ͼ��ʾ��
�ָ������˵Ľ����¼����ͳ��˫����ʤ��ƽ�������������Ҹ���˫���ֱ��ʲô���Ƶ�ʤ�����
�����ʽ��
�����1�и���������N��<=10^5^������˫������Ĵ��������N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�C�������ӡ���J������������B������������1����ĸ����׷�����2�������ҷ����м���1���ո�
�����ʽ��
�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ�����3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�����ⲻΨһ�����������ĸ����С�Ľ⡣
����������
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
���������
5 3 2
2 3 5
B B
*/

//���Ե����ȥ�������ڵ����д���ȷ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int who_win(char a, char b);  //�����Ӯ�����0 �� �����Ӯ�����1��
int ci_shu(char a);//��Ӯ��ʱ�����ʲô�������C������0�������J������1�������B������2��
char * shu_chu_zi_mu(int (*p)[3]); //�Ƚ�ÿ����ĸ���ֵĴ��������������ĸ
void game(char * j, char * y, int num, int (*r)[3], int (*re)[3]); //������λѡ��ʯͷ�������������������
int main(void)
{
    int num;
    scanf("%d",&num);
    char jia[num],yi[num];
    char * b;
    int i;
    for( i=0 ; i<num ; i++)
        scanf(" %c %c",&jia[i],&yi[i]); //�������ʼ�ӿո񣬷������ֿո��������⣬�������ն�����ַ���������
    int res[2][3]={{0,0,0},{0,0,0}};
    int res_cishu[2][3]={{0,0,0},{0,0,0}};
    game( jia, yi, num , res, res_cishu);
    b = shu_chu_zi_mu(res_cishu);
    for( i=0 ; i<2 ; i++)
    {
        int j;
        for ( j=0 ; j<2 ; j++)
            printf("%d ",res[i][j]);
        printf("%d\n",res[i][2]);
    }
    printf("%c %c",b[0],b[1]);
    return 0;
}

int who_win(char a, char b)
{
    if (a == 'C' && b == 'J')
        return 0;
    else if (a == 'C' && b == 'B')
        return 1;
    else if (a == 'J' && b == 'C')
        return 1;
    else if( a == 'J' && b == 'B')
        return 0;
    else if (a == 'B' && b == 'C')
        return 0;
    else if (a == 'B' && b == 'J')
        return 1;
}

int ci_shu(char a)
{
    if(a == 'J')
        return 0;
    else if(a == 'C')
        return 1;
    else if(a == 'B')
        return 2;
}

char * shu_chu_zi_mu(int (*p)[3])
{
    char a[2];
    char * z;
    z = (char *)malloc(sizeof(char)*2);
    int i;
    for (i=0 ; i<2 ; i++)
    {
        if(p[i][2] >= p[i][1] && p[i][2] >= p[i][0])
            a[i] = 'B';
        else if(p[i][1] >= p[i][0] && p[i][1] > p[i][2])
            a[i] = 'C';
        else
            a[i] = 'J';
    }
    z = a;
    return z;
}

void game(char * j, char * y, int num ,int (*r)[3] ,int (*re)[3])
{
    int i;
    for (i=0 ; i<num ; i++)
    {
        if (y[i] == j[i])
        {
            r[0][1] += 1;
            r[1][1] += 1;
        }
        else
        {
            int tem = who_win(j[i],y[i]);
            r[tem][0] += 1;
            if (tem == 1)
            {
                int mid = ci_shu(y[i]);
                re[tem][mid]+=1;
            }
            else
            {
                int mid = ci_shu(j[i]);
                re[tem][mid]+=1;
            }
        }
    }
    r[0][2] = num - r[0][1] - r[0][0];
    r[1][2] = num - r[1][1] - r[1][0];
}


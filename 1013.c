/*
ʱ�䣺2018/6/15 09��26��
���ߣ�¥��Ȼ
��Ŀ��
1013 ������ (20)��20 �֣�
��P~i~��ʾ��i�����������θ�����������M <= N <= 10^4^�������P~M~��P~N~������������
�����ʽ��
������һ���и���M��N������Կո�ָ���
�����ʽ��
�����P~M~��P~N~������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�
����������
5 27
���������
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
#include <stdio.h>
#include <math.h>

void primer(int num_1,int num_2);
int IsPrime(int n);

int main(void)
{
    int i,j;
    scanf("%d %d",&i,&j);
    primer(i,j);
    return 0;
}

int IsPrime(int z)        //�ж��Ƿ�Ϊ����
{
    int item = (int)sqrt(z)+1;
    int j;
    if (z<2)
        return 0;
    else if (z == 2 || z == 3)
        return 1;
    else if (z%6!=1 && z%6!=5)
        return 0;
    for (j = 5; j < item; j+=6)
    {
        if (z%j==0 || z%(j+2)==0)
            return 0;
    }
    return 1;
}

void primer(int num_1,int num_2)
{
    int prime[num_2 - num_1];
    int i = 0;
    int j = 2;
    int z;
    int total = 0;
    while (total < num_2)          //��������������������������
    {
        if (IsPrime(j))
        {
            total++;
            if(total>=num_1)
            {
                prime[i] = j;
                i++;
            }
        }
        if(j%2!=0)
            j+=2;
        else
            j++;
    }
    for(z=0 ; z<num_2-num_1+1 ; z++)         //����ʽ�������
    {

        if((z+1)%10!=0 && (z+1)!=num_2-num_1+1)
            printf("%d ",prime[z]);
        else if((z+1)%10==0 && (z+1) != num_2-num_1+1)
            printf("%d\n",prime[z]);
        else
            printf("%d",prime[z]);
    }
}

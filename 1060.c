/*
ʱ�䣺2018/6/24 14��23��
���ߣ�¥��Ȼ
��Ŀ��
1060 ��������(25)��25 �֣�
Ӣ������ѧ�Ұ����ٺ�ϲ���ﳵ����˵��Ϊ����ҫ�Լ����ﳵ��������������һ��������������E����������E���ﳵ����EӢ����������E����˵�������Լ���E����87��

�ָ���ĳ��N����ﳵ���룬���������Ӧ�İ�������E��<=N����

�����ʽ��

�����һ�и���һ��������N��<=10^5^�����������ﳵ���������ڶ��и���N���Ǹ�����������ÿ����ﳵ���롣

�����ʽ��

��һ���и���N��İ���������

����������

10
6 7 6 9 3 10 8 2 7 8
���������

6
*/

/*  ��ȷ��
#include <stdio.h>
#include <stdlib.h>

int sort(const void * a, const void * b)
{
    return (*(int*)b-*(int*)a);
}

int main(void)
{
    int N;//����Ŀ
    scanf("%d",&N);
    int i; //ѭ������
    int num[N]; //�������
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    qsort(num,N,sizeof(int),sort);
    for(i=0;i<N && num[i]>i+1;i++);
    printf("%d",i);
    return 0;
}
*/


/*  24fen����һ�����Ե����ȥ
#include <stdio.h>
#include <stdlib.h>

int sort(const void * a, const void * b)
{
    return (*(int*)a-*(int*)b);
}

int main(void)
{
    int N;//����Ŀ
    scanf("%d",&N);
    int i; //ѭ������
    int num[N]; //�������
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
    qsort(num,N,sizeof(int),sort);
    int E;
    for(i=0 ; i<N ; i++)
    {
        E = N-i;
        if(num[i]>E)
            break;
    }
    printf("%d",E);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
//void bubble_sort(int * a, int n); //�������С��������
void InsertionSort(int * n ,int N);
//int cmp (const void * a, const void * b){   return ( *(int*)a - *(int*)b );}
int main(void)
{
    int N;//����Ŀ
    scanf("%d",&N);
    int i; //ѭ������
    int num[N]; //�������
    for(i=0 ; i<N ; i++)
        scanf("%d",&num[i]);
 //   qsort(num,N,sizeof(int),cmp);
    InsertionSort(num,N);
    int E; //��������
    for(E=0 ; E<N && num[E]>E+1 ; E++);        //ԭ�ȵ�E���ж�������������
    printf("%d",E);
    return 0;
}


//���г�ʱ
void InsertionSort(int * n ,int N)
{
    int i,j; //ѭ������
    for(i=1 ; i<N ; i++)
    {
        int tem = n[i];
        for(j=i ; j>0 && n[j-1]<tem ; j--)
            n[j] = n[j-1];
        n[j] = tem;
    }
}


/*
void bubble_sort(int * a, int n)
{
    int i,j; //����ѭ������
    int change; //y�����жϵڶ���ѭ�����Ƿ����Ԫ�ػ�������
    int k; //����Ԫ�ػ���
    for(i = n-1 , change = 1 ; i>=1 && change ; i--)
    {
        change = 0;
        for (j=0 ; j<n-1 ; j++)
        {
            if(a[j]>a[j+1])
            {
                k = a[j];
                a[j] = a[j+1];
                a[j+1] = k;
                change = 1;
            }
        }
    }
}
*/

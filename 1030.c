/*
ʱ�䣺2018/6/23 17��03��
���ߣ�¥��Ȼ
��Ŀ��
1030 ��������(25)��25 �֣�
����һ�����������У���������p������������е����ֵ��M����Сֵ��m�����M <= m * p���������������������С�

���ڸ�������p��һЩ���������������ѡ�񾡿��ܶ��������һ���������С�

�����ʽ��

�����һ�и�������������N��p������N��<= 10^5^����������������ĸ�����p��<= 10^9^���Ǹ����Ĳ������ڶ��и���N����������ÿ����������10^9^��

�����ʽ��

��һ�������������ѡ����ٸ����������������һ���������С�

����������

10 8
2 3 20 4 5 1 6 7 8 9
���������

8
*/

#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int * a,int n); //ð������  //�����㷨û������
//int comp(const void *a, const void *b) { return *(int*)a - *(int*)b; }

int main(void)
{
    int N,P; //MΪ�����е�Ԫ�ظ�����PΪ��������
    scanf("%d %d",&N,&P);
    int num[N]; //�洢����������Ԫ��
    int i,j;//ѭ������
    for(i=0 ; i<N ; i++) //Ԫ�ظ�ֵ
        scanf("%d",&num[i]);
    bubble_sort(num,N); //�����н�������
//    qsort(num, N, sizeof(int), comp);
    int res=0;// ��¼��������������ж��ٸ�Ԫ��
    /*  //�ⲿ�ּ�¼res�Ĺ���������
    for(i=0 ; i<N-1; i++)
    {
        for(j=N-1; j>i ; j--)
        {
            if(num[j]<=num[i]*P*1L)
            {
                if(j-i+1 > res)
                    res = j-i+1;
            }
            if(j-i<res)
                break;
        }
        if(N-i-1<res)
            break;
    }
    */
    int first,last;
    for(first = 0, last = 0; last < N; first++)  //����������last�õĺܾ���
    {
        while(last < N && num[last] <= 1L * num[first] * P)
            last++;
        if(res < last - first)
            res = last - first;
    }
    printf("%d",res);
    return 0;
}


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


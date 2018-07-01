/*
ʱ�䣺2018/6/25 19��15��
���ߣ�¥��Ȼ
��Ŀ��
1025 ��ת���� (25)��25 �֣�
����һ������K�Լ�һ��������L�����д����L��ÿK����㷴ת�����磺����LΪ1��2��3��4��5��6��KΪ3�������Ӧ��Ϊ3��2��1��6��5��4�����KΪ4�������Ӧ��Ϊ4��3��2��1��5��6������󲻵�K��Ԫ�ز���ת��

�����ʽ��

ÿ���������1������������ÿ������������1�и�����1�����ĵ�ַ������ܸ���������N(<= 10^5^)���Լ�������K(<=N)����Ҫ��ת���������ĸ��������ĵ�ַ��5λ�Ǹ�������NULL��ַ��-1��ʾ��

��������N�У�ÿ�и�ʽΪ��

Address Data Next

����Address�ǽ���ַ��Data�Ǹý�㱣����������ݣ�Next����һ���ĵ�ַ��

�����ʽ��

��ÿ������������˳�������ת�����������ÿ�����ռһ�У���ʽ��������ͬ��

����������

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
���������

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/

#include <stdio.h>
#include <stdlib.h>

#define SWAP(A,B) {Node temp = A; A = B; B = temp;}

struct node{
    int address;
    int data;
    int next;
};

typedef struct node * Node;

int main(void)
{
    Node *list,*p;
    int addre,N,K;
    scanf("%d %d %d",&addre,&N,&K);
    list = (Node *)malloc(sizeof(Node)*N);
    int i,j;
    for(i=0 ; i<N ; i++)
    {
        list[i] = malloc(sizeof(struct node));
        scanf("%d %d %d",&list[i]->address,&list[i]->data,&list[i]->next);
    }
    for(i=0 ; i<N ; i++)
    {
        for(j=i ; j<N ; j++)
        {
            if(list[j]->address==(i?list[i-1]->next:addre)){
                SWAP(list[i],list[j]);
                break;
            }
        }
        if(list[i]->next == -1)
        {
            N = i+1;
        }
    }
    for(i = 0; i < N / K; i++)
    {
        p = list + i * K;
        for(j = 0; j < K / 2; j++)
        {
            SWAP(p[j], p[K - j - 1]);
        }
    }
    for(i=0 ; i<N-1 ; i++)
        printf("%05d %d %05d\n",list[i]->address,list[i]->data,list[i+1]->address);
    printf("%05d %d -1\n",list[N-1]->address,list[N-1]->data);
    return 0;
}


/*
�ܽ᣺
1.ָ���ָ����ڴ����

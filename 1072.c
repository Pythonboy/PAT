/*
ʱ�䣺2018/6/24 10��01��
���ߣ�¥��Ȼ
��Ŀ��
�����ʽ��
�����һ�и������������� N���� 1000���� M���� 6�����ֱ���ѧ����������Ҫ����ɵ���Ʒ���������ڶ��и��� M ����Ҫ����ɵ���Ʒ��ţ����б��Ϊ 4 λ���֡���� N �У�ÿ�и���һλѧ����������д���� 1-4 ����дӢ����ĸ��ɣ���������Ʒ���� K��0 �� K �� 10�����Լ� K ����Ʒ�ı�š�

�����ʽ��
˳�μ��ÿ��ѧ��Я������Ʒ���������Ҫ����ɵ���Ʒ���ڣ������¸�ʽ�����������Ϣ������Ҫ����ɵ���Ʒ����Ϣ��ע����ĩ�����ж���ո񣩣�

������д: ��Ʒ���1 ��Ʒ���2 ����
���һ��������������ѧ�����������ͱ������Ʒ��������

����������
4 2
2333 6666
CYLL 3 1234 2345 3456
U 4 9966 6666 8888 6666
GG 2 2333 7777
JJ 3 0012 6666 2333
���������
U: 6666 6666
GG: 2333
JJ: 6666 2333
3 5
*/

#include <stdio.h>
#include <string.h>

struct student{
    char Name[5];
    int d; //ѧ����Ʒ����
    int thing[10];
};

int IsIn(int i,int * n, int m)
{
    int j;
    for(j=0 ; j<m ;j++)
    {
        if(i==n[j])
            return 1;
    }
    return 0;
}

int main(void)
{
    int N,m;//N ����ѧ��������m������Ҫ��ѯ����Ʒ��Ŀ
    scanf("%d %d",&N,&m);
    struct student Stu[N];
    int check[m];  //�����Ҫ��ѯ����Ʒ���
    int i,j; //ѭ������
    int total_s=0,total_t = 0;//�ֱ��¼��ѯ����ѧ����������Ʒ����
    for(i=0 ; i<m ; i++)
        scanf("%d",&check[i]);
//    for(i=0 ; i<m ; i++)       //˵��cheak����û������
 //       printf("%d",check[i]);
    for(i=0 ; i<N ;i++)
    {
        scanf("%s",Stu[i].Name);
        scanf("%d",&Stu[i].d);
        for(j=0 ; j<Stu[i].d ;j++)
            scanf("%d",&Stu[i].thing[j]);
    }

    for(i=0 ; i<N ; i++)
    {
        int flag = 0;
        int t = 0; //��¼ÿ��ѧʤ�� �鵽����Ʒ����
        for(j=0 ; j<Stu[i].d ; j++)
        {
 //           printf("%d\n",Stu[i].thing[j]);  //˵���ṹ����thing��������û������
            if(IsIn(Stu[i].thing[j],check,m))
            {
                if(t==0)
                    printf("%s: %04d",Stu[i].Name,Stu[i].thing[j]);
                else
                    printf(" %04d",Stu[i].thing[j]);
                t+=1;
                flag = 1;
                total_t += 1;
            }
        }
        if(flag == 1)
        {
            total_s += 1;
            printf("\n");
        }

    }
    printf("%d %d",total_s,total_t);
    return 0;


}

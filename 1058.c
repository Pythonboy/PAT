/*
ʱ�䣺2018/6/27 23��48��
���ߣ�¥��Ȼ
��Ŀ��
1058 ѡ���⣨20 �֣�
���Ķ�ѡ���ǱȽ��鷳�����飬���������д�����������ʦ���Ķ�ѡ�⣬����ָ���ĵ���������ࡣ

�����ʽ��
�����ڵ�һ�и������������� N���� 1000���� M���� 100�����ֱ���ѧ�������Ͷ�ѡ��ĸ�������� M �У�ÿ��˳�θ���һ���������ֵ�������� 5 ������������ѡ������������� 2 �Ҳ����� 5 ��������������ȷѡ�������������ѡ�����������������������ȷѡ�ע��ÿ���ѡ���СдӢ����ĸ a ��ʼ˳�����С�������� 1 ���ո�ָ������ N �У�ÿ�и���һ��ѧ���Ĵ����������ÿ��𰸸�ʽΪ (ѡ�е�ѡ����� ѡ��1 ����)������Ŀ˳�������ע�⣺��Ŀ��֤ѧ���Ĵ�������ǺϷ��ģ���������ѡ�е�ѡ��������ʵ��ѡ�����������

�����ʽ��
���������˳�����ÿ��ѧ���ĵ÷֣�ÿ������ռһ�С�ע������ʱֻ��ѡ��ȫ����ȷ���ܵõ�����ķ��������һ��������������Ŀ�Ĵ�������ͱ�ţ���Ŀ���������˳��� 1 ��ʼ��ţ�������в��У��򰴱�ŵ���˳����������ּ��ÿո�ָ�������β�����ж���ո����������Ŀ��û���˴��������һ����� Too simple��

����������
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
���������
3
6
5
2 2 3 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Max(int * E,int M)
{
    int i;
    int max = 0;
    for(i=0 ; i<M ; i++)
    {
        if(E[i]>max)
            max = E[i];
    }
    return max;

}

struct score{
    int perfect_score; //����
    int choice ;//ѡ�����
//    int right;//��ȷ��ѡ�����
    char xuanxiang[20];//ѡ��
};

int main(void)
{
    int N,M;//�ֱ����ѧ�������Ͷ�ѡ�����
    scanf("%d %d",&N,&M);
    while(getchar()!='\n')
        continue;
    int i,j;//ѭ������
    struct score *sco[M];
    for(i=0 ; i<M ; i++)
    {
        sco[i] = malloc(sizeof(struct score));
        scanf("%d %d",&sco[i]->perfect_score,&sco[i]->choice);
        getchar();
        scanf("%[^\n]",sco[i]->xuanxiang);
    }
    while(getchar()!='\n')
        continue;
//    for(i=0 ; i<M ; i++)
//        printf("%s\n",sco[i]->xuanxiang);      //����û������
    int grade[N];
    memset(grade,0,sizeof(int)*N);
    int error[M] ;
    memset(error,0,sizeof(int)*M);
    for(i=0 ; i<N ; i++)
    {
        char student[M][20];
        char ch;
        int j=0;
        while((ch = getchar())!='\n')
        {
            if(ch=='(')
            {
                scanf("%[^)]",student[j]);
                if(!strcmp(student[j],sco[j]->xuanxiang))
                {
                    grade[i]+=sco[j]->perfect_score;
                }
                else
                {
                    error[j]++;
                }
                j++;
            }
            else
                continue;
        }
    }
    for(i=0 ; i<N ; i++)
        printf("%d\n",grade[i]);
    int max = Max(error,M);
    int xia_biao[M];
    j = 0;
    for(i=0 ; i<M ; i++)
    {
        if(error[i] == max)
            xia_biao[j++] = i+1;
    }
    if(max!=0)
    {
        printf("%d ",max);
        for(i=0 ; i<j ; i++)
            printf("%d%c",xia_biao[i],i==j-1?'\n':' ');
    }
    else
    {
        printf("Too simple\n");
    }

    return 0;
}


/*
�ܽ᣺
1.ʹ��scanf("[]")���뺯����ѡ����Ϊ�ַ�������
2.ʹ��strcmp�����������ж�ѡ���Ƿ���ȷ
*/





/*
ʱ�䣺2018/6/21 20��18��
���ߣ�¥��Ȼ
��Ŀ��
1065 ����(25)��25 �֣�
�������������Ķ��ڵ�����ʿ��һ�ְ��ơ���������������˵Ĵ����ɶ����ҳ��䵥�Ŀ��ˣ��Ա��������ذ���

�����ʽ��

�����һ�и���һ��������N��<=50000��������֪����/���µĶ��������N�У�ÿ�и���һ�Է���/���¡���Ϊ���������ÿ�˶�Ӧһ��ID�ţ�Ϊ5λ���֣���00000��99999����ID���Կո�ָ���֮�����һ��������M��<=10000����Ϊ�μ��ɶԵ������������һ�и�����Mλ���˵�ID���Կո�ָ�����Ŀ��֤�����ػ��Ų���������

�����ʽ��

���ȵ�һ������䵥���˵������������ڶ��а�ID����˳���г��䵥�Ŀ��ˡ�ID����1���ո�ָ����е���β�����ж���ո�

����������

3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
���������

5
10000 23333 44444 55555 88888
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ID[100000];
    int N,ID1,ID2;
    scanf("%d",&N);
    int i;
    for(i=0 ; i<100000 ; i++)
        ID[i] = -1;
    for(i=0 ; i<N ; i++)
    {
        scanf("%d %d",&ID1,&ID2);
        ID[ID1] = ID2;
        ID[ID2] = ID1;
    }
    int M;
    scanf("%d",&M);
    int count = 0; //��¼��������
    for(i=0 ; i<M ; i++)
    {
        scanf("%d",&ID1);
        if(ID[ID1]<0)
        {
            ID[ID1] = -2; //-2������
            count++;
         //   printf("%05d\n",ID1);
        }
        else
        {
            ID[ID1] = -3;
        }
    }
    for(i=0 ; i<100000 ; i++)
    {
        if(ID[i]>=0 && ID[ID[i]] == -3)
            ID[ID[i]] = -2 , count++;
    }
    printf("%d\n",count);
    for(i=0 ; i<100000 ; i++)
    {
        if(ID[i]==-2)
            printf("%05d%c",i,--count?' ':'\n');
    }
    return 0;
}

/*
�ܽ᣺
1.��һ������������±�����¼IDֵ
2.�Է��޵�IDֵ���й���
*/








/*  �𰸲���ȷ
#include <stdio.h>
//˼·�����ɶԵ��ѻ���ʿ�޳���ȥ������ID��char���洢����strstr()�������ж��Ƿ����һ���������Ƿ�ͬʱ��������ID
#include <stdlib.h>
#include <string.h>

int cmp(const void * a,const void * b)
{
    return *(char *)a - *(char *)b;
}

int main(void)
{
    int N;//���޶���
    scanf("%d",&N);
    char couple[N*2][6];//�洢����ID
    char Couple[N*2*7];//�����޵�ID�ϲ���һ��
    Couple[0] = '\0';
    int i;
    for(i=0 ; i<N*2 ; i++)
    {
        scanf("%s",couple[i]);
        strcat(Couple,couple[i]);
        strcat(Couple," ");
    }
 //   printf("%s\n",Couple);
    int K;//�λ�����
    scanf("%d",&K);
    while(getchar()!='\n')
        continue;
    char all[K*6+1];//����Ϊͬһ���ַ���
    all[0] = '\0';
    char All[K][7];//�ֿ�����ID
    char singal[K][7];//�䵥��ID
 //   scanf("%[^\n]",all);
    for(i=0 ; i<K ; i++)
    {
        scanf("%s",All[i]);
        strcat(all,All[i]);
        strcat(all," ");
    }
    int j = 0;
    for(i=0 ; i<N*2 ; i+=2)
    {
        if(strstr(all,couple[i])!=0 && strstr(all,couple[i+1])==0)
            strcpy(singal[j++],couple[i]);
        else if(strstr(all,couple[i])==0 && strstr(all,couple[i+1])!=0)
            strcpy(singal[j++],couple[i+1]);
        else
            continue;
    }
//    for(i=0 ; i<j ; i++)
  //     printf("%s\n",All[i]);
    for(i=0 ; i<K ; i++)
    {
        if(strstr(Couple,All[i])==0)
            strcpy(singal[j++],All[i]);
    }
  //  printf("%s\n",all);
  //  printf("%s\n",all);

    qsort(All,j,sizeof(char)*5,cmp);
    printf("%d\n",j);
    for(i=0 ; i<j ; i++)
       printf("%s%c",All[i],i==j-1?'\n':' ');
//    printf("%s",all);
    return 0;

}
*/


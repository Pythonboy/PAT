/*
ʱ�䣺2018/7/1
���ߣ�¥��Ȼ
��Ŀ��
1055 ������ (25)��25 �֣�
�ļ�����ʱ���κ���Ҫ������Ը�����N����K�ŵĶ�������Ŷӹ������£�

ÿ������ΪN/K������ȡ���������������ȫ��վ�����һ�ţ�
���������˵ĸ��Ӷ�����ǰ���κ��˰���
ÿ���������վ�м䣨�м�λ��Ϊm/2+1������mΪ������������������ȡ������
ÿ�����������м���Ϊ�ᣬ����߷��������Һ��������վ���м��˵����ࣨ����5�����Ϊ190��188��186��175��170�������Ϊ175��188��190��186��170�������������������ߣ��������������м��˵��ұߣ���
�����������ͬ�������ֵ��ֵ����������С����ﱣ֤��������
�ָ���һ�������ˣ����д����������ǵĶ��Ρ�

�����ʽ��

ÿ���������1������������ÿ������������1�и�������������N��<=10000������������K��<=10���������������N�У�ÿ�и���һ���˵����֣��������ո񡢳��Ȳ�����8��Ӣ����ĸ������ߣ�[30, 300]�����ڵ���������

�����ʽ��

������յĶ��Ρ���K������������Կո�ָ�����ĩ�����ж���ո�ע�⣺��������������ߣ����ŵ���������Ϸ���ǰ��������·���

����������

10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
���������

Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John
*/

//˼·���ȶ�������Ȼ���չ������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char Name[9];
    int height;
};

int cmp(const void * a, const void * b)
{
    struct student * s1 = *(struct student **)a;    //�ص㣬����һ���µĽṹ��ָ�����
    struct student * s2 = *(struct student **)b;
    if(s1->height != s2->height)
        return s2->height - s1->height;    //������ߴӴ�С����
    else
        return strcmp(s1->Name,s2->Name);  //������ĸ��������
}

int main(void)
{
    int N,K;//�ֱ����ѧ�������Ͷ�������
    scanf("%d %d",&N,&K);
    struct student * std[N]; //����һ��ָ������ṹ����
    int i;
    for(i=0 ; i<N ; i++)
    {
        std[i] = malloc(sizeof(struct student));
        scanf("%s %d",std[i]->Name,&std[i]->height);
    }
    qsort(std,N,sizeof(struct student *),cmp);
//    printf("������ߴӴ�С����\n");          //����û������
//    for(i=0 ; i<N ; i++)
 //       printf("%s %d\n",std[i]->Name,std[i]->height);
    int num[K];//ÿ��������
    for(i=0 ; i<K ; i++)
    {
        if(i==0)
            num[i] = N/K + N%K;
        else
            num[i] = N/K;
    }
    int z = 0;
    for(i=0 ; i<K; i++)
    {
        char temp[num[i]][9];
        int j ;
        int k = 0;
        int flag = 1;
        for(j=num[i]/2 ; j<num[i] && j>=0 ;)
        {
//            j += k*flag;
//            k++;
 //           if(k>num[i])
 //               break;
//            flag = -flag;
            strcpy(temp[j],std[z++]->Name);
            k++;
            flag = -flag;
            j+=k*flag;

        }
        for(j=0 ; j<num[i] ; j++)
        {
            printf("%s%c",temp[j],j==num[i]-1?'\n':' ');
        }
    }
    return 0;

}

/*
�ܽ᣺
1.�����ṹ��ָ���������һ�����ڴ�
2.qsort()������cmp�����нṹ��ָ���ָ���ȡֵ
3.����һ��������������ÿһ��Ҫ��������ֵ�˳��
*/

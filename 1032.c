/*
ʱ�䣺2018/6/20 09��08��
���ߣ�¥��Ȼ
��Ŀ��
1032 �ھ�������ļ�ǿ(20)��20 �֣�
Ϊ������ʵ˵���ھ�����������ļ�ǿ��PAT��֯��һ���ھ�����ܴ�������������ݱ������ͳ�Ƴ�������ǿ���Ǹ�ѧУ��

�����ʽ��

�����ڵ�1�и���������10^5^��������N�����������������N�У�ÿ�и���һλ�����ߵ���Ϣ�ͳɼ����������������ѧУ�ı�ţ���1��ʼ������ţ�����������ɼ����ٷ��ƣ����м��Կո�ָ���

�����ʽ��

��һ���и����ܵ÷���ߵ�ѧУ�ı�š������ܷ֣��м��Կո�ָ�����Ŀ��֤��Ψһ��û�в��С�

����������

6
3 65
2 80
1 100
2 70
3 40
3 0
���������

2 150
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int num;    //num�����������
    scanf("%d",&num);
    int grade[num];  //ÿ��ѧУ�����������ܷ�
    memset(grade,0,sizeof(int)*num);  //grade��������Ԫ��ȫ����ʼ��Ϊ0��memsetͷ�ļ�Ϊstring.h
    int school,score,i;
    int res=0;    //school�������ѧУ�ı�ţ�score����ÿ��ѧ���ķ���
    for(i=0 ; i<num ; i++){
        scanf("%d",&school);
        if(school>res)res = school;    //res����ѧУ����߱��
        scanf("%d",&score);
        grade[school] += score;
    }
    int high_school = 0 ,high_score = 0;  //�ֱ������߷ֵ�ѧУ�Լ�������С
    for (i=0 ; i<=res ; i++)
    {
        if (grade[i]>high_score)
        {
            high_school = i;
            high_score = grade[i];
        }
    }
    printf("%d %d",high_school,high_score);
    return 0;
}
